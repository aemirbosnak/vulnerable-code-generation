//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BINARY_FILE "input.bin"
#define CHAR_PER_LINE 16

void convert_binary_to_text(FILE *binary_file, char *output_text_file) {
    unsigned char byte;
    int bit_index = 0;
    char text_char = ' ';

    fprintf(output_text_file, "Oh no! The Binary Chuck Norris Terminator is here to convert your binary file to text!\n");
    fprintf(output_text_file, "Do not try to resist, or else the Binary Chuck Norris Terminator will roundhouse kick your computer!\n");

    while ((byte = fgetc(binary_file)) != EOF) {
        for (int i = 0; i < 8; i++) {
            if ((byte >> i) & 0x01) {
                text_char |= (1 << bit_index);
                bit_index++;
                if (bit_index >= CHAR_PER_LINE) {
                    fprintf(output_text_file, "%c", text_char);
                    text_char = ' ';
                    bit_index = 0;
                }
            }
        }
    }

    if (bit_index > 0) {
        fprintf(output_text_file, "%c", text_char);
    }

    fprintf(output_text_file, "\nBinary file conversion complete! Run 'cat output_text_file.txt' to see the result.\n");
    fprintf(output_text_file, "Remember, the Binary Chuck Norris Terminator is always watching...\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <binary_file>\n", argv[0]);
        return 1;
    }

    FILE *binary_file = fopen(BINARY_FILE, "rb");
    if (binary_file == NULL) {
        perror("Error opening binary file");
        return 1;
    }

    char *output_text_file = malloc(strlen(argv[1]) + 10);
    strcpy(output_text_file, "output_text_file.txt");

    convert_binary_to_text(binary_file, fopen(output_text_file, "w"));

    fclose(binary_file);
    free(output_text_file);

    printf("The Binary Chuck Norris Terminator has finished converting the binary file '%s' to text.\n", argv[1]);

    return 0;
}