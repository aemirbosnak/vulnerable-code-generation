//FormAI DATASET v1.0 Category: Image Steganography ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

/**
 * Function to read the content of the file into the array
 */
int read_file(unsigned char *data, char *in_file) {
    FILE *fp = fopen(in_file, "rb");
    if (!fp) {
        printf("Error: File not found!\n");
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File size exceeded the limit!\n");
        fclose(fp);
        return -1;
    }

    fread(data, file_size, 1, fp);
    fclose(fp);

    return (int) file_size;
}

/**
 * Function to write the content of the array into the file
 */
int write_file(unsigned char *data, int size, char *out_file) {
    FILE *fp = fopen(out_file, "wb");
    if (!fp) {
        printf("Error: Unable to create the output file!\n");
        return -1;
    }

    fwrite(data, size, 1, fp);
    fclose(fp);

    return 0;
}

/**
 * Function to modify the least significant bit of a byte
 */
unsigned char modify_lsb(unsigned char byte, unsigned char bit) {
    return (byte & 0xFE) | (bit & 0x01);
}

/**
 * Function to extract the least significant bit of a byte
 */
unsigned char extract_lsb(unsigned char byte) {
    return byte & 0x01;
}

/**
 * Function to hide a message into the image using LSB steganography technique
 */
int hide_message(unsigned char *image, int size, unsigned char *message, int msg_size, char *out_file) {
    if (msg_size * 8 > size - 54) {
        printf("Error: Image size not sufficient to hold the message!\n");
        return -1;
    }

    // hide the message size into the first 4 bytes of the image
    for (int i = 0; i < 4; i++) {
        image[i] = modify_lsb(image[i], (msg_size >> i * 8) & 0xFF);
    }

    // hide the message into the remaining bytes of the image
    for (int i = 0; i < msg_size; i++) {
        for (int j = 0; j < 8; j++) {
            image[i * 8 + j + 54] = modify_lsb(image[i * 8 + j + 54], (message[i] >> j) & 0x01);
        }
    }

    write_file(image, size, out_file);

    return 0;
}

/**
 * Function to extract the message from the image using LSB steganography technique
 */
unsigned char *extract_message(unsigned char *image, int size, int *msg_size) {
    unsigned char *message;

    // extract the message size from the first 4 bytes of the image
    *msg_size = 0;
    for (int i = 0; i < 4; i++) {
        *msg_size |= extract_lsb(image[i]) << i * 8;
    }

    // allocate memory for the message
    message = (unsigned char *) malloc(*msg_size);

    // extract the message from the remaining bytes of the image
    for (int i = 0; i < *msg_size; i++) {
        message[i] = 0;
        for (int j = 0; j < 8; j++) {
            message[i] |= extract_lsb(image[i * 8 + j + 54]) << j;
        }
    }

    return message;
}

/**
 * The program main function
 */
int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Error: Not enough arguments!\n");
        printf("Usage: %s <input image> <output image> <message>\n", argv[0]);
        return -1;
    }

    // read the image into the array
    unsigned char *image = (unsigned char *) malloc(MAX_FILE_SIZE);
    int image_size = read_file(image, argv[1]);
    if (image_size == -1) {
        return -1;
    }

    // read the message into the array
    unsigned char *message = (unsigned char *) argv[3];
    int msg_size = strlen(message);

    // hide the message into the image
    if (hide_message(image, image_size, message, msg_size, argv[2]) == -1) {
        return -1;
    }

    printf("Message hidden successfully!\n");

    // extract the message from the image
    int extracted_msg_size = 0;
    unsigned char *extracted_msg = extract_message(image, image_size, &extracted_msg_size);
    printf("Extracted message: %s\n", extracted_msg);

    free(image);
    free(extracted_msg);

    return 0;
}