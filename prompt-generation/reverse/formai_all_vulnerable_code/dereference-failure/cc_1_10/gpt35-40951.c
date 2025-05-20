//FormAI DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdio.h>
#include <stdlib.h>

/*
 * Function to get the nth bit in the given integer.
 * The numbering of bits starts from the rightmost bit, i.e. 0th bit.
 */
int get_bit(int num, int n) {
    return (num & (1 << n)) >> n;
}

/*
 * Function to set the nth bit in the given integer to the specified value.
 * The numbering of bits starts from the rightmost bit, i.e. 0th bit.
 */
void set_bit(int *num, int n, int value) {
    if (value == 0) {
        *num &= ~(1 << n);
    } else {
        *num |= (1 << n);
    }
}

/*
 * Function to embed the given message into the image.
 * Assumes that the message fits into the image.
 * Returns the modified image data.
 */
unsigned char* embed_message(unsigned char *image, int image_size,
                             unsigned char *message, int message_size) {
    // Embedding message size in the first two bytes of the image
    int message_bits = message_size * 8;
    image[0] = message_bits >> 8;
    image[1] = message_bits & 0xff;

    // Embedding the message bit by bit
    int i, j;
    for (i = 0; i < message_size; i++) {
        unsigned char byte = message[i];
        for (j = 0; j < 8; j++) {
            int image_byte_index = 2 + i * 8 + j;
            int image_bit_index = 7 - (image_byte_index % 8); // Message is embedded starting with the LSB of the first byte
            set_bit(&image[image_byte_index / 8], image_bit_index, get_bit(byte, j));
        }
    }

    return image;
}

/*
 * Function to extract the message from the image.
 * Assumes that the message size is embedded in the first two bytes of the image.
 * Returns the extracted message as a dynamic array.
 */
unsigned char* extract_message(unsigned char *image, int image_size, int *message_size) {
    // Extracting message size from the first two bytes of the image
    int message_bits = (image[0] << 8) | image[1];
    *message_size = message_bits / 8;

    // Extracting the message bit by bit
    unsigned char *message = (unsigned char*) malloc(*message_size);
    int i, j;
    for (i = 0; i < *message_size; i++) {
        unsigned char byte = 0;
        for (j = 0; j < 8; j++) {
            int image_byte_index = 2 + i * 8 + j;
            int image_bit_index = 7 - (image_byte_index % 8); // Message is embedded starting with the LSB of the first byte
            int bit = get_bit(image[image_byte_index / 8], image_bit_index);
            byte |= (bit << j);
        }
        message[i] = byte;
    }

    return message;
}

int main() {
    char *image_file = "image.bmp";
    char *message_file = "message.txt";

    // Reading image data from file
    FILE *fp = fopen(image_file, "rb");
    if (!fp) {
        printf("Unable to open image file '%s'\n", image_file);
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    int image_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    unsigned char *image = (unsigned char*) malloc(image_size);
    fread(image, 1, image_size, fp);
    fclose(fp);

    // Reading message data from file
    fp = fopen(message_file, "rb");
    if (!fp) {
        printf("Unable to open message file '%s'\n", message_file);
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    int message_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    unsigned char *message = (unsigned char*) malloc(message_size);
    fread(message, 1, message_size, fp);
    fclose(fp);

    // Embedding message into image
    unsigned char *modified_image = embed_message(image, image_size, message, message_size);
    free(image);
    free(message);

    // Writing modified image data to file
    fp = fopen("modified_image.bmp", "wb");
    if (!fp) {
        printf("Unable to create modified image file\n");
        return 1;
    }
    fwrite(modified_image, 1, image_size, fp);
    fclose(fp);
    free(modified_image);

    // Reading modified image data from file
    fp = fopen("modified_image.bmp", "rb");
    if (!fp) {
        printf("Unable to open modified image file\n");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    image_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    image = (unsigned char*) malloc(image_size);
    fread(image, 1, image_size, fp);
    fclose(fp);

    // Extracting message from image
    unsigned char *extracted_message = extract_message(image, image_size, &message_size);
    free(image);

    // Writing extracted message data to file
    fp = fopen("extracted_message.txt", "wb");
    if (!fp) {
        printf("Unable to create extracted message file\n");
        return 1;
    }
    fwrite(extracted_message, 1, message_size, fp);
    fclose(fp);
    free(extracted_message);

    return 0;
}