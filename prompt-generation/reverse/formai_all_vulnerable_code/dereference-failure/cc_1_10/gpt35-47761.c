//FormAI DATASET v1.0 Category: Digital signal processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    // Here's a funny DSP example: a program that translates a person's voice into the sound of a duck quacking!
    // We can do this with some simple DSP techniques like filtering, modulation, and frequency shifting.

    // First, let's load in a sample of the person speaking. We'll use a WAV file since those are easy to read.
    // I hope the person didn't say anything inappropriate!

    // Here's some code to read in the WAV file (which we'll call "in.wav"):

    FILE* in = fopen("in.wav", "rb");
    if (in == NULL)
    {
        printf("Error: Couldn't open input file!\n");
        return 1;
    }

    // Now we need to read in the header of the WAV file to figure out how many samples it has and what the sample rate is.

    unsigned char header[44]; // WAV headers are always 44 bytes
    fread(header, 1, 44, in);

    int num_samples = *(int*)&header[40]; // get the number of samples from the header
    int sample_rate = *(int*)&header[24]; // get the sample rate from the header

    // Now let's allocate some memory to hold the samples.

    float* samples = malloc(num_samples * sizeof(float));

    // We'll read in the samples as 16-bit integers and normalize them to the range [-1, 1].

    for (int i = 0; i < num_samples; i++)
    {
        short sample;
        fread(&sample, 2, 1, in);
        samples[i] = (float)sample / 32768.0f;
    }

    fclose(in);

    // Okay, now we have the input signal. Let's apply some DSP to turn it into a duck!

    // First, let's apply a lowpass filter to remove some of the high frequencies:

    float cutoff_freq = 1000.0f; // in Hz
    float Q = 1.0f / sqrt(2.0f);
    float omega = 2.0f * M_PI * cutoff_freq / sample_rate;
    float alpha = sin(omega) / (2.0f * Q);
    float a0 = 1.0f + alpha;
    float a1 = -2.0f * cos(omega);
    float a2 = 1.0f - alpha;
    float b0 = (1.0f - cos(omega)) / 2.0f;
    float b1 = 1.0f - cos(omega);
    float b2 = (1.0f - cos(omega)) / 2.0f;
    float x1 = 0.0f, x2 = 0.0f, y1 = 0.0f, y2 = 0.0f;

    for (int i = 0; i < num_samples; i++)
    {
        float x0 = samples[i];
        float y0 = (b0 / a0) * x0 + (b1 / a0) * x1 + (b2 / a0) * x2 - (a1 / a0) * y1 - (a2 / a0) * y2;
        x2 = x1;
        x1 = x0;
        y2 = y1;
        y1 = y0;
        samples[i] = y0;
    }

    // Now let's modulate the pitch to make the quack sound more like a duck.

    float pitch_scale = 0.5f; // half the original pitch
    float phase = 0.0f;

    for (int i = 0; i < num_samples; i++)
    {
        phase += 2.0f * M_PI * pitch_scale / sample_rate;
        samples[i] *= sin(phase);
    }

    // Finally, let's shift the frequency down to make the quack sound lower.

    float freq_shift = -500.0f; // in Hz
    float delta_phase = 2.0f * M_PI * freq_shift / sample_rate;
    float phase_acc = 0.0f;

    for (int i = 0; i < num_samples; i++)
    {
        float sample = samples[i];
        phase_acc += delta_phase;
        samples[i] = sample * cos(phase_acc) - sin(phase_acc) * ((i == 0) ? 0 : samples[i - 1]);
    }

    // Okay, we're done! Let's write the output to a new WAV file.

    FILE* out = fopen("out.wav", "wb");
    if (out == NULL)
    {
        printf("Error: Couldn't open output file!\n");
        return 1;
    }

    fwrite(header, 1, 44, out); // write the same header as the input file

    for (int i = 0; i < num_samples; i++)
    {
        short sample = (short)(samples[i] * 32767.0f);
        fwrite(&sample, 2, 1, out);
    }

    fclose(out);

    // Done! Let's clean up.

    free(samples);

    return 0;
}