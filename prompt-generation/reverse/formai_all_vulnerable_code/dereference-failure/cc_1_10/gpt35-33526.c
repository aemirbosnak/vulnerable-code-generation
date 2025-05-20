//FormAI DATASET v1.0 Category: Image Steganography ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define READ_BYTE(fp, ch) { fread(&ch, sizeof(unsigned char), 1, fp); }
#define WRITE_BYTE(fp, ch) { fwrite(&ch, sizeof(unsigned char), 1, fp); }

// Returns the number of bits in a file
size_t filesize(FILE *fp) {
    size_t size = 0;
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    rewind(fp);
    return (size * 8);
}

// Hides a message in a file
void encode_file(const char *filename, const char *message) {
    FILE *input = fopen(filename, "rb");
    FILE *output = fopen("encoded_file.txt", "wb");

    if (input == NULL) {
        fprintf(stderr, "Input file %s not found\n", filename);
        exit(1);
    }

    if (output == NULL) {
        fprintf(stderr, "Output file cannot be created\n");
        exit(1);
    }

    size_t message_size = strlen(message);
    size_t bits_used = 0;
    unsigned char ch;
    char curr_bit, new_ch;

    READ_BYTE(input, ch);

    // Keep hiding bits until message is fully hidden
    for (size_t i = 0; i < message_size; ++i) {
        for (size_t j = 7; j < 8; --j) {
            if (bits_used == filesize(input)) {
                WRITE_BYTE(output, ch);
                fclose(input);
                fclose(output);
                printf("Message hidden successfully!\n");
                exit(0);
            }

            READ_BYTE(input, ch);
            curr_bit = ((message[i] >> j) & 1) ? '1' : '0';
            new_ch = (ch & 0xFE) | (curr_bit - '0');
            WRITE_BYTE(output, new_ch);

            bits_used++;
            ch = new_ch;
        }
    }

    // Finish writing the input file
    while (!feof(input)) {
        READ_BYTE(input, ch);
        WRITE_BYTE(output, ch);
    }

    fclose(input);
    fclose(output);
    printf("Message hidden successfully!\n");
}

// Extracts a message from a file
void decode_file(const char *filename) {
    FILE *input = fopen(filename, "rb");

    if (input == NULL) {
        fprintf(stderr, "Input file %s not found\n", filename);
        exit(1);
    }

    unsigned char ch;
    char curr_bit;
    size_t bits_used = 0;

    // Read every byte in the file
    while (!feof(input)) {
        READ_BYTE(input, ch);

        // Read the last bit from every byte to construct the message
        for (size_t j = 7; j < 8; --j) {
            if (bits_used >= filesize(input)) {
                fclose(input);
                printf("\nMessage extracted successfully!\n");
                exit(0);
            }

            curr_bit = (ch & 1) ? '1' : '0';
            fwrite(&curr_bit, sizeof(char), 1, stdout);

            bits_used++;
            ch >>= 1;
        }
    }

    fclose(input);
    printf("\nMessage extracted successfully!\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-e/-d] <filename> [message]\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "-e") == 0 && argc == 4) {
        encode_file(argv[2], argv[3]);
    } else if (strcmp(argv[1], "-d") == 0 && argc == 3) {
        decode_file(argv[2]);
    } else {
        fprintf(stderr, "Usage: %s [-e/-d] <filename> [message]\n", argv[0]);
        exit(1);
    }

    return 0;
}