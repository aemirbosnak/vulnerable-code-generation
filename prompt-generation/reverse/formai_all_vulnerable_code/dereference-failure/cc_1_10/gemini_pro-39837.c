//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// ECC levels
#define ECC_LEVEL_L 0x01
#define ECC_LEVEL_M 0x00
#define ECC_LEVEL_Q 0x03
#define ECC_LEVEL_H 0x02

// QR code versions
#define QR_VERSION_MIN 1
#define QR_VERSION_MAX 40

// QR code sizes
#define QR_SIZE_MIN 21
#define QR_SIZE_MAX 177

// Function prototypes
char *generate_qrcode(const char *data, int version, int ecc_level, int size);
void print_qrcode(const char *qrcode, int size);

// Main function
int main(void) {
  // Get the data to encode
  char data[1024];
  printf("Enter the data to encode: ");
  gets(data);

  // Get the QR code version
  int version;
  printf("Enter the QR code version (1-40): ");
  scanf("%d", &version);
  while (version < QR_VERSION_MIN || version > QR_VERSION_MAX) {
    printf("Invalid QR code version. Please enter a value between 1 and 40: ");
    scanf("%d", &version);
  }

  // Get the ECC level
  int ecc_level;
  printf("Enter the ECC level (L, M, Q, H): ");
  scanf(" %c", &ecc_level);
  while (ecc_level != ECC_LEVEL_L && ecc_level != ECC_LEVEL_M && ecc_level != ECC_LEVEL_Q && ecc_level != ECC_LEVEL_H) {
    printf("Invalid ECC level. Please enter L, M, Q, or H: ");
    scanf(" %c", &ecc_level);
  }

  // Get the QR code size
  int size;
  printf("Enter the QR code size (21-177): ");
  scanf("%d", &size);
  while (size < QR_SIZE_MIN || size > QR_SIZE_MAX) {
    printf("Invalid QR code size. Please enter a value between 21 and 177: ");
    scanf("%d", &size);
  }

  // Generate the QR code
  char *qrcode = generate_qrcode(data, version, ecc_level, size);

  // Print the QR code
  print_qrcode(qrcode, size);

  // Free the QR code
  free(qrcode);

  return 0;
}

// Function to generate a QR code
char *generate_qrcode(const char *data, int version, int ecc_level, int size) {
  // Calculate the QR code size
  int qr_size = (version - 1) * 4 + 21;

  // Allocate memory for the QR code
  char *qrcode = (char *)malloc(qr_size * qr_size);

  // Initialize the QR code to white
  memset(qrcode, ' ', qr_size * qr_size);

  // Add the finder patterns
  for (int i = 0; i < 7; i++) {
    qrcode[i] = qrcode[i + qr_size - 7] = qrcode[qr_size * (i + 1) - 7] = qrcode[qr_size * (i + 1)] = '\x1b[41m  \x1b[0m';
  }

  // Add the alignment patterns
  if (version >= 2) {
    for (int i = 0; i < version; i++) {
      for (int j = 0; j < version; j++) {
        if (i != 6 && j != 6) {
          qrcode[qr_size * (i + 4) + j + 4] = '\x1b[41m  \x1b[0m';
        }
      }
    }
  }

  // Add the timing patterns
  for (int i = 8; i < qr_size - 8; i++) {
    qrcode[i] = qrcode[i + qr_size - 8] = (i % 2 == 0) ? '\x1b[41m  \x1b[0m' : ' ';
  }

  // Add the data
  int data_length = strlen(data);
  int data_index = 0;
  int qr_index = qr_size / 2;
  int dir = -1;
  for (int i = 0; i < qr_size * qr_size; i++) {
    if (qrcode[qr_index] == ' ') {
      if (data_index < data_length) {
        qrcode[qr_index] = data[data_index++];
      } else {
        qrcode[qr_index] = '\x1b[40m  \x1b[0m';
      }
    }

    if (qr_index % qr_size == 0) {
      dir = -dir;
      qr_index += qr_size * dir;
    } else {
      qr_index += dir;
    }
  }

  // Add the error correction code
  int ecc_length = (version - 1) * 4 + 16;
  int ecc_index = qr_size * qr_size - 1 - ecc_length;
  for (int i = 0; i < ecc_length; i++) {
    qrcode[ecc_index++] = '\x1b[40m  \x1b[0m';
  }

  // Return the QR code
  return qrcode;
}

// Function to print a QR code
void print_qrcode(const char *qrcode, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%s", qrcode[i * size + j]);
    }
    printf("\n");
  }
}