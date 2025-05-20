//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMG_SIZE 10000

typedef struct {
    char* original_img;
    char* encoded_img;
} Image;

int main() {
    // Load original image
    Image* image = (Image*)malloc(sizeof(Image));
    image->original_img = (char*)malloc(MAX_IMG_SIZE);
    image->encoded_img = (char*)malloc(MAX_IMG_SIZE);

    char* file_name = "original_image.jpg";
    FILE* fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return 1;
    }

    fread(image->original_img, 1, MAX_IMG_SIZE, fp);
    fclose(fp);

    // Encode image with secret message
    char secret_msg[] = "This is a secret message.";
    int msg_len = strlen(secret_msg);
    char* encoded_msg = (char*)malloc(msg_len);
    for (int i = 0; i < msg_len; i++) {
        int index = (int)floor(i / 8);
        int value = (int)secret_msg[i] - 'A';
        encoded_msg[i] = (char)((image->original_img[index] & 0xFF) | (value << 8));
    }

    // Replace some pixels with encoded message
    int encoded_img_size = strlen(encoded_msg);
    for (int i = 0; i < encoded_img_size; i++) {
        int index = (int)floor(i / 8);
        image->encoded_img[index] = encoded_msg[i];
    }

    // Write encoded image to file
    FILE* fp_encoded = fopen("encoded_image.jpg", "wb");
    if (fp_encoded == NULL) {
        printf("Error: Could not open file %s\n", "encoded_image.jpg");
        return 1;
    }

    fwrite(image->encoded_img, 1, MAX_IMG_SIZE, fp_encoded);
    fclose(fp_encoded);

    // Free memory
    free(image->original_img);
    free(image->encoded_img);
    free(encoded_msg);

    printf("Steganography complete! Check the encoded image for the secret message.\n");

    return 0;
}