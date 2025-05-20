//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILE_SIZE (1024 * 1024 * 100) // 100 MB

void encrypt_file(char* input_file, char* output_file, char* key) {
    FILE* input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    int file_size = 0;
    fseek(input, 0, SEEK_END);
    file_size = ftell(input);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: input file is too large.\n");
        exit(1);
    }

    rewind(input);

    FILE* output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    char* buffer = (char*) malloc(file_size);
    if (buffer == NULL) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }

    int bytes_read = fread(buffer, 1, file_size, input);
    if (bytes_read!= file_size) {
        printf("Error: could not read input file.\n");
        exit(1);
    }

    srand(time(NULL));
    char* key_buffer = (char*) malloc(strlen(key) + 1);
    strcpy(key_buffer, key);

    for (int i = 0; i < strlen(key); i++) {
        key_buffer[i] = rand() % 26 + 'a';
    }

    for (int i = 0; i < file_size; i++) {
        char c = buffer[i];
        char k = key_buffer[i % strlen(key)];
        char result = (c + k) % 26 + 'a';
        fputc(result, output);
    }

    free(buffer);
    free(key_buffer);

    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        exit(1);
    }

    char* input_file = argv[1];
    char* output_file = argv[2];
    char* key = argv[3];

    encrypt_file(input_file, output_file, key);

    printf("File encrypted successfully.\n");

    return 0;
}