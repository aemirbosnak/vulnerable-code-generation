//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Obfuscated C code for digital watermarking.

// The secret message to hide.
char *secret = "Top Secret";

// The cover image.
unsigned char *image;

// The height and width of the image.
int height, width;

// Embed the secret message in the cover image.
void embed() {
  // Convert the secret message to a stream of bits.
  int bitstream_length = strlen(secret) * 8;
  unsigned char *bitstream = malloc(bitstream_length);
  for (int i = 0; i < strlen(secret); i++) {
    for (int j = 0; j < 8; j++) {
      bitstream[i * 8 + j] = (secret[i] >> j) & 1;
    }
  }

  // Embed the bitstream in the image.
  int bitstream_index = 0;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Modify the least significant bit of the pixel.
      image[y * width + x] &= ~1;
      image[y * width + x] |= bitstream[bitstream_index++];
    }
  }

  // Free the bitstream.
  free(bitstream);
}

// Extract the secret message from the cover image.
char *extract() {
  // Extract the bitstream from the image.
  int bitstream_length = height * width;
  unsigned char *bitstream = malloc(bitstream_length);
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      bitstream[y * width + x] = image[y * width + x] & 1;
    }
  }

  // Convert the bitstream to a secret message.
  char *secret = malloc(bitstream_length / 8 + 1);
  for (int i = 0; i < bitstream_length / 8; i++) {
    secret[i] = 0;
    for (int j = 0; j < 8; j++) {
      secret[i] |= bitstream[i * 8 + j] << j;
    }
  }

  // Free the bitstream.
  free(bitstream);

  // Return the secret message.
  return secret;
}

// Main function.
int main() {
  // Load the image from a file.
  FILE *image_file = fopen("image.bmp", "rb");
  if (image_file == NULL) {
    printf("Error: could not open image file.\n");
    return 1;
  }
  fread(&height, sizeof(int), 1, image_file);
  fread(&width, sizeof(int), 1, image_file);
  image = malloc(height * width);
  fread(image, 1, height * width, image_file);
  fclose(image_file);

  // Embed the secret message in the image.
  embed();

  // Save the watermarked image to a file.
  FILE *watermarked_image_file = fopen("watermarked_image.bmp", "wb");
  if (watermarked_image_file == NULL) {
    printf("Error: could not open watermarked image file.\n");
    return 1;
  }
  fwrite(&height, sizeof(int), 1, watermarked_image_file);
  fwrite(&width, sizeof(int), 1, watermarked_image_file);
  fwrite(image, 1, height * width, watermarked_image_file);
  fclose(watermarked_image_file);

  // Extract the secret message from the watermarked image.
  char *extracted_secret = extract();

  // Print the extracted secret message.
  printf("Extracted secret message: %s\n", extracted_secret);

  // Free the extracted secret message.
  free(extracted_secret);

  // Free the image.
  free(image);

  return 0;
}