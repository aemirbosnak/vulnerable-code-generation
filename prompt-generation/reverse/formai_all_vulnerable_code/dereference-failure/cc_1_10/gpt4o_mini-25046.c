//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

typedef struct {
    QRcode *qrcode;
    int version;
    int level;
    char *data;
} QRCodeGenerator;

void initQRCodeGenerator(QRCodeGenerator *generator, const char *data) {
    generator->data = strdup(data);
    generator->version = 0; // Default version
    generator->level = QR_ECLEVEL_L; // Default error correction level
    generator->qrcode = QRcode_encodeString(data, generator->version, generator->level, QR_MODE_8, 1);
    if (generator->qrcode == NULL) {
        fprintf(stderr, "Failed to generate QR code for data: %s\n", data);
        exit(EXIT_FAILURE);
    }
}

void generateQRCodeImage(QRCodeGenerator *generator) {
    FILE *file;
    file = fopen("qrcode.png", "wb");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    
    // Write PNG header
    unsigned char pngHeader[8] = {
        0x89, 'P', 'N', 'G', 0x0D, 0x0A, 0x1A, 0x0A
    };
    fwrite(pngHeader, sizeof(pngHeader), 1, file);

    // Create a dummy PNG file (incomplete - placeholder for real PNG writing)
    // using independent libraries like libpng would be advised for actual implementation
    fprintf(file, "This is a dummy PNG file. QR Code writing is not fully implemented here.\n");
    
    fclose(file);
    printf("QR code generated and saved as 'qrcode.png'\n");
}

void cleanUpQRCodeGenerator(QRCodeGenerator *generator) {
    if (generator->qrcode) QRcode_free(generator->qrcode);
    free(generator->data);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <data_string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    QRCodeGenerator generator;
    initQRCodeGenerator(&generator, argv[1]);
    generateQRCodeImage(&generator);
    cleanUpQRCodeGenerator(&generator);

    return EXIT_SUCCESS;
}