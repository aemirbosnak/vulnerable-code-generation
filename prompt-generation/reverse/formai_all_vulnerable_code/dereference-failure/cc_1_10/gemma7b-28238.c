//Gemma-7B DATASET v1.0 Category: Audio processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct Sample
{
    short sample[BUFFER_SIZE];
    int sample_count;
} Sample;

Sample *sample_alloc()
{
    Sample *sample = malloc(sizeof(Sample));
    sample->sample_count = 0;
    return sample;
}

void sample_add(Sample *sample, short sample_value)
{
    sample->sample[sample->sample_count++] = sample_value;
}

void sample_play(Sample *sample)
{
    for (int i = 0; i < sample->sample_count; i++)
    {
        short value = sample->sample[i];
        printf("%hi ", value);
    }
    printf("\n");
}

int main()
{
    Sample *sample = sample_alloc();

    // Generate a sine wave
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        short value = (short)(sin(i * 0.001) * 1000);
        sample_add(sample, value);
    }

    // Play the sine wave
    sample_play(sample);

    return 0;
}