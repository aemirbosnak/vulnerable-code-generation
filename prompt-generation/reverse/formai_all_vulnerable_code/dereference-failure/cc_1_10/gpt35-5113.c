//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <stdbool.h>

#define DEFAULT_NUM_THREADS 4
#define BLOCK_SIZE 1024

uint32_t calculate_checksum(const uint8_t *data_block, size_t block_size);
void *checksum_worker(void *args);

typedef struct {
    uint8_t *data_block;
    size_t block_size;
    uint32_t result;
} worker_args_t;

int main(int argc, char *argv[]) {
    // Read file path from command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path/to/file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *file_path = argv[1];

    // Open input file
    FILE *input_file = fopen(file_path, "rb");
    if (!input_file) {
        fprintf(stderr, "Error: failed to open input file %s\n", file_path);
        return EXIT_FAILURE;
    }

    // Determine file size
    fseek(input_file, 0, SEEK_END);
    size_t file_size = ftell(input_file);
    rewind(input_file);

    // Determine number of threads to use
    int num_threads = DEFAULT_NUM_THREADS;
    if (file_size < BLOCK_SIZE * DEFAULT_NUM_THREADS) {
        num_threads = 1;
    } else if (file_size < BLOCK_SIZE * DEFAULT_NUM_THREADS * 2) {
        num_threads = 2;
    }

    // Allocate memory for data blocks and worker thread arguments
    uint8_t *data_blocks[num_threads];
    worker_args_t worker_args[num_threads];

    // Divide file into blocks and spawn worker threads
    pthread_t threads[num_threads];
    size_t block_size = file_size / num_threads;
    for (int i = 0; i < num_threads; i++) {
        size_t offset = i * block_size;
        fseek(input_file, offset, SEEK_SET);
        data_blocks[i] = malloc(block_size);
        size_t bytes_read = fread(data_blocks[i], 1, block_size, input_file);
        if (bytes_read != block_size) {
            fprintf(stderr, "Error: failed to read input file %s\n", file_path);
            return EXIT_FAILURE;
        }

        worker_args[i].data_block = data_blocks[i];
        worker_args[i].block_size = block_size;
        pthread_create(&threads[i], NULL, checksum_worker, &worker_args[i]);
    }

    // Wait for worker threads to finish and combine checksums
    uint32_t checksum = 0;
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        checksum ^= worker_args[i].result;
        free(data_blocks[i]);
    }

    // Print checksum
    printf("Checksum of file %s is: %x\n", file_path, checksum);

    // Close input file and exit
    fclose(input_file);
    return EXIT_SUCCESS;
}

uint32_t calculate_checksum(const uint8_t *data_block, size_t block_size) {
    uint32_t checksum = 0;
    for (size_t i = 0; i < block_size; i++) {
        checksum ^= data_block[i];
    }
    return checksum;
}

void *checksum_worker(void *args) {
    worker_args_t *worker_args = (worker_args_t *) args;
    worker_args->result = calculate_checksum(worker_args->data_block, worker_args->block_size);
    return NULL;
}