//FormAI DATASET v1.0 Category: Image Steganography ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read in the image file and the message
    FILE *imgFile = fopen("image.bmp", "rb");
    FILE *msgFile = fopen("secret_message.txt", "r");
    fseek(imgFile, 0, SEEK_END);
    int imgSize = ftell(imgFile);
    fseek(imgFile, 0, SEEK_SET);
    unsigned char *imgBuffer = malloc(imgSize);
    fread(imgBuffer, 1, imgSize, imgFile);
    fclose(imgFile);
    char *msg = malloc(1024);
    fgets(msg, 1024, msgFile);
    fclose(msgFile);

    // Convert the message into binary
    int msgLen = strlen(msg);
    char *binMsg = malloc(msgLen * 8 + 1);
    for (int i = 0; i < msgLen; i++) {
        int asciiVal = (int) msg[i];
        for (int j = 0; j < 8; j++) {
            if (asciiVal % 2 == 0) {
                binMsg[i * 8 + (7 - j)] = '0';
            } else {
                binMsg[i * 8 + (7 - j)] = '1';
            }
            asciiVal = asciiVal / 2;
        }
    }
    binMsg[msgLen * 8] = '\0';

    // Put message into image buffer
    int imgPos = 54; // BMP header is 54 bytes
    for (int i = 0; i < msgLen * 8; i++) {
        if (binMsg[i] == '1') {
            imgBuffer[imgPos] |= 1;
        } else {
            imgBuffer[imgPos] &= ~1;
        }
        imgPos += 3;
    }

    // Write out the new image with the message hidden in it
    FILE *newImgFile = fopen("image_with_secret_message.bmp", "wb");
    fwrite(imgBuffer, 1, imgSize, newImgFile);
    fclose(newImgFile);

    free(imgBuffer);
    free(msg);
    free(binMsg);

    return 0;
}