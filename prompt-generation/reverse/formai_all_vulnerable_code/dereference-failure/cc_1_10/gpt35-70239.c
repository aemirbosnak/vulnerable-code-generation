//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
  char *file_name_in = argv[1];
  char *file_name_out = argv[2];
  int height, width, max_val, brightness, contrast, i, j;

  // Opening the input file
  FILE *file_in = fopen(file_name_in, "rb");
  if (file_in == NULL) {
    printf("ERROR: Could not open input file");
    return 1;
  }

  // Reading the image header
  fscanf(file_in, "P6\n%d %d\n%d\n", &width, &height, &max_val);

  // Creating the image matrix
  unsigned char *img = (unsigned char*) malloc(width * height * 3 * sizeof(unsigned char));

  // Reading the image pixels
  fread(img, sizeof(unsigned char), width * height * 3, file_in);

  // Closing the input file
  fclose(file_in);

  // Flipping the image
  for (i = 0; i < height/2; i++) {
    for (j = 0; j < width * 3; j++) {
      unsigned char temp = img[i * (width*3) + j];
      img[i * (width*3) + j] = img[(height - i - 1) * (width*3) + j];
      img[(height - i - 1) * (width*3) + j] = temp;
    }
  }

  // Setting the brightness and contrast
  brightness = atoi(argv[3]);
  contrast = atoi(argv[4]);
  for (i = 0; i < height; i++) {
    for (j = 0; j < width * 3; j += 3) {
      img[i * (width*3) + j] += brightness;
      img[i * (width*3) + j + 1] += brightness;
      img[i * (width*3) + j + 2] += brightness;
      
      img[i * (width*3) + j] = (img[i * (width*3) + j] - 128) * contrast + 128;
      img[i * (width*3) + j + 1] = (img[i * (width*3) + j + 1] - 128) * contrast + 128;
      img[i * (width*3) + j + 2] = (img[i * (width*3) + j + 2] - 128) * contrast + 128;
    }
  }

  // Opening the output file
  FILE *file_out = fopen(file_name_out, "wb");
  if (file_out == NULL) {
    printf("ERROR: Could not open output file");
    return 1;
  }

  // Writing the new image
  fprintf(file_out, "P6\n%d %d\n%d\n", width, height, max_val);
  fwrite(img, sizeof(unsigned char), width * height * 3, file_out);

  // Closing the output file
  fclose(file_out);

  // Freeing the memory
  free(img);

  printf("Image processing completed successfully!\n");

  return 0;
}