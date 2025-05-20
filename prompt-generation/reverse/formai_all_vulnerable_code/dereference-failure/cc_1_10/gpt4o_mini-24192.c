//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

// Function to create a QR code from a given text and save it as a PNG file
void generate_qr_code(const char *text, const char *filename) {
    QRcode *qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Failed to encode QR Code\n");
        return;
    }

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        QRcode_free(qrcode);
        return;
    }

    // PNM Header
    fprintf(fp, "P1\n%d %d\n", qrcode->width, qrcode->width);
    
    // Writing QR code data
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            fputc((qrcode->data[y * qrcode->width + x] & 1) ? '1' : '0', fp);
            if (x < qrcode->width - 1) {
                fputc(' ', fp); // space between pixels
            }
        }
        fputc('\n', fp); // new row
    }

    fclose(fp);
    QRcode_free(qrcode);
}

void print_usage(const char *prog_name) {
    printf("Usage: %s <text> <output_filename>\n", prog_name);
    printf("Generates a QR code from the provided text and saves it as a .pbm file.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *text = argv[1];
    const char *filename = argv[2];

    printf("Generating QR code for text: \"%s\"\n", text);
    printf("Saving output to file: \"%s\"\n", filename);
    
    generate_qr_code(text, filename);
    printf("QR Code generated successfully!\n");

    return EXIT_SUCCESS;
}