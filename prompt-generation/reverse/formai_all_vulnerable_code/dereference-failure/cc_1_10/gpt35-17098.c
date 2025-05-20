//FormAI DATASET v1.0 Category: Image Steganography ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [Input Image] [Message] [Output Image]\n", argv[0]);
        return 1;
    }

    char *input_path = argv[1];
    char *message = argv[2];
    char *output_path = argv[3];

    FILE *input_file = fopen(input_path, "rb");
    if (!input_file) {
        printf("Unable to open input file\n");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    unsigned char *input_data = (unsigned char *) malloc(input_file_size);
    fread(input_data, input_file_size, 1, input_file);
    fclose(input_file);

    FILE *output_file = fopen(output_path, "wb");
    if (!output_file) {
        printf("Unable to open output file\n");
        return 1;
    }

    long message_len = strlen(message);

    if (message_len > input_file_size / 8) { // The message is too long to hide in the image
        printf("The message is too long to hide in the image\n");
        return 1;
    }

    int bit_offset = 0; // The current bit we're encoding
    int byte_offset = 0; // The byte we're currently writing to in the image

    for (int i = 0; i < message_len; i++) {
        char c = message[i];
        for (int j = 0; j < 8; j++) {
            if (c & (1 << j)) { // if the current bit is set
                input_data[byte_offset] |= (1 << bit_offset);
            } else { // if the current bit is not set
                input_data[byte_offset] &= ~(1 << bit_offset);
            }

            bit_offset++;
            if (bit_offset == 8) {
                bit_offset = 0;
                byte_offset++;
                if (byte_offset >= input_file_size) {
                    goto END_OUTER_LOOP;
                }
            }
        }
    }
    END_OUTER_LOOP:

    fwrite(input_data, input_file_size, 1, output_file);
    fclose(output_file);

    printf("Message hidden successfully!\n");

    free(input_data);

    return 0;
}