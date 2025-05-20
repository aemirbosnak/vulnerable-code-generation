//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

char *ascii_chars=" .:-=+*#%@";
// the above string represents the intensity levels of the ASCII characters from lightest to darkest

// The function that converts the image to ASCII art
char **image_to_ascii(uint8_t *img_data, int width, int height)
{
  char **ascii_img;
  ascii_img = malloc(height * sizeof(char *));

  if (ascii_img == NULL)
  {
    printf("Error: Unable to allocate memory.\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < height; i++)
  {
    ascii_img[i] = malloc(width * sizeof(char));

    if (ascii_img[i] == NULL)
    {
      printf("Error: Unable to allocate memory.\n");
      exit(EXIT_FAILURE);
    }

    for (int j = 0; j < width; j++)
    {
      // convert the RGB values of the pixel to grayscale intensity level
      int intensity = ((int)img_data[(i * width + j) * 3] + (int)img_data[(i * width + j) * 3 + 1] + (int)img_data[(i * width + j) * 3 + 2]) / 3;

      // finding an ASCII character with the closest intensity level to current intensity
      int index = (int)((float)intensity * 10 / 255);

      // placing the ASCII character in the corresponding position in the ASCII art
      ascii_img[i][j] = ascii_chars[index];
    }
  }

  return ascii_img;
}

int main(int argc, char *argv[])
{
  FILE *fp;

  if (argc < 2)
  {
    printf("Usage: %s [image path]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  fp = fopen(argv[1], "rb");
  if (fp == NULL)
  {
    printf("Error: Unable to open image.\n");
    exit(EXIT_FAILURE);
  }

  fseek(fp, 0, SEEK_END);
  int file_size = ftell(fp);

  uint8_t *img_data = malloc(file_size);
  rewind(fp);
  fread(img_data, file_size, 1, fp);

  fclose(fp);

  // Reading the image width and height from the image data
  uint16_t *width_ptr = (uint16_t *)(&img_data[18]);
  uint16_t *height_ptr = (uint16_t *)(&img_data[22]);
  int width = *width_ptr;
  int height = *height_ptr;

  char **ascii_img = image_to_ascii(&img_data[54], width, height);

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      putchar(ascii_img[i][j]);
    }
    putchar('\n');
  }

  free(img_data);
  for (int i = 0; i < height; i++)
  {
    free(ascii_img[i]);
  }
  free(ascii_img);

  return 0;
}