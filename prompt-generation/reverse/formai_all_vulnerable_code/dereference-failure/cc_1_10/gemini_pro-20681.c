//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Embed the secret message into the image.
void embed_message(char *image_file, char *secret_message) {
  // Open the image file for reading and writing.
  FILE *image = fopen(image_file, "r+");
  if (image == NULL) {
    perror("fopen");
    exit(1);
  }

  // Read the image header.
  unsigned char header[54];
  fread(header, 1, 54, image);

  // Get the image dimensions.
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Get the size of the secret message.
  int message_size = strlen(secret_message);

  // Check if there is enough space in the image to embed the message.
  if (width * height * 3 < message_size) {
    fprintf(stderr, "Error: Image is too small to embed the message.\n");
    exit(1);
  }

  // Embed the message into the image.
  int index = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Get the RGB values of the pixel.
      unsigned char r, g, b;
      fread(&r, 1, 1, image);
      fread(&g, 1, 1, image);
      fread(&b, 1, 1, image);

      // Embed the message bit into the least significant bit of the red channel.
      if (index < message_size) {
        r &= ~1;  // Clear the least significant bit.
        r |= (secret_message[index] >> 7) & 1;  // Set the least significant bit to the message bit.
        index++;
      }

      // Write the modified RGB values back to the image.
      fseek(image, -3, SEEK_CUR);
      fwrite(&r, 1, 1, image);
      fwrite(&g, 1, 1, image);
      fwrite(&b, 1, 1, image);
    }
  }

  // Close the image file.
  fclose(image);
}

// Extract the secret message from the image.
char *extract_message(char *image_file) {
  // Open the image file for reading.
  FILE *image = fopen(image_file, "r");
  if (image == NULL) {
    perror("fopen");
    exit(1);
  }

  // Read the image header.
  unsigned char header[54];
  fread(header, 1, 54, image);

  // Get the image dimensions.
  int width = *(int *)&header[18];
  int height = *(int *)&header[22];

  // Create a buffer to store the secret message.
  char *message = malloc(width * height * 3);
  if (message == NULL) {
    perror("malloc");
    exit(1);
  }

  // Extract the message from the image.
  int index = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Get the RGB values of the pixel.
      unsigned char r, g, b;
      fread(&r, 1, 1, image);
      fread(&g, 1, 1, image);
      fread(&b, 1, 1, image);

      // Extract the message bit from the least significant bit of the red channel.
      if (index < width * height * 3) {
        message[index] = (r & 1) << 7;
        index++;
      }
    }
  }

  // Close the image file.
  fclose(image);

  // Null-terminate the message string.
  message[index] = '\0';

  // Return the message.
  return message;
}

// Print the usage message.
void usage() {
  printf("Usage: ./steganography <embed|extract> <image_file> <secret_message>\n");
}

int main(int argc, char *argv[]) {
  // Check the number of arguments.
  if (argc != 4) {
    usage();
    exit(1);
  }

  // Get the command.
  char *command = argv[1];

  // Get the image file name.
  char *image_file = argv[2];

  // Get the secret message.
  char *secret_message = argv[3];

  // Perform the embed or extract operation.
  if (strcmp(command, "embed") == 0) {
    embed_message(image_file, secret_message);
  } else if (strcmp(command, "extract") == 0) {
    char *message = extract_message(image_file);
    printf("The secret message is: %s\n", message);
    free(message);
  } else {
    usage();
    exit(1);
  }

  return 0;
}