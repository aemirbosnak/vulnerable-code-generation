//FormAI DATASET v1.0 Category: Audio processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100.0
#define PI 3.1415926535898

typedef struct {
    double *data; // Sample data
    int length; // Number of samples
} Sample;

// Function to generate a sine wave sample
Sample generateSineWave(double frequency, double amplitude, double duration) {
    int numSamples = (int) (SAMPLE_RATE * duration);
    Sample sample;
    sample.length = numSamples;
    sample.data = (double *) malloc(numSamples * sizeof(double));
    for (int i = 0; i < numSamples; i++) {
        sample.data[i] = amplitude * sin(2 * PI * frequency * i / SAMPLE_RATE);
    }
    return sample;
}

// Function to mix two samples
Sample mixSamples(Sample sample1, Sample sample2) {
    int length = (sample1.length > sample2.length) ? sample1.length : sample2.length;
    Sample mixed;
    mixed.length = length;
    mixed.data = (double *) malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        double data1 = (i < sample1.length) ? sample1.data[i] : 0.0;
        double data2 = (i < sample2.length) ? sample2.data[i] : 0.0;
        mixed.data[i] = data1 + data2;
    }
    return mixed;
}

// Function to apply an envelope to a sample
Sample applyEnvelope(Sample sample, double attackTime, double decayTime, double sustainLevel, double releaseTime) {
    Sample envelope;
    envelope.length = sample.length;
    envelope.data = (double *) malloc(envelope.length * sizeof(double));
    int attackSamples = (int) (attackTime * SAMPLE_RATE);
    int decaySamples = (int) (decayTime * SAMPLE_RATE);
    int releaseSamples = (int) (releaseTime * SAMPLE_RATE);
    int sustainSamples = envelope.length - attackSamples - decaySamples - releaseSamples;
    double maxAmplitude = 1.0;
    for (int i = 0; i < envelope.length; i++) {
        if (i < attackSamples) {
            envelope.data[i] = (double) i / attackSamples * maxAmplitude;
        } else if (i < attackSamples + decaySamples) {
            envelope.data[i] = (1 - ((double) (i - attackSamples) / decaySamples)) * (maxAmplitude - sustainLevel) + sustainLevel;
        } else if (i < attackSamples + decaySamples + sustainSamples) {
            envelope.data[i] = sustainLevel;
        } else {
            envelope.data[i] = ((double) (envelope.length - i) / releaseSamples) * sustainLevel;
        }
    }
    Sample enveloped;
    enveloped.length = sample.length;
    enveloped.data = (double *) malloc(enveloped.length * sizeof(double));
    for (int i = 0; i < enveloped.length; i++) {
        enveloped.data[i] = sample.data[i] * envelope.data[i];
    }
    return enveloped;
}

int main() {
    
    // Generate two sine wave samples
    Sample bassNote = generateSineWave(110.0, 0.8, 2.0);
    Sample snareDrum = generateSineWave(180.0, 1.0, 1.0);
    
    // Mix the samples together
    Sample mix = mixSamples(bassNote, snareDrum);
    
    // Apply an envelope to the mixed sample
    Sample final = applyEnvelope(mix, 0.1, 0.2, 0.7, 0.4);
    
    // Print the sample data
    for (int i = 0; i < final.length; i++) {
        printf("%.4f\n", final.data[i]);
    }
    
    // Free the memory allocated for the samples
    free(bassNote.data);
    free(snareDrum.data);
    free(mix.data);
    free(final.data);
    
    return 0;
}