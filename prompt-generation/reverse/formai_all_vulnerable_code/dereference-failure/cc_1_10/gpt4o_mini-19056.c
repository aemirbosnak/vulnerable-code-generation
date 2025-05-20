//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_DICT_SIZE 4096
#define BUFFER_SIZE 1024

typedef struct {
    char *input_buffer;
    size_t input_size;
    unsigned char *output_buffer;
    size_t *output_size;
} compression_data_t;

unsigned int dictionary[MAX_DICT_SIZE];
size_t dict_size;

void initialize_dictionary() {
    dict_size = 256;  
    for (size_t i = 0; i < dict_size; i++) {
        dictionary[i] = i;
    }
}

void compress_data(compression_data_t *data) {
    int i, j, k;
    unsigned char *input = (unsigned char *)data->input_buffer;
    unsigned char *output = data->output_buffer;

    int compressed_size = 0, current_code = input[0];
    char buffer[BUFFER_SIZE] = {0};
    size_t buffer_length = 1;

    for (i = 1; i < data->input_size; i++) {
        if (buffer_length < BUFFER_SIZE && input[i] == buffer[buffer_length - 1]) {
            buffer[buffer_length++] = input[i];
            current_code += (int)input[i];
        } else {
            if (dict_size < MAX_DICT_SIZE) {
                dictionary[dict_size++] = current_code;
            }

            output[compressed_size++] = current_code;
            current_code = input[i];
            buffer[0] = input[i];
            buffer_length = 1;
        }
    }
    
    output[compressed_size++] = current_code;
    *data->output_size = compressed_size;
}

void* thread_function(void *arg) {
    compression_data_t *data = (compression_data_t *)arg;
    compress_data(data);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Could not open input file");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    size_t input_size = ftell(input_file);
    rewind(input_file);

    char *input_buffer = (char *)malloc(input_size);
    fread(input_buffer, 1, input_size, input_file);
    fclose(input_file);

    unsigned char output_buffer[BUFFER_SIZE];
    size_t output_size = 0;

    initialize_dictionary();

    compression_data_t data = { input_buffer, input_size, output_buffer, &output_size };

    pthread_t thread;
    if (pthread_create(&thread, NULL, thread_function, (void *)&data) != 0) {
        perror("Failed to create thread");
        free(input_buffer);
        return 1;
    }

    pthread_join(thread, NULL);

    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        perror("Could not open output file");
        free(input_buffer);
        return 1;
    }

    fwrite(output_buffer, sizeof(unsigned char), output_size, output_file);
    fclose(output_file);
    free(input_buffer);

    printf("Compression completed successfully!\n");
    return 0;
}