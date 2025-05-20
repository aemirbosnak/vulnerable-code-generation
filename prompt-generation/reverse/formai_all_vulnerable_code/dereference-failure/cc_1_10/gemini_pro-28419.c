//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Cyberpunk
// Cyberpunk Digital Watermarking

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Neon-hued color palette
enum neon { CYBER_BLUE, TECH_GREEN, RADIANT_VIOLET, PULSATING_AMBER };

// Cyberpunk-inspired image manipulation functions
void Encrypt(char *img, char *watermark, int enckey);
void Decrypt(char *img, char *watermark, int enckey);

// Entry point to the neon-lit world of digital watermarking
int main(int argc, char **argv) {
    // Verify command line parameters
    if (argc < 4) {
        printf("Usage: %s <image> <watermark> <encryption_key>\n", argv[0]);
        return 1;
    }

    // Initialize variables
    char *img = argv[1];
    char *watermark = argv[2];
    int enckey = atoi(argv[3]);

    // Read the image into memory
    FILE *fp = fopen(img, "rb");
    if (!fp) {
        printf("Error: Unable to open image file %s\n", img);
        return 1;
    }
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    char *image = (char *)malloc(size + 1);
    fread(image, 1, size, fp);
    fclose(fp);

    // Inject the watermark into the image using a cyberpunk encryption key
    Encrypt(image, watermark, enckey);
    printf("[*] Watermark embedded into %s with key %d\n", img, enckey);

    // Retrieve the watermark from the image
    char *decrypted = (char *)malloc(strlen(watermark) + 1);
    Decrypt(image, decrypted, enckey);
    printf("[*] Watermark extracted: %s\n", decrypted);

    // Free allocated memory
    free(image);
    free(decrypted);

    return 0;
}

// Encode watermark into image using bitwise operations
void Encrypt(char *img, char *watermark, int enckey) {
    int imglen = strlen(img);
    int wmlen = strlen(watermark);

    for (int i = 0; i < imglen; i++) {
        int mask = enckey & 0xFF;
        img[i] = (img[i] & ~mask) | ((watermark[i % wmlen] & mask) << 8);
        enckey = (enckey << 1) | (enckey >> 31);  // Shift and rotate encryption key
    }
}

// Decode watermark from image using bitwise operations
void Decrypt(char *img, char *watermark, int enckey) {
    int imglen = strlen(img);
    int wmlen = strlen(watermark);

    for (int i = 0; i < imglen; i++) {
        int mask = enckey & 0xFF;
        watermark[i % wmlen] = (img[i] >> 8) & mask;
        enckey = (enckey << 1) | (enckey >> 31);  // Shift and rotate encryption key
    }
}