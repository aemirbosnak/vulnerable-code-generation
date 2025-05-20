//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *input_buffer;
    char *output_buffer;
    int input_index;
    int output_index;
} compression_state_t;

void init_compression_state(compression_state_t *state, char *input_buffer) {
    state->input_buffer = input_buffer;
    state->output_buffer = malloc(BUFFER_SIZE);
    state->input_index = 0;
    state->output_index = 0;
}

void free_compression_state(compression_state_t *state) {
    free(state->output_buffer);
}

int compress_buffer(compression_state_t *state) {
    int i = 0;
    int j = 0;
    int count = 0;
    int buffer_size = BUFFER_SIZE - state->output_index;

    while (i < state->input_index) {
        if (isalpha(state->input_buffer[i])) {
            if (count == 0) {
                state->output_buffer[j++] = state->input_buffer[i];
            } else {
                state->output_buffer[j++] = '*';
            }
            count++;

            if (j == buffer_size + state->output_index) {
                state->output_buffer = realloc(state->output_buffer, buffer_size + BUFFER_SIZE);
                state->output_index += BUFFER_SIZE;
            }
        } else {
            state->output_buffer[j++] = state->input_buffer[i];
        }

        i++;
        count++;
    }

    state->output_buffer[j] = '\0';
    state->output_index += j;
    state->input_index = i;

    return 0;
}

int decompress_buffer(compression_state_t *state) {
    int i = 0;
    int j = 0;
    int count = 0;
    int buffer_size = BUFFER_SIZE - state->output_index;

    while (i < state->output_index) {
        if (state->output_buffer[i] == '*') {
            count++;
        } else {
            state->input_buffer[j++] = state->output_buffer[i];
            count = 0;
        }

        i++;
    }

    state->input_buffer[j] = '\0';
    state->input_index = j;

    return 0;
}

int main() {
    char input_buffer[4096];
    char output_buffer[4096];
    compression_state_t state;

    printf("Enter a string to compress: ");
    fgets(input_buffer, 4096, stdin);

    init_compression_state(&state, input_buffer);
    compress_buffer(&state);

    printf("Compressed string: %s\n", state.output_buffer);

    init_compression_state(&state, state.output_buffer);
    decompress_buffer(&state);

    printf("Decompressed string: %s\n", state.input_buffer);

    free_compression_state(&state);

    return 0;
}