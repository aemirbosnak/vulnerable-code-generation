//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define QR_VERSION 1
#define QR_SIZE 21
#define QR_MARGIN 4

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    int version;
    int size;
    int margin;
    point **data;
} qr_code;

qr_code *qr_code_create(int version, int size, int margin) {
    qr_code *code = malloc(sizeof(qr_code));
    code->version = version;
    code->size = size;
    code->margin = margin;
    code->data = malloc(sizeof(point *) * size);
    for (int i = 0; i < size; i++) {
        code->data[i] = malloc(sizeof(point) * size);
    }
    return code;
}

void qr_code_destroy(qr_code *code) {
    for (int i = 0; i < code->size; i++) {
        free(code->data[i]);
    }
    free(code->data);
    free(code);
}

void qr_code_set_data(qr_code *code, int x, int y, int value) {
    code->data[x][y].x = x;
    code->data[x][y].y = y;
}

void qr_code_print(qr_code *code) {
    for (int y = -code->margin; y < code->size + code->margin; y++) {
        for (int x = -code->margin; x < code->size + code->margin; x++) {
            if (x >= 0 && y >= 0 && x < code->size && y < code->size) {
                printf("%d", code->data[x][y].x);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    qr_code *code = qr_code_create(QR_VERSION, QR_SIZE, QR_MARGIN);

    // Set the data
    for (int i = 0; i < code->size; i++) {
        for (int j = 0; j < code->size; j++) {
            qr_code_set_data(code, i, j, (i + j) % 2);
        }
    }

    // Print the code
    qr_code_print(code);

    // Destroy the code
    qr_code_destroy(code);

    return 0;
}