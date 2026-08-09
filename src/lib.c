int pow5(int x) {
  return x*x*x*x*x;
}

void calc_pow5_residues(int *fifth, int mod) {
  for (int i = 0; i < mod; i++)
	fifth[i] = pow5(i) % mod;
}

void populate_grid(int mod, int grid[][mod], int *fifth) {
  for (int x = 0; x < mod; x++) {
	for (int y = 0; y < mod; y++) {
	  grid[x][y] = (fifth[x] + fifth[y]) % mod;
	}
  }
}

void print_grid(int mod, int grid[][mod]) {
  int x, y;
  printf("   x\n");
  for (x = 0; x < mod; x++) {
	printf(" y ");
	for (y = 0; y < mod; y++) {
	  printf("%2d ", grid[x][y]);
	}
	printf("\n");
  }
}
