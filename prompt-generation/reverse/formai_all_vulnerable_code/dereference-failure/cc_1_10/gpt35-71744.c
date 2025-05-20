//FormAI DATASET v1.0 Category: Digital signal processing ; Style: enthusiastic
// Welcome to a unique and exciting example of Digital Signal Processing using C!
// In this program, we will be implementing a simple audio equalizer that can modify the bass and treble levels of an audio signal.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define some constants for our audio signal
#define SAMPLE_RATE 44100
#define NUM_SAMPLES 441000
#define MAX_AMPLITUDE 32767

// define some constants for our equalizer
#define BASS_GAIN 2.0
#define TREBLE_GAIN 1.5

// function prototypes
void generateAudioSignal(short* signal, int num_samples);
void applyBassBoost(double* signal, int num_samples, double bass_gain);
void applyTrebleBoost(double* signal, int num_samples, double treble_gain);

int main()
{
    // allocate memory for our audio signal
    short* audio_signal = (short*)malloc(NUM_SAMPLES * sizeof(short));

    // generate a sine wave for the audio signal
    generateAudioSignal(audio_signal, NUM_SAMPLES);

    // allocate memory for our signal in double precision
    double* audio_signal_d = (double*)malloc(NUM_SAMPLES * sizeof(double));

    // convert the audio signal to double precision
    for (int i = 0; i < NUM_SAMPLES; i++)
    {
        audio_signal_d[i] = audio_signal[i] / (double)MAX_AMPLITUDE;
    }

    // apply the bass and treble boosts to the audio signal
    applyBassBoost(audio_signal_d, NUM_SAMPLES, BASS_GAIN);
    applyTrebleBoost(audio_signal_d, NUM_SAMPLES, TREBLE_GAIN);

    // convert the audio signal back to short precision
    for (int i = 0; i < NUM_SAMPLES; i++)
    {
        audio_signal[i] = (short)(audio_signal_d[i] * MAX_AMPLITUDE);
    }

    // write the audio signal to a WAV file
    FILE* wav_file = fopen("audio_signal.wav", "wb");
    fwrite(audio_signal, sizeof(short), NUM_SAMPLES, wav_file);
    fclose(wav_file);

    // free the memory used by the audio signal
    free(audio_signal);
    free(audio_signal_d);

    return 0;
}

void generateAudioSignal(short* signal, int num_samples)
{
    double frequency = 440.0;
    double phase = 0.0;
    double phase_increment = 2.0 * M_PI * frequency / SAMPLE_RATE;

    for (int i = 0; i < num_samples; i++)
    {
        signal[i] = (short)(MAX_AMPLITUDE * sin(phase));
        phase += phase_increment;
        
        if (phase >= 2.0 * M_PI)
        {
            phase -= 2.0 * M_PI;
        }
    }
}

void applyBassBoost(double* signal, int num_samples, double bass_gain)
{
    double bass_cutoff_frequency = 100.0;
    double bass_coefficient = tan(M_PI * bass_cutoff_frequency / SAMPLE_RATE);
    double bass_gain_db = 20.0 * log10(bass_gain);
    double bass_alpha = sin(M_PI * bass_cutoff_frequency / SAMPLE_RATE) / (2.0 * pow(10.0, bass_gain_db / 20.0));

    double bass_b0 = (1.0 - cos(M_PI / 4.0)) / 2.0;
    double bass_b1 = 1.0 - cos(M_PI / 4.0);
    double bass_b2 = bass_b0;
    double bass_a0 = 1.0 + bass_alpha;
    double bass_a1 = -2.0 * cos(M_PI / 4.0);
    double bass_a2 = 1.0 - bass_alpha;

    double bass_x1 = 0.0, bass_x2 = 0.0, bass_y1 = 0.0, bass_y2 = 0.0;

    for (int i = 0; i < num_samples; i++)
    {
        double input = signal[i];
        double output = (bass_b0 / bass_a0) * input + (bass_b1 / bass_a0) * bass_x1 + (bass_b2 / bass_a0) * bass_x2
                      - (bass_a1 / bass_a0) * bass_y1 - (bass_a2 / bass_a0) * bass_y2;

        bass_x2 = bass_x1;
        bass_x1 = input;
        bass_y2 = bass_y1;
        bass_y1 = output;

        signal[i] = output;
    }
}

void applyTrebleBoost(double* signal, int num_samples, double treble_gain)
{
    double treble_cutoff_frequency = 8000.0;
    double treble_coefficient = tan(M_PI * treble_cutoff_frequency / SAMPLE_RATE);
    double treble_gain_db = 20.0 * log10(treble_gain);
    double treble_alpha = sin(M_PI * treble_cutoff_frequency / SAMPLE_RATE) / (2.0 * pow(10.0, treble_gain_db / 20.0));

    double treble_b0 = (1.0 + cos(M_PI / 4.0)) / 2.0;
    double treble_b1 = -(1.0 + cos(M_PI / 4.0));
    double treble_b2 = (1.0 + cos(M_PI / 4.0)) / 2.0;
    double treble_a0 = 1.0 + treble_alpha;
    double treble_a1 = -2.0 * cos(M_PI / 4.0);
    double treble_a2 = 1.0 - treble_alpha;

    double treble_x1 = 0.0, treble_x2 = 0.0, treble_y1 = 0.0, treble_y2 = 0.0;

    for (int i = 0; i < num_samples; i++)
    {
        double input = signal[i];
        double output = (treble_b0 / treble_a0) * input + (treble_b1 / treble_a0) * treble_x1 + (treble_b2 / treble_a0) * treble_x2
                      - (treble_a1 / treble_a0) * treble_y1 - (treble_a2 / treble_a0) * treble_y2;

        treble_x2 = treble_x1;
        treble_x1 = input;
        treble_y2 = treble_y1;
        treble_y1 = output;

        signal[i] = output;
    }
}