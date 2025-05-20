//FormAI DATASET v1.0 Category: Audio processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    float *buffer;
    size_t buffer_size;
    size_t read_pos;
} DelayLine;

DelayLine* new_delay_line(size_t delay_size) {
    DelayLine *delay_line = (DelayLine*) malloc(sizeof(DelayLine));
    delay_line->buffer_size = delay_size * SAMPLE_RATE;
    delay_line->buffer = (float*) calloc(delay_line->buffer_size, sizeof(float));
    delay_line->read_pos = delay_line->buffer_size - 1;
    return delay_line;
}

void free_delay_line(DelayLine *delay_line) {
    free(delay_line->buffer);
    free(delay_line);
}

float delay(DelayLine *delay_line, float input, float feedback, float delay_time) {
    float output = delay_line->buffer[delay_line->read_pos];
    delay_line->buffer[delay_line->read_pos] = input + feedback * output;
    delay_line->read_pos = (delay_line->read_pos + 1) % delay_line->buffer_size;
    size_t write_pos = (delay_line->read_pos + (size_t)(delay_time * SAMPLE_RATE)) % delay_line->buffer_size;
    return output + delay_line->buffer[write_pos];
}

int main() {
    DelayLine *delay_line = new_delay_line(1);
    float feedback = 0.5;
    float delay_time = 0.5;
    float left_buffer[BUFFER_SIZE];
    float right_buffer[BUFFER_SIZE];
    float delay_buffer[BUFFER_SIZE];
    while (1) {
        // Read input from audio device
        // ...
        // Process audio
        for (int i = 0; i < BUFFER_SIZE; i++) {
            float input = (left_buffer[i] + right_buffer[i]) / 2.0;
            float delayed = delay(delay_line, input, feedback, delay_time);
            delay_buffer[i] = delayed;
        }
        // Write output to audio device
        // ...
    }
    free_delay_line(delay_line);
    return 0;
}