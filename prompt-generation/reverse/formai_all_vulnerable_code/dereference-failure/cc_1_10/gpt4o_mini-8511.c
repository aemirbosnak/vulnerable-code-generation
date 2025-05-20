//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

// Structure to hold watermarking data
typedef struct {
    char *image_file;
    char *watermark_text;
    int thread_id;
} ThreadData;

// Function prototypes
void *embed_watermark(void *arg);
void read_image(const char *filename, uint8_t **image_data, size_t *size);
void write_image(const char *filename, uint8_t *image_data, size_t size);
void embed_text(uint8_t *image_data, size_t size, const char *watermark_text);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <image_file> <watermark_text> <number_of_threads>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *image_file = argv[1];
    char *watermark_text = argv[2];
    int number_of_threads = atoi(argv[3]);

    pthread_t *threads = malloc(number_of_threads * sizeof(pthread_t));
    ThreadData *thread_data = malloc(number_of_threads * sizeof(ThreadData));

    for (int i = 0; i < number_of_threads; i++) {
        thread_data[i].image_file = image_file;
        thread_data[i].watermark_text = watermark_text;
        thread_data[i].thread_id = i;

        if (pthread_create(&threads[i], NULL, embed_watermark, &thread_data[i]) != 0) {
            fprintf(stderr, "Error creating thread %d: %s\n", i, strerror(errno));
            free(threads);
            free(thread_data);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < number_of_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(threads);
    free(thread_data);

    return EXIT_SUCCESS;
}

void *embed_watermark(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    
    uint8_t *image_data;
    size_t image_size;

    printf("Thread %d: Reading the image file '%s'...\n", data->thread_id, data->image_file);
    read_image(data->image_file, &image_data, &image_size);
    
    printf("Thread %d: Embedding watermark '%s'...\n", data->thread_id, data->watermark_text);
    embed_text(image_data, image_size, data->watermark_text);
    
    char output_file[256];
    snprintf(output_file, sizeof(output_file), "watermarked_%d_%s", data->thread_id, data->image_file);
    
    printf("Thread %d: Writing watermarked image to '%s'...\n", data->thread_id, output_file);
    write_image(output_file, image_data, image_size);
    
    free(image_data);
    printf("Thread %d: Done!\n", data->thread_id);
    
    return NULL;
}

void read_image(const char *filename, uint8_t **image_data, size_t *size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    *image_data = malloc(*size);
    fread(*image_data, 1, *size, file);
    
    fclose(file);
}

void write_image(const char *filename, uint8_t *image_data, size_t size) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file '%s': %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    fwrite(image_data, 1, size, file);
    fclose(file);
}

void embed_text(uint8_t *image_data, size_t size, const char *watermark_text) {
    // Simple embedding scheme: append the watermark text to the end of the image_data
    size_t watermark_length = strlen(watermark_text);

    if (size + watermark_length + 1 > size) {
        fprintf(stderr, "Error: Image data too small to embed watermark.\n");
        exit(EXIT_FAILURE);
    }
    
    memcpy(image_data + size, watermark_text, watermark_length);
    image_data[size + watermark_length] = '\0'; // null-terminate the text
}