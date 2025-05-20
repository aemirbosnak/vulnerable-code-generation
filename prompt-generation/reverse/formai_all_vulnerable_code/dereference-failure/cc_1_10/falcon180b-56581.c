//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 32
#define MAX_FILE_SIZE 1000000

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    FILE *input_file;
    FILE *output_file;
} EncryptionContext;

EncryptionContext create_encryption_context(char *input_filename, char *output_filename, char *key) {
    EncryptionContext context;
    context.key_size = strlen(key);
    strncpy(context.key, key, MAX_KEY_SIZE);
    context.input_file = fopen(input_filename, "rb");
    if (context.input_file == NULL) {
        printf("Error: Could not open input file %s\n", input_filename);
        exit(1);
    }
    context.output_file = fopen(output_filename, "wb");
    if (context.output_file == NULL) {
        printf("Error: Could not open output file %s\n", output_filename);
        exit(1);
    }
    return context;
}

void destroy_encryption_context(EncryptionContext *context) {
    fclose(context->input_file);
    fclose(context->output_file);
}

void encrypt_file(EncryptionContext *context) {
    char input_buffer[MAX_FILE_SIZE];
    char output_buffer[MAX_FILE_SIZE + MAX_KEY_SIZE];
    int input_bytes_read;
    int output_bytes_written;
    int i;
    int j;

    while ((input_bytes_read = fread(input_buffer, 1, MAX_FILE_SIZE, context->input_file)) > 0) {
        for (i = 0; i < input_bytes_read; i++) {
            output_buffer[i] = input_buffer[i] ^ context->key[i % context->key_size];
        }
        output_bytes_written = fwrite(output_buffer, 1, input_bytes_read, context->output_file);
        if (output_bytes_written!= input_bytes_read) {
            printf("Error: Failed to write to output file\n");
            exit(1);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        exit(1);
    }
    EncryptionContext context = create_encryption_context(argv[1], argv[2], argv[3]);
    encrypt_file(&context);
    destroy_encryption_context(&context);
    return 0;
}