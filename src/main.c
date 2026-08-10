#include <stdio.h>
#include <math.h>
#include "lib.c"

int main(void) {
  int mod;
  mod = 11;
  int fifth[mod];
  int grid[mod][mod];

  calc_pow5_residues(fifth, mod);
  populate_grid(mod, grid, fifth);
  print_grid(mod, grid);

  int row_width = (((digits(mod) + 1) * 3) + 1) * mod + 10;
  char img[mod + 3][row_width];
  populate_header(mod, row_width, img);
  grid_to_img(mod, row_width, img, grid);

  write_img(mod, row_width, img);

  return 0;
}
