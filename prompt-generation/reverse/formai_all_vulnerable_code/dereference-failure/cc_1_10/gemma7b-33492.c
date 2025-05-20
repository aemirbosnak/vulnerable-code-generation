//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 256

typedef struct QRCode {
  int width;
  int height;
  int **data;
} QRCode;

QRCode *qrcode_init(int w, int h) {
  QRCode *qr = malloc(sizeof(QRCode));
  qr->width = w;
  qr->height = h;
  qr->data = malloc(sizeof(int *) * h);
  for (int i = 0; i < h; i++) {
    qr->data[i] = malloc(sizeof(int) * w);
  }
  return qr;
}

void qrcode_encode(QRCode *qr, char *str) {
  int len = strlen(str);
  int data_size = (len + 7) / 8;
  qr->data[0][0] = data_size;
  qr->data[0][1] = len;

  for (int i = 0; i < len; i++) {
    qr->data[i / 8][i % 8] = str[i] ^ 0x1F;
  }
}

void qrcode_draw(QRCode *qr) {
  for (int i = 0; i < qr->height; i++) {
    for (int j = 0; j < qr->width; j++) {
      if (qr->data[i][j] & 1) {
        printf("X ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
}

int main() {
  QRCode *qr = qrcode_init(25, 25);
  qrcode_encode(qr, "Hello, world!");
  qrcode_draw(qr);

  return 0;
}