//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_VERSION 4
#define QR_SIZE (4 * QR_VERSION + 17)

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <data>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *data = argv[1];
    int data_len = strlen(data);

    if (data_len > 255) {
        fprintf(stderr, "Data too long: %d bytes (max 255)\n", data_len);
        return EXIT_FAILURE;
    }

    unsigned char qr_code[QR_SIZE][QR_SIZE];

    // Initialize QR code matrix
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            qr_code[i][j] = 0;
        }
    }

    // Generate timing patterns
    for (int i = 0; i < 6; i++) {
        qr_code[i][8] = 1;
        qr_code[i][QR_SIZE - 1 - i] = 1;
        qr_code[QR_SIZE - 1 - i][8] = 1;
    }

    for (int i = 0; i < 7; i++) {
        qr_code[6][i] = 1;
        qr_code[QR_SIZE - 7][i] = 1;
    }

    // Generate alignment patterns
    if (QR_VERSION >= 2) {
        for (int i = 0; i < QR_VERSION + 2; i++) {
            for (int j = 0; j < QR_VERSION + 2; j++) {
                qr_code[QR_SIZE - 7 - j][i + 6] = 1;
                qr_code[i + 6][QR_SIZE - 7 - j] = 1;
            }
        }
    }

    // Generate version information
    if (QR_VERSION >= 7) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 6; j++) {
                qr_code[QR_SIZE - 11 + i][j] = ((QR_VERSION - 1) >> i) & 1;
                qr_code[j][QR_SIZE - 11 + i] = ((QR_VERSION - 1) >> i) & 1;
            }
        }
    }

    // Generate data bits
    int data_index = 0;
    int x = QR_SIZE - 1;
    int y = QR_SIZE - 1;
    int direction = -1;
    while (data_index < data_len) {
        while (qr_code[y][x] != 0) {
            x += direction;
            if (x < 0 || x >= QR_SIZE) {
                y -= direction;
                x += direction * 2;
                direction *= -1;
            }
        }

        qr_code[y][x] = (data[data_index] >> (7 - (data_index % 8))) & 1;
        data_index++;
        x += direction;
        if (x < 0 || x >= QR_SIZE) {
            y -= direction;
            x += direction * 2;
            direction *= -1;
        }
    }

    // Generate format information
    int format_info = 0x5 << 2;
    for (int i = 0; i < 5; i++) {
        qr_code[8][i] = (format_info >> i) & 1;
        qr_code[i][8] = (format_info >> i) & 1;
        qr_code[QR_SIZE - 8 + i][QR_SIZE - 1] = (format_info >> i) & 1;
        qr_code[QR_SIZE - 1][QR_SIZE - 8 + i] = (format_info >> i) & 1;
    }

    // Generate error correction bits
    int ec_data_len = ((QR_VERSION * 4) + 16) * data_len / 255 + 16;
    unsigned char ec_data[ec_data_len];
    memset(ec_data, 0, ec_data_len);
    ec_data[0] = 4;
    ec_data[1] = data_len;
    for (int i = 0; i < data_len; i++) {
        ec_data[i + 2] = data[i];
    }

    int ec_index = 0;
    x = QR_SIZE - 1;
    y = QR_SIZE - 1;
    while (ec_index < ec_data_len) {
        while (qr_code[y][x] != 0) {
            x += direction;
            if (x < 0 || x >= QR_SIZE) {
                y -= direction;
                x += direction * 2;
                direction *= -1;
            }
        }

        qr_code[y][x] = (ec_data[ec_index] >> (7 - (ec_index % 8))) & 1;
        ec_index++;
        x += direction;
        if (x < 0 || x >= QR_SIZE) {
            y -= direction;
            x += direction * 2;
            direction *= -1;
        }
    }

    // Generate terminator
    for (int i = 0; i < 7; i++) {
        qr_code[8][QR_SIZE - i - 1] = 0;
    }

    // Print QR code
    for (int y = 0; y < QR_SIZE; y++) {
        for (int x = 0; x < QR_SIZE; x++) {
            printf("%c ", qr_code[y][x] ? '#' : '.');
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}