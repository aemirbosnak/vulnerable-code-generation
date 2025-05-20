//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    int size;
    char *data;
} QRCode;

QRCode *create_qrcode(const char *data, int size) {
    QRCode *qrcode = malloc(sizeof(QRCode));
    qrcode->size = size;
    qrcode->data = malloc(size * size);
    memset(qrcode->data, ' ', size * size);
    int x = size / 2, y = size / 2;
    int direction = 1;
    int steps = 0;
    int current_char = 0;
    while (current_char < strlen(data)) {
        qrcode->data[y * size + x] = data[current_char++];
        if (x + direction == size || x + direction == -1 || qrcode->data[(y * size + x + direction) % (size * size)] != ' ') {
            direction = -direction;
            steps++;
        }
        x += direction;
        y -= direction;
        if (steps == 1) {
            steps = 0;
            direction = -direction;
        }
    }
    return qrcode;
}

void print_qrcode(QRCode *qrcode) {
    for (int i = 0; i < qrcode->size; i++) {
        for (int j = 0; j < qrcode->size; j++) {
            printf("%c", qrcode->data[i * qrcode->size + j]);
        }
        printf("\n");
    }
}

void free_qrcode(QRCode *qrcode) {
    free(qrcode->data);
    free(qrcode);
}

int main() {
    char *data = "Hello, world!";
    int size = 21;
    QRCode *qrcode = create_qrcode(data, size);
    print_qrcode(qrcode);
    free_qrcode(qrcode);
    return 0;
}