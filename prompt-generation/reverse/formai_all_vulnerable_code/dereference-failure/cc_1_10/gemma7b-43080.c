//Gemma-7B DATASET v1.0 Category: QR code reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct QRCode {
  char **data;
  int width;
  int height;
} QRCode;

QRCode *readQRCode(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  QRCode *qrcode = malloc(sizeof(QRCode));
  qrcode->data = NULL;
  qrcode->width = 0;
  qrcode->height = 0;

  char buffer[MAX_BUFFER_SIZE];
  int read_size = fread(buffer, 1, MAX_BUFFER_SIZE, fp);
  fclose(fp);

  qrcode->data = (char **)malloc(qrcode->height * sizeof(char *));
  for (int i = 0; i < qrcode->height; i++) {
    qrcode->data[i] = (char *)malloc(qrcode->width * sizeof(char));
  }

  for (int i = 0; i < read_size; i++) {
    qrcode->data[buffer[i] / qrcode->width][buffer[i] % qrcode->width] = 1;
  }

  return qrcode;
}

int main() {
  QRCode *qrcode = readQRCode("qrcode.txt");
  if (qrcode == NULL) {
    return 1;
  }

  printf("Data:\n");
  for (int i = 0; i < qrcode->height; i++) {
    for (int j = 0; j < qrcode->width; j++) {
      if (qrcode->data[i][j] == 1) {
        printf("X ");
      } else {
        printf("O ");
      }
    }
    printf("\n");
  }

  free(qrcode->data);
  free(qrcode);

  return 0;
}