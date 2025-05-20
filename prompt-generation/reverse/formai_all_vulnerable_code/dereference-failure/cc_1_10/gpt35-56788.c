//FormAI DATASET v1.0 Category: Audio processing ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846f

typedef struct {
    float *data;
    size_t length;
} signal_t;

typedef struct {
    float *real;
    float *imag;
    size_t length;
} spectrum_t;

signal_t* create_signal(size_t length) {
    signal_t *signal = (signal_t*)malloc(sizeof(signal_t));
    signal->data = (float*)malloc(sizeof(float) * length);
    signal->length = length;
    memset(signal->data, 0, sizeof(float) * length);
    return signal;
}

void destroy_signal(signal_t *signal) {
    if (signal) {
        if (signal->data) {
            free(signal->data);
        }
        free(signal);
    }
}

spectrum_t* create_spectrum(size_t length) {
    spectrum_t *spectrum = (spectrum_t*)malloc(sizeof(spectrum_t));
    spectrum->real = (float*)malloc(sizeof(float) * length);
    spectrum->imag = (float*)malloc(sizeof(float) * length);
    spectrum->length = length;
    memset(spectrum->real, 0, sizeof(float) * length);
    memset(spectrum->imag, 0, sizeof(float) * length);
    return spectrum;
}

void destroy_spectrum(spectrum_t *spectrum) {
    if (spectrum) {
        if (spectrum->real) {
            free(spectrum->real);
        }
        if (spectrum->imag) {
            free(spectrum->imag);
        }
        free(spectrum);
    }
}

void add_spectrums(spectrum_t *s1, spectrum_t *s2, spectrum_t *result) {
    for (size_t i = 0; i < s1->length; i++) {
        result->real[i] = s1->real[i] + s2->real[i];
        result->imag[i] = s1->imag[i] + s2->imag[i];
    }
}

void subtract_spectrums(spectrum_t *s1, spectrum_t *s2, spectrum_t *result) {
    for (size_t i = 0; i < s1->length; i++) {
        result->real[i] = s1->real[i] - s2->real[i];
        result->imag[i] = s1->imag[i] - s2->imag[i];
    }
}

void multiply_spectrums(spectrum_t *s1, spectrum_t *s2, spectrum_t *result) {
    for (size_t i = 0; i < s1->length; i++) {
        result->real[i] = s1->real[i] * s2->real[i] - s1->imag[i] * s2->imag[i];
        result->imag[i] = s1->real[i] * s2->imag[i] + s1->imag[i] * s2->real[i];
    }
}

void fft(signal_t *signal, spectrum_t *spectrum) {
    const size_t n = spectrum->length;
    float *Xre = spectrum->real;
    float *Xim = spectrum->imag;
    float *x = signal->data;
    double w = -2 * PI / n;
    for (size_t i = 0, j = 0; i < n; i++) {
        if (j > i) {
            float t = x[i];
            x[i] = x[j];
            x[j] = t;
        }
        size_t m = n >> 1;
        while (m >= 1 && j >= m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    }
    for (size_t i = 0; i < n; i++) {
        Xre[i] = x[i];
        Xim[i] = 0;
    }
    for (size_t k = 1; k < n; k <<= 1) {
        for (size_t i = 0; i < k; i++) {
            double co = cos(w * i);
            double si = sin(w * i);
            for (size_t j = i; j < n; j += k << 1) {
                size_t l = j + k;
                double tr = co * Xre[l] - si * Xim[l];
                double ti = co * Xim[l] + si * Xre[l];
                Xre[l] = Xre[j] - tr;
                Xim[l] = Xim[j] - ti;
                Xre[j] += tr;
                Xim[j] += ti;
            }
        }
    }
}

void ifft(spectrum_t *spectrum, signal_t *signal) {
    const size_t n = spectrum->length;
    float *Xre = spectrum->real;
    float *Xim = spectrum->imag;
    float *x = signal->data;
    double w = 2 * PI / n;
    for (size_t i = 0; i < n; i++) {
        Xim[i] = -Xim[i];
    }
    fft(signal, spectrum);
    for (size_t i = 0; i < n; i++) {
        Xre[i] /= n;
        Xim[i] /= -n;
    }
}

void print_signal(signal_t *signal) {
    for (size_t i = 0; i < signal->length; i++) {
        printf("%f ", signal->data[i]);
    }
    printf("\n");
}

int main() {
    const size_t length = 8;
    signal_t *signal1 = create_signal(length);
    signal_t *signal2 = create_signal(length);
    signal_t *sum_signal = create_signal(length);
    spectrum_t *spectrum1 = create_spectrum(length);
    spectrum_t *spectrum2 = create_spectrum(length);
    spectrum_t *sum_spectrum = create_spectrum(length);
    memset(signal1->data, 0, sizeof(float) * length);
    memset(signal2->data, 0, sizeof(float) * length);
    memset(spectrum1->real, 0, sizeof(float) * length);
    memset(spectrum1->imag, 0, sizeof(float) * length);
    memset(spectrum2->real, 0, sizeof(float) * length);
    memset(spectrum2->imag, 0, sizeof(float) * length);
    signal1->data[0] = 1.0;
    signal2->data[1] = 1.0;
    fft(signal1, spectrum1);
    fft(signal2, spectrum2);
    multiply_spectrums(spectrum1, spectrum2, sum_spectrum);
    ifft(sum_spectrum, sum_signal);
    print_signal(sum_signal);
    destroy_signal(signal1);
    destroy_signal(signal2);
    destroy_signal(sum_signal);
    destroy_spectrum(spectrum1);
    destroy_spectrum(spectrum2);
    destroy_spectrum(sum_spectrum);
    return 0;
}