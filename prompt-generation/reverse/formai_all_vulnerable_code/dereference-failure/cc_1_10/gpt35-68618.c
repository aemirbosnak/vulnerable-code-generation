//FormAI DATASET v1.0 Category: Image Editor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXFILENAME 50
#define MAXCOMMAND 10

/* Define image struct */
typedef struct image {
  int width;
  int height;
  int *pixels;
} Image;

/* Function to read image from file */
Image* readImage(char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    fprintf(stderr, "ERROR: File not found\n");
    return NULL;
  }

  Image *image = calloc(1, sizeof(Image));

  fscanf(file, "%d", &(image->width));
  fscanf(file, "%d", &(image->height));

  image->pixels = calloc(image->width * image->height, sizeof(int));

  int pixel;

  for (int i = 0; i < image->width * image->height; i++) {
    fscanf(file, "%d", &pixel);
    image->pixels[i] = pixel;
  }

  fclose(file);

  return image;
}

/* Function to write image to file */
void writeImage(char *filename, Image *image) {
  FILE *file = fopen(filename, "w");

  fprintf(file, "%d\n%d\n", image->width, image->height);

  for (int i = 0; i < image->width * image->height; i++) {
    fprintf(file, "%d ", image->pixels[i]);
  }

  fclose(file);
}

/* Function to execute image editing command */
void executeCommand(Image *image, char *command, char *arg1, char *arg2) {
  if (strcmp(command, "brighten") == 0) {
    int brightness = atoi(arg1);
    for (int i = 0; i < image->width * image->height; i++) {
      int pixel = image->pixels[i];
      int red = (pixel & 0xff0000) >> 16;
      int green = (pixel & 0x00ff00) >> 8;
      int blue = pixel & 0x0000ff;

      red = (int)(red * (1 + (brightness / 100.0)));
      green = (int)(green * (1 + (brightness / 100.0)));
      blue = (int)(blue * (1 + (brightness / 100.0)));

      red = red > 255 ? 255 : red;
      green = green > 255 ? 255 : green;
      blue = blue > 255 ? 255 : blue;

      pixel = (red << 16) | (green << 8) | blue;

      image->pixels[i] = pixel;
    }
    printf("Image brightened by %d%%\n", brightness);
  } else if (strcmp(command, "swap") == 0) {
    int index1 = atoi(arg1);
    int index2 = atoi(arg2);

    if (index1 >= image->width * image->height || index2 >= image->width * image->height) {
      fprintf(stderr, "ERROR: Invalid pixel index\n");
      return;
    }

    int temp = image->pixels[index1];
    image->pixels[index1] = image->pixels[index2];
    image->pixels[index2] = temp;

    printf("Pixels at index %d and index %d swapped\n", index1, index2);
  } else {
    fprintf(stderr, "ERROR: Invalid command\n");
  }
}

/* Main function */
int main() {
  char filename[MAXFILENAME];
  printf("Enter image file name: ");
  scanf("%s", filename);

  Image *image = readImage(filename);
  if (!image) {
    return 1;
  }

  char command[MAXCOMMAND], arg1[MAXCOMMAND], arg2[MAXCOMMAND];

  while (1) {
    printf("Enter command (brighten, swap): ");
    scanf("%s", command);

    if (strcmp(command, "exit") == 0) {
      break;
    }

    printf("Enter arguments: ");
    scanf("%s %s", arg1, arg2);

    executeCommand(image, command, arg1, arg2);
  }

  printf("Enter output file name: ");
  scanf("%s", filename);

  writeImage(filename, image);

  free(image->pixels);
  free(image);

  printf("\nDONE!\n");

  return 0;
}