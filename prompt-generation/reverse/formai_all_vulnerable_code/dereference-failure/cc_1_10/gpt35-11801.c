//FormAI DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_W 512
#define MAX_H 512

typedef unsigned char byte;

byte image[MAX_W][MAX_H];
byte stego[MAX_W][MAX_H];

void hide(byte *msg, int len) {
    int i, j, k = 0;

    // Store first pixel as message length
    image[0][0] = len >> 24;
    image[0][1] = len >> 16;
    image[0][2] = len >> 8;
    image[0][3] = len;

    for (i = 0; i < MAX_W && k < len+4; i++) {
        for (j = 0; j < MAX_H && k < len+4; j++) {

            // Don't overwrite message length
            if (i == 0 && j < 4) {
                stego[i][j] = image[i][j];
                continue;
            }

            // Hide message in blue channel
            stego[i][j] = image[i][j] & 0xFC;
            stego[i][j] |= msg[k] >> 6;
            k++;

            // Hide message in green channel
            if (k < len+4) {
                stego[i][j] = image[i][j] & 0xF3;
                stego[i][j] |= msg[k] >> 4;
                k++;
            }

            // Hide message in red channel
            if (k < len+4) {
                stego[i][j] = image[i][j] & 0xCF;
                stego[i][j] |= msg[k] >> 2;
                k++;
            }

            // Hide remaining bits in alpha channel
            if (k < len+4) {
                stego[i][j] = image[i][j] & 0xFC;
                stego[i][j] |= msg[k] >> 6;
                k++;
            }
        }
    }
}

byte *reveal() {
    int i, j, len;
    byte *msg;

    // Retrieve message length from first pixel
    len = (image[0][0] << 24) | (image[0][1] << 16) | (image[0][2] << 8) | image[0][3];
    msg = malloc(len);

    for (i = 0; i < MAX_W; i++) {
        for (j = 0; j < MAX_H; j++) {

            // Skip first pixel
            if (i == 0 && j < 4) {
                continue;
            }

            // Retrieve message from blue channel
            msg[(i*MAX_H+j-4)*4] = stego[i][j] << 6;

            // Retrieve message from green channel
            if ((i*MAX_H+j-4)*4+1 < len) {
                msg[(i*MAX_H+j-4)*4+1] = (stego[i][j] & 0x0C) << 4;
            }

            // Retrieve message from red channel
            if ((i*MAX_H+j-4)*4+2 < len) {
                msg[(i*MAX_H+j-4)*4+2] = (stego[i][j] & 0x03) << 2;
            }

            // Retrieve remaining bits from alpha channel
            if ((i*MAX_H+j-4)*4+3 < len) {
                msg[(i*MAX_H+j-4)*4+3] = stego[i][j] << 6;
            }
        }
    }

    return msg;
}

int main(int argc, char *argv[]) {
    int i, j;
    byte msg[] = "This is an example message hidden inside an image using steganography";

    // Zero-initialize image and stego arrays
    memset(image, 0, sizeof(byte) * MAX_W * MAX_H);
    memset(stego, 0, sizeof(byte) * MAX_W * MAX_H);

    // Load image from file
    FILE *f = fopen("image.raw", "rb");
    if (f) {
        fread(image, sizeof(byte), MAX_W * MAX_H, f);
        fclose(f);
    }

    // Hide message inside image
    hide(msg, sizeof(msg));

    // Save stego image to file
    f = fopen("stego.raw", "wb");
    if (f) {
        fwrite(stego, sizeof(byte), MAX_W * MAX_H, f);
        fclose(f);
    }

    // Reveal message from stego image
    byte *revealed = reveal();
    printf("%s\n", revealed);

    free(revealed);

    return 0;
}