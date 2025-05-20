//FormAI DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* secret_message = "This is a secret message!";
    char* image_filename = "image.bmp";
    char* encoded_image_filename = "encoded_image.bmp";

    FILE *image_file = fopen(image_filename, "rb");
    FILE *encoded_image_file = fopen(encoded_image_filename, "wb");

    if (image_file == NULL || encoded_image_file == NULL) {
        printf("Error opening file(s)!\n");
        return 1;
    }

    // Hide secret message in the pixel values of the image
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image_file);
    fwrite(header, sizeof(unsigned char), 54, encoded_image_file);

    unsigned char pixel[3];
    int i = 0, j = 0, k = 0;
    while (fread(pixel, sizeof(unsigned char), 3, image_file) == 3) {
        if (i < strlen(secret_message)) {
            // Get the binary value of the ASCII code of the secret message character
            char secret_char = secret_message[i];
            unsigned char secret_char_bin[8];
            int n = 7;
            while (secret_char > 0) {
                secret_char_bin[n] = secret_char % 2;
                secret_char = secret_char / 2;
                n--;
            }
            // Modify the least significant bit of each color value of the pixel to encode the secret message
            pixel[k] = (pixel[k] & 0xfe) | secret_char_bin[j];
            j++;
            if (j == 8) {
                j = 0;
                k++;
                if (k == 3) {
                    k = 0;
                    i++;
                }
            }
        }
        fwrite(pixel, sizeof(unsigned char), 3, encoded_image_file);
    }

    fclose(image_file);
    fclose(encoded_image_file);
    printf("Steganography succeeded!\n");
    return 0;
}