//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000 // Number of samples
#define FS 1000 // Sampling frequency
#define F1 50 // Frequency of sine wave
#define F2 150 // Frequency of second sine wave
#define AMP1 0.5 // Amplitude of sine wave
#define AMP2 0.3 // Amplitude of second sine wave
#define PHI1 0 // Phase of sine wave
#define PHI2 0 // Phase of second sine wave
#define NOISE_AMP 0.1 // Amplitude of noise

int main() {
    double t, x, y;
    double sine1, sine2, noise;
    double sum;
    int i;

    double *sine1_array = (double*)malloc(N*sizeof(double));
    double *sine2_array = (double*)malloc(N*sizeof(double));
    double *noise_array = (double*)malloc(N*sizeof(double));

    // Generate sine wave
    for (i = 0; i < N; i++) {
        t = (double)i / FS;
        sine1 = AMP1*sin(2*M_PI*F1*t + PHI1);
        sine2 = AMP2*sin(2*M_PI*F2*t + PHI2);
        sine1_array[i] = sine1;
        sine2_array[i] = sine2;
    }

    // Add noise
    for (i = 0; i < N; i++) {
        noise = NOISE_AMP*rand()/(RAND_MAX/2) - NOISE_AMP/2;
        noise_array[i] = noise;
        sum = sine1_array[i] + sine2_array[i] + noise;
        if (sum > 1) sum = 1;
        if (sum < -1) sum = -1;
        y = sum;
        x = (double)i / FS;
        printf("%f %f\n", x, y);
    }

    free(sine1_array);
    free(sine2_array);
    free(noise_array);

    return 0;
}