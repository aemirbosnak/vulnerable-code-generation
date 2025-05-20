//Falcon2-11B DATASET v1.0 Category: QR code reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_SIZE 64

typedef struct {
    unsigned char data[QR_SIZE];
    int size;
} qr_code;

void error(const char *msg) {
    fprintf(stderr, "error: %s\n", msg);
    exit(1);
}

qr_code read_code(FILE *file) {
    qr_code code;
    fread(code.data, sizeof(code.data), 1, file);
    code.size = strlen(code.data);
    return code;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        error("usage: %s <file>\n");
    }
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        error("could not open file\n");
    }
    qr_code code = read_code(file);
    if (code.size!= QR_SIZE) {
        error("invalid qr code size\n");
    }
    int count = 0;
    while (count < QR_SIZE) {
        int i = 0;
        int j = QR_SIZE - count - 1;
        while (i < QR_SIZE && j >= 0) {
            if (code.data[i] == code.data[j]) {
                i++;
                j--;
            } else {
                break;
            }
        }
        if (i >= QR_SIZE || j < 0) {
            error("invalid qr code\n");
        }
        count = QR_SIZE - i - 1;
    }
    fclose(file);
    return 0;
}