//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Cell {
  int data;
  struct Cell* next;
} Cell;

Cell* createCell(int data) {
  Cell* cell = (Cell*)malloc(sizeof(Cell));
  cell->data = data;
  cell->next = NULL;
  return cell;
}

void insertAtTail(Cell* head, int data) {
  Cell* newCell = createCell(data);
  if (head == NULL) {
    head = newCell;
  } else {
    head->next = newCell;
  }
  head = newCell;
}

int main() {
  Cell* head = NULL;
  char* msg = "Hello, world!";

  for (int i = 0; msg[i] != '\0'; i++) {
    insertAtTail(head, msg[i]);
  }

  int qrCodeSize = 25;
  int** qrCode = (int**)malloc(sizeof(int*) * qrCodeSize);
  for (int i = 0; i < qrCodeSize; i++) {
    qrCode[i] = (int*)malloc(sizeof(int) * qrCodeSize);
  }

  for (int i = 0; head != NULL; i++) {
    int data = head->data;
    qrCode[data][data] = 1;
    head = head->next;
  }

  for (int i = 0; i < qrCodeSize; i++) {
    for (int j = 0; j < qrCodeSize; j++) {
      if (qrCode[i][j] == 1) {
        printf("%d ", 1);
      } else {
        printf("%d ", 0);
      }
    }
    printf("\n");
  }

  return 0;
}