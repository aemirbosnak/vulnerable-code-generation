//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    float *data;
    int size;
} Signal;

void init_signal(Signal *signal, int size) {
    signal->data = (float*)malloc(sizeof(float) * size);
    signal->size = size;
    for (int i = 0; i < size; i++) {
        signal->data[i] = 0.0;
    }
}

void free_signal(Signal *signal) {
    free(signal->data);
}

void fill_signal(Signal *signal, float value) {
    for (int i = 0; i < signal->size; i++) {
        signal->data[i] = value;
    }
}

void print_signal(Signal *signal) {
    for (int i = 0; i < signal->size; i++) {
        printf("%f ", signal->data[i]);
    }
    printf("\n");
}

void apply_gain(Signal *signal, float gain) {
    for (int i = 0; i < signal->size; i++) {
        signal->data[i] *= gain;
    }
}

void low_pass_filter(Signal *signal, float cutoff_frequency, float sample_rate) {
    float wc = 2 * PI * cutoff_frequency / sample_rate;
    float cos_wc = cos(wc);
    float sin_wc = sin(wc);

    for (int i = 0; i < signal->size; i++) {
        float y = 0.0;
        for (int j = 0; j < i; j++) {
            y += signal->data[j] * cos_wc;
        }
        for (int j = i; j < signal->size; j++) {
            y += signal->data[j] * sin_wc;
        }
        signal->data[i] = y;
    }
}

int main() {
    Signal signal;
    init_signal(&signal, BUFFER_SIZE);

    fill_signal(&signal, 1.0);
    print_signal(&signal);

    apply_gain(&signal, 0.5);
    print_signal(&signal);

    low_pass_filter(&signal, 1000, SAMPLE_RATE);
    print_signal(&signal);

    free_signal(&signal);
    return 0;
}