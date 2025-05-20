//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: futuristic
#include <stdio.h>

int main() {
  // Opening image file
  FILE *imageFile = fopen("image.bmp", "rb");
  
  // Reading header data
  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, imageFile);

  // Extracting image dimensions
  int width = *(int*)&header[18];
  int height = *(int*)&header[22];

  // Allocating memory for image data
  int imageSize = width * height * 3;
  unsigned char* imageData = (unsigned char*)malloc(sizeof(unsigned char) * imageSize);

  // Reading image data
  fread(imageData, sizeof(unsigned char), imageSize, imageFile);

  // Flipping the image horizontally
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width / 2; x++) {
      int index1 = (y * width + x) * 3;
      int index2 = (y * width + (width - x - 1)) * 3;

      // Swapping pixel values for R, G, B channels
      unsigned char tempR = imageData[index1];
      unsigned char tempG = imageData[index1 + 1];
      unsigned char tempB = imageData[index1 + 2];

      imageData[index1] = imageData[index2];
      imageData[index1 + 1] = imageData[index2 + 1];
      imageData[index1 + 2] = imageData[index2 + 2];

      imageData[index2] = tempR;
      imageData[index2 + 1] = tempG;
      imageData[index2 + 2] = tempB;
    }
  }

  // Adjusting the brightness and contrast of the image
  float brightness = 0.2;
  float contrast = 1.5;

  for (int i = 0; i < imageSize; i++) {
    float pixelValue = imageData[i];

    // Applying brightness adjustment
    pixelValue += brightness * 255;

    // Applying contrast adjustment
    pixelValue = (pixelValue - 127.5) * contrast + 127.5;

    if (pixelValue > 255) {
      pixelValue = 255;
    }

    if (pixelValue < 0) {
      pixelValue = 0;
    }

    imageData[i] = (unsigned char)pixelValue;
  }

  // Writing the modified image data to a new file
  FILE *outputFile = fopen("modified_image.bmp", "wb");

  fwrite(header, sizeof(unsigned char), 54, outputFile);
  fwrite(imageData, sizeof(unsigned char), imageSize, outputFile);

  fclose(imageFile);
  fclose(outputFile);

  return 0;
}