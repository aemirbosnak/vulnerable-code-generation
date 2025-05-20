//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1024

typedef struct {
  int size;
  int data[MAX_SIZE];
} QRCode;

QRCode* qrcode_create(int size) {
  QRCode* qrcode = malloc(sizeof(QRCode));
  qrcode->size = size;
  for (int i = 0; i < size * size; i++) {
    qrcode->data[i] = 0;
  }
  return qrcode;
}

void qrcode_destroy(QRCode* qrcode) {
  free(qrcode);
}

void qrcode_set(QRCode* qrcode, int x, int y, int value) {
  if (x < 0 || x >= qrcode->size || y < 0 || y >= qrcode->size) {
    return;
  }
  qrcode->data[y * qrcode->size + x] = value;
}

int qrcode_get(QRCode* qrcode, int x, int y) {
  if (x < 0 || x >= qrcode->size || y < 0 || y >= qrcode->size) {
    return 0;
  }
  return qrcode->data[y * qrcode->size + x];
}

void qrcode_print(QRCode* qrcode) {
  for (int y = 0; y < qrcode->size; y++) {
    for (int x = 0; x < qrcode->size; x++) {
      printf("%d", qrcode_get(qrcode, x, y));
    }
    printf("\n");
  }
}

int main() {
  QRCode* qrcode = qrcode_create(21);

  // Set the finder patterns
  for (int i = 0; i < 7; i++) {
    qrcode_set(qrcode, i, 0, 1);
    qrcode_set(qrcode, i, 6, 1);
    qrcode_set(qrcode, 0, i, 1);
    qrcode_set(qrcode, 6, i, 1);
  }

  // Set the timing patterns
  for (int i = 8; i < 15; i++) {
    qrcode_set(qrcode, i, 6, 1);
    qrcode_set(qrcode, 6, i, 1);
  }

  // Set the alignment patterns
  for (int i = 11; i < 15; i++) {
    qrcode_set(qrcode, i, 11, 1);
    qrcode_set(qrcode, 11, i, 1);
  }

  // Set the data
  int data_index = 0;
  for (int y = 10; y < qrcode->size - 10; y++) {
    for (int x = 10; x < qrcode->size - 10; x++) {
      if (data_index < strlen("Hello, world!")) {
        qrcode_set(qrcode, x, y, "Hello, world!"[data_index] - '0');
        data_index++;
      }
    }
  }

  // Print the QR code
  qrcode_print(qrcode);

  // Destroy the QR code
  qrcode_destroy(qrcode);

  return 0;
}