//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define PIXEL_COUNT WIDTH * HEIGHT

// Function to generate a random color
void generate_color(int *r, int *g, int *b) {
   *r = rand() % 256;
   *g = rand() % 256;
   *b = rand() % 256;
}

// Function to generate a random pixel
void generate_pixel(int *pixels, int x, int y) {
   int index = y * WIDTH + x;
   generate_color(&pixels[index * 3], &pixels[index * 3 + 1], &pixels[index * 3 + 2]);
}

// Function to generate a surrealist image
void generate_image(int *pixels) {
   srand(time(NULL));
   for (int i = 0; i < PIXEL_COUNT; i++) {
      int x = rand() % WIDTH;
      int y = rand() % HEIGHT;
      generate_pixel(pixels, x, y);
   }
}

// Function to save the image to a file
void save_image(const char *filename, int *pixels) {
   FILE *file = fopen(filename, "wb");
   if (file == NULL) {
      printf("Error: Could not open file '%s'\n", filename);
      exit(1);
   }
   fwrite(pixels, sizeof(int), PIXEL_COUNT, file);
   fclose(file);
}

int main(int argc, char *argv[]) {
   if (argc!= 2) {
      printf("Usage: %s <output_file>\n", argv[0]);
      exit(1);
   }

   int pixels[PIXEL_COUNT];
   generate_image(pixels);
   save_image(argv[1], pixels);

   return 0;
}