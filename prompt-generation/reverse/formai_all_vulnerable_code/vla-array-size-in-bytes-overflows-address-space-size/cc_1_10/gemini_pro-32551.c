//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Introspection: A C program delving into the depths of digital signal processing

// Prelude: Embarking on a DSP Odyssey
int main() {

    // A canvas to capture the ephemeral waveform: Our signal
    int signal_length;
    printf("We begin our DSP symphony. How long shall our signal's tale be? (Enter length): ");
    scanf("%d", &signal_length);

    float signal[signal_length];
    printf("Now, weave the fabric of your signal. Enter %d values: ", signal_length);
    for (int i = 0; i < signal_length; i++) {
        scanf("%f", &signal[i]);
    }

    // The conductor's baton: Our filter coefficients
    int filter_length;
    printf("Time to craft our filter. How many coefficients shall it wield? (Enter length): ");
    scanf("%d", &filter_length);

    float filter[filter_length];
    printf("Now, let's hear the coefficients that will shape our filter: ");
    for (int i = 0; i < filter_length; i++) {
        scanf("%f", &filter[i]);
    }

    // Convolution: The heart of our signal metamorphosis
    int output_length = signal_length + filter_length - 1;
    float output[output_length];
    for (int i = 0; i < output_length; i++) {
        output[i] = 0;
        for (int j = 0; j < signal_length; j++) {
            // Reflecting on the past: Multiplying signal values with corresponding filter coefficients
            if ((i - j) >= 0 && (i - j) < filter_length) {
                output[i] += signal[j] * filter[i - j];
            }
        }
    }

    // Unveiling the transformed signal: A symphony of echoes
    printf("\nBehold, the metamorphosis of your signal:\n");
    for (int i = 0; i < output_length; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");

    // A moment of introspection: Analyzing the outcome
    float sum = 0;
    float mean = 0;
    float variance = 0;
    for (int i = 0; i < output_length; i++) {
        sum += output[i];
    }
    mean = sum / output_length;
    for (int i = 0; i < output_length; i++) {
        variance += pow(output[i] - mean, 2);
    }
    variance /= output_length;

    printf("\nReflecting on our journey:\n");
    printf("Mean of the filtered signal: %f\n", mean);
    printf("Variance of the filtered signal: %f\n", variance);

    return 0;
}