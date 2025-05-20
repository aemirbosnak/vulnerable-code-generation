//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// You can compile this with: gcc qrcode_generator.c -o qrcode_generator -lm

#define QR_VERSION 1
#define QR_SIZE 21
#define QR_MODULE_SIZE 3

const char *qr_alphanumeric_map = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+/:-.";

typedef struct {
    int size;
    int **matrix;
} QRCode;

// Function declaration
QRCode* create_qr_code(const char *input);
void destroy_qr_code(QRCode *qr);
void draw_qr_code(QRCode *qr);
void add_finder_patterns(QRCode *qr);
void add_timing_patterns(QRCode *qr);
void add_format_info(QRCode *qr);

int main() {
    char input[256];

    printf("Enter the data to encode in QR Code: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove new line character if exists
    input[strcspn(input, "\n")] = 0;

    QRCode *qr = create_qr_code(input);
    if (qr == NULL) {
        printf("Error generating QR Code.\n");
        return 1;
    }

    printf("Generated QR Code:\n");
    draw_qr_code(qr);

    destroy_qr_code(qr);
    return 0;
}

QRCode* create_qr_code(const char *input) {
    QRCode *qr = (QRCode *)malloc(sizeof(QRCode));
    if (qr == NULL) {
        return NULL;
    }

    qr->size = QR_SIZE;
    qr->matrix = (int **)malloc(qr->size * sizeof(int *));
    for (int i = 0; i < qr->size; i++) {
        qr->matrix[i] = (int *)malloc(qr->size * sizeof(int));
        memset(qr->matrix[i], 0, qr->size * sizeof(int));
    }

    add_finder_patterns(qr);
    add_timing_patterns(qr);
    add_format_info(qr);

    // You may add more encoding logic here for input data

    return qr;
}

void add_finder_patterns(QRCode *qr) {
    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 7; y++) {
            int is_black = (x == 0 || x == 6 || y == 0 || y == 6 || (x >= 2 && x <= 4 && y >= 2 && y <= 4)) ? 1 : 0;
            qr->matrix[x][y] = is_black;
            qr->matrix[x][qr->size - 1 - y] = is_black;
            qr->matrix[qr->size - 1 - x][y] = is_black;
        }
    }
}

void add_timing_patterns(QRCode *qr) {
    for (int i = 8; i < qr->size - 8; i++) {
        qr->matrix[i][6] = (i % 2);
        qr->matrix[6][i] = (i % 2);
    }
}

void add_format_info(QRCode *qr) {
    // This is a simple bipartite format pattern, not complete.
    qr->matrix[8][0] = 1; 
    qr->matrix[8][1] = 0; 
    // You may want to implement the complete format information encoding
}

void draw_qr_code(QRCode *qr) {
    for (int i = 0; i < qr->size; i++) {
        for (int j = 0; j < qr->size; j++) {
            if (qr->matrix[i][j]) {
                printf("##");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void destroy_qr_code(QRCode *qr) {
    for (int i = 0; i < qr->size; i++) {
        free(qr->matrix[i]);
    }
    free(qr->matrix);
    free(qr);
}