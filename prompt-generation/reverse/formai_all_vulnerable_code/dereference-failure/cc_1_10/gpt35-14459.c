//FormAI DATASET v1.0 Category: Audio processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void createSineWave(float frequency, float duration, int sample_rate, float amplitude, short* output)
{
    int num_samples = (int)(duration * sample_rate);

    for(int i = 0; i < num_samples; ++i)
    {
        float time = (float)i / sample_rate;
        float value = sinf(2.0f * M_PI * frequency * time) * amplitude;

        output[i] = (short)value;
    }
}

void applyGain(float* input, float gain, int num_samples)
{
    for(int i = 0; i < num_samples; ++i)
        input[i] *= gain;
}

void mixAudio(float* input, float* output, int num_samples)
{
    for(int i = 0; i < num_samples; ++i)
        output[i] += input[i];
}

int main()
{
    const float frequency = 440.0f;
    const float duration = 5.0f;
    const int sample_rate = 44100;
    const float amplitude = 0.75f;
    const float gain = 2.0f;

    int num_samples = (int)(duration * sample_rate);
    short* sine_wave = (short*)malloc(sizeof(short) * num_samples);

    createSineWave(frequency, duration, sample_rate, amplitude, sine_wave);

    float* input_samples = (float*)malloc(sizeof(float) * num_samples);
    float* output_samples = (float*)malloc(sizeof(float) * num_samples);

    for(int i = 0; i < num_samples; ++i)
    {
        input_samples[i] = (float)sine_wave[i] / 32767.0f;
        output_samples[i] = 0.0f;
    }

    applyGain(input_samples, gain, num_samples);
    mixAudio(input_samples, output_samples, num_samples);

    for(int i = 0; i < num_samples; ++i)
        output_samples[i] *= amplitude;

    for(int i = 0; i < num_samples; ++i)
        printf("%f\n", output_samples[i]);

    free(sine_wave);
    free(input_samples);
    free(output_samples);

    return 0;
}