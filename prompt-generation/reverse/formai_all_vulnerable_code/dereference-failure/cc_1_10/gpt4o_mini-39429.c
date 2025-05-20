//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <fftw3.h>
#include <unistd.h>

#define SAMPLE_RATE 44100
#define CHUNK_SIZE 1024
#define NUM_THREADS 4

typedef struct {
    double *input;
    fftw_complex *output;
    int chunk_id;
} fft_data;

void *process_fft(void *arg) {
    fft_data *data = (fft_data *)arg;
    fftw_plan plan;
    
    // Create FFTW plan
    plan = fftw_plan_dft_r2c_1d(CHUNK_SIZE, data->input, data->output, FFTW_ESTIMATE);

    // Execute FFT
    fftw_execute(plan);
    
    // Print result for this chunk
    printf("Chunk %d FFT result:\n", data->chunk_id);
    for (int i = 0; i < CHUNK_SIZE / 2 + 1; i++) {
        printf("Frequency bin %d: %f + %fi\n", i, data->output[i][0], data->output[i][1]);
    }

    // Clean up
    fftw_destroy_plan(plan);
    return NULL;
}

void generate_signal(double *signal, int size) {
    for (int i = 0; i < size; i++) {
        signal[i] = 0.5 * sin(2 * M_PI * 440 * i / SAMPLE_RATE) + 0.5 * sin(2 * M_PI * 880 * i / SAMPLE_RATE);
    }
}

int main() {
    // Allocate memory for the input signal and output FFT results
    double *signal = (double *)malloc(CHUNK_SIZE * sizeof(double));
    fftw_complex *fft_output[NUM_THREADS];
    pthread_t threads[NUM_THREADS];
    fft_data thread_data[NUM_THREADS];

    // Generate a test signal
    generate_signal(signal, CHUNK_SIZE);

    // Create threads for processing FFT
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].input = signal + (i * (CHUNK_SIZE / NUM_THREADS));
        thread_data[i].output = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * (CHUNK_SIZE / 2 + 1));
        thread_data[i].chunk_id = i;

        if (pthread_create(&threads[i], NULL, process_fft, &thread_data[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        fftw_free(thread_data[i].output); // Free FFT output memory
    }

    // Clean up
    free(signal);
    return 0;
}