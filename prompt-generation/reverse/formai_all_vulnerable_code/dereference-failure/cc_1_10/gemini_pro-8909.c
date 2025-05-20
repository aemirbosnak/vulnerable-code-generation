//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the image struct
typedef struct image {
  unsigned char *data;
  int width;
  int height;
} image;

// Load an image from a file
image *load_image(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "rb");
  if (!file) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }

  // Read the header
  unsigned char header[18];
  fread(header, 18, 1, file);

  // Check if the file is a BMP file
  if (header[0] != 'B' || header[1] != 'M') {
    fprintf(stderr, "Error: file is not a BMP file\n");
    fclose(file);
    return NULL;
  }

  // Get the image dimensions
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Allocate memory for the image data
  image *img = malloc(sizeof(image));
  img->data = malloc(width * height * 3);
  img->width = width;
  img->height = height;

  // Read the image data
  fread(img->data, width * height * 3, 1, file);

  // Close the file
  fclose(file);

  // Return the image
  return img;
}

// Save an image to a file
void save_image(image *img, char *filename) {
  // Open the file
  FILE *file = fopen(filename, "wb");
  if (!file) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return;
  }

  // Write the header
  unsigned char header[18];
  header[0] = 'B';
  header[1] = 'M';
  *(int *)&header[2] = sizeof(header) + img->width * img->height * 3;
  *(int *)&header[10] = sizeof(header);
  *(int *)&header[14] = img->width;
  *(int *)&header[18] = img->height;
  *(short *)&header[26] = 1;
  *(short *)&header[28] = 24;
  fwrite(header, 18, 1, file);

  // Write the image data
  fwrite(img->data, img->width * img->height * 3, 1, file);

  // Close the file
  fclose(file);
}

// Flip an image horizontally
void flip_horizontal(image *img) {
  for (int y = 0; y < img->height; y++) {
    for (int x = 0; x < img->width / 2; x++) {
      unsigned char temp = img->data[y * img->width * 3 + x * 3];
      img->data[y * img->width * 3 + x * 3] = img->data[y * img->width * 3 + (img->width - x - 1) * 3];
      img->data[y * img->width * 3 + (img->width - x - 1) * 3] = temp;
    }
  }
}

// Flip an image vertically
void flip_vertical(image *img) {
  for (int y = 0; y < img->height / 2; y++) {
    for (int x = 0; x < img->width; x++) {
      unsigned char temp = img->data[y * img->width * 3 + x * 3];
      img->data[y * img->width * 3 + x * 3] = img->data[(img->height - y - 1) * img->width * 3 + x * 3];
      img->data[(img->height - y - 1) * img->width * 3 + x * 3] = temp;
    }
  }
}

// Change the brightness of an image
void change_brightness(image *img, int brightness) {
  for (int y = 0; y < img->height; y++) {
    for (int x = 0; x < img->width; x++) {
      for (int c = 0; c < 3; c++) {
        int new_value = img->data[y * img->width * 3 + x * 3 + c] + brightness;
        if (new_value < 0) new_value = 0;
        if (new_value > 255) new_value = 255;
        img->data[y * img->width * 3 + x * 3 + c] = new_value;
      }
    }
  }
}

// Change the contrast of an image
void change_contrast(image *img, int contrast) {
  float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
  for (int y = 0; y < img->height; y++) {
    for (int x = 0; x < img->width; x++) {
      for (int c = 0; c < 3; c++) {
        int new_value = factor * (img->data[y * img->width * 3 + x * 3 + c] - 128) + 128;
        if (new_value < 0) new_value = 0;
        if (new_value > 255) new_value = 255;
        img->data[y * img->width * 3 + x * 3 + c] = new_value;
      }
    }
  }
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided enough arguments
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <input image> <output image> <operation>\n", argv[0]);
    return 1;
  }

  // Load the input image
  image *img = load_image(argv[1]);
  if (!img) {
    return 1;
  }

  // Perform the specified operation
  if (strcmp(argv[3], "flip-horizontal") == 0) {
    flip_horizontal(img);
  } else if (strcmp(argv[3], "flip-vertical") == 0) {
    flip_vertical(img);
  } else if (strcmp(argv[3], "change-brightness") == 0) {
    change_brightness(img, atoi(argv[4]));
  } else if (strcmp(argv[3], "change-contrast") == 0) {
    change_contrast(img, atoi(argv[4]));
  } else {
    fprintf(stderr, "Unknown operation: %s\n", argv[3]);
    return 1;
  }

  // Save the output image
  save_image(img, argv[2]);

  // Free the memory allocated for the image
  free(img->data);
  free(img);

  return 0;
}