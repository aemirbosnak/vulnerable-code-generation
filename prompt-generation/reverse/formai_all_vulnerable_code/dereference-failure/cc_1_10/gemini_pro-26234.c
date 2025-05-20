//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
    char *filename;
    char *output_filename;
    int start;
    int end;
} thread_args;

void *recover_data(void *args) {
    thread_args *arg = (thread_args *)args;

    FILE *input_file = fopen(arg->filename, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return NULL;
    }

    FILE *output_file = fopen(arg->output_filename, "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        return NULL;
    }

    char buffer[1024];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        if (fwrite(buffer, 1, bytes_read, output_file) != bytes_read) {
            perror("Error writing to output file");
            return NULL;
        }
    }

    if (ferror(input_file)) {
        perror("Error reading from input file");
        return NULL;
    }

    fclose(input_file);
    fclose(output_file);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <num_threads>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];
    int num_threads = atoi(argv[3]);

    if (num_threads < 1 || num_threads > NUM_THREADS) {
        fprintf(stderr, "Error: invalid number of threads\n");
        return EXIT_FAILURE;
    }

    pthread_t threads[NUM_THREADS];
    thread_args args[NUM_THREADS];

    int file_size;
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    fclose(input_file);

    int chunk_size = file_size / num_threads;
    for (int i = 0; i < num_threads; i++) {
        args[i].filename = input_filename;
        args[i].output_filename = output_filename;
        args[i].start = i * chunk_size;
        args[i].end = (i + 1) * chunk_size;
    }

    for (int i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, recover_data, &args[i]) != 0) {
            perror("Error creating thread");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Error joining thread");
            return EXIT_FAILURE;
        }
    }

    printf("Data recovery complete.\n");
    return EXIT_SUCCESS;
}