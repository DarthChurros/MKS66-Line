#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "draw.h"

void draw_line(struct pixel** img_ary, int x1, int y1, int x2, int y2) {

}

struct pixel** init_image(size_t width, size_t height) {
  struct pixel** img_ary = malloc((height + 1) * sizeof(struct pixel*));
  img_ary[height] = NULL;

  struct pixel** row = **img_ary;
  struct pixel* pix = *row;

  while (row) {
    pix = *row;
    *pix = calloc(width, sizeof(struct pixel));
    int i;

    for (i = 0; i < width; i++, pix++) {
      pix->r=0;
      pix->g=0;
      pix->b=0;
    }
  }

  return img_ary;
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
