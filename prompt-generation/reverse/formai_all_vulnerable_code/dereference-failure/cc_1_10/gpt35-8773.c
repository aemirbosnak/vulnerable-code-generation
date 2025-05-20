//FormAI DATASET v1.0 Category: Image Steganography ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#define BMP_HEADER_SIZE 54
#define STEGO_MSG_MAX_SIZE 500

typedef struct {
  uint8_t* data;
  uint32_t size;
} buffer;

void read_input(const char* path, buffer* out) {
  FILE* file = fopen(path, "rb");

  if (file == NULL) {
    fprintf(stderr, "Error opening file: %s\n", strerror(errno));
    exit(-1);
  }

  fseek(file, 0, SEEK_END);
  out->size = ftell(file);
  rewind(file);

  out->data = (uint8_t*) malloc(out->size);
  fread(out->data, out->size, 1, file);

  fclose(file);
}

void write_output(const char* path, buffer* out) {
  FILE* file = fopen(path, "wb");

  if (file == NULL) {
    fprintf(stderr, "Error opening file: %s\n", strerror(errno));
    exit(-1);
  }

  fwrite(out->data, out->size, 1, file);

  fclose(file);
}

void print_usage() {
  printf("Usage: ./stego <input_image> <output_image> <message>\n");
}

int main(int argc, char const *argv[]) {
  if (argc != 4) {
    print_usage();
    return -1;
  }

  buffer img_buffer;
  buffer msg_buffer;
  buffer out_buffer;
  uint32_t msg_size;
  uint32_t msg_offset = BMP_HEADER_SIZE;

  char* img_path = (char*) argv[1];
  char* out_path = (char*) argv[2];
  char* msg_str = (char*) argv[3];

  // Read input files
  read_input(img_path, &img_buffer);
  memcpy(&out_buffer, &img_buffer, sizeof(buffer));

  msg_size = strlen(msg_str);
  if (msg_size > STEGO_MSG_MAX_SIZE) {
    fprintf(stderr, "Message size must not exceed %d characters\n", STEGO_MSG_MAX_SIZE);
    exit(-1);
  }

  // Write message size to the first byte of the message
  msg_buffer.data = (uint8_t*) calloc(msg_size + 1, sizeof(uint8_t));
  msg_buffer.size = msg_size + 1;
  memcpy(msg_buffer.data + 1, msg_str, msg_size);
  msg_buffer.data[0] = (uint8_t) msg_size;

  // Check if message can fit into image
  if (img_buffer.size < msg_offset + msg_size + 1) {
    fprintf(stderr, "Message size too large for input image\n");
    exit(-1);
  }

  // Embed message into image
  for (int i = 0; i < msg_size + 1; ++i) {
    for (int j = 0; j < 8; ++j) {
      out_buffer.data[msg_offset] &= 0xFE; // Clear LSB
      out_buffer.data[msg_offset] |= (msg_buffer.data[i] >> j) & 0x1; // Set LSB
      ++msg_offset;
    }
  }

  // Write output file
  write_output(out_path, &out_buffer);

  // Clean up
  free(img_buffer.data);
  free(out_buffer.data);
  free(msg_buffer.data);

  return 0;
}