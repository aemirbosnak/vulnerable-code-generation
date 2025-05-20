//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265358979323846
#define MAX_SIZE 1000

typedef struct {
    double *data;
    int size;
} Signal;

void create_signal(Signal *signal, int size) {
    signal->data = (double *)malloc(size * sizeof(double));
    signal->size = size;
    for (int i = 0; i < size; i++) {
        signal->data[i] = sin(2 * PI * i / size);
    }
}

void destroy_signal(Signal *signal) {
    free(signal->data);
    signal->data = NULL;
    signal->size = 0;
}

void print_signal(Signal *signal) {
    for (int i = 0; i < signal->size; i++) {
        printf("%f ", signal->data[i]);
    }
    printf("\n");
}

void convolve(Signal *signal1, Signal *signal2, Signal *result) {
    int size1 = signal1->size;
    int size2 = signal2->size;
    int size3 = size1 + size2 - 1;

    if (size3 > MAX_SIZE) {
        printf("Error: Result signal is too large.\n");
        return;
    }

    result->data = (double *)malloc(size3 * sizeof(double));
    result->size = size3;

    for (int i = 0; i < size3; i++) {
        double sum = 0;
        for (int j = 0; j < size2; j++) {
            int k = i - j + size1;
            if (k >= 0 && k < size3) {
                sum += signal1->data[j] * signal2->data[k];
            }
        }
        result->data[i] = sum;
    }
}

int main() {
    Signal signal1, signal2, result;
    int size1, size2;

    printf("Enter the size of the first signal: ");
    scanf("%d", &size1);
    create_signal(&signal1, size1);

    printf("Enter the size of the second signal: ");
    scanf("%d", &size2);
    create_signal(&signal2, size2);

    convolve(&signal1, &signal2, &result);
    printf("Result signal:\n");
    print_signal(&result);

    destroy_signal(&signal1);
    destroy_signal(&signal2);
    destroy_signal(&result);

    return 0;
}