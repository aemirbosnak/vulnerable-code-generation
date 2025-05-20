//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define MAX_DELAY_TIME 10.0

typedef struct {
    float *buffer;
    int buffer_size;
    int read_index;
    int write_index;
} DelayLine;

void init_delay_line(DelayLine *delay_line, int buffer_size) {
    delay_line->buffer_size = buffer_size;
    delay_line->buffer = malloc(buffer_size * sizeof(float));
    delay_line->read_index = 0;
    delay_line->write_index = 0;
    memset(delay_line->buffer, 0, buffer_size * sizeof(float));
}

void write_to_delay_line(DelayLine *delay_line, float input_sample) {
    delay_line->buffer[delay_line->write_index] = input_sample;
    delay_line->write_index = (delay_line->write_index + 1) % delay_line->buffer_size;
}

float read_from_delay_line(DelayLine *delay_line, float delay_time) {
    int index = (int)(delay_time * SAMPLE_RATE / 1000);
    if (index < 0) {
        index = 0;
    }
    else if (index >= delay_line->buffer_size) {
        index = delay_line->buffer_size - 1;
    }
    return delay_line->buffer[(delay_line->read_index + index) % delay_line->buffer_size];
}

int main() {
    int i;
    float input_sample, output_sample, delay_time;
    DelayLine delay_line;

    init_delay_line(&delay_line, BUFFER_SIZE);

    for (i = 0; i < SAMPLE_RATE; i++) {
        input_sample = 0.0;
        read_from_delay_line(&delay_line, delay_time);
        output_sample = input_sample + delay_time * input_sample;
        write_to_delay_line(&delay_line, output_sample);
        printf("%f\n", output_sample);
    }

    return 0;
}