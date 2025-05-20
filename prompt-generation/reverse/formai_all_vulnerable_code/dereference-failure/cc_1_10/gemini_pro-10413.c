//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

void embed_watermark(byte *imgData, int imgWidth, int imgHeight, byte *wmData, int wmWidth, int wmHeight) {
    int i, j, k, l, x, y;

    // Convert watermark to binary
    byte *wmBin = (byte *)malloc(wmWidth * wmHeight);
    for (i = 0; i < wmWidth * wmHeight; i++) {
        wmBin[i] = (wmData[i] > 127) ? 1 : 0;
    }

    // Embed watermark into image
    for (i = 0; i < imgHeight; i++) {
        for (j = 0; j < imgWidth; j++) {
            // Get bit from watermark
            x = j % wmWidth;
            y = i % wmHeight;
            k = y * wmWidth + x;
            l = i * imgWidth + j;
            int bit = wmBin[k];

            // Embed bit into image
            if (bit == 1) {
                // Set pixel to odd value
                if (imgData[l] % 2 == 0) {
                    imgData[l]++;
                }
            } else {
                // Set pixel to even value
                if (imgData[l] % 2 == 1) {
                    imgData[l]--;
                }
            }
        }
    }

    free(wmBin);
}

int extract_watermark(byte *imgData, int imgWidth, int imgHeight, byte *wmData, int wmWidth, int wmHeight) {
    int i, j, k, l, x, y;

    // Convert image to binary
    byte *imgBin = (byte *)malloc(imgWidth * imgHeight);
    for (i = 0; i < imgWidth * imgHeight; i++) {
        imgBin[i] = (imgData[i] % 2 == 1) ? 1 : 0;
    }

    // Extract watermark from image
    for (i = 0; i < wmHeight; i++) {
        for (j = 0; j < wmWidth; j++) {
            // Get bit from image
            x = j % wmWidth;
            y = i % wmHeight;
            k = y * wmWidth + x;
            l = i * imgWidth + j;
            int bit = imgBin[l];

            // Set bit in watermark
            wmData[k] = bit;
        }
    }

    free(imgBin);

    return 0;
}

int main() {
    // Load image data
    byte imgData[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int imgWidth = 10;
    int imgHeight = 10;

    // Load watermark data
    byte wmData[] = {0, 1, 1, 0, 1, 0, 0, 1};
    int wmWidth = 8;
    int wmHeight = 8;

    // Embed watermark into image
    embed_watermark(imgData, imgWidth, imgHeight, wmData, wmWidth, wmHeight);

    // Save watermarked image to file
    FILE *fp = fopen("watermarked.bmp", "wb");
    fwrite(imgData, sizeof(byte), imgWidth * imgHeight, fp);
    fclose(fp);

    // Extract watermark from image
    byte extractedWmData[wmWidth * wmHeight];
    extract_watermark(imgData, imgWidth, imgHeight, extractedWmData, wmWidth, wmHeight);

    // Compare extracted watermark to original watermark
    int i, j;
    int error = 0;
    for (i = 0; i < wmWidth * wmHeight; i++) {
        if (wmData[i] != extractedWmData[i]) {
            error++;
        }
    }

    printf("Watermark error: %d\n", error);

    return 0;
}