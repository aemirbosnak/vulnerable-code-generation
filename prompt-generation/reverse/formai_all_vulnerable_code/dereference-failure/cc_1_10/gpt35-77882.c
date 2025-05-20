//FormAI DATASET v1.0 Category: Audio processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void generate_sine_wave(double frequency, double duration, double sample_rate, short **waveform, int *length);
void normalize(short *waveform, int length);
void low_pass_filter(short *waveform, int length, double cutoff_frequency, double sample_rate);

int main()
{
    double frequency = 1000.0; // Hz
    double duration = 1.0; // seconds
    double sample_rate = 44100.0; // samples per second
    double cutoff_frequency = 5000.0; // Hz

    short *waveform = NULL;
    int length = 0;

    generate_sine_wave(frequency, duration, sample_rate, &waveform, &length);

    normalize(waveform, length);

    low_pass_filter(waveform, length, cutoff_frequency, sample_rate);

    // Output the waveform to a file
    FILE *outfile = fopen("output.pcm", "wb");
    fwrite(waveform, sizeof(short), length, outfile);
    fclose(outfile);

    free(waveform);

    return 0;
}

void generate_sine_wave(double frequency, double duration, double sample_rate, short **waveform, int *length)
{
    *length = (int) (duration * sample_rate);
    *waveform = (short *) malloc(*length * sizeof(short));

    int i;
    for (i = 0; i < *length; i++) {
        double t = (double) i / sample_rate;
        double amplitude = 32767 * 0.8;
        double value = amplitude * sin(2 * PI * frequency * t);
        (*waveform)[i] = (short) value;
    }
}

void normalize(short *waveform, int length)
{
    int i;
    short max_amplitude = 0;

    for (i = 0; i < length; i++) {
        if (abs(waveform[i]) > max_amplitude) {
            max_amplitude = abs(waveform[i]);
        }
    }

    double factor = 32767.0 / (double) max_amplitude;

    for (i = 0; i < length; i++) {
        waveform[i] = (short) ((double) waveform[i] * factor);
    }
}

void low_pass_filter(short *waveform, int length, double cutoff_frequency, double sample_rate)
{
    int n, k;
    double *coefficients = (double *) malloc(length * sizeof(double));

    double omega_c = 2 * PI * cutoff_frequency / sample_rate;

    for (n = 0; n < length; n++) {
        coefficients[n] = sin(omega_c * (n - length / 2)) / (PI * (n - length / 2));
        coefficients[n] *= 0.54 - 0.46 * cos(2 * PI * n / (length - 1)); // Hanning window
    }

    for (n = 0; n < length; n++) {
        double sum = 0;
        for (k = 0; k < length; k++) {
            sum += coefficients[k] * waveform[(n + k) % length];
        }
        waveform[n] = (short) sum;
    }

    free(coefficients);
}