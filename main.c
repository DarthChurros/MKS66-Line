#include <stdlib.h>
#include <stdio.h>
#include "draw.h"

int main() {
  struct pixel** image = init_image(2048, 2048);

  int i;
  struct pixel color = {255, 128, 0, 0};

  for (i = 0; i < 2048; i+=16) {
    draw_line(image, color, 0, i, 2047, 2047-i);
    draw_line(image, color, i, 0, 2047-i, 2047);

    color.r -= 2;
    color.g += 2;
    color.b += 2;
  }

  color.r += 2;
  color.g -= 2;
  color.b -= 2;

  draw_line(image, color, 0, 2047, 2047, 0);

  write_image(image);
  return 0;
}
