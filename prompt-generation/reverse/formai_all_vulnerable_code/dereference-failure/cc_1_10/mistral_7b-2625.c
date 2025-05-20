//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double b[3];
    double a[3];
} IIR_filter;

void initIIRFilter(IIR_filter *filter, double b0, double b1, double b2, double a1, double a2) {
    filter->a[0] = 1.0;
    filter->a[1] = a1;
    filter->a[2] = a2;

    filter->b[0] = b0;
    filter->b[1] = b1;
    filter->b[2] = b2;
}

double applyIIRFilter(IIR_filter *filter, double input) {
    double output = input * filter->b[0];
    double temp = filter->a[1] * input + filter->a[2] * output;

    filter->a[0] = filter->a[1];
    filter->a[1] = temp;

    return output;
}

int main() {
    int N = 1024;
    double fs = 8000.0;
    double sample_time = 1.0 / fs;

    IIR_filter filter;
    initIIRFilter(&filter, 0.6, 0.8, 0.3, 1.0, 0.5);

    double *input = (double *)calloc(N, sizeof(double));
    double *output = (double *)calloc(N, sizeof(double));

    for (int i = 0; i < N; i++) {
        input[i] = sin(2 * PI * i / (N / 2) * sample_time);
        output[i] = applyIIRFilter(&filter, input[i]);
    }

    FILE *fp = fopen("output.wav", "wb");

    for (int i = 0; i < N; i++) {
        fwrite(&output[i], sizeof(double), 1, fp);
    }

    fclose(fp);

    free(input);
    free(output);

    return 0;
}