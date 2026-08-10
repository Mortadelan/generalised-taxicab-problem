
/*
  count digits of x in base 10
 */
int digits(int x) {
  int i = 0;
  while (x >= 10) {
	x /= 10;
	i++;
  }
  return i;
}

/*
  raise x to the fifth power
 */
int pow5(int x) {
  return x*x*x*x*x;
}

/*
  calculate i^5 modulus mod
 */
void calc_pow5_residues(int *fifth, int mod) {
  for (int i = 0; i < mod; i++)
	fifth[i] = pow5(i) % mod;
}

/*
  populate_grid: populate grid with sums of fifth power residues, modulus mod
 */
void populate_grid(int mod, int grid[][mod], int *fifth) {
  for (int x = 0; x < mod; x++) {
	for (int y = 0; y < mod; y++) {
	  grid[x][y] = (fifth[x] + fifth[y]) % mod;
	}
  }
}

/*
  print_grid: print, line by line, the grid given by the 2D array grid[][mod]
 */
void print_grid(int mod, int grid[][mod]) {
  int x, y;
  for (x = 0; x < mod; x++) {
	for (y = 0; y < mod; y++) {
	  printf("%2d ", grid[x][y]);
	}
	printf("\n");
  }
}

/*
 populate_header: fill char *img with the PPM header for an RGB image,
 defined by a grid of mod x mod, and with mod number of colours
 */
void populate_header(
  int mod,
  int row_width,
  char img[mod + 3][row_width])
{
  sprintf(img[0], "P3\n");
  sprintf(img[1], "%d %d\n", mod, mod);
  sprintf(img[2], "%d\n", mod);
}

/*
  grid_to_img: converts a 2D grid with values between 0 and mod, into a PPM image file
  stored inside char *img
 */
void grid_to_img(
  int mod,
  int row_width,
  char img[mod + 3][row_width],
  int grid[][mod])
{
  for (int y = 0; y < mod; y++) {
	int pos = 0;
	for (int x = 0; x < mod; x++) {
	  pos += snprintf(
	    &img[y + 3][pos],
	    row_width - pos,
	    "%d %d %d ",
	    grid[y][x],
	    grid[y][x],
	    grid[y][x]
	  );
	}
	pos += snprintf(
      &img[y + 3][pos],
      row_width - pos,
      "\n"
	);
  }
}

/*
  write_img: writes a 2D array into a file named after the mod value
 */
void write_img(
  int mod,
  int row_width,
  char img[mod + 3][row_width])
{
  char name[16];
  sprintf(name, "mod%d.ppm", mod);
  FILE *fp = fopen(name, "w");

  if (fp == NULL) {
	perror("couldn't open img.ppm");
	return;
  }

  for (int i = 0; i < mod + 3; i++)
	fputs(img[i], fp);

  fclose(fp);
}

/*
  generate_img: generates a 2D grid and a PPM image of that 2D grid
  the grid is a sum table of the fifth power residues of a given modulus
 */
void generate_img(int mod) {
  int fifth[mod];
  int grid[mod][mod];

  calc_pow5_residues(fifth, mod);
  populate_grid(mod, grid, fifth);
  print_grid(mod, grid);

  int row_width = (((digits(mod) + 1) * 3) + 1) * mod + 50;
  char img[mod + 3][row_width];
  populate_header(mod, row_width, img);
  grid_to_img(mod, row_width, img, grid);

  write_img(mod, row_width, img);
}

/*
  count_colours: count what will become colours, but in actuality we're counting occourances of numbers within a grid

void count_colours(int mod, int grid[][mod]) {
}
 */
