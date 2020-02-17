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

  if (a > 0) {
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
    if (a > b) { // octant 8
      int err = 2 * a - b;
      while (x1 < x2) {
        plot(img_ary, color, x1, y1);
        if (err < 0) {
          y1--;
          err -= b;
        }
        x1++;
        err += a;
      }
    } else { // octant 7
      int err = -2 * b + a;
      while (y1 > y2) {
        plot(img_ary, color, x1, y1);
        if (err > 0) {
          x1++;
          err += a;
        }
        y1--;
        err -= b;
      }
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
    *row = calloc(width + 1, sizeof(struct pixel));
    // pix = *row;
    // int j;
    //
    // for (j = 0; j < width; j++, pix++) {
    //   pix->r=0;
    //   pix->g=0;
    //   pix->b=0;
    // }
    (*row)[width].blank = 1;
  }

  return img_ary;
}

void write_image(struct pixel** img_ary) {
  FILE* img = fopen("image.ppm", "w");

  struct pixel** row;
  struct pixel* pix;

  for (row = img_ary; *row; row++);
  for (pix = *img_ary; !pix->blank; pix++);

  fprintf(img, "P3\n%ld %ld 255\n", pix - *img_ary, row - img_ary);

  for (row--; row >= img_ary; row--) {
    // printf("%p, %p\n", row, img_ary);
    for (pix = *row; !pix->blank; pix++) {
      fprintf(img, "%d ", pix->r);
      fprintf(img, "%d ", pix->g);
      fprintf(img, "%d ", pix->b);
    }
    fprintf(img, "\n");
  }

  fclose(img);
}
