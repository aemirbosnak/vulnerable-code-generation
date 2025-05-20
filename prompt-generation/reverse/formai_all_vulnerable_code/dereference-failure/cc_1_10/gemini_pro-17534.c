//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define KEY_LEN 16

typedef struct {
    FILE *input;
    FILE *output;
    char *key;
    int key_len;
} thread_args;

void *encrypt_thread(void *args) {
    thread_args *a = (thread_args *)args;

    char buf[BUF_SIZE];
    size_t bytes_read, bytes_written;

    while ((bytes_read = fread(buf, 1, BUF_SIZE, a->input)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buf[i] ^= a->key[i % a->key_len];
        }

        bytes_written = fwrite(buf, 1, bytes_read, a->output);

        if (bytes_written != bytes_read) {
            perror("fwrite");
            return NULL;
        }
    }

    if (ferror(a->input)) {
        perror("fread");
        return NULL;
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input file> <output file> <key> <num threads>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char *key = argv[3];
    int key_len = strlen(key);

    if (key_len > KEY_LEN) {
        fprintf(stderr, "Key length must be <= %d\n", KEY_LEN);
        return EXIT_FAILURE;
    }

    int num_threads = atoi(argv[4]);
    if (num_threads <= 0) {
        fprintf(stderr, "Number of threads must be > 0\n");
        return EXIT_FAILURE;
    }

    pthread_t threads[num_threads];
    thread_args args[num_threads];

    for (int i = 0; i < num_threads; i++) {
        args[i].input = input;
        args[i].output = output;
        args[i].key = key;
        args[i].key_len = key_len;

        if (pthread_create(&threads[i], NULL, encrypt_thread, (void *)&args[i]) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return EXIT_FAILURE;
        }
    }

    if (fclose(input) != 0) {
        perror("fclose");
        return EXIT_FAILURE;
    }

    if (fclose(output) != 0) {
        perror("fclose");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}