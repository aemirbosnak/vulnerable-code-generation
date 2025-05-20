//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE (1024 * 1024)
#define ENCRYPTION_KEY "Cyberpunk2021"

typedef struct {
    FILE *file;
    char *filename;
    unsigned char *buffer;
    size_t size;
} FileContext;

void init_encryptor(void) {
    srand(time(NULL));
}

unsigned char get_random_byte(void) {
    return rand() % 256;
}

void encrypt_file(FileContext *context) {
    FILE *output_file = fopen("encrypted.bin", "wb");

    if (output_file == NULL) {
        printf("Error: Failed to create output file.\n");
        exit(1);
    }

    char *key = ENCRYPTION_KEY;
    size_t key_size = strlen(key);

    for (size_t i = 0; i < context->size; i++) {
        context->buffer[i] ^= key[i % key_size];
    }

    fwrite(context->buffer, context->size, 1, output_file);

    fclose(output_file);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FileContext input_context = {0};
    FileContext output_context = {0};

    input_context.filename = argv[1];
    output_context.filename = argv[2];

    input_context.file = fopen(input_context.filename, "rb");
    if (input_context.file == NULL) {
        printf("Error: Failed to open input file.\n");
        return 1;
    }

    fseek(input_context.file, 0, SEEK_END);
    input_context.size = ftell(input_context.file);

    if (input_context.size > MAX_FILE_SIZE) {
        printf("Error: Input file is too large.\n");
        return 1;
    }

    input_context.buffer = malloc(input_context.size);
    if (input_context.buffer == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return 1;
    }

    fseek(input_context.file, 0, SEEK_SET);
    fread(input_context.buffer, input_context.size, 1, input_context.file);

    encrypt_file(&output_context);

    free(input_context.buffer);
    fclose(input_context.file);

    return 0;
}