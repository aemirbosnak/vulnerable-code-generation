//Falcon2-11B DATASET v1.0 Category: Audio processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>

#define BUFSIZE 2048

typedef struct {
    double *data;
    int len;
} buffer;

typedef struct {
    double *data;
    int len;
} freq_bin;

buffer read_audio(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    buffer buf;
    fseek(fp, 0, SEEK_END);
    buf.len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    buf.data = malloc(sizeof(double) * buf.len);
    fread(buf.data, sizeof(double), buf.len, fp);
    fclose(fp);

    return buf;
}

freq_bin fft(buffer buf) {
    freq_bin freq_bins;
    freq_bins.len = BUFSIZE;
    freq_bins.data = malloc(sizeof(double) * freq_bins.len);

    double *fft_data = malloc(sizeof(double) * freq_bins.len);
    double *real_data = malloc(sizeof(double) * freq_bins.len);
    double *imag_data = malloc(sizeof(double) * freq_bins.len);

    int i;
    for (i = 0; i < BUFSIZE; i++) {
        fft_data[i] = buf.data[i];
    }
    for (i = 0; i < BUFSIZE; i++) {
        real_data[i] = 0.0;
        imag_data[i] = 0.0;
    }

    for (i = 0; i < BUFSIZE; i++) {
        for (int j = 0; j < BUFSIZE; j++) {
            real_data[j] += fft_data[i] * fft_data[j];
            imag_data[j] += fft_data[i] * fft_data[j];
        }
    }

    for (i = 0; i < BUFSIZE; i++) {
        real_data[i] = real_data[i] / (double)BUFSIZE;
        imag_data[i] = imag_data[i] / (double)BUFSIZE;
    }

    for (i = 0; i < BUFSIZE; i++) {
        freq_bins.data[i] = sqrt(real_data[i] * real_data[i] + imag_data[i] * imag_data[i]);
    }

    free(fft_data);
    free(real_data);
    free(imag_data);

    return freq_bins;
}

void write_freq_bins(const char* filename, freq_bin freq_bins) {
    FILE* fp = fopen(filename, "wb");
    fwrite(freq_bins.data, sizeof(double), freq_bins.len, fp);
    fclose(fp);
}

int main() {
    buffer buf = read_audio("input.wav");
    freq_bin freq_bins = fft(buf);
    write_freq_bins("output.txt", freq_bins);

    return 0;
}