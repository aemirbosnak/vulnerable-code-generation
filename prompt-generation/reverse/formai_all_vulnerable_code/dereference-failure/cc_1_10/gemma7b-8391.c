//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define QR_MAX_SIZE 256

typedef struct QRCode {
  int size;
  int **data;
  char **color;
} QRCode;

QRCode *qrcode_init(int size) {
  QRCode *qrcode = malloc(sizeof(QRCode));
  qrcode->size = size;
  qrcode->data = malloc(size * size * sizeof(int));
  qrcode->color = malloc(size * size * sizeof(char));
  return qrcode;
}

void qrcode_encode(QRCode *qrcode, char *str) {
  int i, j, k;
  int len = strlen(str);
  for (i = 0; i < len; i++) {
    int bit = str[i] % 2;
    for (j = 0; j < qrcode->size; j++) {
      for (k = 0; k < qrcode->size; k++) {
        qrcode->data[j][k] = bit;
      }
    }
  }
}

void qrcode_draw(QRCode *qrcode) {
  int i, j;
  for (i = 0; i < qrcode->size; i++) {
    for (j = 0; j < qrcode->size; j++) {
      if (qrcode->data[i][j] == 1) {
        qrcode->color[i][j] = 'X';
      } else {
        qrcode->color[i][j] = ' ';
      }
    }
  }
}

void qrcode_print(QRCode *qrcode) {
  int i, j;
  for (i = 0; i < qrcode->size; i++) {
    for (j = 0; j < qrcode->size; j++) {
      printf("%c ", qrcode->color[i][j]);
    }
    printf("\n");
  }
}

int main() {
  QRCode *qrcode = qrcode_init(10);
  qrcode_encode(qrcode, "Hello, world!");
  qrcode_draw(qrcode);
  qrcode_print(qrcode);
  free(qrcode);
  return 0;
}