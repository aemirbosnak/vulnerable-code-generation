//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMG_WIDTH 80
#define IMG_HEIGHT 40

char* ascii_chars = " .:-=+*#%@";

void convert_to_ascii(unsigned char* img, char* output) {
  float grayscale_value;
  int index;

  for (int y = 0; y < IMG_HEIGHT; y++) {
    for (int x = 0; x < IMG_WIDTH; x++) {
      index = y * IMG_WIDTH + x;
      grayscale_value = (float)img[index] / 255.0f;
      output[index] = ascii_chars[(int)(grayscale_value * (strlen(ascii_chars) - 1))];
    }
    output[y * IMG_WIDTH + IMG_WIDTH] = '\n';
  }
  output[IMG_HEIGHT * IMG_WIDTH] = '\0';
}

int main(int argc, char** argv) {
  FILE* file;
  unsigned char* buffer;
  char* ascii_output;
  long file_size;

  // Check if image file is provided as argument
  if (argc < 2) {
    printf("Error: image file path not provided.\n");
    return -1;
  }

  // Open image file
  file = fopen(argv[1], "r");
  if (!file) {
    printf("Error: Unable to open file %s\n", argv[1]);
    return -1;
  }

  // Get file size and allocate buffer
  fseek(file, 0, SEEK_END);
  file_size = ftell(file);
  fseek(file, 0, SEEK_SET);
  buffer = (unsigned char*)malloc(file_size);

  // Read image data into buffer
  fread(buffer, file_size, 1, file);

  // Close file
  fclose(file);

  // Allocate memory for ascii output
  ascii_output = (char*)malloc(IMG_WIDTH * IMG_HEIGHT + IMG_HEIGHT + 1);

  // Convert image data to ascii art and print
  convert_to_ascii(buffer, ascii_output);
  printf("%s", ascii_output);

  // Free memory
  free(buffer);
  free(ascii_output);

  return 0;
}