//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QR_CODE_SIZE 256

typedef struct QRCode {
  int size;
  char **data;
} QRCode;

QRCode *qrcode_new(int size) {
  QRCode *qrcode = malloc(sizeof(QRCode));
  qrcode->size = size;
  qrcode->data = malloc(size * size * sizeof(char));
  return qrcode;
}

void qrcode_encode(QRCode *qrcode, char *str) {
  int i, j, k;
  for (i = 0; str[i] != '\0'; i++) {
    for (j = 0; j < qrcode->size; j++) {
      for (k = 0; k < qrcode->size; k++) {
        qrcode->data[j][k] = 0;
      }
    }
    qrcode->data[str[i] - 65][str[i] - 65] = 1;
  }
}

void qrcode_print(QRCode *qrcode) {
  int i, j;
  for (i = 0; i < qrcode->size; i++) {
    for (j = 0; j < qrcode->size; j++) {
      printf("%c ", qrcode->data[i][j] ? '#' : '.');
    }
    printf("\n");
  }
}

int main() {
  QRCode *qrcode = qrcode_new(25);
  qrcode_encode(qrcode, "Donald Knuth");
  qrcode_print(qrcode);

  free(qrcode->data);
  free(qrcode);

  return 0;
}