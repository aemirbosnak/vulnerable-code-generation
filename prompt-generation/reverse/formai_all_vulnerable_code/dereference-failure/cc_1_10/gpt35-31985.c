//FormAI DATASET v1.0 Category: Image Editor ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 255

// Image struct
typedef struct {
  int width;
  int height;
  unsigned char *data;
} Image;

// Function to create a new image
Image* create_image(int width, int height) {
  Image *img = malloc(sizeof(Image));
  if (img == NULL) {
    fprintf(stderr, "Error: could not allocate memory for image.\n");
    exit(1);
  }

  img->width = width;
  img->height = height;
  img->data = malloc(sizeof(unsigned char)*width*height);
  if (img->data == NULL) {
    fprintf(stderr, "Error: could not allocate memory for image data.\n");
    exit(1);
  }

  memset(img->data, 0, sizeof(unsigned char)*width*height);
  return img;
}

// Function to free an image
void free_image(Image *img) {
  free(img->data);
  free(img);
}

// Function to read an image from file
Image* read_image(char *filename) {
  FILE *fptr = fopen(filename, "rb");
  if (fptr == NULL) {
    fprintf(stderr, "Error: could not open file \"%s\".\n", filename);
    exit(1);
  }

  char header[54];
  fread(header, sizeof(char), 54, fptr);

  int width = *(int*)&header[18];
  int height = *(int*)&header[22];

  Image *img = create_image(width, height);

  fseek(fptr, *(int*)&header[10], SEEK_SET);
  fread(img->data, sizeof(unsigned char), width*height, fptr);

  fclose(fptr);
  return img;
}

// Function to write an image to file
void write_image(char *filename, Image *img) {
  FILE *fptr = fopen(filename, "wb");
  if (fptr == NULL) {
    fprintf(stderr, "Error: could not open file \"%s\".\n", filename);
    exit(1);
  }

  // BMP header
  char header[54];
  memset(header, 0, sizeof(header));
  header[0] = 'B';
  header[1] = 'M';
  *(int*)&header[2] = 54 + img->width*img->height;
  *(int*)&header[10] = 54;
  *(int*)&header[14] = 40;
  *(int*)&header[18] = img->width;
  *(int*)&header[22] = img->height;
  *(short*)&header[26] = 1;
  *(short*)&header[28] = 8;
  *(int*)&header[34] = img->width*img->height;
  fwrite(header, sizeof(char), 54, fptr);

  // BMP palette
  unsigned char palette[1024];
  memset(palette, 0, sizeof(palette));
  for (int i = 0; i < 256; i++) {
    palette[4*i+0] = i;
    palette[4*i+1] = i;
    palette[4*i+2] = i;
  }
  fwrite(palette, sizeof(unsigned char), 1024, fptr);

  fwrite(img->data, sizeof(unsigned char), img->width*img->height, fptr);
  fclose(fptr);
}

// Function to invert an image
Image* invert_image(Image *img) {
  Image *new_img = create_image(img->width, img->height);
  for (int i = 0; i < img->width*img->height; i++) {
    new_img->data[i] = 255 - img->data[i];
  }
  return new_img;
}

// Function to reduce the color depth of an image
Image* reduce_color_depth(Image *img, int depth) {
  int color_step = 256/depth;
  Image *new_img = create_image(img->width, img->height);
  for (int i = 0; i < img->width*img->height; i++) {
    new_img->data[i] = (img->data[i]/color_step)*color_step;
  }
  return new_img;
}

int main(int argc, char **argv) {
  if (argc < 3 || argc > 4) {
    fprintf(stderr, "Usage: %s <input file> <output file> [q]\n", argv[0]);
    exit(1);
  }

  char *input_filename = argv[1];
  char *output_filename = argv[2];
  int quality = 100;
  if (argc == 4) {
    if (sscanf(argv[3], "%d", &quality) != 1 || quality < 0 || quality > 100) {
      fprintf(stderr, "Error: invalid quality level \"%s\".\n", argv[3]);
      exit(1);
    }
  }

  Image *img = read_image(input_filename);
  Image *new_img = reduce_color_depth(invert_image(img), 4);

  write_image(output_filename, new_img);

  free_image(img);
  free_image(new_img);

  return 0;
}