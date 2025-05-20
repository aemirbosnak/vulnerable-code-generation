//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 32

void generate_key(char* key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[KEY_SIZE] = '\0';
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    char* file_buffer = malloc(file_size + 1);
    if (file_buffer == NULL) {
        printf("Error allocating memory.\n");
        fclose(input_file);
        return 1;
    }

    fread(file_buffer, file_size, 1, input_file);
    fclose(input_file);

    char key[KEY_SIZE + 1];
    generate_key(key);

    for (int i = 0; i < file_size; i++) {
        file_buffer[i] ^= key[i % KEY_SIZE];
    }

    FILE* output_file = fopen("encrypted.txt", "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        free(file_buffer);
        return 1;
    }

    fwrite(file_buffer, file_size, 1, output_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");
    free(file_buffer);

    return 0;
}