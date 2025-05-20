//FormAI DATASET v1.0 Category: Image Steganography ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 512

int main(int argc, char *argv[])
{
    if (argc < 4) {
        printf("Usage: %s <input_file> <output_file> <message>\n", argv[0]);
        exit(1);
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];
    char *message = argv[3];

    // Read the input file
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        printf("Could not open file: %s\n", input_filename);
        exit(1);
    }

    fseek(input_file, 0, SEEK_END);
    int input_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    unsigned char *input_buffer = (unsigned char *) malloc(input_size);
    fread(input_buffer, 1, input_size, input_file);

    fclose(input_file);

    // Embed the message in the image
    for (int i = 0; i < strlen(message); i++) {
        unsigned char byte = message[i];
        for (int j = 0; j < 8; j++) {
            int bit = (byte >> (7 - j)) & 1;
            input_buffer[i*8+j] = (input_buffer[i*8+j] & ~1) | bit;
        }
    }

    // Write the final image to the output file
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Could not create file: %s\n", output_filename);
        exit(1);
    }

    fwrite(input_buffer, 1, input_size, output_file);
    fclose(output_file);

    printf("Message embedded in image successfully!\n");

    free(input_buffer);

    return 0;
}