//FormAI DATASET v1.0 Category: Image Steganography ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Constants for image dimensions and maximum file size.
 */
#define WIDTH 256
#define HEIGHT 256
#define MAX_FILE_SIZE (256*256)/8

/*
 * Function to get the length of a file.
 */
long int get_file_length(FILE* file) {
  long int length;

  fseek(file, 0, SEEK_END);
  length = ftell(file);
  fseek(file, 0, SEEK_SET);

  return length;
}

/*
 * Function to encode a message into an image using LSB steganography.
 * Returns 0 on success, 1 if message is too large for image, and 2 if there was an error
 * opening files.
 */
int encode(char* input_filename, char* output_filename, char* message) {
  FILE* input_file;
  FILE* output_file;
  char* binary_message;
  unsigned char byte;
  int i, j, k, message_length, bit_count;

  /* Open input and output files. */
  input_file = fopen(input_filename, "rb");
  output_file = fopen(output_filename, "wb");
  if (input_file == NULL || output_file == NULL) {
    return 2;
  }

  /* Get the length of the message and check if it will fit in the image. */
  message_length = strlen(message);
  if (message_length * 8 > MAX_FILE_SIZE) {
    return 1;
  }

  /* Convert the message to binary. */
  binary_message = (char*) calloc(message_length * 8 + 1, sizeof(char));
  if (binary_message == NULL) {
    return 2;
  }
  for (i = 0; i < message_length; i++) {
    for (j = 0; j < 8; j++) {
      binary_message[i*8+j] = ((message[i] >> (7-j)) & 1) + '0';
    }
  }

  /* Write the header to the output file. */
  fwrite("P5\n256 256\n255\n", sizeof(char), 16, output_file);

  /* Encode the message into the image using LSB steganography. */
  bit_count = 0;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      /* Read a pixel from the input image. */
      if (fread(&byte, sizeof(unsigned char), 1, input_file) != 1) {
        return 2;
      }

      /* Encode one bit of the message into the least significant bit of the pixel value. */
      if (bit_count < message_length * 8) {
        byte = (byte & 0xFE) | (binary_message[bit_count] - '0');
        bit_count++;
      }

      /* Write the pixel to the output file. */
      if (fwrite(&byte, sizeof(unsigned char), 1, output_file) != 1) {
        return 2;
      }
    }
  }

   /* Close the input and output files. */
  fclose(input_file);
  fclose(output_file);

  /* Free memory used for binary message. */
  free(binary_message);

  return 0;
}

/*
 * Function to decode a message from an image using LSB steganography.
 * Returns 0 on success, 1 if there is no message in the image, and 2 if there was an error
 * opening files.
 */
int decode(char* input_filename, char* message) {
  FILE* input_file;
  char* binary_message;
  unsigned char byte;
  int i, j, k, message_length, bit_count;

  /* Open input file. */
  input_file = fopen(input_filename, "rb");
  if (input_file == NULL) {
    return 2;
  }

  /* Skip the header of the PGM file. */
  fseek(input_file, 16, SEEK_SET);

  /* Decode the message from the image using LSB steganography. */
  message_length = 0;
  bit_count = 0;
  binary_message = (char*) calloc(MAX_FILE_SIZE + 1, sizeof(char));
  if (binary_message == NULL) {
    return 2;
  }
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      /* Read a pixel from the input image. */
      if (fread(&byte, sizeof(unsigned char), 1, input_file) != 1) {
        return 2;
      }

      /* Decode the least significant bit of the pixel value. */
      if (bit_count < MAX_FILE_SIZE) {
        binary_message[bit_count] = ((byte & 1) + '0');
        bit_count++;
      }
    }
  }

  /* Convert the binary message to text. */
  message_length = bit_count / 8;
  message[message_length] = '\0';
  for (i = 0; i < message_length; i++) {
    byte = 0;
    for (j = 0; j < 8; j++) {
      byte = byte << 1;
      byte |= (binary_message[i*8+j] - '0');
    }
    message[i] = byte;
  }

  /* Close the input file. */
  fclose(input_file);

  /* Free memory used for binary message. */
  free(binary_message);

  /* Return 1 if there is no message in the image. */
  if (message_length == 0) {
    return 1;
  }

  return 0;
}

/*
 * Main function.
 */
int main(int argc, char* argv[]) {
  int result;
  char message[MAX_FILE_SIZE + 1] = "Hello, world!";
  char decoded_message[MAX_FILE_SIZE + 1] = "";

  /* Encode the message into the image. */
  result = encode("image.pgm", "encoded_image.pgm", message);
  if (result != 0) {
    printf("Error: %d\n", result);
    return 1;
  }

  /* Decode the message from the image. */
  result = decode("encoded_image.pgm", decoded_message);
  if (result != 0) {
    printf("Error: %d\n", result);
    return 1;
  }

  /* Print the decoded message. */
  printf("Decoded message: %s\n", decoded_message);

  return 0;
}