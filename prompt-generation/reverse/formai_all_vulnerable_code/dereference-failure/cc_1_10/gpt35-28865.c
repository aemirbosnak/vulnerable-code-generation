//FormAI DATASET v1.0 Category: QR code generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *qrCode = NULL; //initializing the qr code
int qrCodeSize = 0;  //initializing the size of qr code

void printQRCode() {
  // This function prints the qr code.
  int i, j;

  for (i = 0; i < qrCodeSize; i++) {
    for (j = 0; j < qrCodeSize; j++) {
      if (qrCode[i * qrCodeSize + j] == 1) {
        printf("* "); //prints * if the bit value is 1
      } else {
        printf("  "); //prints two spaces if the bit value is 0
      }
    }
    printf("\n");
  }
}

void generateQRCode(int *data, int dataSize) {
  int i, j;

  qrCodeSize = dataSize + 8; //calculating size of qr code
  qrCode = (char *)malloc(sizeof(char) * qrCodeSize * qrCodeSize); //allocating memory for qr code

  // initialize qr code array to 0
  memset(qrCode, 0, qrCodeSize * qrCodeSize * sizeof(char));

  // add start and end markers
  for (i = 0; i < 8; i++) {
    qrCode[i * qrCodeSize] = 1; //adds start marker
    qrCode[qrCodeSize * 7 + i] = 1; //adds end marker
    qrCode[i + qrCodeSize * 7] = 1; //adds end marker
  }

  // add data bits
  for (i = 0; i < dataSize; i++) {
    for (j = 0; j < 8; j++) {
      int mask = 1 << j;
      qrCode[(i + 8) * qrCodeSize + 7 - j] = (data[i] & mask) ? 1 : 0; //adds data bits
    }
  }

  // add error correction bits

  // add vertical parity bits
  for (i = 0; i < qrCodeSize - 8; i++) {
    int parity = 0;
    for (j = 0; j < qrCodeSize; j++) {
      parity ^= qrCode[j * qrCodeSize + i]; //calculates vertical parity bits
    }
    qrCode[(qrCodeSize - 8) * qrCodeSize + i] = parity;
  }

  // add horizontal parity bits
  for (i = 0; i < qrCodeSize - 8; i++) {
    int parity = 0;
    for (j = 0; j < qrCodeSize; j++) {
      parity ^= qrCode[i * qrCodeSize + j]; //calculates horizontal parity bits
    }
    qrCode[i * qrCodeSize + qrCodeSize - 7] = parity;
  }
}

int main() {
  int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}; //sample data
  int dataSize = sizeof(data) / sizeof(int); //calculates size of data

  generateQRCode(data, dataSize); //generates the qr code with the given data

  printQRCode(); //prints the generated qr code

  free(qrCode); //deallocating the memory for qr code

  return 0;
}