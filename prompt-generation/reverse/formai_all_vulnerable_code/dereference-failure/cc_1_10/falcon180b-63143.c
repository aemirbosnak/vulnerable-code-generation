//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <key> <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    char key[MAX_KEY_SIZE];
    strncpy(key, argv[1], sizeof(key));

    FILE *input_file = fopen(argv[2], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    FILE *output_file = fopen(argv[3], "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    int key_size = strlen(key);
    char *key_table = (char *)malloc(key_size * sizeof(char));
    for (int i = 0; i < key_size; i++) {
        key_table[i] = tolower(key[i]);
    }

    int input_buffer_size = 1024;
    char input_buffer[input_buffer_size];
    int output_buffer_size = input_buffer_size;
    char output_buffer[output_buffer_size];

    while (fread(input_buffer, sizeof(char), input_buffer_size, input_file) > 0) {
        int input_buffer_len = strlen(input_buffer);
        int output_buffer_index = 0;

        for (int i = 0; i < input_buffer_len; i++) {
            char input_char = tolower(input_buffer[i]);
            int key_index = tolower(key_table[i % key_size]) - 'a';

            if (isalpha(input_char)) {
                output_buffer[output_buffer_index++] = key_table[(key_index + input_char - 'a') % 26] + 'a';
            } else {
                output_buffer[output_buffer_index++] = input_char;
            }
        }

        fwrite(output_buffer, sizeof(char), output_buffer_index, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    free(key_table);

    printf("File encryption complete.\n");

    return 0;
}