//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 256

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct QRCode {
  Node** matrix;
  int size;
} QRCode;

QRCode* qr_code_create(int size) {
  QRCode* qr = malloc(sizeof(QRCode));
  qr->matrix = malloc(sizeof(Node**) * size);
  for (int i = 0; i < size; i++) {
    qr->matrix[i] = NULL;
  }
  qr->size = size;
  return qr;
}

void qr_code_encode(QRCode* qr, int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = qr->matrix[data] ? qr->matrix[data] : NULL;
  qr->matrix[data] = newNode;
}

void qr_code_print(QRCode* qr) {
  for (int i = 0; i < qr->size; i++) {
    for (Node* node = qr->matrix[i]; node; node = node->next) {
      printf("%d ", node->data);
    }
    printf("\n");
  }
}

int main() {
  QRCode* qr = qr_code_create(5);
  qr_code_encode(qr, 10);
  qr_code_encode(qr, 20);
  qr_code_encode(qr, 30);
  qr_code_print(qr);

  return 0;
}