//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CODE_SIZE 256

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct QRCode {
    Node** data;
    int size;
} QRCode;

QRCode* qr_code_create(int size) {
    QRCode* qr = malloc(sizeof(QRCode));
    qr->data = malloc(sizeof(Node*) * size);
    qr->size = size;
    return qr;
}

void qr_code_add(QRCode* qr, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (qr->data[qr->size - 1] != NULL) {
        qr->data[qr->size - 1]->next = newNode;
    } else {
        qr->data[qr->size - 1] = newNode;
    }
}

void qr_code_print(QRCode* qr) {
    for (int i = 0; i < qr->size; i++) {
        for (Node* node = qr->data[i]; node; node = node->next) {
            printf("%c ", node->data);
        }
        printf("\n");
    }
}

int main() {
    QRCode* qr = qr_code_create(5);
    qr_code_add(qr, 'A');
    qr_code_add(qr, 'B');
    qr_code_add(qr, 'C');
    qr_code_add(qr, 'D');
    qr_code_add(qr, 'E');
    qr_code_print(qr);

    return 0;
}