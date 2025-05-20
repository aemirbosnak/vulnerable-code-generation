//FormAI DATASET v1.0 Category: Image Steganography ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10000  // maximum size of the input file
#define BYTE_SIZE 8     // each byte contains 8 bits

// function to get the file size
long get_file_size(FILE* file) {
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}

// function to read the input file
char* read_file(char* filename, long* size) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open %s\n", filename);
        exit(1);
    }

    long file_size = get_file_size(file);
    char* buffer = (char*) malloc(file_size);
    size_t bytes_read = fread(buffer, 1, file_size, file);
    fclose(file);

    if (bytes_read != file_size) {
        printf("Error: Could not read %s\n", filename);
        free(buffer);
        exit(1);
    }

    *size = file_size;
    return buffer;
}

// function to write the output file
void write_file(char* filename, char* buffer, long size) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Could not open %s\n", filename);
        exit(1);
    }

    size_t bytes_written = fwrite(buffer, 1, size, file);
    fclose(file);

    if (bytes_written != size) {
        printf("Error: Could not write %s\n", filename);
        exit(1);
    }
}

// function to encode the message into the image
void encode(char* image_filename, char* message, char* output_filename) {
    long image_size;
    char* image_data = read_file(image_filename, &image_size);

    // Each character is encoded into a byte
    int message_len = strlen(message);
    int max_chars = (image_size - 54) / BYTE_SIZE;
    if (message_len > max_chars) {
        printf("Error: The message is too long to be encoded into this image.\n");
        free(image_data);
        exit(1);
    }

    // Set the message length in the first 4 bytes of the image
    int* message_len_ptr = (int*) (image_data + 54);
    *message_len_ptr = message_len;

    // Encode each character into a byte of the image starting from the 5th byte
    char* image_ptr = image_data + 58;
    int bit_pos = 0;
    for (int i = 0; i < message_len; i++) {
        char c = message[i];
        for (int j = 0; j < BYTE_SIZE; j++) {
            int bit = (c >> j) & 1;
            (*image_ptr) &= ~(1 << bit_pos);
            (*image_ptr) |= (bit << bit_pos);
            bit_pos++;
            if (bit_pos == BYTE_SIZE) {
                bit_pos = 0;
                image_ptr++;
            }
        }
    }

    write_file(output_filename, image_data, image_size);
    free(image_data);
}

// function to decode the message from the image
char* decode(char* image_filename) {
    long image_size;
    char* image_data = read_file(image_filename, &image_size);

    // Get the message length from the first 4 bytes of the image
    int* message_len_ptr = (int*) (image_data + 54);
    int message_len = *message_len_ptr;

    // Decode each byte of the message from the image starting from the 5th byte
    char* message = (char*) malloc(message_len + 1);
    char* message_ptr = message;
    char* image_ptr = image_data + 58;
    int bit_pos = 0;
    for (int i = 0; i < message_len; i++) {
        char c = 0;
        for (int j = 0; j < BYTE_SIZE; j++) {
            int bit = ((*image_ptr) >> bit_pos) & 1;
            c |= (bit << j);
            bit_pos++;
            if (bit_pos == BYTE_SIZE) {
                bit_pos = 0;
                image_ptr++;
            }
        }
        *message_ptr = c;
        message_ptr++;
    }
    *message_ptr = '\0';

    free(image_data);
    return message;
}

int main() {
    char image_filename[] = "image.bmp";
    char message[] = "Hello, world!";
    char output_filename[] = "output.bmp";
    
    // encode the message into the image
    encode(image_filename, message, output_filename);
    
    // decode the message from the image
    char* decoded_message = decode(output_filename);
    printf("Decoded message: %s\n", decoded_message);
    free(decoded_message);

    return 0;
}