#include <stdlib.h>
#include <stdio.h>
#include "draw.h"

int main() {
  struct pixel** image = init_image(512, 512);
  write_image(image);
  return 0;
}
