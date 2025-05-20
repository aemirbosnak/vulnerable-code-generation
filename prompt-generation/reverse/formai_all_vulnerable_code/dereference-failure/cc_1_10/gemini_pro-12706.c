//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1000000

char *generate_random_key(int size) {
    char *key = malloc(size + 1);
    for (int i = 0; i < size; i++) {
        key[i] = (rand() % 26) + 'a';
    }
    key[size] = '\0';
    return key;
}

void encrypt_file(char *input_file, char *output_file, char *key) {
    FILE *file_in = fopen(input_file, "rb");
    if (file_in == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    FILE *file_out = fopen(output_file, "wb");
    if (file_out == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    int bytes_read = 0;
    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file_in)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % strlen(key)];
        }
        fwrite(buffer, 1, bytes_read, file_out);
    }

    fclose(file_in);
    fclose(file_out);
}

void usage(char *program_name) {
    printf("Usage: %s input_file output_file key_size\n", program_name);
    printf("Example: %s input.txt output.txt 128\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
        return 1;
    }

    srand(time(NULL));

    int key_size = atoi(argv[3]);
    char *key = generate_random_key(key_size);

    encrypt_file(argv[1], argv[2], key);

    printf("File encrypted successfully!\n");

    free(key);

    return 0;
}