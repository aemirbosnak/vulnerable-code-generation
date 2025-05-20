//FormAI DATASET v1.0 Category: Digital signal processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// function to generate a sine wave with specified frequency and amplitude
void generate_sine_wave(double *wave, int n_samples, double sampling_rate, double freq, double amp) {
    int i;
    double t;
    for (i = 0; i < n_samples; i++) {
        t = i / sampling_rate;
        wave[i] = amp * sin(2 * PI * freq * t);
    }
}

// function to generate a sawtooth wave with specified frequency and amplitude
void generate_sawtooth_wave(double *wave, int n_samples, double sampling_rate, double freq, double amp) {
    int i;
    double t;
    for (i = 0; i < n_samples; i++) {
        t = i / sampling_rate;
        wave[i] = amp * (2 * ((t * freq) - floor(0.5 + t * freq)) - 1);
    }
}

// function to compute the Fast Fourier Transform of a signal
void fft(double *signal, int n_samples, double *real_part, double *imag_part) {
    int i, j, k, n, m, bit;
    double c, s, tmp_re, tmp_im, theta;
    n = n_samples / 2;
    for (i = 0; i < n_samples; i++) {
        real_part[i] = signal[i];
        imag_part[i] = 0.0;
    }
    j = 0;
    for (i = 0; i < n_samples - 1; i++) {
        if (i < j) {
            tmp_re = real_part[j];
            real_part[j] = real_part[i];
            real_part[i] = tmp_re;
            tmp_im = imag_part[j];
            imag_part[j] = imag_part[i];
            imag_part[i] = tmp_im;
        }
        k = n;
        while (k <= j) {
            j -= k;
            k /= 2;
        }
        j += k;
    }
    m = 2;
    while (m <= n_samples) {
        theta = 2 * PI / m;
        for (i = 0; i < m / 2; i++) {
            c = cos(i * theta);
            s = sin(i * theta);
            for (j = i; j < n_samples; j += m) {
                k = j + m / 2;
                tmp_re = c * real_part[k] - s * imag_part[k];
                tmp_im = s * real_part[k] + c * imag_part[k];
                real_part[k] = real_part[j] - tmp_re;
                imag_part[k] = imag_part[j] - tmp_im;
                real_part[j] += tmp_re;
                imag_part[j] += tmp_im;
            }
        }
        m *= 2;
    }
}

int main() {
    int i, n_samples = 1024;
    double sampling_rate = 44100.0;
    double freq1 = 440.0, freq2 = 880.0;
    double amp1 = 1.0, amp2 = 0.5;
    double *sine_wave = (double *)malloc(n_samples * sizeof(double));
    double *sawtooth_wave = (double *)malloc(n_samples * sizeof(double));
    double *real_part = (double *)malloc(n_samples * sizeof(double));
    double *imag_part = (double *)malloc(n_samples * sizeof(double));
    double *power_spectrum = (double *)malloc(n_samples / 2 * sizeof(double));
    generate_sine_wave(sine_wave, n_samples, sampling_rate, freq1, amp1);
    generate_sawtooth_wave(sawtooth_wave, n_samples, sampling_rate, freq2, amp2);
    for (i = 0; i < n_samples; i++) {
        sine_wave[i] += sawtooth_wave[i];
    }
    fft(sine_wave, n_samples, real_part, imag_part);
    for (i = 0; i < n_samples / 2; i++) {
        power_spectrum[i] = sqrt(real_part[i] * real_part[i] + imag_part[i] * imag_part[i]);
    }
    printf("Frequency (Hz)\tPower (dB)\n");
    for (i = 0; i < n_samples / 2; i++) {
        printf("%.2f\t\t%.2f\n", i * sampling_rate / n_samples, 20 * log10(power_spectrum[i] / n_samples));
    }
    return 0;
}