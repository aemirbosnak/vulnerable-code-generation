//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_MAX_SIZE 255
#define QR_MAX_DATA 255

typedef struct QRCode {
  int size;
  char **data;
} QRCode;

QRCode* qr_code_create(int size) {
  QRCode* qr = malloc(sizeof(QRCode));
  qr->size = size;
  qr->data = malloc(size * size * sizeof(char));
  return qr;
}

void qr_code_encode(QRCode* qr, char* data) {
  int i, j, k;
  for (i = 0; i < qr->size; i++) {
    for (j = 0; j < qr->size; j++) {
      qr->data[i][j] = 0;
    }
  }

  k = 0;
  for (i = 0; i < qr->size && k < strlen(data); i++) {
    for (j = 0; j < qr->size && k < strlen(data); j++) {
      qr->data[i][j] = data[k];
      k++;
    }
  }
}

void qr_code_print(QRCode* qr) {
  for (int i = 0; i < qr->size; i++) {
    for (int j = 0; j < qr->size; j++) {
      printf("%c ", qr->data[i][j]);
    }
    printf("\n");
  }
}

int main() {
  QRCode* qr = qr_code_create(5);
  qr_code_encode(qr, "Hello, World!");
  qr_code_print(qr);

  free(qr->data);
  free(qr);

  return 0;
}