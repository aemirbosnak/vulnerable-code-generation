//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BLOCK_SIZE 512
#define THREAD_COUNT 4
#define TOTAL_BLOCKS 1024 * 1024 // Change this according to your needs

typedef struct {
    int thread_id;
    FILE *disk_image;
    long start_block;
    long end_block;
} recovery_args;

void* recover_data(void* args) {
    recovery_args* r_args = (recovery_args*)args;
    char buffer[BLOCK_SIZE];
    long blocks_rec = 0;

    // Locking mechanism for printing to avoid garbled output
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    for (long block = r_args->start_block; block < r_args->end_block; block++) {
        fseek(r_args->disk_image, block * BLOCK_SIZE, SEEK_SET);
        size_t read_bytes = fread(buffer, 1, BLOCK_SIZE, r_args->disk_image);

        if (read_bytes < BLOCK_SIZE) {
            if (feof(r_args->disk_image)) {
                break; // End of file reached
            }
            if (ferror(r_args->disk_image)) {
                fprintf(stderr, "Error reading block %ld: %s\n", block, strerror(errno));
                continue;
            }
        }

        // Simulate data recovery by writing recovered blocks to a file
        pthread_mutex_lock(&mutex);
        FILE *recovered_file = fopen("recovered_data.bin", "ab");
        if (recovered_file) {
            fwrite(buffer, 1, BLOCK_SIZE, recovered_file);
            fclose(recovered_file);
            blocks_rec++;
        } else {
            fprintf(stderr, "Could not open recovered_data.bin: %s\n", strerror(errno));
        }
        pthread_mutex_unlock(&mutex);
    }

    printf("Thread %d recovered %ld blocks.\n", r_args->thread_id, blocks_rec);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <disk_image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *disk_image = fopen(argv[1], "rb");
    if (!disk_image) {
        fprintf(stderr, "Could not open disk image: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    pthread_t threads[THREAD_COUNT];
    recovery_args args[THREAD_COUNT];

    long blocks_per_thread = TOTAL_BLOCKS / THREAD_COUNT;

    for (int i = 0; i < THREAD_COUNT; i++) {
        args[i].thread_id = i;
        args[i].disk_image = disk_image;
        args[i].start_block = i * blocks_per_thread;
        args[i].end_block = (i + 1) * blocks_per_thread;

        if (pthread_create(&threads[i], NULL, recover_data, (void*)&args[i]) != 0) {
            fprintf(stderr, "Error creating thread %d: %s\n", i, strerror(errno));
            fclose(disk_image);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(disk_image);
    printf("Data recovery completed successfully!\n");

    return EXIT_SUCCESS;
}