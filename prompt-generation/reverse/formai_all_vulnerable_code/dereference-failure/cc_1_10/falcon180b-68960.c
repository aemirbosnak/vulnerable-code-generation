//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define MAX_DELAY_TIME 5000
#define MAX_FEEDBACK 0.9
#define MAX_GAIN 10

typedef struct {
    float *buffer;
    int buffer_size;
    int read_index;
    int write_index;
} DelayLine;

void init_delay_line(DelayLine *delay_line) {
    delay_line->buffer = (float *)malloc(delay_line->buffer_size * sizeof(float));
    delay_line->read_index = 0;
    delay_line->write_index = 0;
    for (int i = 0; i < delay_line->buffer_size; i++) {
        delay_line->buffer[i] = 0;
    }
}

void process_delay_line(DelayLine *delay_line, float input, float *output, float gain) {
    float feedback = 0;
    if (delay_line->write_index > 0) {
        feedback = delay_line->buffer[delay_line->read_index] * gain;
    }
    *output = input + feedback;
    delay_line->buffer[delay_line->write_index] = *output;
    delay_line->read_index = (delay_line->read_index + 1) % delay_line->buffer_size;
    delay_line->write_index = (delay_line->write_index + 1) % delay_line->buffer_size;
}

int main() {
    DelayLine delay_line;
    init_delay_line(&delay_line);

    float input_buffer[BUFFER_SIZE];
    float output_buffer[BUFFER_SIZE];
    float gain = 0;
    bool delay_active = false;

    while (true) {
        for (int i = 0; i < BUFFER_SIZE; i++) {
            float sample = 0;
            if (delay_active) {
                sample = input_buffer[i] + delay_line.buffer[delay_line.read_index] * gain;
            } else {
                sample = input_buffer[i];
            }
            output_buffer[i] = sample;
        }

        for (int i = 0; i < BUFFER_SIZE; i++) {
            input_buffer[i] = output_buffer[i];
        }

        if (delay_active) {
            delay_line.buffer[delay_line.write_index] = input_buffer[0];
            delay_active = false;
        } else if (gain < MAX_GAIN) {
            gain += 0.01;
        } else {
            delay_active = true;
            gain = 0;
        }
    }

    return 0;
}