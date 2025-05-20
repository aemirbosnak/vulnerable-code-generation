//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define MAX_DELAY 2000

typedef struct {
    float *buffer;
    int read_index;
    int write_index;
    int size;
    int delay;
} DelayLine;

void init_delay_line(DelayLine *dl, int size) {
    dl->buffer = (float *)malloc(size * sizeof(float));
    dl->size = size;
    dl->read_index = 0;
    dl->write_index = 0;
    dl->delay = 0;
}

void free_delay_line(DelayLine *dl) {
    free(dl->buffer);
}

void write_delay_line(DelayLine *dl, float sample) {
    dl->buffer[dl->write_index] = sample;
    dl->write_index = (dl->write_index + 1) % dl->size;
}

float read_delay_line(DelayLine *dl, int delay) {
    int index = (dl->read_index - delay + dl->size) % dl->size;
    return dl->buffer[index];
}

void process_audio(float *input, float *output, int num_samples, DelayLine *delay_line, int delay) {
    for (int i = 0; i < num_samples; i++) {
        float sample = input[i];
        float delayed_sample = read_delay_line(delay_line, delay);
        float wet_sample = sample + 0.5f * delayed_sample;
        float dry_sample = sample - 0.5f * delayed_sample;
        output[i] = wet_sample;
        write_delay_line(delay_line, wet_sample);
    }
}

int main() {
    int num_samples = SAMPLE_RATE / 1000;
    float *input = (float *)malloc(num_samples * sizeof(float));
    float *output = (float *)malloc(num_samples * sizeof(float));
    DelayLine delay_line;
    init_delay_line(&delay_line, MAX_DELAY);

    for (int i = 0; i < num_samples; i++) {
        input[i] = sin(2 * M_PI * i / SAMPLE_RATE);
    }

    process_audio(input, output, num_samples, &delay_line, 1000);

    for (int i = 0; i < num_samples; i++) {
        printf("%f\n", output[i]);
    }

    free_delay_line(&delay_line);
    free(input);
    free(output);

    return 0;
}