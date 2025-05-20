//FormAI DATASET v1.0 Category: Audio processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Struct to hold audio data
typedef struct {
    short *data;
    int length;
} AudioData;

// Function for thread to process audio data
void* process_audio(void* arg) {
    AudioData* audio = (AudioData*) arg;
    short* data = audio->data;
    int length = audio->length;
    
    // Apply audio effect to each sample of the data
    for (int i = 0; i < length; i++) {
        data[i] = data[i] * 2;
    }
    
    // Signal that processing is complete
    pthread_exit(NULL);
}

int main() {
    // Generate some test audio data
    const int length = 44100;
    short* data = (short*) malloc(sizeof(short) * length);
    for (int i = 0; i < length; i++) {
        data[i] = rand() % 65536 - 32768;
    }
    
    // Create thread for audio processing
    pthread_t thread;
    AudioData audio;
    audio.data = data;
    audio.length = length;
    pthread_create(&thread, NULL, process_audio, &audio);
    
    // Wait for audio processing thread to complete
    pthread_join(thread, NULL);
    
    // Print processed audio data
    for (int i = 0; i < length; i++) {
        printf("%d\n", data[i]);
    }
    
    // Clean up memory
    free(data);
    
    return 0;
}