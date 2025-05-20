//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 26

void encrypt_char(char *input, int key) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                input[i] = (input[i] + key - 'A') % 26 + 'A';
            } else {
                input[i] = (input[i] + key - 'a') % 26 + 'a';
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <key>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    char *input_buffer = malloc(sizeof(char) * 1024);
    size_t bytes_read = fread(input_buffer, sizeof(char), 1024, input_file);
    fclose(input_file);

    int key = atoi(argv[2]);
    if (key < 0 || key > KEY_LENGTH) {
        printf("Invalid key. Key must be a number between 0 and %d.\n", KEY_LENGTH);
        free(input_buffer);
        return 1;
    }

    printf("Key: %d\n", key);

    encrypt_char(input_buffer, key);

    FILE *output_file = fopen(argv[1], "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        free(input_buffer);
        return 1;
    }

    fwrite(input_buffer, sizeof(char), bytes_read, output_file);
    fclose(output_file);

    free(input_buffer);

    return 0;
}