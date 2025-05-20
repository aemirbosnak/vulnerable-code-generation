//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the width and height of the pixel art
#define WIDTH 100
#define HEIGHT 100

// Define the number of colors to use
#define NUM_COLORS 10

// Define the minimum and maximum values for the color channels
#define MIN_COLOR 0
#define MAX_COLOR 255

// Create a 2D array to store the pixel art
unsigned char pixel_art[WIDTH][HEIGHT][3];

// Function to generate a random color
unsigned char* random_color() {
  // Create an array to store the color
  unsigned char color[3];

  // Generate a random value for each color channel
  for (int i = 0; i < 3; i++) {
    color[i] = (rand() % (MAX_COLOR - MIN_COLOR + 1)) + MIN_COLOR;
  }

  // Return the color
  return color;
}

// Function to generate the pixel art
void generate_pixel_art() {
  // Set the random seed
  srand(time(NULL));

  // Loop through each pixel in the pixel art
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      // Generate a random color for the pixel
      unsigned char* color = random_color();

      // Set the pixel to the random color
      pixel_art[i][j][0] = color[0];
      pixel_art[i][j][1] = color[1];
      pixel_art[i][j][2] = color[2];
    }
  }
}

// Function to write the pixel art to a file
void write_pixel_art(char* filename) {
  // Open the file
  FILE* fp = fopen(filename, "wb");

  // Write the header to the file
  fprintf(fp, "P3\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_COLOR);

  // Loop through each pixel in the pixel art
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      // Write the pixel to the file
      fprintf(fp, "%d %d %d ", pixel_art[i][j][0], pixel_art[i][j][1], pixel_art[i][j][2]);
    }
  }

  // Close the file
  fclose(fp);
}

// Main function
int main() {
  // Generate the pixel art
  generate_pixel_art();

  // Write the pixel art to a file
  write_pixel_art("pixel_art.ppm");

  return 0;
}