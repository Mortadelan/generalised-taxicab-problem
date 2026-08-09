#include <stdio.h>
#include "lib.c"
#include <math.h>

int main(void) {
  int mod;
  mod = 11;
  int fifth[mod];
  int grid[mod][mod];

  calc_pow5_residues(fifth, mod);
  populate_grid(mod, grid, fifth);
  print_grid(mod, grid);

  return 0;
}
