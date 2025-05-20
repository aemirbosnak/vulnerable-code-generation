//GEMINI-pro DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Constants and structures

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} Color;

typedef struct {
  unsigned int width;
  unsigned int height;
  Color *data;
} Image;

// Functions

Image *load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error: cannot open file '%s'.\n", filename);
    return NULL;
  }

  // Read the file header

  unsigned char header[14];
  fread(header, 1, 14, fp);

  // Check the file header

  if (header[0] != 'B' || header[1] != 'M') {
    fprintf(stderr, "Error: invalid file header.\n");
    fclose(fp);
    return NULL;
  }

  // Read the file data

  unsigned int filesize = *(unsigned int *)&header[2];
  unsigned int offset = *(unsigned int *)&header[10];
  unsigned int size = filesize - offset;

  Image *image = (Image *)malloc(sizeof(Image));
  if (image == NULL) {
    fprintf(stderr, "Error: cannot allocate memory for image.\n");
    fclose(fp);
    return NULL;
  }

  image->width = *(unsigned int *)&header[18];
  image->height = *(unsigned int *)&header[22];
  image->data = (Color *)malloc(image->width * image->height * sizeof(Color));
  if (image->data == NULL) {
    fprintf(stderr, "Error: cannot allocate memory for image data.\n");
    free(image);
    fclose(fp);
    return NULL;
  }

  fseek(fp, offset, SEEK_SET);
  fread(image->data, 1, size, fp);

  // Close the file

  fclose(fp);

  // Return the image

  return image;
}

void save_image(const char *filename, Image *image) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    fprintf(stderr, "Error: cannot open file '%s'.\n", filename);
    return;
  }

  // Write the file header

  unsigned char header[14];
  header[0] = 'B';
  header[1] = 'M';
  *(unsigned int *)&header[2] = image->width * image->height * 3 + 14;
  *(unsigned int *)&header[10] = 14;
  fwrite(header, 1, 14, fp);

  // Write the file data

  fwrite(image->data, 1, image->width * image->height * 3, fp);

  // Close the file

  fclose(fp);
}

// Main function

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Load the input image

  Image *image = load_image(argv[1]);
  if (image == NULL) {
    return EXIT_FAILURE;
  }

  // Process the image

  for (unsigned int y = 0; y < image->height; y++) {
    for (unsigned int x = 0; x < image->width; x++) {
      Color color = image->data[y * image->width + x];
      color.r = (color.r + 128) % 256;
      color.g = (color.g + 128) % 256;
      color.b = (color.b + 128) % 256;
      image->data[y * image->width + x] = color;
    }
  }

  // Save the output image

  save_image(argv[2], image);

  // Free the image

  free(image->data);
  free(image);

  return EXIT_SUCCESS;
}