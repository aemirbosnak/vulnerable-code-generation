//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define SHIFT 3  // Caesar cipher shift
#define NUM_THREADS 4  // Number of threads for encryption

typedef struct {
    char *buffer;
    size_t length;
    int thread_id;
} ThreadData;

void *encrypt(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    size_t offset = data->thread_id * (data->length / NUM_THREADS);
    size_t thread_length = (data->thread_id == NUM_THREADS - 1) ? 
                           (data->length - offset) : 
                           (data->length / NUM_THREADS);

    for (size_t i = 0; i < thread_length; ++i) {
        char c = data->buffer[offset + i];
        if (c >= 'a' && c <= 'z') {
            c = ((c - 'a' + SHIFT) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A' + SHIFT) % 26) + 'A';
        }
        data->buffer[offset + i] = c;
    }
    return NULL;
}

void encrypt_file(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "rb");
    if (!in) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    fseek(in, 0, SEEK_END);
    size_t length = ftell(in);
    rewind(in);

    char *buffer = malloc(length + 1);
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(in);
        exit(EXIT_FAILURE);
    }

    fread(buffer, 1, length, in);
    buffer[length] = '\0';  // Null-terminate the buffer
    fclose(in);

    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_data[i].buffer = buffer;
        thread_data[i].length = length;
        thread_data[i].thread_id = i;
        pthread_create(&threads[i], NULL, encrypt, &thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    FILE *out = fopen(output_file, "wb");
    if (!out) {
        perror("Failed to open output file");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    fwrite(buffer, 1, length, out);
    fclose(out);
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    encrypt_file(argv[1], argv[2]);
    printf("File encrypted successfully!\n");

    return EXIT_SUCCESS;
}