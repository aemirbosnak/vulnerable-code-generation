//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#define BLOCK_SIZE 64
#define NUM_THREADS 4

typedef struct {
    uint8_t *data;
    size_t size;
    uint8_t *watermark;
    size_t watermark_size;
    sem_t semaphore;
} watermark_task_t;

void *watermark_thread(void *arg) {
    watermark_task_t *task = (watermark_task_t *)arg;

    for (size_t i = 0; i < task->size; i += BLOCK_SIZE) {
        for (size_t j = 0; j < BLOCK_SIZE; j++) {
            task->data[i + j] ^= task->watermark[j];
        }
    }

    sem_post(&task->semaphore);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input file> <output file> <watermark file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(input_file, 0, SEEK_END);
    size_t input_size = ftell(input_file);
    rewind(input_file);

    uint8_t *input_data = malloc(input_size);
    if (input_data == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    fread(input_data, 1, input_size, input_file);
    fclose(input_file);

    FILE *watermark_file = fopen(argv[3], "rb");
    if (watermark_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(watermark_file, 0, SEEK_END);
    size_t watermark_size = ftell(watermark_file);
    rewind(watermark_file);

    uint8_t *watermark = malloc(watermark_size);
    if (watermark == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    fread(watermark, 1, watermark_size, watermark_file);
    fclose(watermark_file);

    size_t num_blocks = (input_size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    watermark_task_t tasks[num_blocks];

    for (size_t i = 0; i < num_blocks; i++) {
        tasks[i].data = input_data + i * BLOCK_SIZE;
        tasks[i].size = BLOCK_SIZE;
        tasks[i].watermark = watermark;
        tasks[i].watermark_size = watermark_size;
        sem_init(&tasks[i].semaphore, 0, 0);
    }

    pthread_t threads[NUM_THREADS];
    for (size_t i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, watermark_thread, &tasks[i]);
    }

    for (size_t i = 0; i < num_blocks; i++) {
        sem_wait(&tasks[i].semaphore);
    }

    for (size_t i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fwrite(input_data, 1, input_size, output_file);
    fclose(output_file);

    free(input_data);
    free(watermark);

    return EXIT_SUCCESS;
}