//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define QR_VERSION 1
#define QR_SIZE (21) // 21x21 for version 1
#define MODULE_SIZE (10)

typedef struct {
    int size;
    int **modules;
} QRCode;

QRCode* create_qr_code() {
    QRCode *qr = (QRCode*)malloc(sizeof(QRCode));
    qr->size = QR_SIZE;
    qr->modules = (int**)malloc(qr->size * sizeof(int*));

    for (int i = 0; i < qr->size; i++) {
        qr->modules[i] = (int*)malloc(qr->size * sizeof(int));
        memset(qr->modules[i], 0, qr->size * sizeof(int));
    }
    return qr;
}

void destroy_qr_code(QRCode *qr) {
    for (int i = 0; i < qr->size; i++) {
        free(qr->modules[i]);
    }
    free(qr->modules);
    free(qr);
}

void draw_finder_patterns(QRCode *qr) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (((i >= 2 && i <= 4) && (j >= 2 && j <= 4)) || (i == 0 || i == 6 || j == 0 || j == 6)) {
                qr->modules[i][j] = 1;
            }
        }
    }

    // Top left
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            qr->modules[i][j] = 1;
        }
    }
    // Top right
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            qr->modules[i][qr->size - j - 1] = 1;
        }
    }
    // Bottom left
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            qr->modules[qr->size - i - 1][j] = 1;
        }
    }
}

void draw_timing_patterns(QRCode *qr) {
    for (int i = 8; i < 15; i++) {
        qr->modules[6][i] = (i % 2 == 0) ? 1 : 0; // Horizontal
        qr->modules[i][6] = (i % 2 == 0) ? 1 : 0; // Vertical
    }
}

void apply_format_info(QRCode *qr) {
    // For simplicity, we're not implementing this fully
    // Placeholder for applying format info
}

void add_data(QRCode *qr, const char *data) {
    // Simplified example: Just fill a small section
    int length = strlen(data);
    for (int i = 0; i < length && i < qr->size - 8; i++) {
        qr->modules[qr->size - 1][i] = (data[i] == '1') ? 1 : 0;
    }
}

void print_qr_code(QRCode *qr) {
    for (int i = 0; i < qr->size; i++) {
        for (int j = 0; j < qr->size; j++) {
            if (qr->modules[i][j] == 1) {
                printf("##");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Minimalist QR Code Generator\n\n");

    QRCode *qr = create_qr_code();
    draw_finder_patterns(qr);
    draw_timing_patterns(qr);
    
    const char *data = "1010101010"; // Sample binary data
    add_data(qr, data);
    
    print_qr_code(qr);
    destroy_qr_code(qr);
    
    return 0;
}