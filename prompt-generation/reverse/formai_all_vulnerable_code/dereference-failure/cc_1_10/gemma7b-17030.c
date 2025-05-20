//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_MAX_SIZE 255

typedef struct QRCode {
  int size;
  char **data;
} QRCode;

QRCode *qrcode_new(int size) {
  QRCode *qrcode = malloc(sizeof(QRCode));
  qrcode->size = size;
  qrcode->data = malloc(size * size);
  return qrcode;
}

void qrcode_encode(QRCode *qrcode, char *str) {
  int i = 0;
  int j = 0;
  qrcode->data[0] = str[0];
  qrcode->data[1] = str[1];
  qrcode->data[2] = str[2];
  qrcode->data[3] = str[3];
  qrcode->data[4] = str[4];
  qrcode->data[5] = str[5];

  for (i = 6; str[i] != '\0'; i++) {
    qrcode->data[j++] = str[i];
  }
}

void qrcode_print(QRCode *qrcode) {
  int i = 0;
  int j = 0;
  for (i = 0; i < qrcode->size; i++) {
    for (j = 0; j < qrcode->size; j++) {
      printf("%c ", qrcode->data[i * qrcode->size + j]);
    }
    printf("\n");
  }
}

int main() {
  QRCode *qrcode = qrcode_new(5);
  qrcode_encode(qrcode, "HELLO, WORLD!");
  qrcode_print(qrcode);

  return 0;
}