//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024
#define NUM_CHANNELS 2
#define NUM_FRAMES 44100 // One second of audio

typedef struct {
    float *data;
    int capacity;
    int size;
} Buffer;

void init_buffer(Buffer *buffer, int capacity) {
    buffer->data = (float *)malloc(capacity * sizeof(float));
    buffer->capacity = capacity;
    buffer->size = 0;
}

void push_sample(Buffer *buffer, float sample) {
    if (buffer->size == buffer->capacity) {
        printf("Buffer overflow\n");
        exit(1);
    }
    buffer->data[buffer->size++] = sample;
}

void process_audio(float *input_buffer, float *output_buffer, int num_frames, float gain) {
    for (int i = 0; i < num_frames; i++) {
        for (int j = 0; j < NUM_CHANNELS; j++) {
            float sample = input_buffer[i * NUM_CHANNELS + j] * gain;
            output_buffer[i * NUM_CHANNELS + j] = sample;
        }
    }
}

int main() {
    Buffer input_buffer;
    init_buffer(&input_buffer, FRAME_SIZE);

    FILE *input_file = fopen("input.wav", "rb");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    float *output_buffer = (float *)malloc(FRAME_SIZE * NUM_CHANNELS * sizeof(float));

    int num_frames_read = 0;
    while (num_frames_read < NUM_FRAMES) {
        int bytes_read = fread(input_buffer.data + num_frames_read * NUM_CHANNELS, sizeof(float), FRAME_SIZE - num_frames_read * NUM_CHANNELS, input_file);
        if (bytes_read <= 0) {
            printf("Error reading input file\n");
            exit(1);
        }
        num_frames_read += bytes_read / NUM_CHANNELS;
    }

    float gain = 2.0;
    process_audio(input_buffer.data, output_buffer, NUM_FRAMES, gain);

    FILE *output_file = fopen("output.wav", "wb");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    fwrite(output_buffer, sizeof(float), NUM_FRAMES * NUM_CHANNELS, output_file);

    free(output_buffer);
    fclose(input_file);
    fclose(output_file);

    return 0;
}