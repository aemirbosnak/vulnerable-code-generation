//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main() {
  int height, width, max_pixel;
  char magic_number[3];
  printf("Enter the magic number of the image file: ");
  scanf("%s", magic_number);
  printf("Enter the height of the image: ");
  scanf("%d", &height);
  printf("Enter the width of the image: ");
  scanf("%d", &width);
  printf("Enter the maximum pixel value of the image: ");
  scanf("%d", &max_pixel);

  int image[height][width], flipped_image[height][width];
  printf("Enter the pixel values of the image:\n");
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      scanf("%d", &image[i][j]);
    }
  }

  // Flipping the Image
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      flipped_image[height-1-i][width-1-j] = image[i][j];
    }
  }

  // Changing Brightness
  int brightness_value;
  printf("Enter the brightness value to change the image (between -255 to 255): ");
  scanf("%d", &brightness_value);
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      int new_pixel_value = image[i][j] + brightness_value;
      if(new_pixel_value > max_pixel) {
        image[i][j] = max_pixel;
      } else if(new_pixel_value < 0) {
        image[i][j] = 0;
      } else {
        image[i][j] = new_pixel_value;
      }
    }
  }

  // Changing Contrast
  float contrast_value;
  printf("Enter the contrast value to change the image (between 0 to 10): ");
  scanf("%f", &contrast_value);
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      int new_pixel_value = (image[i][j] - max_pixel/2) * contrast_value + max_pixel/2;
      if(new_pixel_value > max_pixel) {
        image[i][j] = max_pixel;
      } else if(new_pixel_value < 0) {
        image[i][j] = 0;
      } else {
        image[i][j] = new_pixel_value;
      }
    }
  }

  printf("The original image:\n");
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      printf("%d ", image[i][j]);
    }
    printf("\n");
  }

  printf("The flipped image:\n");
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      printf("%d ", flipped_image[i][j]);
    }
    printf("\n");
  }

  return 0;
}