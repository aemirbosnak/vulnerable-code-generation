//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH 100

void stegano(char* secret_message, char* image_file_name, char* output_file_name) {
    FILE* input_file = fopen(image_file_name, "rb");
    FILE* output_file = fopen(output_file_name, "wb");

    if (input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Error opening files.\n");
        return;
    }

    char buffer[256];
    int message_length;
    int num_bytes_read = fread(buffer, 1, sizeof(buffer), input_file);

    message_length = strlen(secret_message);
    if (message_length > MAX_MESSAGE_LENGTH) {
        fprintf(stderr, "Message is too long.\n");
        return;
    }

    int num_bits_in_byte = 8;
    int num_bytes_in_message = message_length / num_bits_in_byte;
    int num_bytes_left = message_length % num_bits_in_byte;

    for (int i = 0; i < num_bytes_in_message; i++) {
        int bit_position = (i * num_bits_in_byte) - 1;
        int byte_index = i * num_bits_in_byte;

        int bit_value = (secret_message[i] - '0') * 2;

        int byte_value = buffer[byte_index];
        byte_value ^= bit_value;

        fwrite(&byte_value, 1, sizeof(byte_value), output_file);
    }

    if (num_bytes_left > 0) {
        int byte_index = (num_bytes_in_message + 1) * num_bits_in_byte;
        int bit_position = (num_bytes_in_message + 1) * num_bits_in_byte - 1;

        int bit_value = (secret_message[num_bytes_in_message] - '0') * 2;

        int byte_value = buffer[byte_index];
        byte_value ^= bit_value;

        fwrite(&byte_value, 1, sizeof(byte_value), output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <image_file> <secret_message> <output_file>\n", argv[0]);
        return 1;
    }

    char* image_file_name = argv[1];
    char* secret_message = argv[2];
    char* output_file_name = argv[3];

    stegano(secret_message, image_file_name, output_file_name);

    return 0;
}