//FormAI DATASET v1.0 Category: Digital signal processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
This program computes the Fourier transform of an input signal using the Cooley-Tukey algorithm.
It takes a one-dimensional signal of length N, and outputs its frequency-domain representation.
The algorithm uses a divide-and-conquer approach, dividing the input signal into two halves recursively
and performing Fourier transforms on each half. The results are then combined using complex multiplications
to form the final output.
*/

// Define complex number struct
typedef struct {
    double real;
    double imag;
} complex;

// Perform complex multiplication
complex cmult(complex x, complex y) {
    complex z;
    z.real = x.real * y.real - x.imag * y.imag;
    z.imag = x.real * y.imag + x.imag * y.real;
    return z;
}

// Perform Fourier transform on a sequence
void fft(complex *seq, int N) {
    // Base case for recursion
    if (N == 1) {
        return;
    }
    // Divide the sequence into even and odd halves
    complex *even = malloc(N/2 * sizeof(complex));
    complex *odd = malloc(N/2 * sizeof(complex));
    for (int i = 0; i < N/2; i++) {
        even[i] = seq[2*i];
        odd[i] = seq[2*i+1];
    }
    // Recursively compute Fourier transforms for the even and odd halves
    fft(even, N/2);
    fft(odd, N/2);
    // Combine the Fourier transforms of the two halves using complex multiplications
    for (int k = 0; k < N/2; k++) {
        complex temp = cmult(odd[k], (complex){cos(2*M_PI*k/N), -sin(2*M_PI*k/N)});
        seq[k] = even[k];
        seq[k+N/2] = (complex){even[k].real + temp.real, even[k].imag + temp.imag};
    }
    free(even);
    free(odd);
}

int main() {
    // Generate input signal
    int N = 16;
    complex *seq = malloc(N * sizeof(complex));
    for (int i = 0; i < N; i++) {
        seq[i] = (complex){cos(2*M_PI*i/N), 0};
    }
    // Compute Fourier transform using Cooley-Tukey algorithm
    fft(seq, N);
    // Print frequency-domain representation of input signal
    for (int i = 0; i < N; i++) {
        printf("Frequency %d: (%f, %f)\n", i, seq[i].real, seq[i].imag);
    }
    free(seq);
    return 0;
}