//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CODE_SIZE 256

typedef struct QRCode {
  int width;
  int height;
  int **data;
} QRCode;

QRCode *qrcode_new(int w, int h) {
  QRCode *qr = malloc(sizeof(QRCode));
  qr->width = w;
  qr->height = h;
  qr->data = malloc(w * h * sizeof(int));
  return qr;
}

void qrcode_encode(QRCode *qr, const char *msg) {
  int i = 0;
  int len = strlen(msg);
  for (qr->height = 1; qr->height * qr->width < len; qr->height++) {
    qr->width = (int)ceil(len / qr->height);
  }
  qr->data = realloc(qr->data, qr->width * qr->height * sizeof(int));
  for (; i < len; i++) {
    qr->data[i] = msg[i] & 0x03;
  }
  qr->data[i] = 0;
}

void qrcode_print(QRCode *qr) {
  int i, j;
  for (i = 0; i < qr->height; i++) {
    for (j = 0; j < qr->width; j++) {
      printf("%d ", qr->data[i * qr->width + j]);
    }
    printf("\n");
  }
}

int main() {
  QRCode *qr = qrcode_new(2, 2);
  qrcode_encode(qr, "Hello, world!");
  qrcode_print(qr);

  free(qr->data);
  free(qr);

  return 0;
}