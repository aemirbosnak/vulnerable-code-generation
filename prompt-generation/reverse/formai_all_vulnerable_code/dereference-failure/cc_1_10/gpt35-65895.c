//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to my image flipping program!\n");
  printf("Note: Do not try this on a real photo, use a fake one instead!\n");

  char filename[20];
  printf("Enter the name of the image file (with .bmp extension): ");
  scanf("%s", filename);

  FILE *file = fopen(filename, "r+b");
  if (!file) {
    printf("File not found. Please make sure the file name and extension are correct.\n");
    return 0;
  }

  printf("Great, we found your file! Let's start flipping!\n");
  
  // Get image details
  unsigned int width, height;
  fseek(file, 18, SEEK_SET);
  fread(&width, sizeof(unsigned int), 1, file);
  fread(&height, sizeof(unsigned int), 1, file);

  // Create a buffer to store the pixels
  unsigned char *buffer = (unsigned char*) malloc(width * height * 3);

  // Read the pixels from file into the buffer
  fseek(file, 54, SEEK_SET);
  fread(buffer, sizeof(unsigned char), width * height * 3, file);

  // Let's have some fun with flipping! (literally)
  printf("Choose a direction to flip the image:\n");
  printf("1) Flip horizontally\n");
  printf("2) Flip vertically\n");
  int choice;
  scanf("%d", &choice);

  if (choice == 1) {
    printf("Flipping horizontally...\n");
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width / 2; j++) {
        unsigned char *left = buffer + ((i * width) + j) * 3;
        unsigned char *right = buffer + ((i * width) + (width - j - 1)) * 3;
        // Swap the pixels
        unsigned char temp[3];
        temp[0] = left[0];
        temp[1] = left[1];
        temp[2] = left[2];
        left[0] = right[0];
        left[1] = right[1];
        left[2] = right[2];
        right[0] = temp[0];
        right[1] = temp[1];
        right[2] = temp[2];
      }
    }
  }
  else if (choice == 2) {
    printf("Flipping vertically...\n");
    for (int i = 0; i < height / 2; ++i) {
      for (int j = 0; j < width; ++j) {
        unsigned char *top = buffer + ((i * width) + j) * 3;
        unsigned char *bottom = buffer + (((height - i - 1) * width) + j) * 3;
        // Swap the pixels
        unsigned char temp[3];
        temp[0] = top[0];
        temp[1] = top[1];
        temp[2] = top[2];
        top[0] = bottom[0];
        top[1] = bottom[1];
        top[2] = bottom[2];
        bottom[0] = temp[0];
        bottom[1] = temp[1];
        bottom[2] = temp[2];
      }
    }
  }
  else {
    printf("Invalid choice. We'll just leave the image as it is then.\n");
  }

  // Save the flipped image back to file
  printf("The image has been flipped successfully!\n");
  printf("Enter a name for the new image file (with .bmp extension): ");
  scanf("%s", filename);

  FILE *newfile = fopen(filename, "w+b");
  if (!newfile) {
    printf("Error creating new file.\n");
    return 0;
  }

  unsigned int size = 54 + (width * height * 3);
  unsigned int header[13] = {
      0x42, 0x4d, size, 0, 0, 54, 40, width, height, 0, 0, 0, 0
  };
  fwrite(header, sizeof(unsigned int), 13, newfile);
  fwrite(buffer, sizeof(unsigned char), width * height * 3, newfile);

  fclose(file);
  fclose(newfile);
  free(buffer);

  printf("The new image has been saved as %s\n", filename);
  printf("Thank you for using my program! Remember, always flip with caution.\n");

  return 0;
}