//FormAI DATASET v1.0 Category: Image Steganography ; Style: careful
#include <stdio.h>
#include <stdlib.h>

/* Function prototype */
void hideMessageInImage(FILE* cover_image, FILE* stego_image, FILE* message_file);

int main(void) {
    /* File pointers */
    FILE *cover_image, *stego_image, *message_file;

    /* Open files for reading and writing */
    cover_image = fopen("cover_image.bmp", "rb");
    stego_image = fopen("stego_image.bmp", "wb");
    message_file = fopen("secret_message.txt", "rb");

    /* Check if files opened successfully */
    if (cover_image == NULL || stego_image == NULL || message_file == NULL) {
        puts("Error opening file. Exiting program.");
        exit(1);
    }

    /* Call function to hide message in image using LSB steganography */
    hideMessageInImage(cover_image, stego_image, message_file);

    /* Close files */
    fclose(cover_image);
    fclose(stego_image);
    fclose(message_file);

    return 0;
}

void hideMessageInImage(FILE* cover_image, FILE* stego_image, FILE* message_file) {
    unsigned char byte, bit, message_bit;
    int i, j, message_length, byte_count = 0, bit_count = 0;

    /* Extract header info from cover image */
    /* ... */

    /* Get secret message from file */
    fseek(message_file, 0, SEEK_END);
    message_length = ftell(message_file);
    rewind(message_file);

    /* Write header info to stego image */
    /* ... */

    /* Hide message in LSB of image bytes */
    while (fread(&byte, sizeof(unsigned char), 1, cover_image) == 1) {
        /* Get next bit of message */
        if (bit_count < message_length * 8) {
            fseek(message_file, byte_count / 8, SEEK_SET);
            fread(&message_bit, sizeof(unsigned char), 1, message_file);
            message_bit = (message_bit >> (7 - (byte_count % 8))) & 1;
        } else {
            /* If all message bits have been hidden, finish hiding process by writing rest of cover image bytes to stego image */
            fseek(cover_image, -1, SEEK_CUR);
            while (fread(&byte, sizeof(unsigned char), 1, cover_image) == 1) {
                fwrite(&byte, sizeof(unsigned char), 1, stego_image);
            }
            break;
        }

        /* Modify LSB of byte to hide message bit */
        byte = (byte & 0xFE) | message_bit;

        /* Write modified byte to stego image */
        fwrite(&byte, sizeof(unsigned char), 1, stego_image);

        /* Keep track of number of bytes and bits used in hiding process */
        byte_count++;
        bit_count++;
    }
}