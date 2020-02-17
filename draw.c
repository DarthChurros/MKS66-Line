#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "draw.h"

void plot(struct pixel** img_ary, struct pixel color, int x, int y) {
  img_ary[y][x] = color;
}

void draw_line(struct pixel** img_ary, struct pixel color, int x1, int y1, int x2, int y2) {
  if (x1 > x2) {
    x1 = x1 ^ x2;
    x2 = x1 ^ x2;
    x1 = x1 ^ x2;

    y1 = y1 ^ y2;
    y2 = y1 ^ y2;
    y1 = y1 ^ y2;
  }

  int a = y2 - y1;
  int b = x1 - x2;

  if (!b) { //vertical
    int y;
    for (y = y1; y <= y2; y++) plot(img_ary, color, x1, y);
    return;
  }

  if (a * b < 0) {
    if (a < -b) { //octant 1
      int err = 2 * a + b;
      while (x1 < x2) {
        plot(img_ary, color, x1, y1);
        if (err > 0) {
          y1++;
          err += b;
        }
        x1++;
        err += a;
      }
    } else { //octant 2
      int err = 2 * b + a;
      while (y1 < y2) {
        plot(img_ary, color, x1, y1);
        if (err < 0) {
          x1++;
          err += a;
        }
        y1++;
        err += b;
      }
    }
  } else {
    if (a > b) { // octant 3
      
    }
  }
}

struct pixel** init_image(size_t width, size_t height) {
  struct pixel** img_ary = malloc((height + 1) * sizeof(struct pixel*));
  img_ary[height] = NULL;

  struct pixel** row = img_ary;
  struct pixel* pix = *row;

  int i;
  for (i = 0; i < height; i++, row++) {
    *row = calloc(width, sizeof(struct pixel));
    pix = *row;
    int j;

    for (j = 0; j < width; j++, pix++) {
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
      fprintf(img, "%d ", img_ary[i][j].r);
      fprintf(img, "%d ", img_ary[i][j].g);
      fprintf(img, "%d ", img_ary[i][j].b);
    }
    fprintf(img, "\n");
  }

  fclose(img);
}
