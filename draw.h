#ifndef DRAW_H
#define DRAW_H

struct pixel {
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

void draw_line(struct pixel** img_ary, int x1, int y1, int x2, int y2);
void init_image(struct pixel** img_ary, size_t width, size_t height);
void write_image(struct pixel** img_ary);


#endif
