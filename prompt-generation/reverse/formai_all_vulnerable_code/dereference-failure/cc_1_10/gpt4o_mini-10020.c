//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <qrencode.h>

// Function to generate a QR code from a given string
void generateQRCode(const char *input, const char *filename) {
    QRcode *qr;
    uint8_t *qrcodeData;
    FILE *fp;
    int size, margin = 4, imageSize;

    // Create the QR code
    qr = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qr == NULL) {
        fprintf(stderr, "Could not generate QR code\n");
        exit(EXIT_FAILURE);
    }

    // Calculate size of QR code image
    size = qr->width;
    imageSize = size + margin * 2;

    // Allocate memory for image
    qrcodeData = (uint8_t *)malloc(imageSize * imageSize);
    if (qrcodeData == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        QRcode_free(qr);
        exit(EXIT_FAILURE);
    }

    // Initialize QR code image
    for (int y = 0; y < imageSize; y++) {
        for (int x = 0; x < imageSize; x++) {
            if (x < margin || x >= size + margin || y < margin || y >= size + margin) {
                qrcodeData[y * imageSize + x] = 255; // White pixel
            } else {
                qrcodeData[y * imageSize + x] = (qr->data[(y - margin) * size + (x - margin)] & 1) ? 0 : 255; // Black or white
            }
        }
    }

    // Save QR code image to PGM file format
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file for writing\n");
        free(qrcodeData);
        QRcode_free(qr);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "P5\n%d %d\n255\n", imageSize, imageSize);
    fwrite(qrcodeData, sizeof(uint8_t), imageSize * imageSize, fp);
    
    // Cleanup
    fclose(fp);
    free(qrcodeData);
    QRcode_free(qr);
}

// Function to get the current timestamp as a string
void getCurrentTimestamp(char *buffer, size_t length) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, length, "%Y-%m-%d %H:%M:%S", tm_info);
}

// Function to log QR code generation
void logQRCodeGeneration(const char *filename, const char *input) {
    char timestamp[20];
    getCurrentTimestamp(timestamp, sizeof(timestamp));

    FILE *logFile = fopen("qrcode_gen.log", "a");
    if (logFile != NULL) {
        fprintf(logFile, "[%s] Generated QR code for \"%s\" saved as \"%s\"\n", timestamp, input, filename);
        fclose(logFile);
    } else {
        fprintf(stderr, "Could not open log file for writing\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_string> <output_filename.pgm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputString = argv[1];
    const char *outputFilename = argv[2];

    // Generate QR code and log the generation
    generateQRCode(inputString, outputFilename);
    logQRCodeGeneration(outputFilename, inputString);

    printf("QR code generated successfully for \"%s\" and saved to \"%s\"\n", inputString, outputFilename);
    return EXIT_SUCCESS;
}