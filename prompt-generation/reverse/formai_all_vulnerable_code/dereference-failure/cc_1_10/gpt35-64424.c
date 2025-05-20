//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define CHUNK_SIZE 1024

struct tuple {
    char *data;
    size_t size;
};

void *compress_chunk(void *arg) {
    struct tuple *t = (struct tuple *) arg;
    char *data = (char *) malloc(t->size / 2);
    size_t compressed_size = 0;

    for (size_t i = 0; i < t->size;) {
        char current_char = t->data[i];
        size_t count = 0;

        while (i < t->size && t->data[i] == current_char) {
            count++;
            i++;
        }

        if (count > 3) {
            data[compressed_size++] = current_char;
            data[compressed_size++] = count - 3;
        } else {
            for (size_t j = 0; j < count; j++) {
                data[compressed_size++] = current_char;
            }
        }
    }

    free(t->data);
    t->data = data;
    t->size = compressed_size;

    return NULL;
}

int compress(char *input, size_t input_size, char **output, size_t *output_size) {
    if (input_size == 0) {
        return 1;
    }

    size_t num_chunks = input_size / CHUNK_SIZE;

    if (input_size % CHUNK_SIZE != 0) {
        num_chunks++;
    }

    struct tuple *tuples = (struct tuple *) malloc(num_chunks * sizeof(struct tuple));

    for (size_t i = 0, j = 0; i < input_size;) {
        size_t chunk_size;

        if (i + CHUNK_SIZE > input_size) {
            chunk_size = input_size - i;
        } else {
            chunk_size = CHUNK_SIZE;
        }

        tuples[j].data = (char *) malloc(chunk_size);
        tuples[j].size = chunk_size;
        memcpy(tuples[j].data, input + i, chunk_size);
        i += chunk_size;
        j++;
    }

    pthread_t *threads = (pthread_t *) malloc(num_chunks * sizeof(pthread_t));

    for (size_t i = 0; i < num_chunks; i++) {
        pthread_create(&threads[i], NULL, compress_chunk, &tuples[i]);
    }

    for (size_t i = 0; i < num_chunks; i++) {
        pthread_join(threads[i], NULL);
    }

    size_t compressed_size = 0;

    for (size_t i = 0; i < num_chunks; i++) {
        compressed_size += tuples[i].size;
    }

    *output = (char *) malloc(compressed_size);
    *output_size = compressed_size;

    size_t current_pos = 0;

    for (size_t i = 0; i < num_chunks; i++) {
        memcpy(*output + current_pos, tuples[i].data, tuples[i].size);
        current_pos += tuples[i].size;
    }

    free(threads);
    free(tuples);

    return 0;
}

int main() {
    char input[] = "aaaabbbcccdddeeefff";
    size_t input_size = sizeof(input) - 1;
    char *output;
    size_t output_size;
    int result = compress(input, input_size, &output, &output_size);

    if (result != 0) {
        printf("Compression failed.\n");
    } else {
        printf("Input size: %lu\n", input_size);
        printf("Output size: %lu\n", output_size);
        printf("Output data: ");

        for (size_t i = 0; i < output_size; i++) {
            printf("%c", output[i]);
        }

        printf("\n");
    }

    free(output);

    return 0;
}