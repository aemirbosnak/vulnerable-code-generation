//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1024
#define BLACK 0
#define WHITE 1

typedef struct QR_Code {
    int size;
    int **data;
} QR_Code;

void init_qrcode(QR_Code *qrcode, int size) {
    qrcode->size = size;
    qrcode->data = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        qrcode->data[i] = (int *)malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            qrcode->data[i][j] = WHITE;
        }
    }
}

void destroy_qrcode(QR_Code *qrcode) {
    for (int i = 0; i < qrcode->size; i++) {
        free(qrcode->data[i]);
    }
    free(qrcode->data);
}

void set_qrcode(QR_Code *qrcode, int x, int y, int color) {
    if (x >= 0 && x < qrcode->size && y >= 0 && y < qrcode->size) {
        qrcode->data[y][x] = color;
    }
}

void print_qrcode(QR_Code *qrcode) {
    for (int i = 0; i < qrcode->size; i++) {
        for (int j = 0; j < qrcode->size; j++) {
            if (qrcode->data[i][j] == BLACK) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int size = rand() % MAX_SIZE + 1;
    QR_Code qrcode;
    init_qrcode(&qrcode, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            set_qrcode(&qrcode, i, j, rand() % 2);
        }
    }
    print_qrcode(&qrcode);
    destroy_qrcode(&qrcode);
    return 0;
}