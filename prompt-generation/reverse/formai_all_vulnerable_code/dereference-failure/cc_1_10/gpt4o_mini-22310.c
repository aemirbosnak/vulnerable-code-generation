//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define NUM_NODES 4

// Data structure to hold the segment for each thread
typedef struct {
    char *input;
    char *output;
    int start;
    int end;
} CompressionData;

// Function to perform Run-Length Encoding (RLE)
void *compress_segment(void *arg) {
    CompressionData *data = (CompressionData*)arg;
    char *input = data->input;
    char *output = data->output;
    int j = 0;

    for (int i = data->start; i < data->end; i++) {
        int count = 1;
        while (i + 1 < data->end && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        j += snprintf(output + j, BUFFER_SIZE - j, "%d%c", count, input[i]);
    }

    return NULL;
}

// Function to perform decompression
void decompress(const char *input, char *output) {
    int i = 0, j = 0;

    while (input[i]) {
        int count = 0;

        // Read the count (a sequence of digits)
        while (isdigit(input[i])) {
            count = count * 10 + (input[i] - '0');
            i++;
        }

        // The character to repeat
        char character = input[i++];
        for (int k = 0; k < count; k++) {
            output[j++] = character;
        }
    }
    output[j] = '\0';  // Null terminate the output string
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string_to_compress>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    int len = strlen(input);
    
    // Prepare compression segments for each node/thread
    pthread_t threads[NUM_NODES];
    CompressionData data[NUM_NODES];
    char *compressed_segments[NUM_NODES];
    
    // Allocate buffers for each compressed segment
    for (int i = 0; i < NUM_NODES; i++) {
        compressed_segments[i] = (char *)malloc(BUFFER_SIZE);
        memset(compressed_segments[i], 0, BUFFER_SIZE);
    }

    // Distributing the task of compression
    int segment_length = len / NUM_NODES;
    for (int i = 0; i < NUM_NODES; i++) {
        data[i].input = input;
        data[i].output = compressed_segments[i];
        data[i].start = i * segment_length;
        data[i].end = (i == NUM_NODES - 1) ? len : (i + 1) * segment_length;
        pthread_create(&threads[i], NULL, compress_segment, (void*)&data[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_NODES; i++) {
        pthread_join(threads[i], NULL);
    }

    // Combine the compressed segments
    char final_compressed[BUFFER_SIZE] = {0};
    for (int i = 0; i < NUM_NODES; i++) {
        strcat(final_compressed, compressed_segments[i]);
        free(compressed_segments[i]);  // Free segment memory
    }

    // Output the compressed result
    printf("Compressed data: %s\n", final_compressed);

    // Decompress to verify the compression
    char decompressed[BUFFER_SIZE] = {0};
    decompress(final_compressed, decompressed);

    // Output the decompressed result
    printf("Decompressed data: %s\n", decompressed);

    return 0;
}