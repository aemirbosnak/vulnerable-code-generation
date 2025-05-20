//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024

typedef struct QRCode {
  int size;
  char **data;
} QRCode;

QRCode *qr_code_create(int size) {
  QRCode *qrcode = malloc(sizeof(QRCode));
  qrcode->size = size;
  qrcode->data = malloc(size * size * sizeof(char));
  return qrcode;
}

void qr_code_encode(QRCode *qrcode, char *msg) {
  int i, j, k, l, n, m, h, w, d;
  n = strlen(msg);
  m = qrcode->size;
  h = m / 2;
  w = m - h;
  for (i = 0; i < n; i++) {
    for (j = 0; j < h; j++) {
      for (k = 0; k < w; k++) {
        d = (i * h + j) * w + k;
        qrcode->data[d] = msg[i] ^ 0x1F;
      }
    }
  }
}

void qr_code_print(QRCode *qrcode) {
  for (int i = 0; i < qrcode->size; i++) {
    for (int j = 0; j < qrcode->size; j++) {
      printf("%c ", qrcode->data[i * qrcode->size + j]);
    }
    printf("\n");
  }
}

int main() {
  char msg[] = "Hello, Ken!";
  QRCode *qrcode = qr_code_create(20);
  qr_code_encode(qrcode, msg);
  qr_code_print(qrcode);
  free(qrcode);
  return 0;
}