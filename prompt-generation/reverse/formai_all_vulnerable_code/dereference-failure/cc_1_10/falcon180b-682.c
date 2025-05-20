//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 32
#define MAX_FILE_SIZE 1000000

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <file_to_encrypt> <output_file> <key>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    char key[MAX_KEY_SIZE];
    strncpy(key, argv[3], strlen(argv[3]));
    if (strlen(key) == 0) {
        printf("Key cannot be empty.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    int key_length = strlen(key);
    if (key_length > MAX_KEY_SIZE) {
        printf("Key is too long (maximum length is %d).\n", MAX_KEY_SIZE);
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    char *input_buffer = malloc(MAX_FILE_SIZE);
    char *output_buffer = malloc(MAX_FILE_SIZE);

    int input_buffer_size = fread(input_buffer, 1, MAX_FILE_SIZE, input_file);
    if (input_buffer_size <= 0) {
        printf("Error reading input file.\n");
        free(input_buffer);
        free(output_buffer);
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    int output_buffer_size = 0;
    for (int i = 0; i < input_buffer_size; i++) {
        char c = input_buffer[i];
        char k = key[i % key_length];
        char o = (c ^ k);
        output_buffer[output_buffer_size++] = o;
    }

    fwrite(output_buffer, 1, output_buffer_size, output_file);

    free(input_buffer);
    free(output_buffer);

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    return 0;
}