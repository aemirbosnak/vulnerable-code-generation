//FormAI DATASET v1.0 Category: QR code generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <qrencode.h>

// Function to generate QR code and save in PNG format
void generateQRCode(const char* data, const char* filename, int size) {
    QRcode *qr = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qr == NULL) {
        printf("Error: Failed to generate QR code.");
        exit(EXIT_FAILURE);
    }
    
    // Open file for writing
    FILE *fp;
    if ((fp = fopen(filename, "wb+")) == NULL) {
        printf("Error: Failed to open file for writing.");
        QRcode_free(qr); 
        exit(EXIT_FAILURE);
    }
    
    // Initialize QR code output image buffer
    unsigned char *buffer;
    buffer = (unsigned char *) malloc(size * size * sizeof(unsigned char));
    memset(buffer, 0xff, size * size);
    
    // Copy QR code data into output image buffer
    int x, y, pos;
    for (y = 0; y < qr->width; y++) {
        for (x = 0; x < qr->width; x++) {
            pos = (y + 1) * (size + 2) + (x + 1);
            buffer[pos] = qr->data[y * qr->width + x] & 1 ? 0 : 0xff;
        }
    }
    
    // Write PNG file header
    unsigned char header[8] = {137, 80, 78, 71, 13, 10, 26, 10};
    fwrite(header, sizeof(unsigned char), 8, fp);
    
    // Write IHDR chunk
    unsigned char chunk[13] = { 0,0,0,13,73,72,68,82, (size>>24) & 0xFF, (size>>16) & 0xFF, (size>>8) & 0xFF, size & 0xFF, 8, 0, 0, 0 };
    fwrite(&chunk, sizeof(unsigned char), 13, fp);
    
    // Process QR code data and write it as IDAT chunk(s)
    int row, n;
    unsigned char *p = buffer;
    unsigned char idat[2] = {0x49, 0x44};
    for (row = 0; row < size; row += n) {
        n = size - row;
        if (n > 32767) n = 32767;
        idat[2] = n >> 8;
        idat[3] = n & 0xff;
        fwrite(&idat, sizeof(unsigned char), 4, fp);
        fwrite(p, sizeof(unsigned char), n, fp);
        p += n;
    }
    
    // Write IEND chunk
    unsigned char end[12] = {0,0,0,0,73,69,78,68, 0xAE, 0x42, 0x60, 0x82};
    fwrite(end, sizeof(unsigned char), 12, fp);
    
    // Close file and free memory
    fclose(fp);
    QRcode_free(qr);
    free(buffer);
}

int main() {
    // Variables for user input
    char input[256];
    int size;
    char filename[256];
    
    // Get user input for QR code data
    printf("Enter the data to generate QR code: ");
    fgets(input, sizeof(input), stdin);
    
    // Trim the trailing newline from input string
    input[strcspn(input, "\n")] = '\0';
    
    // Get user input for QR code size
    printf("Enter the size of QR code: ");
    scanf("%d", &size);
    
    // Get user input for QR code filename
    printf("Enter the filename to save QR code: ");
    scanf("%s", filename);
    
    // Generate QR code and save in PNG format
    generateQRCode(input, filename, size);
    
    printf("QR code generated and saved in %s", filename);

    return 0;
}