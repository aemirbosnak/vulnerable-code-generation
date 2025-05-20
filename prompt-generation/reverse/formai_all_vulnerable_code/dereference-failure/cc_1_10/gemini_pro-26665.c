//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 512

unsigned char *encode(unsigned char *image, unsigned char *secret, int size) {
    unsigned char *output = (unsigned char *)malloc(MAX_SIZE);
    int i = 0, j = 0;
    while (i < size) {
        output[i] = image[i] & 0xFE;
        output[i] |= secret[j] & 1;
        i++;
        j++;
    }
    return output;
}

unsigned char *decode(unsigned char *image, int size) {
    unsigned char *secret = (unsigned char *)malloc(size);
    int i = 0, j = 0;
    while (i < size) {
        secret[j] = image[i] & 1;
        i++;
        j++;
    }
    return secret;
}

int main() {
    unsigned char image[MAX_SIZE];
    unsigned char secret[MAX_SIZE];
    int size;

    FILE *fp1 = fopen("image.bmp", "rb");
    if (fp1 == NULL) {
        perror("Error opening image file");
        return -1;
    }
    fread(image, 1, MAX_SIZE, fp1);
    fclose(fp1);

    FILE *fp2 = fopen("secret.txt", "rb");
    if (fp2 == NULL) {
        perror("Error opening secret file");
        return -1;
    }
    size = fread(secret, 1, MAX_SIZE, fp2);
    fclose(fp2);

    unsigned char *encoded = encode(image, secret, size);

    FILE *fp3 = fopen("encoded.bmp", "wb");
    if (fp3 == NULL) {
        perror("Error opening encoded file");
        return -1;
    }
    fwrite(encoded, 1, MAX_SIZE, fp3);
    fclose(fp3);

    unsigned char *decoded = decode(encoded, size);

    FILE *fp4 = fopen("decoded.txt", "wb");
    if (fp4 == NULL) {
        perror("Error opening decoded file");
        return -1;
    }
    fwrite(decoded, 1, size, fp4);
    fclose(fp4);

    free(image);
    free(secret);
    free(encoded);
    free(decoded);

    return 0;
}