//FormAI DATASET v1.0 Category: Audio processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BLOCK_SIZE 256 // Define audio block size

/* Function to perform FFT on a given input buffer */
void FFT(double *xr, double *xi, int size)
{
    int i, j, k, n;
    double temp_r, temp_i, w_r, w_i, theta;

    n = size / 2;

    for (i = 0; i < n; i++) {
        j = i + n;
        temp_r = xr[i] - xr[j];
        temp_i = xi[i] - xi[j];
        xr[i] += xr[j];
        xi[i] += xi[j];
        xr[j] = temp_r;
        xi[j] = temp_i;
    }

    for (i = 2; i <= n; i <<= 1) {
        theta = M_PI / (i / 2);
        w_r = cos(theta);
        w_i = sin(theta);

        for (j = 0; j < n; j += i) {
            temp_r = 1.0;
            temp_i = 0.0;

            for (k = j; k < j + i / 2; k++) {
                temp_r = xr[k + i / 2] * temp_r - xi[k + i / 2] * temp_i;
                temp_i = xi[k + i / 2] * temp_r + xr[k + i / 2] * temp_i;
                xr[k + i / 2] = xr[k] - temp_r;
                xi[k + i / 2] = xi[k] - temp_i;
                xr[k] += temp_r;
                xi[k] += temp_i;
                temp_r = w_r * temp_r - w_i * temp_i;
                temp_i = w_r * temp_i + w_i * temp_r;
            }
        }
    }
}

/* Function to perform frequency analysis on a given audio buffer */
void analyzeAudio(double *buffer, int bufSize, int sampleRate)
{
    double *xr, *xi, *window;
    int i, j, numBlocks, pos;

    numBlocks = bufSize / BLOCK_SIZE;

    window = (double *) malloc (sizeof(double) * BLOCK_SIZE);
    xr = (double *) malloc (sizeof(double) * BLOCK_SIZE);
    xi = (double *) malloc (sizeof(double) * BLOCK_SIZE);

    /* Initialize windowing function */
    for (i = 0; i < BLOCK_SIZE; i++) {
        window[i] = 0.54 - 0.46 * cos(2 * M_PI * i / (BLOCK_SIZE - 1));
    }

    /* Perform FFT on each audio block */
    for (i = 0; i < numBlocks; i++) {
        pos = i * BLOCK_SIZE;

        /* Apply windowing function to audio block */
        for (j = 0; j < BLOCK_SIZE; j++) {
            xr[j] = window[j] * buffer[pos + j];
            xi[j] = 0.0;
        }

        /* Perform FFT on audio block */
        FFT(xr, xi, BLOCK_SIZE);

        /* Print frequency analysis results */
        printf("Block %d:\n", i);
        for (j = 0; j < BLOCK_SIZE / 2; j++) {
            printf("%dHz: %f\n", j * sampleRate / BLOCK_SIZE, 20 * log10(sqrt(xr[j] * xr[j] + xi[j] * xi[j])));
        }
        printf("\n");
    }

    free(window);
    free(xr);
    free(xi);
}

int main()
{
    double *buffer;
    int bufSize = BLOCK_SIZE * 10, sampleRate = 44100; // Set sample rate to 44100Hz
    int i;

    buffer = (double *) malloc (sizeof(double) * bufSize);
    for (i = 0; i < bufSize; i++) {
        buffer[i] = sin(2 * M_PI * 5000 * i / sampleRate) + sin(2 * M_PI * 12000 * i / sampleRate);
    }

    analyzeAudio(buffer, bufSize, sampleRate);

    free(buffer);

    return 0;
}