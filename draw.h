#ifndef DRAW_H
#define DRAW_H

struct pixel {
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

void init_pixel(struct pixel pix);
void draw_line(struct pixel** img_ary);
void init_image(struct pixel** img_ary);


#endif
