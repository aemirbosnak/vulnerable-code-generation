//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Image dimensions
#define WIDTH 800
#define HEIGHT 600

// Romeo and Juliet style text
#define ROMEO "Wherefore art thou, Romeo?"
#define JULIET "My bounty is as boundless as the sea"

// Function to flip an image vertically
void flip_vertical(unsigned char *image) {
  for (int i = 0; i < HEIGHT / 2; i++) {
    for (int j = 0; j < WIDTH; j++) {
      unsigned char temp = image[i * WIDTH + j];
      image[i * WIDTH + j] = image[(HEIGHT - i - 1) * WIDTH + j];
      image[(HEIGHT - i - 1) * WIDTH + j] = temp;
    }
  }
}

// Function to change the brightness of an image
void change_brightness(unsigned char *image, int brightness) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      int new_value = image[i * WIDTH + j] + brightness;
      if (new_value > 255) {
        new_value = 255;
      } else if (new_value < 0) {
        new_value = 0;
      }
      image[i * WIDTH + j] = new_value;
    }
  }
}

// Function to change the contrast of an image
void change_contrast(unsigned char *image, int contrast) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      int new_value = (image[i * WIDTH + j] - 128) * contrast + 128;
      if (new_value > 255) {
        new_value = 255;
      } else if (new_value < 0) {
        new_value = 0;
      }
      image[i * WIDTH + j] = new_value;
    }
  }
}

// Main function
int main() {
  // Allocate memory for the image
  unsigned char *image = malloc(WIDTH * HEIGHT);

  // Load the image from a file
  FILE *file = fopen("image.bmp", "rb");
  fread(image, 1, WIDTH * HEIGHT, file);
  fclose(file);

  // Flip the image vertically
  flip_vertical(image);

  // Change the brightness of the image
  change_brightness(image, 50);

  // Change the contrast of the image
  change_contrast(image, 150);

  // Draw the Romeo and Juliet text on the image
  int text_width = strlen(ROMEO) * 12;
  int text_height = 16;
  int text_x = (WIDTH - text_width) / 2;
  int text_y = (HEIGHT - text_height) / 2;
  for (int i = 0; i < strlen(ROMEO); i++) {
    for (int j = 0; j < 12; j++) {
      image[(text_y + i) * WIDTH + text_x + j] = 0;
    }
  }
  for (int i = 0; i < strlen(JULIET); i++) {
    for (int j = 0; j < 12; j++) {
      image[(text_y + i + 20) * WIDTH + text_x + j] = 0;
    }
  }

  // Save the image to a file
  file = fopen("image_processed.bmp", "wb");
  fwrite(image, 1, WIDTH * HEIGHT, file);
  fclose(file);

  // Free the memory allocated for the image
  free(image);

  return 0;
}