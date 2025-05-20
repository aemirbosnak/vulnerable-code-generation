//FormAI DATASET v1.0 Category: Image Steganography ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned char r, g, b;
} pixel;

int main(int argc, char *argv[]) {

  // Load input image
  FILE *input_file = fopen(argv[1], "r");
  char header[54];
  fread(header, sizeof(char), 54, input_file);
  int width = *(int*)&header[18];
  int height = *(int*)&header[22];
  int padding = 0;
  while((width*3+padding) % 4 != 0) {
    padding++;
  }
  int row_size = width*3+padding;
  int img_size = row_size*height;
  unsigned char *img_data = malloc(sizeof(unsigned char) * img_size);
  fread(img_data, sizeof(unsigned char), img_size, input_file);
  fclose(input_file);

  // Load message to be hidden
  FILE *msg_file = fopen(argv[2], "r");
  fseek(msg_file, 0, SEEK_END);
  int msg_size = ftell(msg_file);
  fseek(msg_file, 0, SEEK_SET);
  char *message = malloc(sizeof(char) * (msg_size+1));
  fread(message, sizeof(char), msg_size, msg_file);
  message[msg_size] = '\0';
  fclose(msg_file);

  // Hide message in image
  for(int i = 0; i < msg_size; i++) {
    int bit_count = 0;
    char current_char = message[i];
    for(int j = 0; j < 8; j++) {
      int bit = (current_char >> j) & 1;
      int img_byte_index = (i*8+j)*3;
      if(bit) {
        if(img_data[img_byte_index] % 2 == 0) {
          img_data[img_byte_index]++;
        }
      } else {
        if(img_data[img_byte_index] % 2 == 1) {
          img_data[img_byte_index]--;
        }
      }
    }
  }

  // Write output image
  FILE *output_file = fopen(argv[3], "w");
  fwrite(header, sizeof(char), 54, output_file);
  fwrite(img_data, sizeof(unsigned char), img_size, output_file);
  fclose(output_file);

  return 0;
}