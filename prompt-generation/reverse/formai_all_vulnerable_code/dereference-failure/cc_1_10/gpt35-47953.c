//FormAI DATASET v1.0 Category: Image Classification system ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the Image structure
typedef struct Image {
  int width;
  int height;
  int *pixels;
} Image;

// Function to classify the image
int classify_image(Image *img) {
  int sum = 0;

  // Calculate the sum of all pixel values
  for (int i = 0; i < img->width * img->height; i++) {
    sum += img->pixels[i];
  }

  // Calculate the average pixel value
  int avg = sum / (img->width * img->height);

  // Classify the image based on the average pixel value
  if (avg < 50) {
    return 0; // Dark image
  } else if (avg < 150) {
    return 1; // Gray image
  } else {
    return 2; // Bright image
  }
}

int main(void) {
  // Define and initialize the image
  Image img;
  img.width = 4;
  img.height = 4;
  img.pixels = malloc(img.width * img.height * sizeof(int));
  img.pixels[0] = 155;
  img.pixels[1] = 135;
  img.pixels[2] = 160;
  img.pixels[3] = 155;
  img.pixels[4] = 140;
  img.pixels[5] = 130;
  img.pixels[6] = 170;
  img.pixels[7] = 155;
  img.pixels[8] = 150;
  img.pixels[9] = 125;
  img.pixels[10] = 180;
  img.pixels[11] = 150;
  img.pixels[12] = 185;
  img.pixels[13] = 175;
  img.pixels[14] = 140;
  img.pixels[15] = 130;

  // Classify the image
  int class = classify_image(&img);

  // Print the classification result
  if (class == 0) {
    printf("The image is dark.\n");
  } else if (class == 1) {
    printf("The image is gray.\n");
  } else {
    printf("The image is bright.\n");
  }

  return 0;
}