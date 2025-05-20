//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 512

unsigned char image[MAX_SIZE][MAX_SIZE][3];
unsigned char secret[MAX_SIZE][MAX_SIZE];

void read_image(char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  fread(image, sizeof(unsigned char), MAX_SIZE * MAX_SIZE * 3, fp);
  fclose(fp);
}

void write_image(char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  fwrite(image, sizeof(unsigned char), MAX_SIZE * MAX_SIZE * 3, fp);
  fclose(fp);
}

void hide_secret(char *secret_filename) {
  FILE *fp = fopen(secret_filename, "rb");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  fread(secret, sizeof(unsigned char), MAX_SIZE * MAX_SIZE, fp);
  fclose(fp);

  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      for (int k = 0; k < 3; k++) {
        image[i][j][k] = (image[i][j][k] & 0xfe) | (secret[i][j] & 0x01);
        secret[i][j] >>= 1;
      }
    }
  }
}

void extract_secret(char *secret_filename) {
  FILE *fp = fopen(secret_filename, "wb");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      for (int k = 0; k < 3; k++) {
        secret[i][j] = secret[i][j] << 1 | (image[i][j][k] & 0x01);
      }
    }
  }

  fwrite(secret, sizeof(unsigned char), MAX_SIZE * MAX_SIZE, fp);
  fclose(fp);
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: %s <input_image> <output_image> <secret_file> <extract/hide>\n", argv[0]);
    exit(1);
  }

  read_image(argv[1]);

  if (strcmp(argv[4], "hide") == 0) {
    hide_secret(argv[3]);
  } else if (strcmp(argv[4], "extract") == 0) {
    extract_secret(argv[3]);
  } else {
    printf("Invalid operation: extract/hide\n");
    exit(1);
  }

  write_image(argv[2]);

  return 0;
}