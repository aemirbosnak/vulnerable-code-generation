//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000000
unsigned char image[MAX_IMAGE_SIZE];

void hide_message(char *message, int message_len) {
  int image_len = strlen(image);

  for (int i = 0; i < message_len; i++) {
    int byte = message[i];
    for (int j = 0; j < 8; j++) {
      int bit = (byte >> j) & 1;
      image[image_len++] = (image[image_len - 1] & ~1) | bit;
    }
  }
}

char *extract_message(int message_len) {
  char *message = malloc(message_len + 1);
  int image_len = strlen(image);

  for (int i = 0; i < message_len; i++) {
    unsigned char byte = 0;
    for (int j = 0; j < 8; j++) {
      byte |= (image[image_len++] & 1) << j;
    }
    message[i] = byte;
  }

  message[message_len] = '\0';
  return message;
}

int main() {
  FILE *image_file = fopen("image.bmp", "rb");
  if (image_file == NULL) {
    perror("Error opening image file");
    return 1;
  }

  fread(image, 1, MAX_IMAGE_SIZE, image_file);
  fclose(image_file);

  char *message = "Hello, world!";
  int message_len = strlen(message);

  hide_message(message, message_len);

  FILE *stego_file = fopen("stego.bmp", "wb");
  if (stego_file == NULL) {
    perror("Error opening stego file");
    return 1;
  }

  fwrite(image, 1, strlen(image), stego_file);
  fclose(stego_file);

  stego_file = fopen("stego.bmp", "rb");
  if (stego_file == NULL) {
    perror("Error opening stego file");
    return 1;
  }

  fread(image, 1, MAX_IMAGE_SIZE, stego_file);
  fclose(stego_file);

  char *extracted_message = extract_message(message_len);

  printf("Extracted message: %s\n", extracted_message);
  free(extracted_message);

  return 0;
}