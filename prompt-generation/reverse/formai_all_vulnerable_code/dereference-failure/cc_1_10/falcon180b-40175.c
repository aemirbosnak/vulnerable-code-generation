//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    float *data;
    int length;
} signal_t;

signal_t *create_signal(int length) {
    signal_t *signal = malloc(sizeof(signal_t));
    signal->data = malloc(length * sizeof(float));
    signal->length = length;
    for (int i = 0; i < length; i++) {
        signal->data[i] = 0.0;
    }
    return signal;
}

void destroy_signal(signal_t *signal) {
    free(signal->data);
    free(signal);
}

void fill_buffer(float *buffer, int length, signal_t *signal) {
    int offset = 0;
    for (int i = 0; i < length; i++) {
        buffer[i] = signal->data[offset];
        offset++;
        if (offset >= signal->length) {
            offset = 0;
        }
    }
}

void apply_filter(float *buffer, int length, float *filter_coefficients, int filter_length) {
    float sum = 0.0;
    for (int i = 0; i < filter_length; i++) {
        sum += buffer[i] * filter_coefficients[i];
    }
    buffer[0] = sum;
}

int main() {
    signal_t *signal = create_signal(44100);
    float *buffer = malloc(BUFFER_SIZE * sizeof(float));
    float *filter_coefficients = malloc(5 * sizeof(float));
    filter_coefficients[0] = 1.0;
    filter_coefficients[1] = -1.0;
    filter_coefficients[2] = 1.0;
    filter_coefficients[3] = -1.0;
    filter_coefficients[4] = 1.0;

    for (int i = 0; i < 44100; i++) {
        signal->data[i] = sin(2.0 * M_PI * i / SAMPLE_RATE);
    }

    for (int i = 0; i < 44100; i++) {
        fill_buffer(buffer, BUFFER_SIZE, signal);
        apply_filter(buffer, BUFFER_SIZE, filter_coefficients, 5);
        for (int j = 0; j < BUFFER_SIZE; j++) {
            printf("%f ", buffer[j]);
        }
        printf("\n");
    }

    destroy_signal(signal);
    free(buffer);
    free(filter_coefficients);

    return 0;
}