//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 440.0 // Frequency of A4 note
#define BUFFER_SIZE 256 // Number of samples per buffer
#define NUM_CHANNELS 2  // Stereo audio
#define NUM_BUFFERS 4   // Number of buffers to process

typedef struct {
    float *buffer;
    int size;
} AudioBuffer;

typedef struct {
    int buffer_id;
    AudioBuffer *audio_buffers;
} ThreadArgs;

// Function to generate a sine wave
void generate_sine_wave(float *buffer, int size, float frequency, int sample_rate) {
    static double phase = 0.0;
    double increment = (2.0 * M_PI * frequency) / sample_rate;

    for (int i = 0; i < size; i++) {
        buffer[i] = (float)(0.5 * sin(phase));
        phase += increment;

        // Keep phase within the bounds of 2 * Pi
        if (phase >= 2.0 * M_PI) {
            phase -= 2.0 * M_PI;
        }
    }
}

// Function to process audio buffer
void* process_audio(void* args) {
    ThreadArgs *thread_args = (ThreadArgs*)args;
    int buffer_id = thread_args->buffer_id;
    AudioBuffer *audio_buffers = thread_args->audio_buffers;

    // Generate sine wave
    generate_sine_wave(audio_buffers[buffer_id].buffer, BUFFER_SIZE, FREQUENCY, SAMPLE_RATE);
    
    printf("Processed buffer %d\n", buffer_id);
    
    return NULL;
}

int main() {
    pthread_t threads[NUM_BUFFERS];
    AudioBuffer audio_buffers[NUM_BUFFERS];
    ThreadArgs thread_args[NUM_BUFFERS];

    // Allocate buffers for audio processing
    for (int i = 0; i < NUM_BUFFERS; i++) {
        audio_buffers[i].buffer = (float*)malloc(BUFFER_SIZE * sizeof(float));
        audio_buffers[i].size = BUFFER_SIZE;
        if (audio_buffers[i].buffer == NULL) {
            fprintf(stderr, "Memory allocation failed for buffer %d\n", i);
            return 1;
        }
        thread_args[i].buffer_id = i;
        thread_args[i].audio_buffers = audio_buffers;
    }

    // Create threads for processing buffers
    for (int i = 0; i < NUM_BUFFERS; i++) {
        pthread_create(&threads[i], NULL, process_audio, &thread_args[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_BUFFERS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Output processed audio buffers
    for (int i = 0; i < NUM_BUFFERS; i++) {
        printf("Buffer %d audio samples:\n", i);
        for (int j = 0; j < BUFFER_SIZE; j++) {
            printf("%f ", audio_buffers[i].buffer[j]);
        }
        printf("\n");
        free(audio_buffers[i].buffer); // Free allocated memory
    }

    return 0;
}