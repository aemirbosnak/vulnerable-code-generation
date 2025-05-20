//FormAI DATASET v1.0 Category: Image Steganography ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define HEADER_SIZE 54

// Function to hide message within image
void hide_message(unsigned char *image_data, char *message) {
    int i, j, k = 0;
    unsigned char byte;
    int message_len = strlen(message);

    for (i = HEADER_SIZE; i < HEADER_SIZE + message_len * 8; i += 8) {
        byte = message[k];

        for (j = 0; j < 8; ++j) {
            if (byte & (1 << j)) {
                image_data[i+j] |= 1;
            } else {
                image_data[i+j] &= ~1;
            }
        }

        ++k;
    }
}

// Function to extract hidden message from image
void extract_message(unsigned char *image_data, int image_size, int message_len) {
    int i, j, k = 0;
    unsigned char byte;

    for (i = HEADER_SIZE; i < HEADER_SIZE + message_len * 8; i += 8) {
        byte = 0;

        for (j = 0; j < 8; ++j) {
            if (image_data[i+j] & 1) {
                byte |= 1 << j;
            }
        }

        printf("%c", byte);

        // Stop if we encounter null character, indicating end of message
        if (byte == 0) {
            break;
        }

        ++k;
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    FILE *in_file;
    char *message;
    int message_len;
    unsigned char *image_data;
    int image_size;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s [-hide/-extract] [input_image.bmp] [message]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    in_file = fopen(argv[2], "rb");

    if (in_file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    // Calculate size of image
    fseek(in_file, 0, SEEK_END);
    image_size = ftell(in_file);
    fseek(in_file, 0, SEEK_SET);

    // Allocate memory for image data
    image_data = (unsigned char*) malloc(image_size);
    if (image_data == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for image data\n");
        exit(EXIT_FAILURE);
    }

    // Read image data from file
    fread(image_data, sizeof(unsigned char), image_size, in_file);
    fclose(in_file);

    // Check if hiding message or extracting message
    if (strcmp(argv[1], "-hide") == 0) {
        message = argv[3];
        message_len = strlen(message);

        // Check if message is too long to encode
        if ((HEADER_SIZE + message_len * 8) > image_size) {
            fprintf(stderr, "Error: Message too long to encode in image\n");
            exit(EXIT_FAILURE);
        }

        // Hide message in image
        hide_message(image_data, message);

        // Write image data to file
        in_file = fopen(argv[2], "wb");
        
        if (in_file == NULL) {
            fprintf(stderr, "Error: Unable to open file %s for writing\n", argv[2]);
            exit(EXIT_FAILURE);
        }

        fwrite(image_data, sizeof(unsigned char), image_size, in_file);
        fclose(in_file);

        printf("Message successfully hidden in image\n");
    } else if (strcmp(argv[1], "-extract") == 0) {
        // Calculate length of hidden message
        message_len = (image_size - HEADER_SIZE) / 8;

        // Extract hidden message from image
        extract_message(image_data, image_size, message_len);
    } else {
        fprintf(stderr, "Error: Invalid option specified\n");
        exit(EXIT_FAILURE);
    }

    // Free allocated memory
    free(image_data);

    return 0;
}