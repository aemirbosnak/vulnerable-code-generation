//FormAI DATASET v1.0 Category: Audio processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100       /* Sampling rate (Hz) */
#define BUFFER_SIZE 2048        /* Size of buffer (samples) */
#define PI 3.14159265358979323846

/*Function to generate white noise */
void generate_noise(float *buffer, int num_samples) {
    int i;
    for (i = 0; i < num_samples; i++) {
        buffer[i] = ((float)rand() / (float)RAND_MAX) * 2.0 - 1.0; /*Generate a random number from -1 to 1*/
    }
}

/* Function to generate a sinusoidal wave */
void generate_sine(float *buffer, float frequency, int num_samples) {
    int i;
    for (i = 0; i < num_samples; i++) {
        buffer[i] = sin(2.0 * PI * frequency * (float)i / (float)SAMPLE_RATE);
    }
}

/* Function to filter the audio signal */
void lowpass_filter(float *buffer, int num_samples, float cutoff_frequency) {
    int i;
    float rc = 1.0 / (2.0 * PI * cutoff_frequency);
    float dt = 1.0 / (float)SAMPLE_RATE;

    float alpha = dt / (rc + dt);

    float prev_output = 0;
    for (i = 0; i < num_samples; i++) {
        buffer[i] = alpha * buffer[i] + (1 - alpha) * prev_output;
        prev_output = buffer[i];
    }
}

int main() {
    float *buffer = (float*)malloc(BUFFER_SIZE * sizeof(float)); /* Allocate buffer memory */

    generate_noise(buffer, BUFFER_SIZE); /* Generate white noise */
    lowpass_filter(buffer, BUFFER_SIZE, 1000); /* Filter the noise with a low-pass filter */

    generate_sine(buffer, 500, BUFFER_SIZE); /* Generate a 500 Hz sinusoidal wave */
    lowpass_filter(buffer, BUFFER_SIZE, 500); /* Filter the sinusoidal wave with a low-pass filter */

    /* Write the buffer to a file */
    FILE *file = fopen("output.raw", "wb");
    fwrite(buffer, sizeof(float), BUFFER_SIZE, file);
    fclose(file);

    free(buffer); /* Free allocated memory */
    return 0;
}