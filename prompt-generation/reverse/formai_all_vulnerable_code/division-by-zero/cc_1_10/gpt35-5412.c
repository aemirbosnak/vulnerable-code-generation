//FormAI DATASET v1.0 Category: Image Steganography ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// surrealist steganography function
void surrealEncode(char* coverImage, char* secretImage, char* outputImage) {
    FILE* cover = fopen(coverImage, "rb");
    FILE* secret = fopen(secretImage, "rb");
    FILE* output = fopen(outputImage, "wb");

    if (cover == NULL || secret == NULL || output == NULL) {
        printf("Error: File(s) not found.\n");
        exit(1);
    }

    // get cover file size
    fseek(cover, 0, SEEK_END);
    long int coverSize = ftell(cover);
    rewind(cover);

    // get secret file size
    fseek(secret, 0, SEEK_END);
    long int secretSize = ftell(secret);
    rewind(secret);

    // check if secret file can fit within cover file
    if ((secretSize * 8) > coverSize) {
        printf("Error: Secret file size too large for cover file.\n");
        exit(1);
    }

    // generate a random seed
    srand((unsigned int) time(NULL));

    // get random starting position within cover image
    int startPos = rand() % coverSize;

    // set starting position within cover image
    fseek(cover, startPos, SEEK_SET);

    // write hidden message to output image
    int byteCounter = 0;
    char hiddenByte = 0;

    for (int i = 0; i < secretSize; i++) {
        char secretByte = fgetc(secret);

        for (int j = 0; j < 8; j++) {
            char coverByte = fgetc(cover);

            if (byteCounter >= startPos && byteCounter < (startPos + secretSize * 8)) {
                // encode secret bits using surreal algorithm
                if (secretByte & (1 << j)) {
                    hiddenByte |= (1 << (j % 4));
                    hiddenByte = ~hiddenByte;
                } else {
                    hiddenByte &= ~(1 << (j % 4));
                    hiddenByte = ~hiddenByte;
                }

                // write hidden byte to output image
                fputc(hiddenByte, output);
            } else {
                // write cover byte to output image
                fputc(coverByte, output);
            }

            byteCounter++;
        }
    }

    // copy remaining bytes from cover image to output image
    char tempByte;
    while ((tempByte = fgetc(cover)) != EOF) {
        fputc(tempByte, output);
    }

    // close files
    fclose(cover);
    fclose(secret);
    fclose(output);
}

int main() {
    // encode secret image within cover image
    surrealEncode("cover.jpg", "secret.png", "output.jpg");

    return 0;
}