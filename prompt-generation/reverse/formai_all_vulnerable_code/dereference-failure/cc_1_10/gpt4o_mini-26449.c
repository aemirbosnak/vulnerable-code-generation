//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define KEY 0xAA // Simple XOR key

typedef struct {
    char *input_file;
    char *output_file;
    int encrypt;
} FileOperation;

void *encrypt_decrypt(void *arg) {
    FileOperation *file_op = (FileOperation *)arg;
    FILE *input = fopen(file_op->input_file, "rb");
    if (!input) {
        perror("Error opening input file");
        pthread_exit(NULL);
    }

    FILE *output = fopen(file_op->output_file, "wb");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        pthread_exit(NULL);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= KEY; // XOR encryption/decryption
        }
        fwrite(buffer, 1, bytes_read, output);
    }

    fclose(input);
    fclose(output);
    printf("File %s successfully written to %s\n", file_op->encrypt ? "encrypted" : "decrypted", file_op->output_file);
    pthread_exit(NULL);
}

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s -e|-d <input_file> <output_file>\n", prog_name);
    fprintf(stderr, "  -e: Encrypt the input file\n");
    fprintf(stderr, "  -d: Decrypt the input file\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    FileOperation file_op;
    file_op.input_file = argv[2];
    file_op.output_file = argv[3];

    if (strcmp(argv[1], "-e") == 0) {
        file_op.encrypt = 1; // Encrypt
    } else if (strcmp(argv[1], "-d") == 0) {
        file_op.encrypt = 0; // Decrypt
    } else {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    pthread_t thread_id;
    if (pthread_create(&thread_id, NULL, encrypt_decrypt, (void *)&file_op) != 0) {
        perror("Failed to create thread");
        return EXIT_FAILURE;
    }

    pthread_join(thread_id, NULL); // Wait for thread to finish

    return EXIT_SUCCESS;
}