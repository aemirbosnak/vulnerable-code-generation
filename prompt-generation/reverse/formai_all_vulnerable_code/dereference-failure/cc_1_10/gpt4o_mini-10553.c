//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

// Function declarations
void generateQRCode(const char *content);
void saveQRCodeAsPNG(QRcode *qrcode, const char *filename);

int main() {
    char input[256];
    printf("Welcome to the QR Code Generator!\n");
    printf("Enter the content for the QR Code (or type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Remove the newline character
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break; // Exit the program
        }

        generateQRCode(input);
    }

    printf("Goodbye!\n");
    return 0;
}

// Function to generate a QR Code for the given content
void generateQRCode(const char *content) {
    QRcode *qrcode;
    char filename[300];

    // Generate the QR code
    qrcode = QRcode_encodeString(content, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        printf("Failed to generate QR code\n");
        return;
    }

    // Create a filename for the QR code image
    snprintf(filename, sizeof(filename), "%s.png", content);
    saveQRCodeAsPNG(qrcode, filename);

    printf("QR Code generated and saved as %s\n", filename);

    // Free allocated memory
    QRcode_free(qrcode);
}

// Function to save the QR Code as a PNG image
void saveQRCodeAsPNG(QRcode *qrcode, const char *filename) {
    FILE *fp;
    int size = qrcode->width;
    unsigned char *png_data; // Holds the PNG data

    // Define the basic PNG header structure
    typedef struct {
        unsigned char signature[8];
        unsigned char ihdr[25];
        unsigned char idat[19];
        unsigned char iend[12];
    } PNGHeader;

    // Prepare the PNG header
    PNGHeader header;
    memcpy(header.signature, "\x89PNG\r\n\x1a\n", 8); // PNG signature
    // Basic IHDR chunk for our QR Code image
    sprintf((char *)&header.ihdr, "IHDR%08x%08x%08x%08x\240\0\0\0", size, size, 8, 0);
    memcpy(header.idat, "IDAT", 4); // IDAT, we'll add image data
    memcpy(header.iend, "IEND", 4); // IEND
    
    // Prepare the IDAT chunk with simple data (this won't be proper PNG encoding for simplicity)
    // Create a buffer to hold pixel data
    int image_size = size * size;
    png_data = (unsigned char *)malloc(image_size + sizeof(header));
    
    // Fill the image buffer according to QR Code pixels
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            png_data[y * size + x] = qrcode->data[y * size + x] & 1 ? 0 : 255; // Black or White
        }
    }
    
    // Save as a file
    fp = fopen(filename, "wb");
    if (!fp) {
        printf("Failed to create file %s\n", filename);
        free(png_data);
        return;
    }

    // Write PNG header and image data to file
    fwrite(&header, sizeof(header), 1, fp);
    fwrite(png_data, image_size, 1, fp);
    fwrite(&header.iend, sizeof(header.iend), 1, fp);
    
    // Clean up
    fclose(fp);
    free(png_data);
}