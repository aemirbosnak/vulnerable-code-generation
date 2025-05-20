//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char* data;
    unsigned int len;
} StegoData;

int main() {
    // Create a new stego data
    StegoData* stego = (StegoData*)malloc(sizeof(StegoData));
    stego->len = 0;

    // Read the secret message
    char secret[100];
    printf("Enter the secret message: ");
    fgets(secret, sizeof(secret), stdin);

    // Convert the secret message to binary
    unsigned char* bin = (unsigned char*)malloc(strlen(secret) + 1);
    for (int i = 0; i < strlen(secret); i++) {
        bin[i] = secret[i];
    }

    // Hide the secret message in an image
    unsigned char* image = (unsigned char*)malloc(10000);
    int* hidden = (int*)malloc(10000);
    int index = 0;
    for (int i = 0; i < 10000; i++) {
        int value = (int)image[i];
        value += bin[index++];
        if (value > 255) {
            value = 255;
        }
        hidden[i] = value;
    }

    // Convert the hidden message back to binary
    unsigned char* hidden_bin = (unsigned char*)malloc(10000);
    for (int i = 0; i < 10000; i++) {
        int value = hidden[i];
        hidden_bin[i] = value & 0xff;
    }

    // Convert the hidden message back to a string
    char* hidden_str = (char*)malloc(10000);
    for (int i = 0; i < 10000; i++) {
        hidden_str[i] = (char)hidden_bin[i];
    }

    // Print the hidden message
    printf("Hidden message: %s\n", hidden_str);

    // Free memory
    free(bin);
    free(hidden_bin);
    free(hidden_str);
    free(image);
    free(stego);

    return 0;
}