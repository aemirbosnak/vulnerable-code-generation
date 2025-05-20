//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_FILE_SIZE 1024 * 1024
#define MAX_MESSAGE_SIZE 1024
#define LSB_MASK 0x01

void hide_message(char *image_file, char *message);
void extract_message(char *image_file);
void print_usage(void);

int main(int argc, char **argv)
{
    if (argc != 3) {
        print_usage();
        return 1;
    }

    if (strcmp(argv[1], "-h") == 0) {
        print_usage();
        return 0;
    } else if (strcmp(argv[1], "-e") == 0) {
        hide_message(argv[2], argv[3]);
    } else if (strcmp(argv[1], "-d") == 0) {
        extract_message(argv[2]);
    } else {
        print_usage();
        return 1;
    }

    return 0;
}

void hide_message(char *image_file, char *message)
{
    FILE *image_fp = fopen(image_file, "rb+");
    if (image_fp == NULL) {
        fprintf(stderr, "Error opening image file: %s\n", image_file);
        return;
    }

    // Check if the message is too large to hide in the image
    if (strlen(message) > MAX_MESSAGE_SIZE) {
        fprintf(stderr, "Error: Message is too large to hide in image\n");
        fclose(image_fp);
        return;
    }

    // Get the file size
    fseek(image_fp, 0, SEEK_END);
    uint64_t file_size = ftell(image_fp);
    rewind(image_fp);

    // Check if the image is large enough to hide the message
    if (file_size < MAX_FILE_SIZE) {
        fprintf(stderr, "Error: Image is too small to hide message\n");
        fclose(image_fp);
        return;
    }

    // Hide the message in the image
    uint8_t *image_data = malloc(file_size);
    fread(image_data, 1, file_size, image_fp);

    for (int i = 0; i < strlen(message); i++) {
        uint8_t byte = message[i];
        for (int j = 0; j < 8; j++) {
            uint8_t bit = (byte >> j) & LSB_MASK;
            image_data[i * 8 + j] &= ~LSB_MASK;
            image_data[i * 8 + j] |= bit;
        }
    }

    // Write the modified image data back to the file
    fseek(image_fp, 0, SEEK_SET);
    fwrite(image_data, 1, file_size, image_fp);
    fclose(image_fp);

    free(image_data);
}

void extract_message(char *image_file)
{
    FILE *image_fp = fopen(image_file, "rb");
    if (image_fp == NULL) {
        fprintf(stderr, "Error opening image file: %s\n", image_file);
        return;
    }

    // Get the file size
    fseek(image_fp, 0, SEEK_END);
    uint64_t file_size = ftell(image_fp);
    rewind(image_fp);

    // Extract the message from the image
    uint8_t *image_data = malloc(file_size);
    fread(image_data, 1, file_size, image_fp);

    char *message = malloc(MAX_MESSAGE_SIZE + 1);
    for (int i = 0; i < MAX_MESSAGE_SIZE; i++) {
        uint8_t byte = 0;
        for (int j = 0; j < 8; j++) {
            byte <<= 1;
            byte |= image_data[i * 8 + j] & LSB_MASK;
        }
        message[i] = byte;
        if (message[i] == '\0') {
            break;
        }
    }

    // Print the message
    printf("%s\n", message);

    free(image_data);
    free(message);
    fclose(image_fp);
}

void print_usage(void)
{
    printf("Usage: image_steganography [-h] [-e image_file message] [-d image_file]\n");
    printf("Options:\n");
    printf("  -h  Print this help message and exit\n");
    printf("  -e  Hide a message in an image file\n");
    printf("  -d  Extract a message from an image file\n");
}