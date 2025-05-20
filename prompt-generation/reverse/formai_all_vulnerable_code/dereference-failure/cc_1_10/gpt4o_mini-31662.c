//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define SAMPLE_RATE 44100
#define SAMPLE_COUNT 44100
#define THREAD_COUNT 4

typedef struct {
    double *input;
    double *output;
    int start;
    int end;
} ThreadData;

void *apply_filter(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    for (int i = data->start; i < data->end; i++) {
        // Simple moving average filter
        int count = 5;
        double sum = 0.0;

        for (int j = -count; j <= 0; j++) {
            if (i + j >= 0) {
                sum += data->input[i + j];
            }
        }
        
        data->output[i] = sum / count;
    }
    return NULL;
}

void generate_sample(double *sample, int count) {
    for (int i = 0; i < count; i++) {
        sample[i] = sin(2 * M_PI * 440 * (double)i / SAMPLE_RATE) + 0.5 * sin(2 * M_PI * 880 * (double)i / SAMPLE_RATE);
    }
}

void write_output(const char *filename, double *data, int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%lf\n", data[i]);
    }
    
    fclose(file);
}

int main() {
    double *input_samples = malloc(SAMPLE_COUNT * sizeof(double));
    double *output_samples = malloc(SAMPLE_COUNT * sizeof(double));
    pthread_t threads[THREAD_COUNT];
    ThreadData thread_data[THREAD_COUNT];
    int samples_per_thread = SAMPLE_COUNT / THREAD_COUNT;

    generate_sample(input_samples, SAMPLE_COUNT);

    // Create threads for processing
    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_data[i].input = input_samples;
        thread_data[i].output = output_samples;
        thread_data[i].start = i * samples_per_thread;
        thread_data[i].end = (i + 1) * samples_per_thread;

        pthread_create(&threads[i], NULL, apply_filter, &thread_data[i]);
    }

    // Join threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    write_output("output_samples.txt", output_samples, SAMPLE_COUNT);

    free(input_samples);
    free(output_samples);

    printf("Processing complete. Output written to output_samples.txt\n");
    return 0;
}