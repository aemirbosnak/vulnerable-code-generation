//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define QR_MAX_SIZE 256

typedef struct qr_code_t {
    int size;
    int **data;
} qr_code_t;

qr_code_t* qr_code_init(int size) {
    qr_code_t* qr = malloc(sizeof(qr_code_t));
    qr->size = size;
    qr->data = malloc(size * size * sizeof(int));
    return qr;
}

void qr_code_encode(qr_code_t* qr, char* msg) {
    int i, j, k = 0;
    for (i = 0; i < qr->size; i++) {
        for (j = 0; j < qr->size; j++) {
            qr->data[i][j] = 0;
        }
    }
    for (i = 0; msg[i] != '\0'; i++) {
        qr->data[k/qr->size][k%qr->size] = msg[i] & 0x1F;
        k++;
    }
}

void qr_code_draw(qr_code_t* qr) {
    int i, j;
    for (i = 0; i < qr->size; i++) {
        for (j = 0; j < qr->size; j++) {
            if (qr->data[i][j] == 0) {
                printf(" ");
            } else {
                printf("■");
            }
        }
        printf("\n");
    }
}

int main() {
    qr_code_t* qr = qr_code_init(16);
    qr_code_encode(qr, "Hello, world!");
    qr_code_draw(qr);
    free(qr);
    return 0;
}