//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: medieval
// Hark! A DSP program of yore,
// To filter signals, a noble chore.
// From ancient castles to modern halls,
// Digital signals echo through history's calls.

#include <stdio.h>
#include <stdlib.h>

// Lo, a humble function, FIR we call,
// To filter signals, a medieval thrall.
float* fir(float *input, int inputLength, float *kernel, int kernelLength) {
    // Arise, fair knights, and gather your might,
    // For the kernel and input shall clash in this fight.
    float *output = malloc(inputLength * sizeof(float));

    // Iterate o'er the input, a valiant quest,
    // Each sample shall be tested, put to the test.
    for (int i = 0; i < inputLength; i++) {
        // Summon the kernel, a noble array,
        // Apply its magic, a filter's sway.
        float sum = 0.0f;
        for (int j = 0; j < kernelLength; j++) {
            // Multiply the twain, a sacred dance,
            // Kernel and input, a harmonious trance.
            sum += kernel[j] * input[i - j];
        }
        // Lo, the output, a new signal born,
        // Filtered and pure, as bright as the morn.
        output[i] = sum;
    }

    // Return the output, a signal so grand,
    // Filtered and fit for all the realm's demand.
    return output;
}

// Now, let us venture forth, to test our might,
// With a signal and kernel, we'll set the scene aright.
int main(int argc, char **argv) {
    // First, a signal, a gentle breeze,
    // Its samples like notes, a symphony that weaves.
    float input[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    int inputLength = sizeof(input) / sizeof(float);

    // Next, a kernel, a window so fine,
    // Its coefficients shall shape the signal's line.
    float kernel[] = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f};
    int kernelLength = sizeof(kernel) / sizeof(float);

    // Call upon our filtering function so bold,
    // To transform the signal, as stories are told.
    float *output = fir(input, inputLength, kernel, kernelLength);

    // Behold, the output, a signal transformed,
    // Its shape altered, its destiny adorned.
    for (int i = 0; i < inputLength; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");

    // Free the knights, their duty now done,
    // The signal filtered, the battle won.
    free(output);

    // Thus ends our tale, of DSP and yore,
    // A testament to knowledge, forevermore.
    return 0;
}