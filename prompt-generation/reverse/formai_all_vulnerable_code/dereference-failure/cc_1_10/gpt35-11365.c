//FormAI DATASET v1.0 Category: QR code generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <qrencode.h>

// This function generates a QR code from a given string
void generateQRCode(char *data, int width, int height, char *filename) {
    QRcode *qr;
    uint8_t *image;
    int x, y, top, left, bottom, right;
    FILE *fp;

    // Generate the QR code
    qr = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if(qr == NULL) {
        fprintf(stderr, "Error generating QR code\n");
        return;
    }

    // Allocate memory for the image
    image = (uint8_t*)calloc(qr->width*qr->width, sizeof(uint8_t));
    if(image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        QRcode_free(qr);
        return;
    }

    // Convert the QR code to an image
    for(y=0; y<qr->width; y++) {
        for(x=0; x<qr->width; x++) {
            if(qr->data[y*qr->width+x] & 1) {
                image[y*qr->width+x] = 0;
            } else {
                image[y*qr->width+x] = 255;
            }
        }
    }

    // Find the limits of the QR code in the image
    top = qr->width-1;
    left = qr->width-1;
    bottom = 0;
    right = 0;
    for(y=0; y<qr->width; y++) {
        for(x=0; x<qr->width; x++) {
            if(image[y*qr->width+x] == 0) {
                if(y < top) {
                    top = y;
                }
                if(x < left) {
                    left = x;
                }
                if(y > bottom) {
                    bottom = y;
                }
                if(x > right) {
                    right = x;
                }
            }
        }
    }

    // Add a 1 pixel border to the QR code
    top--;
    left--;
    bottom++;
    right++;
    width = right - left + 1;
    height = bottom - top + 1;

    // Write the image to a PNG file
    fp = fopen(filename, "wb");
    if(fp == NULL) {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
        QRcode_free(qr);
        free(image);
        return;
    }
    fprintf(fp, "\x89\x50\x4E\x47\x0D\x0A\x1A\x0A");
    fwrite("\x00\x00\x00\x0D\x49\x48\x44\x52", 1, 8, fp);
    fwrite(&width, 4, 1, fp);
    fwrite(&height, 4, 1, fp);
    fwrite("\x08\x03\x00\x00\x00", 1, 5, fp);
    fwrite("\x00\x6E\x65\xD8\x12", 1, 5, fp);
    fwrite(image+top*qr->width+left, 1, width*height, fp);
    fwrite("\x00\x00\x00\x00\x49\x45\x4E\x44\xAE\x42\x60\x82", 1, 12, fp);
    fclose(fp);

    // Free memory
    QRcode_free(qr);
    free(image);
}

int main(void) {
    char data[256]; // Maximum length of data to encode is 236 characters
    char filename[256];
    int width = 256;
    int height = 256;

    // Prompt user for data to encode
    printf("Enter data to encode (maximum 236 characters):\n");
    fgets(data, 256, stdin);
    data[strcspn(data, "\n")] = 0;

    // Prompt user for filename to save QR code as
    printf("Enter filename to save QR code as (without extension):\n");
    fgets(filename, 256, stdin);
    filename[strcspn(filename, "\n")] = 0;
    strcat(filename, ".png");

    // Generate the QR code and save it to file
    generateQRCode(data, width, height, filename);

    // Exit
    printf("QR code saved as %s\n", filename);
    return 0;
}