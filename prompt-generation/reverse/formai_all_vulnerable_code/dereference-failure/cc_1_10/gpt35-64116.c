//FormAI DATASET v1.0 Category: Audio processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100.0
#define AMPLITUDE 1.0

double sine_wave(double frequency, double time)
{
    double sine = sin(2.0 * M_PI * frequency * time);
    return sine;
}

double square_wave(double frequency, double time)
{
    double period = 1.0 / frequency;
    double value = fmod(time, period) / period;
    
    if (value < 0.5)
    {
        return 1.0;
    }
    else
    {
        return -1.0;
    }
}

double sawtooth_wave(double frequency, double time)
{
    double period = 1.0 / frequency;
    double value = fmod(time, period) / period;
    
    return (value * 2.0) - 1.0;
}

double triangle_wave(double frequency, double time)
{
    double period = 1.0 / frequency;
    double value = fmod(time, period) / period;
    
    if (value < 0.5)
    {
        return (value * 4.0) - 1.0;
    }
    else
    {
        return (-value * 4.0) + 3.0;
    }
}

int main()
{
    double frequency = 440.0;
    double duration = 5.0;
    double time_step = 1.0 / SAMPLE_RATE;

    double *sine_waveform = calloc(SAMPLE_RATE * duration, sizeof(double));
    double *square_waveform = calloc(SAMPLE_RATE * duration, sizeof(double));
    double *sawtooth_waveform = calloc(SAMPLE_RATE * duration, sizeof(double));
    double *triangle_waveform = calloc(SAMPLE_RATE * duration, sizeof(double));

    double time = 0.0;
    for (int i = 0; i < SAMPLE_RATE * duration; i++)
    {
        sine_waveform[i] = sine_wave(frequency, time);
        square_waveform[i] = square_wave(frequency, time);
        sawtooth_waveform[i] = sawtooth_wave(frequency, time);
        triangle_waveform[i] = triangle_wave(frequency, time);

        time += time_step;
    }

    FILE *sine_file = fopen("sine_wave.raw", "wb");
    FILE *square_file = fopen("square_wave.raw", "wb");
    FILE *sawtooth_file = fopen("sawtooth_wave.raw", "wb");
    FILE *triangle_file = fopen("triangle_wave.raw", "wb");

    for (int i = 0; i < SAMPLE_RATE * duration; i++)
    {
        double sine_sample = AMPLITUDE * sine_waveform[i];
        double square_sample = AMPLITUDE * square_waveform[i];
        double sawtooth_sample = AMPLITUDE * sawtooth_waveform[i];
        double triangle_sample = AMPLITUDE * triangle_waveform[i];

        fwrite(&sine_sample, sizeof(double), 1, sine_file);
        fwrite(&square_sample, sizeof(double), 1, square_file);
        fwrite(&sawtooth_sample, sizeof(double), 1, sawtooth_file);
        fwrite(&triangle_sample, sizeof(double), 1, triangle_file);
    }

    fclose(sine_file);
    fclose(square_file);
    fclose(sawtooth_file);
    fclose(triangle_file);

    free(sine_waveform);
    free(square_waveform);
    free(sawtooth_waveform);
    free(triangle_waveform);

    return 0;
}