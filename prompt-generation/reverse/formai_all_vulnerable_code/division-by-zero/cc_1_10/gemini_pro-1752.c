//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef unsigned char byte;

byte image[MAX_HEIGHT][MAX_WIDTH];

int main()
{
  FILE *imageFile;
  int width, height;
  int x, y;
  char ch;
  int i, j;
  int threshold;
  char asciiChars[] = " .,-~:;=!*#@$%^*+?i><|()1{}[]";

  // Open the image file
  if ((imageFile = fopen("image.pgm", "rb")) == NULL)
  {
    perror("Error opening image file");
    return EXIT_FAILURE;
  }

  // Read the image header
  fscanf(imageFile, "P5 %d %d 255\n", &width, &height);

  // Read the image data
  for (y = 0; y < height; y++)
  {
    for (x = 0; x < width; x++)
    {
      fread(&image[y][x], sizeof(byte), 1, imageFile);
    }
  }

  // Close the image file
  fclose(imageFile);

  // Calculate the threshold value
  threshold = 0;
  for (y = 0; y < height; y++)
  {
    for (x = 0; x < width; x++)
    {
      threshold += image[y][x];
    }
  }
  threshold /= (width * height);

  // Convert the image to ASCII art
  printf("\n");
  for (y = 0; y < height; y++)
  {
    for (x = 0; x < width; x++)
    {
      if (image[y][x] > threshold)
      {
        printf("%c", asciiChars[(int)(image[y][x] * (strlen(asciiChars) - 1) / 255)]);
      }
      else
      {
        printf(" ");
      }
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}