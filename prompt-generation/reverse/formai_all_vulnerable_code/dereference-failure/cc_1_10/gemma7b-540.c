//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 256

typedef struct QRCode {
  int size;
  char **data;
} QRCode;

QRCode *qrcode_new(int size) {
  QRCode *qr = malloc(sizeof(QRCode));
  qr->size = size;
  qr->data = malloc(size * size * sizeof(char));
  return qr;
}

void qrcode_encode(QRCode *qr, char *str) {
  int i, j, k, l = strlen(str);
  for (i = 0; i < qr->size; i++) {
    for (j = 0; j < qr->size; j++) {
      qr->data[i][j] = 0;
    }
  }
  k = 0;
  for (i = 0; i < l; i++) {
    for (j = 0; j < qr->size; j++) {
      if (k % 2 == 0) {
        qr->data[j][i] = str[i] ^ 0x1F;
      } else {
        qr->data[j][i] = str[i] ^ 0x1F;
      }
    }
    k++;
  }
}

void qrcode_draw(QRCode *qr) {
  int i, j;
  for (i = 0; i < qr->size; i++) {
    for (j = 0; j < qr->size; j++) {
      printf("%c ", qr->data[i][j] & 0x0F);
    }
    printf("\n");
  }
}

int main() {
  QRCode *qr = qrcode_new(25);
  qrcode_encode(qr, "Hello, world!");
  qrcode_draw(qr);
  free(qr);
  return 0;
}