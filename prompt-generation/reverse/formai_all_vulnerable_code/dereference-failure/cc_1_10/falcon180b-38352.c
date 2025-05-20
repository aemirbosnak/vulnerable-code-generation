//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_FILE_SIZE 1000000

typedef struct {
    char key[MAX_KEY_SIZE];
    char filename[MAX_FILE_SIZE];
} config_t;

void read_config(config_t *config) {
    printf("Enter key: ");
    scanf("%s", config->key);
    printf("Enter filename: ");
    scanf("%s", config->filename);
}

void write_encrypted_file(config_t *config) {
    FILE *input_file, *output_file;
    char input_buffer[MAX_FILE_SIZE];
    char output_buffer[MAX_FILE_SIZE];
    int input_size, output_size, i;

    input_file = fopen(config->filename, "rb");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    output_file = fopen("encrypted.txt", "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    while ((input_size = fread(input_buffer, 1, MAX_FILE_SIZE, input_file)) > 0) {
        for (i = 0; i < input_size; i++) {
            output_buffer[i] = input_buffer[i] ^ config->key[i % MAX_KEY_SIZE];
        }
        fwrite(output_buffer, 1, input_size, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    config_t config;

    printf("Enter key: ");
    scanf("%s", config.key);
    printf("Enter filename: ");
    scanf("%s", config.filename);

    read_config(&config);
    write_encrypted_file(&config);

    return 0;
}