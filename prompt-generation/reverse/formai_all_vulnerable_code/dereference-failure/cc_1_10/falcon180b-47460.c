//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATA_SIZE 1024
#define WATERMARK_SIZE 64

typedef struct {
    double *data;
    int size;
} Data;

typedef struct {
    double *data;
    int size;
} Watermark;

double get_random_number(double min, double max) {
    return rand() % 1000000 * (max - min) / 1000000 + min;
}

void generate_watermark(Watermark *watermark) {
    watermark->size = WATERMARK_SIZE;
    watermark->data = (double *)malloc(WATERMARK_SIZE * sizeof(double));
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        watermark->data[i] = get_random_number(0, 1);
    }
}

void add_watermark(Data *data, Watermark *watermark) {
    for (int i = 0; i < data->size; i++) {
        data->data[i] += watermark->data[i % WATERMARK_SIZE];
    }
}

void remove_watermark(Data *data, Watermark *watermark) {
    for (int i = 0; i < data->size; i++) {
        data->data[i] -= watermark->data[i % WATERMARK_SIZE];
    }
}

int main() {
    Data data;
    Watermark watermark;

    generate_watermark(&watermark);
    data.data = (double *)malloc(DATA_SIZE * sizeof(double));
    for (int i = 0; i < DATA_SIZE; i++) {
        data.data[i] = get_random_number(0, 1);
    }

    add_watermark(&data, &watermark);

    for (int i = 0; i < DATA_SIZE; i++) {
        printf("%f ", data.data[i]);
    }

    remove_watermark(&data, &watermark);

    for (int i = 0; i < DATA_SIZE; i++) {
        printf("%f ", data.data[i]);
    }

    free(data.data);
    free(watermark.data);

    return 0;
}