//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Sine wave generator
double sine(double frequency, double sampleRate, double time) {
    return sin(2 * M_PI * frequency * time / sampleRate);
}

// Square wave generator
double square(double frequency, double sampleRate, double time) {
    return signbit(sin(2 * M_PI * frequency * time / sampleRate));
}

// Triangle wave generator
double triangle(double frequency, double sampleRate, double time) {
    return 2 * fabs(fmod(sin(2 * M_PI * frequency * time / sampleRate), 1)) - 1;
}

// Sawtooth wave generator
double sawtooth(double frequency, double sampleRate, double time) {
    return 2 * (fmod(sin(2 * M_PI * frequency * time / sampleRate), 1) - 0.5);
}

// Generate a white noise signal
double white_noise(double sampleRate, double time) {
    return 2 * (rand() / (double)RAND_MAX) - 1;
}

// Generate a pink noise signal
double pink_noise(double sampleRate, double time) {
    double f = rand() / (double)RAND_MAX;
    double a = 1 / f;
    double b = 1 - a;
    double x_prev = white_noise(sampleRate, time);
    double x = a * x_prev + b * white_noise(sampleRate, time);
    return x;
}

// Generate a brown noise signal
double brown_noise(double sampleRate, double time) {
    double f = rand() / (double)RAND_MAX;
    double a = 1 / f;
    double b = 1 - a;
    double x_prev = brown_noise(sampleRate, time);
    double x = a * x_prev + b * white_noise(sampleRate, time);
    return x;
}

// Main function
int main() {
    // Set the sample rate
    double sampleRate = 44100;

    // Set the duration of the audio signal
    double duration = 1;

    // Create an array to store the audio signal
    double *audioSignal = malloc(sizeof(double) * sampleRate * duration);

    // Generate a sine wave
    for (int i = 0; i < sampleRate * duration; i++) {
        audioSignal[i] = sine(440, sampleRate, i / sampleRate);
    }

    // Write the audio signal to a file
    FILE *fp = fopen("sine_wave.wav", "wb");
    fwrite(audioSignal, sizeof(double), sampleRate * duration, fp);
    fclose(fp);

    return 0;
}