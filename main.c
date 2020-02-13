#include <stdlib.h>
#include <stdio.h>
#include "draw.h"

int main() {
  struct pixel** image = init_image(512, 512);


  plot(image, (struct pixel){255,0,0}, 256,256);

  write_image(image);
  return 0;
}
