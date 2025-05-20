//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_CHARS 95 //ascii chars from 32 to126 

char ascii_chars[MAX_CHARS] = {' ', '.', ',', ':', ';', '=', '!', '*', '#', '$', '@', '%', '9', '8', '6', '5', '4', '3', '2', '1', '0', 'o', 'x', 'X', 'Z', 'z', 'Y', 'U', 'J', 'C', 'L', 'Q', '0', 'O', 'C', 'M', 'W', 'B', '8', '&', 'G', 'P', 'S', 'N', 'H', 'K', 'D', 'A', 'R', 'M', '@', '#', 'H', 'N', 'W', 'M', 'B', 'Q', 'U', 'O', 'A', 'Z', 'X', 'Y', 'C', 'L', 'J', 'p', 'q', 'd', 'b', 'k', 'h', 'a', 'o', 'w', 'm', 'Z', 'X', 'B', 'W', '8', '0', 'Q', 'O', 'V', 'v', 'u', 'n', 'r', 'c', '|', '/', '\\', '(', ')', 'Y'};
// array of ascii characters used for ASCII art conversion

void convert(FILE *image_file, char *output_file_name) {
  // input image file and output file name
  
  const char* greyscale_chars[] = {" ", ".", "-", "*", "=", "+", "^", "&", "8", "O", "X", "$", "4", "#", "A", "T"}; // array of greyscale characters used to convert each pixel
  
  char filepath[50];
  sprintf(filepath, "%s.txt", output_file_name);
  
  FILE *output_file = fopen(filepath, "w"); // open output file
  
  if (image_file == NULL) { // check if image file was opened properly
    printf("Error opening image file\n");
    return;
  }
  
  int height, width;
  char format[2]; 
  fscanf(image_file, "%s", format); // read image format
  fscanf(image_file, "%d %d", &width, &height); // read image dimensions
  
  if (strcmp(format, "P3") != 0) { // check if image format is P3 (ASCII)
    printf("Invalid image format\n");
    return;
  }
  
  if (height > MAX_WIDTH) { // check if image height is too large
    printf("Image dimensions too large\n");
    return;
  }
  
  int pixel_number = 0;
  int pixel_array[3]; // array to hold RGB values of each pixel
  
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      for (int k = 0; k < 3; k++) {
        fscanf(image_file, "%d", &pixel_array[k]); // read RGB values of each pixel
      }
      
      float pixel_value = (pixel_array[0] + pixel_array[1] + pixel_array[2]) / 3.0; // calculate average of RGB values
      
      int idx = (int) (pixel_value / 256.0 * MAX_CHARS); // calculate index of ascii_chars to use based on pixel_value
      
      fprintf(output_file, "%c", ascii_chars[idx]); // write ascii character to output file
    }
    fprintf(output_file, "\n"); // go to next line
  }
  
  fclose(output_file); // close output file
}

int main() {
  FILE *image_file = fopen("image.ppm", "r"); // open image file
  
  convert(image_file, "output"); // convert image and write to output file
  
  fclose(image_file);
  
  return 0;
}