//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int version;
    int level;
    char *data;
    int data_len;
    int width;
    int height;
    char **matrix;
} QRCode;

QRCode *qr_init(int version, int level, char *data) {
    QRCode *qr = malloc(sizeof(QRCode));
    qr->version = version;
    qr->level = level;
    qr->data = data;
    qr->data_len = strlen(data);
    qr->width = 4 * version + 17;
    qr->height = 4 * version + 17;
    qr->matrix = malloc(qr->width * sizeof(char *));
    for (int i = 0; i < qr->width; i++) {
        qr->matrix[i] = malloc(qr->height * sizeof(char));
        for (int j = 0; j < qr->height; j++) {
            qr->matrix[i][j] = ' ';
        }
    }
    return qr;
}

void qr_free(QRCode *qr) {
    for (int i = 0; i < qr->width; i++) {
        free(qr->matrix[i]);
    }
    free(qr->matrix);
    free(qr->data);
    free(qr);
}

void qr_encode(QRCode *qr) {
    // TODO
}

void qr_print(QRCode *qr) {
    for (int i = 0; i < qr->height; i++) {
        for (int j = 0; j < qr->width; j++) {
            printf("%c", qr->matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <version> <level> <data>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int version = atoi(argv[1]);
    int level = atoi(argv[2]);
    char *data = argv[3];

    QRCode *qr = qr_init(version, level, data);
    qr_encode(qr);
    qr_print(qr);
    qr_free(qr);

    return EXIT_SUCCESS;
}