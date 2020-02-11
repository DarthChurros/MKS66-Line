#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "draw.h"

void init_pixel(struct pixel pix) {

}

void draw_line(struct pixel** img_ary) {

}

void init_image(struct pixel** img_ary) {

}

void write_image(struct pixel** img_ary) {
  FILE* img = fopen("image.ppm", "w");
  fprintf(img, "P3\n512 512 255\n");

  int i;
  int j;
  int k;
  for (i = 0; i < 512; i++) {
    for (j = 0; j < 512; j++) {
      fprintf(img, "%d ", img_ary[i][j].r));
      fprintf(img, "%d ", img_ary[i][j].g));
      fprintf(img, "%d ", img_ary[i][j].b));
    }
    fprintf(img, "\n");
  }

  fclose(img);
}
