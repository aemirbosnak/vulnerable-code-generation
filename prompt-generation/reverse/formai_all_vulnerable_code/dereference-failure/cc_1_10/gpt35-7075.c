//FormAI DATASET v1.0 Category: Image Editor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
  unsigned char red, green, blue;
} pixel_t;

typedef struct {
  pixel_t *pixels;
  size_t width, height;
} bitmap_t;

bitmap_t *load_bitmap(const char *filename) {
  FILE *f = fopen(filename, "rb");
  if (!f) return NULL;
  bitmap_t *bmp = malloc(sizeof(bitmap_t));
  bmp->pixels = NULL;

  // Read header
  unsigned char header[54]; // BMP files always start with a 54-byte header
  fread(header, sizeof(unsigned char), 54, f);

  // Verify header
  if (header[0] != 'B' || header[1] != 'M') {
    fclose(f);
    free(bmp);
    return NULL;
  }

  // Read dimensions
  bmp->width = *(int*)&header[18];
  bmp->height = *(int*)&header[22];

  // Read pixel data
  int padding = (4 - (bmp->width * sizeof(pixel_t)) % 4) % 4;
  bmp->pixels = malloc(sizeof(pixel_t) * bmp->width * bmp->height);
  for (int y = 0; y < bmp->height; y++) {
    for (int x = 0; x < bmp->width; x++) {
      pixel_t *p = &bmp->pixels[y * bmp->width + x];
      fread(p, sizeof(pixel_t), 1, f);
    }
    fseek(f, padding, SEEK_CUR);
  }

  fclose(f);
  return bmp;
}

void save_bitmap(bitmap_t *bmp, const char *filename) {
  FILE *f = fopen(filename, "wb");
  if (!f) return;

  unsigned char header[54] = {
    'B','M', // magic
    0,0,0,0, // size in bytes
    0,0,0,0, // app specific
    54,0,0,0, // offset to start of pixel data
    40,0,0,0, // info hd size
    0,0,0,0, // width
    0,0,0,0, // height (negative to flip)
    1,0,24,0, // planes, bpp
    0,0,0,0, // compression
    0,0,0,0, // image size
    0,0,0,0, // ppm x
    0,0,0,0, // ppm y
    0,0,0,0, // palette
    0,0,0,0 // # of colors
  };

  int padding = (4 - (bmp->width * sizeof(pixel_t)) % 4) % 4;
  int size = bmp->width * bmp->height * sizeof(pixel_t) + bmp->height * padding;

  header[ 2] = (unsigned char)(size    );
  header[ 3] = (unsigned char)(size>> 8);
  header[ 4] = (unsigned char)(size>>16);
  header[ 5] = (unsigned char)(size>>24);

  header[18] = bmp->width        ;
  header[19] = bmp->width    >> 8;
  header[20] = bmp->width    >>16;
  header[21] = bmp->width    >>24;

  header[22] = bmp->height       ;
  header[23] = bmp->height   >> 8;
  header[24] = bmp->height   >>16;
  header[25] = bmp->height   >>24;

  fwrite(header, sizeof(unsigned char), 54, f);
  for (int y = 0; y < bmp->height; y++) {
    for (int x = 0; x < bmp->width; x++) {
      pixel_t *p = &bmp->pixels[y * bmp->width + x];
      fwrite(p, sizeof(pixel_t), 1, f);
    }
    for (int i = 0; i < padding; i++) {
      fputc(0, f);
    }
  }

  fclose(f);
}

void grayscale(bitmap_t *bmp) {
  for (int y = 0; y < bmp->height; y++) {
    for (int x = 0; x < bmp->width; x++) {
      pixel_t *p = &bmp->pixels[y * bmp->width + x];
      unsigned char gray = (p->red + p->green + p->blue) / 3;
      p->red = p->green = p->blue = gray;
    }
  }
}

bool is_inside(int x, int y, int width, int height) {
  return x >= 0 && x < width && y >= 0 && y < height;
}

void blur(bitmap_t *bmp, int radius) {
  pixel_t *temp = malloc(sizeof(pixel_t) * bmp->width * bmp->height); // temp buffer to hold intermediate results
  if (!temp) return;

  for (int y = 0; y < bmp->height; y++) {
    for (int x = 0; x < bmp->width; x++) {
      // Accumulate colors from nearby pixels
      int red = 0, green = 0, blue = 0, count = 0;
      for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
          int xx = x + i, yy = y + j;
          if (is_inside(xx, yy, bmp->width, bmp->height)) {
            pixel_t *p = &bmp->pixels[yy * bmp->width + xx];
            red += p->red;
            green += p->green;
            blue += p->blue;
            count++;
          }
        }
      }

      // Compute average color and store in temp buffer
      pixel_t *p = &temp[y * bmp->width + x];
      p->red = red / count;
      p->green = green / count;
      p->blue = blue / count;
    }
  }

  // Copy temp buffer back to original buffer
  memcpy(bmp->pixels, temp, sizeof(pixel_t) * bmp->width * bmp->height);
  free(temp);
}

int main() {
  bitmap_t *bmp = load_bitmap("example.bmp");
  if (!bmp) {
    printf("Failed to load bitmap\n");
    return -1;
  }

  grayscale(bmp);
  blur(bmp, 4);
  save_bitmap(bmp, "output.bmp");

  free(bmp->pixels);
  free(bmp);
  return 0;
}