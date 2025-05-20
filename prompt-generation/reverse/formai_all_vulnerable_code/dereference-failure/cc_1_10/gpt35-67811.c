//FormAI DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

char *text_to_binary(char *text);

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Usage: %s <input image> <output image> <secret message>\n", argv[0]);
        exit(1);
    }

    char *input_file_path = argv[1];
    char *output_file_path = argv[2];
    char *secret_message = argv[3];

    // Load input image
    FILE *input_file = fopen(input_file_path, "rb");
    if (!input_file) {
        printf("Error: Could not open file %s\n", input_file_path);
        exit(1);
    }

    unsigned char buffer[MAX_LEN];
    fread(buffer, 1, MAX_LEN, input_file);
    fclose(input_file);

    // Convert text message to binary
    char *binary_message = text_to_binary(secret_message);

    int message_length = strlen(binary_message);
    if (message_length * 8 > MAX_LEN) {
        printf("Error: Message is too long to hide in the image.\n");
        exit(1);
    }

    // Write binary message to least significant bit of each byte in the image buffer
    int byte_index = 0;
    for (int i = 0; i < message_length; i++) {
        for (int j = 0; j < 8; j++) {
            if (byte_index >= MAX_LEN) {
                break;
            }

            buffer[byte_index] &= ~1;
            buffer[byte_index] |= (binary_message[i] >> j) & 1;
            byte_index++;
        }
    }

    // Save the modified image
    FILE *output_file = fopen(output_file_path, "wb");
    if (!output_file) {
        printf("Error: Could not create file %s\n", output_file_path);
        exit(1);
    }

    fwrite(buffer, 1, MAX_LEN, output_file);
    fclose(output_file);

    printf("Message hidden successfully in %s\n", output_file_path);
    return 0;
}

char *text_to_binary(char *text) {
    int text_length = strlen(text);
    char *binary_message = (char *) malloc(text_length * 8 + 1);
    binary_message[text_length * 8] = '\0';

    for (int i = 0; i < text_length; i++) {
        char c = text[i];
        for (int j = 0; j < 8; j++) {
            binary_message[i * 8 + j] = ((c >> j) & 1) ? '1' : '0';
        }
    }

    return binary_message;
}