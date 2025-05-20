//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

void create_qr_code(const char *text, const char *filename) {
    // Create a QR code
    QRcode *qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!qrcode) {
        fprintf(stderr, "Error: Could not create QR code.\n");
        return;
    }

    // Prepare to generate a PGM file for the QR code
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: Could not open file %s for writing.\n", filename);
        QRcode_free(qrcode);
        return;
    }

    // Write the PGM header
    fprintf(fp, "P2\n");
    fprintf(fp, "%d %d\n", qrcode->width, qrcode->width);
    fprintf(fp, "255\n");

    // Write the QR code data to the PGM file
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            int value = qrcode->data[y * qrcode->width + x] & 1 ? 0 : 255;
            fprintf(fp, "%d ", value);
        }
        fprintf(fp, "\n");
    }

    // Close the file and free memory
    fclose(fp);
    QRcode_free(qrcode);
    printf("QR code generated successfully and saved as %s\n", filename);
}

int main() {
    // Artistic introduction
    printf("===================================\n");
    printf("         QR Code Generator        \n");
    printf("         By Your Name             \n");
    printf("===================================\n\n");

    char text[256];
    char filename[256];

    // User prompt
    printf("Enter the text/content for the QR code: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove trailing newline

    printf("Enter the filename to save the QR code (e.g., qrcode.pgm): ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove trailing newline

    // Call the QR code creation function
    create_qr_code(text, filename);

    // Artistic conclusion
    printf("\n===================================\n");
    printf("        Thank you for using!      \n");
    printf("        Share your QR codes!      \n");
    printf("===================================\n");

    return 0;
}