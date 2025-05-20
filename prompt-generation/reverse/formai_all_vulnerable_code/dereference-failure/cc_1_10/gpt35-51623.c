//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

// Data structure for passing data to threads
typedef struct {
    char* input_buffer;
    char* output_buffer;
    int start_index;
    int end_index;
} ThreadData;

// Compresses a given buffer
void compress(char* input_buffer, char* output_buffer, int start_index, int end_index) {
    int index = start_index;
    int compressed_index = start_index;

    while (index < end_index) {
        char current = input_buffer[index];
        int count = 1;

        while (input_buffer[index + 1] == current && (index + 1) < end_index) {
            count++;
            index++;
        }

        if (count > 3) {
            output_buffer[compressed_index++] = '$';
            output_buffer[compressed_index++] = count + '0';
            output_buffer[compressed_index++] = current;
        } else {
            for (int i = 0; i < count; i++) {
                output_buffer[compressed_index++] = current;
            }
        }

        index++;
    }
}

// Thread function for compressing a chunk of the input buffer
void* compress_thread(void* thread_data_ptr) {
    ThreadData* data = (ThreadData*)thread_data_ptr;
    compress(data->input_buffer, data->output_buffer, data->start_index, data->end_index);

    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <num_threads>\n", argv[0]);
        exit(1);
    }

    char* input_file = argv[1];
    char* output_file = argv[2];
    int num_threads = atoi(argv[3]);
    
    // Read input file and store contents in buffer
    FILE* in_file = fopen(input_file, "r");
    if (in_file == NULL) {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }

    fseek(in_file, 0, SEEK_END);
    long input_file_size = ftell(in_file);
    rewind(in_file);

    char* input_buffer = (char*)malloc(input_file_size);
    fread(input_buffer, sizeof(char), input_file_size, in_file);

    // Create output buffer
    char* output_buffer = (char*)malloc(input_file_size);

    // Divide input buffer into chunks for each thread
    int chunk_size = input_file_size / num_threads;

    pthread_t threads[num_threads];
    ThreadData thread_data[num_threads];

    int start_index = 0;
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].input_buffer = input_buffer;
        thread_data[i].output_buffer = output_buffer;
        thread_data[i].start_index = start_index;
        thread_data[i].end_index = start_index + chunk_size;

        // Make sure the last thread takes care of any remaining bytes
        if (i == num_threads - 1) {
            thread_data[i].end_index = input_file_size;
        }

        pthread_create(&threads[i], NULL, compress_thread, (void*)&thread_data[i]);

        start_index += chunk_size;
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Write compressed data to output file
    FILE* out_file = fopen(output_file, "w");
    if (out_file == NULL) {
        printf("Error: Cannot open output file.\n");
        exit(1);
    }

    fwrite(output_buffer, sizeof(char), input_file_size, out_file);

    // Cleanup
    fclose(in_file);
    fclose(out_file);
    free(input_buffer);
    free(output_buffer);

    return 0;
}