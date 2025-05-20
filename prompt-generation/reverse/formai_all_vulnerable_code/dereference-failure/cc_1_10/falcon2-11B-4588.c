//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <openssl/sha.h>

#define BUFFER_SIZE 1024
#define PIXEL_SIZE 4

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <message> <destination_image>\n", argv[0]);
        return 1;
    }

    char *message = argv[1];
    char *destination_image = argv[2];

    if (encode_image(message, destination_image)!= 0) {
        printf("Failed to encode image.\n");
        return 1;
    }

    printf("Successfully encoded image.\n");
    return 0;
}

int encode_image(char *message, char *destination_image) {
    FILE *image_file = fopen(destination_image, "rb");
    if (image_file == NULL) {
        perror("fopen");
        return 1;
    }

    unsigned char buffer[BUFFER_SIZE];
    fread(buffer, 1, BUFFER_SIZE, image_file);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, message, strlen(message));
    SHA256_Final(hash, &ctx);

    unsigned char *pixels = (unsigned char *)malloc(BUFFER_SIZE * sizeof(unsigned char));
    for (int i = 0; i < BUFFER_SIZE; i++) {
        pixels[i] = 0;
    }

    unsigned int pixel_index = 0;
    unsigned char *pixel = pixels;
    while (fread(buffer, 1, BUFFER_SIZE, image_file) == BUFFER_SIZE) {
        for (int j = 0; j < BUFFER_SIZE; j++) {
            unsigned char b = buffer[j];
            b &= 0xF0;
            b |= (hash[pixel_index] & 0xF);
            pixel[pixel_index++] = b;
        }
    }

    fwrite(pixels, 1, BUFFER_SIZE * PIXEL_SIZE, image_file);

    free(pixels);
    fclose(image_file);
    return 0;
}