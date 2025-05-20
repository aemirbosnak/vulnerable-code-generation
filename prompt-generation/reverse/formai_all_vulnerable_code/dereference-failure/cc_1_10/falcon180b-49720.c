//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000
#define PI 3.14159265358979323846

double *generate_data(int size) {
    double *data = (double *) malloc(size * sizeof(double));
    int i;
    for (i = 0; i < size; i++) {
        data[i] = sin(2 * PI * i / size);
    }
    return data;
}

void compute_fft(double *data, int size) {
    int i, j, k;
    double w_r, w_i, w_r_k, w_i_k, t_r, t_i;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            w_r = cos(2 * PI * j * i / size);
            w_i = sin(2 * PI * j * i / size);
            w_r_k = cos(2 * PI * j * k / size);
            w_i_k = sin(2 * PI * j * k / size);
            t_r = w_r_k * data[i] - w_i_k * data[k];
            t_i = w_i_k * data[i] + w_r_k * data[k];
            data[i] = data[k];
            data[k] = t_r;
        }
    }
}

void print_data(double *data, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%lf ", data[i]);
    }
    printf("\n");
}

int main() {
    int size = MAX_SIZE;
    double *data = generate_data(size);
    double start_time, end_time;

    start_time = clock();
    compute_fft(data, size);
    end_time = clock();

    printf("Time taken: %lf seconds\n", (double) (end_time - start_time) / CLOCKS_PER_SEC);

    print_data(data, size);

    free(data);

    return 0;
}