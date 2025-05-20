//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define MAX_BUFFER_SIZE 8192

void recursive_dft(double *real, double *imag, int n, int step) {
    if (n <= 1) return;

    recursive_dft(real, imag, n / 2, step * 2);
    recursive_dft(real + step, imag + step, n / 2, step * 2);

    for (int k = 0; k < n / 2; k++) {
        double t_real = real[k * step];
        double t_imag = imag[k * step];

        double angle = 2 * M_PI * k / n;
        double w_real = cos(angle);
        double w_imag = sin(angle);
        
        real[k * step] = t_real + w_real * real[k * step + step] - w_imag * imag[k * step + step];
        imag[k * step] = t_imag + w_real * imag[k * step + step] + w_imag * real[k * step + step];
        
        real[k * step + step] = t_real - w_real * real[k * step + step] + w_imag * imag[k * step + step];
        imag[k * step + step] = t_imag - w_real * imag[k * step + step] - w_imag * real[k * step + step];
    }
}

void transform_audio(const char *input_file, const char *output_file) {
    SNDFILE *infile, *outfile;
    SF_INFO sfinfo;

    infile = sf_open(input_file, SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Could not open input file.\n");
        return;
    }

    double *buffer = malloc(MAX_BUFFER_SIZE * sizeof(double));
    if (!buffer) {
        fprintf(stderr, "Could not allocate memory.\n");
        sf_close(infile);
        return;
    }

    int readcount;
    while ((readcount = sf_readf_double(infile, buffer, MAX_BUFFER_SIZE)) > 0) {
        double *real = malloc(readcount * sizeof(double));
        double *imag = calloc(readcount, sizeof(double)); // Initialize imag to zero
        
        for (int i = 0; i < readcount; i++) {
            real[i] = buffer[i]; // Load real part
        }
        
        recursive_dft(real, imag, readcount, 1);

        // Output transformed data (real)
        // Save it in a new file, you might want to transform it back later
        if (!outfile) {
            sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
            outfile = sf_open(output_file, SFM_WRITE, &sfinfo);
            if (!outfile) {
                fprintf(stderr, "Could not open output file.\n");
                free(real);
                free(imag);
                sf_close(infile);
                return;
            }
        }
        
        sf_writef_double(outfile, real, readcount);
        
        free(real);
        free(imag);
    }
    
    free(buffer);
    sf_close(infile);
    sf_close(outfile);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file.wav> <output_file.wav>\n", argv[0]);
        return 1;
    }
    
    transform_audio(argv[1], argv[2]);
    printf("Audio transformation completed successfully.\n");
    return 0;
}