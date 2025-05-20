//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_QR_CODE_SIZE 1024
#define MAX_QR_CODE_DATA (MAX_QR_CODE_SIZE * 4)

typedef struct {
    int version;
    int error_correction_level;
    int mask;
    int data_codewords[MAX_QR_CODE_DATA];
} QRCode;

QRCode* qr_code_decode(const char* data) {
    int i, j, k;
    int pos = 0;
    int num_codewords = 0;
    QRCode* qr_code = malloc(sizeof(QRCode));

    qr_code->version = (data[pos] - '0');
    pos++;

    for (i = 0; i < 3; i++) {
        qr_code->mask = (qr_code->mask << 1) | (data[pos] - '0');
        pos++;
    }

    qr_code->error_correction_level = (data[pos] - '0');
    pos++;

    for (i = 0; i < qr_code->version * 4 + 17; i++) {
        if (isdigit(data[pos])) {
            qr_code->data_codewords[num_codewords++] = data[pos] - '0';
        } else if (data[pos] == '0' || data[pos] == '1') {
            qr_code->data_codewords[num_codewords++] = data[pos] - '0';
        } else {
            printf("Invalid QR code data\n");
            exit(1);
        }
        pos++;
    }

    return qr_code;
}

void qr_code_print(QRCode* qr_code) {
    int i, j, k;
    int num_codewords = qr_code->version * 4 + 17;

    for (i = 0; i < num_codewords; i++) {
        printf("%d ", qr_code->data_codewords[i]);
    }
}

int main(int argc, char* argv[]) {
    char* qr_data;
    QRCode* qr_code;

    if (argc < 2) {
        printf("Usage: %s QR_CODE_DATA\n", argv[0]);
        exit(1);
    }

    qr_data = argv[1];
    qr_code = qr_code_decode(qr_data);
    qr_code_print(qr_code);

    return 0;
}