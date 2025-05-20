//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 256

typedef struct {
    const char *input_file;
    const char *output_file;
    int key;
} EncryptArgs;

void* encrypt_file(void *args);
void display_progress(const char *filename, size_t total_size);
void encrypt_buffer(char *buffer, size_t size, int key);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    EncryptArgs args;
    args.input_file = argv[1];
    args.output_file = argv[2];
    args.key = atoi(argv[3]);

    pthread_t encrypt_thread;
    if (pthread_create(&encrypt_thread, NULL, encrypt_file, &args) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    // Join the thread (wait for completion)
    pthread_join(encrypt_thread, NULL);

    printf("File encryption completed successfully.\n");
    return 0;
}

void* encrypt_file(void *args) {
    EncryptArgs *encrypt_args = (EncryptArgs *)args;

    FILE *input_fp = fopen(encrypt_args->input_file, "rb");
    if (input_fp == NULL) {
        perror("Error opening input file");
        return NULL;
    }

    // Open output file
    FILE *output_fp = fopen(encrypt_args->output_file, "wb");
    if (output_fp == NULL) {
        perror("Error opening output file");
        fclose(input_fp);
        return NULL;
    }

    // Get the size of the input file
    fseek(input_fp, 0, SEEK_END);
    size_t total_size = ftell(input_fp);
    fseek(input_fp, 0, SEEK_SET);

    char *buffer = malloc(BUFFER_SIZE);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(input_fp);
        fclose(output_fp);
        return NULL;
    }

    size_t read_size = 0;
    size_t total_read = 0;

    while ((read_size = fread(buffer, 1, BUFFER_SIZE, input_fp)) > 0) {
        encrypt_buffer(buffer, read_size, encrypt_args->key);
        fwrite(buffer, 1, read_size, output_fp);
        total_read += read_size;

        display_progress(encrypt_args->input_file, total_size);
    }

    free(buffer);
    fclose(input_fp);
    fclose(output_fp);
    return NULL;
}

void encrypt_buffer(char *buffer, size_t size, int key) {
    for (size_t i = 0; i < size; ++i) {
        buffer[i] ^= key; // Simple XOR encryption
    }
}

void display_progress(const char *filename, size_t total_size) {
    static size_t last_reported = 0;
    static int progress_bar_length = 50;

    size_t current_size = ftell(stdin);

    if (current_size > last_reported) {
        last_reported = current_size;
        int progress = (int)((current_size * progress_bar_length) / total_size);
        
        printf("\r[");
        for (int i = 0; i < progress; ++i) {
            printf("#");
        }
        for (int i = progress; i < progress_bar_length; ++i) {
            printf(" ");
        }
        printf("] %zu/%zu bytes processed.", current_size, total_size);
        fflush(stdout);
    }

    usleep(100000); // Reduce CPU usage
}