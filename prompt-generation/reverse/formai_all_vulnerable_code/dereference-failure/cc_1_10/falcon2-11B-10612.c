//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to encrypt the image
void encrypt(char* imgName, char* key, char* output) {
    // read the image
    FILE *file = fopen(imgName, "rb");
    if (file == NULL) {
        printf("Error opening image file.\n");
        return;
    }

    // read the image into a buffer
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    char* buf = malloc(size);
    fread(buf, size, 1, file);
    fclose(file);

    // encrypt the buffer
    for (int i = 0; i < size; i++) {
        buf[i] ^= key[i % strlen(key)];
    }

    // write the encrypted buffer to the output file
    file = fopen(output, "wb");
    if (file == NULL) {
        printf("Error opening output file.\n");
        return;
    }
    fwrite(buf, size, 1, file);
    fclose(file);

    // free the buffer
    free(buf);
}

// function to decrypt the image
void decrypt(char* imgName, char* key, char* output) {
    // read the image
    FILE *file = fopen(imgName, "rb");
    if (file == NULL) {
        printf("Error opening image file.\n");
        return;
    }

    // read the image into a buffer
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    char* buf = malloc(size);
    fread(buf, size, 1, file);
    fclose(file);

    // decrypt the buffer
    for (int i = 0; i < size; i++) {
        buf[i] ^= key[i % strlen(key)];
    }

    // write the decrypted buffer to the output file
    file = fopen(output, "wb");
    if (file == NULL) {
        printf("Error opening output file.\n");
        return;
    }
    fwrite(buf, size, 1, file);
    fclose(file);

    // free the buffer
    free(buf);
}

int main() {
    char* imgName = "image.png";
    char* key = "secret";
    char* outputEnc = "encrypted.png";
    char* outputDec = "decrypted.png";

    encrypt(imgName, key, outputEnc);
    decrypt(outputEnc, key, outputDec);

    printf("Image encrypted and decrypted successfully.\n");

    return 0;
}