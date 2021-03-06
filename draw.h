#ifndef DRAW_H
#define DRAW_H

struct pixel {
  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char blank;
};

void plot(struct pixel** img_ary, struct pixel color, int x, int y);
void draw_line(struct pixel** img_ary, struct pixel color, int x1, int y1, int x2, int y2);
struct pixel** init_image(size_t width, size_t height);
void write_image(struct pixel** img_ary);


#endif
