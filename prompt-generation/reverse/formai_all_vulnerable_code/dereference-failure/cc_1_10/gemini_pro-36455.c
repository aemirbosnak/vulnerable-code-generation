//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>
#include <pthread.h>

// Define the audio parameters
#define NUM_CHANNELS    2
#define SAMPLE_RATE    44100
#define FRAMES_PER_BUFFER  512
#define NUM_BUFFERS    5

// Create a mutex to protect the shared audio buffer
pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;

// Create a condition variable to signal when the audio buffer is full
pthread_cond_t buffer_full = PTHREAD_COND_INITIALIZER;

// Create a condition variable to signal when the audio buffer is empty
pthread_cond_t buffer_empty = PTHREAD_COND_INITIALIZER;

// Create an array of audio buffers
float *buffers[NUM_BUFFERS];

// Create an index to keep track of the current buffer
int buffer_index = 0;

// Create a thread to fill the audio buffer
void *fill_buffer_thread(void *args) {
    // Get the audio stream
    PaStream *stream = (PaStream *)args;

    // Loop until the stream is stopped
    while (Pa_IsStreamActive(stream)) {
        // Lock the mutex
        pthread_mutex_lock(&buffer_mutex);

        // Check if the buffer is full
        while (buffer_index >= NUM_BUFFERS) {
            // Wait for the buffer to be emptied
            pthread_cond_wait(&buffer_empty, &buffer_mutex);
        }

        // Get the next buffer
        float *buffer = buffers[buffer_index];

        // Fill the buffer with audio data
        Pa_ReadStream(stream, buffer, FRAMES_PER_BUFFER);

        // Increment the buffer index
        buffer_index++;

        // Signal that the buffer is full
        pthread_cond_signal(&buffer_full);

        // Unlock the mutex
        pthread_mutex_unlock(&buffer_mutex);
    }

    return NULL;
}

// Create a thread to empty the audio buffer
void *empty_buffer_thread(void *args) {
    // Get the audio stream
    PaStream *stream = (PaStream *)args;

    // Loop until the stream is stopped
    while (Pa_IsStreamActive(stream)) {
        // Lock the mutex
        pthread_mutex_lock(&buffer_mutex);

        // Check if the buffer is empty
        while (buffer_index <= 0) {
            // Wait for the buffer to be filled
            pthread_cond_wait(&buffer_full, &buffer_mutex);
        }

        // Get the next buffer
        float *buffer = buffers[buffer_index - 1];

        // Empty the buffer by writing it to the audio stream
        Pa_WriteStream(stream, buffer, FRAMES_PER_BUFFER);

        // Decrement the buffer index
        buffer_index--;

        // Signal that the buffer is empty
        pthread_cond_signal(&buffer_empty);

        // Unlock the mutex
        pthread_mutex_unlock(&buffer_mutex);
    }

    return NULL;
}

int main() {
    // Initialize PortAudio
    Pa_Initialize();

    // Open the audio stream
    PaStream *stream;
    Pa_OpenDefaultStream(&stream, NUM_CHANNELS, NUM_CHANNELS, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, NULL, NULL);

    // Create the audio buffers
    for (int i = 0; i < NUM_BUFFERS; i++) {
        buffers[i] = (float *)malloc(FRAMES_PER_BUFFER * NUM_CHANNELS * sizeof(float));
    }

    // Create the threads
    pthread_t fill_buffer_thread_id;
    pthread_t empty_buffer_thread_id;
    pthread_create(&fill_buffer_thread_id, NULL, fill_buffer_thread, stream);
    pthread_create(&empty_buffer_thread_id, NULL, empty_buffer_thread, stream);

    // Start the audio stream
    Pa_StartStream(stream);

    // Wait for the threads to finish
    pthread_join(fill_buffer_thread_id, NULL);
    pthread_join(empty_buffer_thread_id, NULL);

    // Stop the audio stream
    Pa_StopStream(stream);

    // Close the audio stream
    Pa_CloseStream(stream);

    // Terminate PortAudio
    Pa_Terminate();

    return 0;
}