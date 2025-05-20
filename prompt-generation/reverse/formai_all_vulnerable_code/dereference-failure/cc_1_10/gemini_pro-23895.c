//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define QR_VERSION 1
#define QR_SIZE 21
#define QR_DATA_SIZE 17
#define QR_ERROR_SIZE 4

#define QR_ALIGNMENT_PATTERN 0x11B

#define QR_CHARACTERS "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:"

static bool qr_data_check(const char *data) {
    int i;

    for (i = 0; i < QR_DATA_SIZE; i++) {
        if (strchr(QR_CHARACTERS, data[i]) == NULL) {
            return false;
        }
    }

    return true;
}

static int qr_align_position(int version) {
    if (version == 1) {
        return 0;
    } else if (version <= 6) {
        return 6;
    } else if (version <= 12) {
        return 12;
    } else {
        return 16;
    }
}

static void qr_init_matrix(int matrix[QR_SIZE][QR_SIZE]) {
    int i, j;

    for (i = 0; i < QR_SIZE; i++) {
        for (j = 0; j < QR_SIZE; j++) {
            matrix[i][j] = -1;
        }
    }

    matrix[7][7] = 0;
}

static void qr_place_finder_patterns(int matrix[QR_SIZE][QR_SIZE]) {
    int i, j;

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            if (i == 0 || i == 6 || j == 0 || j == 6) {
                matrix[i][j] = 1;
            }
        }
    }

    for (i = 2; i < 6; i++) {
        matrix[i][2] = 1;
        matrix[i][5] = 1;
    }

    for (j = 2; j < 6; j++) {
        matrix[2][j] = 1;
        matrix[5][j] = 1;
    }
}

static void qr_place_timing_patterns(int matrix[QR_SIZE][QR_SIZE]) {
    int i, j;

    for (i = 8; i < QR_SIZE - 8; i++) {
        if (i % 2 == 0) {
            matrix[i][6] = 0;
            matrix[6][i] = 0;
        }
    }
}

static void qr_place_alignment_patterns(int matrix[QR_SIZE][QR_SIZE], int version) {
    int i, j;
    int align_position = qr_align_position(version);

    for (i = 0; i < QR_SIZE; i += align_position + 2) {
        for (j = 0; j < QR_SIZE; j += align_position + 2) {
            if (i == 6 || i == QR_SIZE - 7 || j == 6 || j == QR_SIZE - 7) {
                continue;
            }

            matrix[i][j] = QR_ALIGNMENT_PATTERN;
            matrix[i + 1][j] = QR_ALIGNMENT_PATTERN;
            matrix[i][j + 1] = QR_ALIGNMENT_PATTERN;
            matrix[i + 1][j + 1] = QR_ALIGNMENT_PATTERN;
        }
    }
}

static void qr_place_data(int matrix[QR_SIZE][QR_SIZE], const char *data) {
    int i, j;
    int bit_index = 0;
    int data_index = 0;
    int data_value = 0;

    for (i = QR_SIZE - 1; i >= 0; i--) {
        for (j = QR_SIZE - 1; j >= 0; j--) {
            if (matrix[i][j] != -1) {
                continue;
            }

            if (bit_index == 0) {
                data_value = data[data_index++];
            }

            int bit = data_value & 0x01;
            matrix[i][j] = bit;

            data_value >>= 1;
            bit_index++;

            if (bit_index == 8) {
                bit_index = 0;
            }
        }
    }
}

static void qr_error_correct(int matrix[QR_SIZE][QR_SIZE]) {
    int i, j;

    for (i = 0; i < QR_DATA_SIZE + QR_ERROR_SIZE + 1; i++) {
        for (j = 0; j < QR_DATA_SIZE + QR_ERROR_SIZE + 1; j++) {
            
        }
    }
}

static void qr_mask(int matrix[QR_SIZE][QR_SIZE]) {
    int i, j;

    for (i = 0; i < QR_SIZE; i++) {
        for (j = 0; j < QR_SIZE; j++) {
            if (matrix[i][j] == -1) {
                continue;
            }

            matrix[i][j] = (i + j) % 3 == 0 ? 1 - matrix[i][j] : matrix[i][j];
        }
    }
}

static void qr_print(int matrix[QR_SIZE][QR_SIZE]) {
    int i, j;

    for (i = 0; i < QR_SIZE; i++) {
        for (j = 0; j < QR_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s data\n", argv[0]);
        return 1;
    }

    if (!qr_data_check(argv[1])) {
        printf("Invalid data\n");
        return 1;
    }

    int matrix[QR_SIZE][QR_SIZE];

    qr_init_matrix(matrix);
    qr_place_finder_patterns(matrix);
    qr_place_timing_patterns(matrix);
    qr_place_alignment_patterns(matrix, QR_VERSION);
    qr_place_data(matrix, argv[1]);
    qr_error_correct(matrix);
    qr_mask(matrix);
    qr_print(matrix);

    return 0;
}