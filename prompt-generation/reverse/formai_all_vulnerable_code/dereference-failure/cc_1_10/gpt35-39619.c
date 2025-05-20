//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <errno.h>
#include <limits.h>

#define PI 3.14159265359

/* function prototypes */
void low_pass_filter(double fc, double fs, double *input, double *output, int n);

int main(int argc, char **argv) {
    /* check if file path is provided */
    if (argc < 2) {
        printf("Please provide an audio file path.\n");
        return 1;
    }

    /* open audio file */
    FILE *fp;
    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Failed to open file. Error: %s\n", strerror(errno));
        return 1;
    }

    /* read audio data */
    fseek(fp, 0, SEEK_END);
    int audio_size = ftell(fp) / sizeof(int16_t);
    rewind(fp);
    int16_t *audio_in = (int16_t *)malloc(audio_size * sizeof(int16_t));
    fread(audio_in, sizeof(int16_t), audio_size, fp);
    fclose(fp);

    /* convert audio data to double precision */
    double *audio_in_d = (double *)malloc(audio_size * sizeof(double));
    for (int i = 0; i < audio_size; i++) {
        audio_in_d[i] = (double)audio_in[i] / INT16_MAX;
    }

    /* apply low-pass filter */
    double fc = 1000.0;  // cutoff frequency in Hz
    double fs = 44100.0;  // sampling frequency in Hz
    double *audio_out = (double *)malloc(audio_size * sizeof(double));
    low_pass_filter(fc, fs, audio_in_d, audio_out, audio_size);

    /* convert filtered audio data to int16_t */
    int16_t *audio_out_i16 = (int16_t *)malloc(audio_size * sizeof(int16_t));
    for (int i = 0; i < audio_size; i++) {
        audio_out_i16[i] = (int16_t)(audio_out[i] * INT16_MAX);
    }

    /* play filtered audio using ALSA */
    system("amixer set PCM 100%");  // set volume to maximum
    fp = fopen("filtered_audio.pcm", "wb");  // save filtered audio to file
    if (fp == NULL) {
        printf("Failed to open file. Error: %s\n", strerror(errno));
        return 1;
    }
    fwrite(audio_out_i16, sizeof(int16_t), audio_size, fp);
    fclose(fp);
    system("aplay -f cd filtered_audio.pcm");  // play audio using aplay

    /* free memory */
    free(audio_in);
    free(audio_in_d);
    free(audio_out);
    free(audio_out_i16);

    return 0;
}

void low_pass_filter(double fc, double fs, double *input, double *output, int n) {
    double omega = 2.0 * PI * fc / fs;
    double alpha = sin(omega) / (2.0 * cos(omega) + sin(omega));
    double b0 = (1.0 - cos(omega)) / 2.0;
    double b1 = 1.0 - cos(omega);
    double b2 = (1.0 - cos(omega)) / 2.0;
    double a0 = 1.0 + alpha;
    double a1 = -2.0 * cos(omega);
    double a2 = 1.0 - alpha;

    /* initialize filter */
    double x1 = 0.0;
    double x2 = 0.0;
    double y1 = 0.0;
    double y2 = 0.0;

    /* apply filter */
    for (int i = 0; i < n; i++) {
        double x = input[i];
        double y = (b0 / a0) * x + (b1 / a0) * x1 + (b2 / a0) * x2 - (a1 / a0) * y1 - (a2 / a0) * y2;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
        output[i] = y;
    }
}