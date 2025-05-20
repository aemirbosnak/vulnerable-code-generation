//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define WIDTH 80
#define HEIGHT 40

char ascii_chars[] = {'@', '#', 'S', '%', '?', '*', '+', ';', ':', ',', '.'};

// Function to get the brightness of a pixel given its RGB values
int get_brightness(int r, int g, int b) {
  return (r + g + b) / 3;
}

int main(int argc, char *argv[]) {
  // Open the input file
  FILE *input_file;

  if (argc < 2) {
    printf("Please specify the input file.\n");
    return 1;
  }

  input_file = fopen(argv[1], "rb");

  if (input_file == NULL) {
    printf("Unable to open the input file: %s\n", argv[1]);
    return 1;
  }

  // Open the output file
  FILE *output_file = fopen("output.txt", "w");

  if (output_file == NULL) {
    printf("Unable to open the output file.\n");
    return 1;
  }

  // Read the input image header
  uint8_t header[54];
  fread(header, sizeof(uint8_t), 54, input_file);

  int width = *(int*)&header[18];
  int height = *(int*)&header[22];

  // Print the image details
  printf("Input image: %s\n", argv[1]);
  printf("Image size: %dx%d\n", width, height);

  // Read the input image data
  int padding = 0;

  if ((width * 3) % 4 != 0) {
    padding = 4 - ((width * 3) % 4);
  }

  uint8_t image_data[height * (width * 3 + padding)];
  fread(image_data, sizeof(uint8_t), height * (width * 3 + padding), input_file);

  // Convert the image to ASCII art and write it to output file
  int brightness, index;
  char ascii_char;
  int char_index;

  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      // Get the corresponding pixel values from the original image
      int px = ((float)x / WIDTH) * width;
      int py = ((float)y / HEIGHT) * height;

      int offset = py * (width * 3 + padding) + px * 3;
      int r = image_data[offset + 2];
      int g = image_data[offset + 1];
      int b = image_data[offset];

      // Calculate the brightness of the pixel and map it to an ASCII character
      brightness = get_brightness(r, g, b);
      index = brightness / (256 / (sizeof(ascii_chars) / sizeof(ascii_chars[0])));
      ascii_char = ascii_chars[index];

      // Write the ASCII character to output file
      char_index = y * WIDTH + x;
      fprintf(output_file, "%c", ascii_char);
    }

    // Add a new line at the end of each row
    fprintf(output_file, "\n");
  }

  // Close the input and output files
  fclose(input_file);
  fclose(output_file);

  printf("Output file generated: output.txt\n");

  return 0;
}