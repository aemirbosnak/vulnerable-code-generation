//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Hidden secrets
#define MAGIC_NUMBER 0x1234ABCD
#define SECRET_KEY "Abracadabra"

// Mysterious image format
typedef struct {
    int magic;
    int width, height;
    unsigned char *data;
} Image;

// Encrypted image container
typedef struct {
    unsigned char *data;
    size_t size;
} EncryptedImage;

// The enigmatic image editor
Image *edit_image(EncryptedImage *encrypted, const char *key) {
    if (encrypted->size < sizeof(Image)) {
        fprintf(stderr, "Encrypted image too small\n");
        return NULL;
    }

    // Decipher the cipher
    unsigned char *decrypted = malloc(encrypted->size);
    for (size_t i = 0; i < encrypted->size; i++) {
        decrypted[i] = encrypted->data[i] ^ key[i % strlen(key)];
    }

    // Reveal the hidden image
    Image *image = (Image *) decrypted;
    if (image->magic != MAGIC_NUMBER) {
        fprintf(stderr, "Invalid image format\n");
        free(decrypted);
        return NULL;
    }

    // Modify the image data
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int index = y * image->width + x;
            image->data[index] = (image->data[index] + 32) % 256;
        }
    }

    return image;
}

// The enigmatic image saver
void save_image(EncryptedImage *encrypted, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file for writing\n");
        return;
    }

    fwrite(encrypted->data, encrypted->size, 1, fp);
    fclose(fp);
}

// Unveiling the enigma
int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <encrypted_image> <key> <output_image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load the encrypted image
    EncryptedImage encrypted;
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open encrypted image file\n");
        return EXIT_FAILURE;
    }

    fseek(fp, 0, SEEK_END);
    encrypted.size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    encrypted.data = malloc(encrypted.size);
    if (fread(encrypted.data, encrypted.size, 1, fp) != 1) {
        fprintf(stderr, "Failed to read encrypted image file\n");
        free(encrypted.data);
        fclose(fp);
        return EXIT_FAILURE;
    }

    fclose(fp);

    // Decipher and edit the image
    Image *image = edit_image(&encrypted, argv[2]);
    if (image == NULL) {
        fprintf(stderr, "Failed to edit image\n");
        free(encrypted.data);
        return EXIT_FAILURE;
    }

    // Save the edited image
    save_image(&encrypted, argv[3]);
    printf("Image edited and saved to %s\n", argv[3]);

    // Free the memory
    free(encrypted.data);
    free(image);
    return EXIT_SUCCESS;
}