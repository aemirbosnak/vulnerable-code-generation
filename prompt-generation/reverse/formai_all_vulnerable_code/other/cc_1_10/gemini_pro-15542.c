//GEMINI-pro DATASET v1.0 Category: QR code reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef unsigned char byte;

#define MAX_DIM 1024

typedef struct {
    int width;
    int height;
    byte pixels[MAX_DIM][MAX_DIM];
} QRCode;

QRCode qrcode;

void read_qrcode(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    assert(fp != NULL);

    fscanf(fp, "%d %d\n", &qrcode.width, &qrcode.height);
    assert(qrcode.width <= MAX_DIM && qrcode.height <= MAX_DIM);

    for (int i = 0; i < qrcode.height; i++) {
        for (int j = 0; j < qrcode.width; j++) {
            fscanf(fp, "%hhu ", &qrcode.pixels[i][j]);
        }
        fscanf(fp, "\n");
    }

    fclose(fp);
}

void print_qrcode() {
    for (int i = 0; i < qrcode.height; i++) {
        for (int j = 0; j < qrcode.width; j++) {
            printf("%c", qrcode.pixels[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_qrcode(argv[1]);
    print_qrcode();

    return EXIT_SUCCESS;
}