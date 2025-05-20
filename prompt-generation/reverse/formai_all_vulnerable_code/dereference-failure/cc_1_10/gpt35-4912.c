//FormAI DATASET v1.0 Category: Image Steganography ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void hide_bit_in_byte(unsigned char *b, unsigned char bit) {
    *b = (*b & 0xFE) | (bit & 0x01);
}

unsigned char extract_bit_from_byte(unsigned char b) {
    return b & 0x01;
}

int get_file_size(FILE *fp) {
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    return size;
}

void encode_message(FILE *cover_file, FILE *output_file, char *message) {
    // Determine how many bytes of data we need to encode the message
    int message_length = 0;
    for (int i = 0; message[i] != '\0'; i++) {
        message_length++;
    }
    int data_length = (int) ceil((float) message_length / 8.0);

    // Write the message length to the output file
    fwrite(&message_length, sizeof(int), 1, output_file);

    // Pre-compute how many bytes of cover data we'll need to read
    int cover_size = get_file_size(cover_file);
    int required_cover_size = (int) ceil((float) data_length / 3.0);
    if (cover_size < required_cover_size) {
        printf("ERROR: Cover file is not big enough to encode message\n");
        exit(1);
    }

    // Begin writing encoded data to output file
    unsigned char r, g, b, bit;
    int cover_count = 0, bit_count = 0;
    while (bit_count < data_length * 8) {
        // Read the next pixel from the cover file
        fread(&r, sizeof(unsigned char), 1, cover_file);
        fread(&g, sizeof(unsigned char), 1, cover_file);
        fread(&b, sizeof(unsigned char), 1, cover_file);
        cover_count += 3;

        // Get the next bit to encode
        if (bit_count < message_length * 8) {
            int char_index = (int) floor((float) bit_count / 8.0);
            int bit_index = bit_count % 8;
            bit = (message[char_index] >> (7 - bit_index)) & 0x01;
            bit_count++;
        } else {
            bit = 0;
        }

        // Encode the next bit in the pixel data
        hide_bit_in_byte(&r, bit);
        hide_bit_in_byte(&g, bit);
        hide_bit_in_byte(&b, bit);
        fwrite(&r, sizeof(unsigned char), 1, output_file);
        fwrite(&g, sizeof(unsigned char), 1, output_file);
        fwrite(&b, sizeof(unsigned char), 1, output_file);
    }

    // Copy remaining cover data to output file
    unsigned char buffer;
    while (cover_count < cover_size) {
        fread(&buffer, sizeof(unsigned char), 1, cover_file);
        fwrite(&buffer, sizeof(unsigned char), 1, output_file);
        cover_count++;
    }
}

char *decode_message(FILE *stego_file) {
    // Read the message length from the stego file
    int message_length;
    fread(&message_length, sizeof(int), 1, stego_file);

    // Allocate space for the message
    char *message = (char *) malloc(sizeof(char) * (message_length + 1));
    message[message_length] = '\0';

    // Extract each bit of the message from the stego file
    unsigned char r, g, b, bit;
    int bit_count = 0;
    while (bit_count < message_length * 8) {
        // Read the next pixel from the stego file
        fread(&r, sizeof(unsigned char), 1, stego_file);
        fread(&g, sizeof(unsigned char), 1, stego_file);
        fread(&b, sizeof(unsigned char), 1, stego_file);

        // Extract the encoded bit from the pixel data
        bit = extract_bit_from_byte(r);
        message[bit_count / 8] |= bit << (7 - (bit_count % 8));
        bit_count++;

        if (bit_count < message_length * 8) {
            bit = extract_bit_from_byte(g);
            message[bit_count / 8] |= bit << (7 - (bit_count % 8));
            bit_count++;
        }

        if (bit_count < message_length * 8) {
            bit = extract_bit_from_byte(b);
            message[bit_count / 8] |= bit << (7 - (bit_count % 8));
            bit_count++;
        }
    }

    return message;
}

int main() {
    // Open the cover and output files
    FILE *cover_file = fopen("cover.bmp", "rb");
    FILE *output_file = fopen("stego.bmp", "wb");

    // Check that the files opened successfully
    if (cover_file == NULL || output_file == NULL) {
        printf("ERROR: Failed to open file\n");
        return 1;
    }

    // Encode a message in the cover file
    char message[] = "This is a secret message!";
    encode_message(cover_file, output_file, message);

    // Close the files
    fclose(cover_file);
    fclose(output_file);

    // Open the stego file and decode the hidden message
    FILE *stego_file = fopen("stego.bmp", "rb");

    // Check that the file opened successfully
    if (stego_file == NULL) {
        printf("ERROR: Failed to open file\n");
        return 1;
    }

    // Decode the message and print it to the console
    char *decoded_message = decode_message(stego_file);
    printf("Message: %s\n", decoded_message);

    // Free memory and close files
    free(decoded_message);
    fclose(stego_file);

    return 0;
}