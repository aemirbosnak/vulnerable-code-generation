//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 3

void encrypt_char(char *input, int length) {
    for (int i = 0; i < length; ++i) {
        if (isalpha(*(input + i))) {
            if (isupper(*(input + i))) {
                *(input + i) = (char) (((int)*(input + i) - 65 + KEY) % 26 + 65);
            } else {
                *(input + i) = (char) (((int)*(input + i) - 97 + KEY) % 26 + 97);
            }
        }
    }
}

int main() {
    FILE *input_file, *output_file;
    char *input_buffer;
    size_t input_size;

    input_file = fopen("input.txt", "rb");
    if (input_file == NULL) {
        perror("Error opening input file.");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    input_size = ftell(input_file);
    rewind(input_file);

    input_buffer = (char *) malloc(input_size + 1);
    if (input_buffer == NULL) {
        perror("Error allocating memory for input buffer.");
        fclose(input_file);
        return 1;
    }

    size_t bytes_read = fread(input_buffer, 1, input_size, input_file);
    if (bytes_read != input_size) {
        perror("Error reading input file.");
        free(input_buffer);
        fclose(input_file);
        return 1;
    }

    input_buffer[input_size] = '\0';
    encrypt_char(input_buffer, input_size);

    output_file = fopen("output.txt", "wb");
    if (output_file == NULL) {
        perror("Error opening output file.");
        free(input_buffer);
        fclose(input_file);
        return 1;
    }

    size_t bytes_written = fwrite(input_buffer, 1, input_size, output_file);
    if (bytes_written != input_size) {
        perror("Error writing to output file.");
        free(input_buffer);
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    printf("File encrypted successfully.\n");

    free(input_buffer);
    fclose(input_file);
    fclose(output_file);

    return 0;
}