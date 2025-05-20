//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000000

void embed_message(char *image_filename, char *message_filename, char *output_filename) {
  FILE *image_file = fopen(image_filename, "rb");
  if (image_file == NULL) {
    fprintf(stderr, "Error opening image file: %s\n", image_filename);
    exit(1);
  }

  FILE *message_file = fopen(message_filename, "rb");
  if (message_file == NULL) {
    fprintf(stderr, "Error opening message file: %s\n", message_filename);
    exit(1);
  }

  FILE *output_file = fopen(output_filename, "wb");
  if (output_file == NULL) {
    fprintf(stderr, "Error opening output file: %s\n", output_filename);
    exit(1);
  }

  // Read the image data into a buffer
  unsigned char *image_data = malloc(MAX_IMAGE_SIZE);
  if (image_data == NULL) {
    fprintf(stderr, "Error allocating memory for image data\n");
    exit(1);
  }
  size_t image_size = fread(image_data, 1, MAX_IMAGE_SIZE, image_file);
  if (image_size == 0) {
    fprintf(stderr, "Error reading image data\n");
    exit(1);
  }

  // Read the message data into a buffer
  unsigned char *message_data = malloc(MAX_IMAGE_SIZE);
  if (message_data == NULL) {
    fprintf(stderr, "Error allocating memory for message data\n");
    exit(1);
  }
  size_t message_size = fread(message_data, 1, MAX_IMAGE_SIZE, message_file);
  if (message_size == 0) {
    fprintf(stderr, "Error reading message data\n");
    exit(1);
  }

  // Embed the message in the image data
  for (size_t i = 0; i < message_size; i++) {
    image_data[i] |= message_data[i];
  }

  // Write the modified image data to the output file
  fwrite(image_data, 1, image_size, output_file);

  // Free the allocated memory
  free(image_data);
  free(message_data);

  // Close the files
  fclose(image_file);
  fclose(message_file);
  fclose(output_file);
}

void extract_message(char *image_filename, char *output_filename) {
  FILE *image_file = fopen(image_filename, "rb");
  if (image_file == NULL) {
    fprintf(stderr, "Error opening image file: %s\n", image_filename);
    exit(1);
  }

  FILE *output_file = fopen(output_filename, "wb");
  if (output_file == NULL) {
    fprintf(stderr, "Error opening output file: %s\n", output_filename);
    exit(1);
  }

  // Read the image data into a buffer
  unsigned char *image_data = malloc(MAX_IMAGE_SIZE);
  if (image_data == NULL) {
    fprintf(stderr, "Error allocating memory for image data\n");
    exit(1);
  }
  size_t image_size = fread(image_data, 1, MAX_IMAGE_SIZE, image_file);
  if (image_size == 0) {
    fprintf(stderr, "Error reading image data\n");
    exit(1);
  }

  // Extract the message from the image data
  unsigned char *message_data = malloc(MAX_IMAGE_SIZE);
  if (message_data == NULL) {
    fprintf(stderr, "Error allocating memory for message data\n");
    exit(1);
  }
  for (size_t i = 0; i < image_size; i++) {
    message_data[i] = image_data[i] & 1;
  }

  // Write the message data to the output file
  fwrite(message_data, 1, image_size, output_file);

  // Free the allocated memory
  free(image_data);
  free(message_data);

  // Close the files
  fclose(image_file);
  fclose(output_file);
}

int main(int argc, char *argv[]) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <embed/extract> <image_file> <message_file> [output_file]\n", argv[0]);
    exit(1);
  }

  char *command = argv[1];
  char *image_filename = argv[2];
  char *message_filename = argv[3];
  char *output_filename = NULL;
  if (argc > 4) {
    output_filename = argv[4];
  }

  if (strcmp(command, "embed") == 0) {
    embed_message(image_filename, message_filename, output_filename);
  } else if (strcmp(command, "extract") == 0) {
    extract_message(image_filename, output_filename);
  } else {
    fprintf(stderr, "Invalid command: %s\n", command);
    exit(1);
  }

  return 0;
}