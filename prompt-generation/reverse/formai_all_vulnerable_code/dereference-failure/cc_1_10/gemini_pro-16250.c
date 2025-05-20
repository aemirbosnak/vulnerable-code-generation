//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: rigorous
#include <stdio.h>
#include <stdint.h>

uint32_t bytes_to_uint32(uint8_t *bytes) {
  uint32_t result = 0;
  for (int i = 0; i < 4; i++) {
    result |= bytes[i] << (8 * i);
  }
  return result;
}

uint8_t *uint32_to_bytes(uint32_t value) {
  uint8_t *bytes = malloc(4);
  for (int i = 0; i < 4; i++) {
    bytes[i] = (value >> (8 * i)) & 0xFF;
  }
  return bytes;
}

int main() {
  FILE *image_file = fopen("image.png", "rb+");
  if (image_file == NULL) {
    printf("Error opening image file.\n");
    return 1;
  }

  fseek(image_file, 0, SEEK_END);
  size_t image_size = ftell(image_file);
  rewind(image_file);

  uint8_t *image_data = malloc(image_size);
  fread(image_data, 1, image_size, image_file);

  // Read the first 4 bytes of the image data to get the file size.
  uint32_t file_size = bytes_to_uint32(image_data);

  // Read the next 4 bytes of the image data to get the offset to the image data.
  uint32_t image_data_offset = bytes_to_uint32(image_data + 4);

  // Move the file pointer to the start of the image data.
  fseek(image_file, image_data_offset, SEEK_SET);

  // Read the image data into a buffer.
  uint8_t *image_buffer = malloc(file_size - image_data_offset);
  fread(image_buffer, 1, file_size - image_data_offset, image_file);

  // Hide a message in the image data.
  uint8_t *message = "Hello, world!";
  size_t message_length = strlen(message);
  for (size_t i = 0; i < message_length; i++) {
    image_buffer[i] = image_buffer[i] & 0xF0 | (message[i] & 0x0F);
  }

  // Write the modified image data to the file.
  fseek(image_file, image_data_offset, SEEK_SET);
  fwrite(image_buffer, 1, file_size - image_data_offset, image_file);

  // Free the allocated memory.
  free(image_data);
  free(image_buffer);

  fclose(image_file);
  return 0;
}