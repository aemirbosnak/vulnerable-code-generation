//FormAI DATASET v1.0 Category: Digital signal processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE      44100  // CD quality audio sample rate
#define CUTOFF_FREQUENCY 5000   // Cutoff frequency in Hz
#define FILTER_ORDER     2      // Filter order (number of poles)

// Utility function to allocate a vector of doubles
double* vector_double(int n) {
    return (double*) calloc(n, sizeof(double));
}

// Utility function to compute the sinc function
void sinc(double* x, double* y, int n) {
    int i;
    for (i = 0; i < n; i++) {
        double arg = M_PI * x[i];
        if (arg == 0.0) {
            y[i] = 1.0;
        } else {
            y[i] = sin(arg) / arg;
        }
    }
}

// Utility function to compute the hamming window function
void hamming(double* x, double* y, int n) {
    int i;
    for (i = 0; i < n; i++) {
        y[i] = 0.54 - 0.46 * cos(2 * M_PI * i / (n - 1));
    }
}

// Utility function to compute the frequency response of a digital filter
void frequency_response(double* b, double* a, int nb, int na, double* H, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        double w = M_PI * i / (n - 1);
        double num = 0.0, den = 0.0;
        for (j = 0; j < nb; j++) {
            num += b[j] * cos(w * j);
        }
        for (j = 0; j < na; j++) {
            den += a[j] * cos(w * j);
        }
        H[i] = num / den;
    }
}

int main() {
    double* x;   // Input signal vector
    double* y;   // Output signal vector
    double* b;   // Filter coefficients (numerator)
    double* a;   // Filter coefficients (denominator)
    double* H;   // Filter frequency response
    double* t;   // Time vector
    double* h;   // Impulse response vector
    int n = 1024; // Signal length
    int i, j;

    // Allocate memory
    x = vector_double(n);
    y = vector_double(n);
    b = vector_double(FILTER_ORDER + 1);
    a = vector_double(FILTER_ORDER + 1);
    H = vector_double(n);
    t = vector_double(n);
    h = vector_double(n);

    // Generate input signal
    for (i = 0; i < n; i++) {
        double time = (double) i / SAMPLE_RATE;
        x[i] = sin(2 * M_PI * CUTOFF_FREQUENCY * time);
        t[i] = time;
    }

    // Compute filter coefficients
    sinc(vector_double(FILTER_ORDER + 1), b, FILTER_ORDER + 1);
    hamming(vector_double(FILTER_ORDER + 1), b, FILTER_ORDER + 1);
    for (i = 0; i <= FILTER_ORDER; i++) {
        a[i] = 0.0;
    }
    a[0] = b[0];
    for (i = 1; i <= FILTER_ORDER; i++) {
        a[0] += b[i];
        a[i] = -b[i];
    }

    // Compute filter frequency response
    frequency_response(b, a, FILTER_ORDER + 1, FILTER_ORDER + 1, H, n);

    // Compute impulse response
    for (i = 0; i < n; i++) {
        double t0 = (double) i / SAMPLE_RATE;
        double s = 0.0;
        for (j = 0; j <= FILTER_ORDER; j++) {
            double t1 = (double) j / SAMPLE_RATE;
            s += b[j] * sin(2 * M_PI * CUTOFF_FREQUENCY * (t0 - t1)) / (M_PI * (t0 - t1));
        }
        h[i] = s;
    }

    // Apply filter to input signal
    for (i = 0; i < n; i++) {
        double s = 0.0;
        for (j = 0; j <= FILTER_ORDER; j++) {
            if (i - j >= 0) {
                s += b[j] * x[i - j];
            }
            if (i - j - 1 >= 0) {
                s -= a[j + 1] * y[i - j - 1];
            }
        }
        y[i] = s / a[0];
    }

    // Write output signal to stdout
    for (i = 0; i < n; i++) {
        printf("%f %f %f %f\n", t[i], x[i], y[i], h[i]);
    }

    // Deallocate memory
    free(x);
    free(y);
    free(b);
    free(a);
    free(H);
    free(t);
    free(h);

    return 0;
}