#include <stdlib.h>
#include <stdio.h>
#include "draw.h"

int main() {
  struct pixel** image = init_image(512, 512);


  plot(image, (struct pixel){255,0,0,0}, 256,256);

  draw_line(image, (struct pixel){0,255,127,0}, 100, 100, 300, 220);

  draw_line(image, (struct pixel){0,255,255,0}, 200, 100, 200, 400);

  draw_line(image, (struct pixel){255,255,255,0}, 200, 200, 300, 350);

  draw_line(image, (struct pixel){255,0,255,0}, 300, 200, 450, 100);

  write_image(image);
  return 0;
}
