//FormAI DATASET v1.0 Category: Audio processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 4096
#define NUM_CHANNELS 2

// Audio processing function
void process_audio(void *buffer, size_t size) {
    // Cast buffer to appropriate data type
    float *audio_buffer = (float *) buffer;
    
    // Apply gain to audio buffer
    for (size_t i = 0; i < size; i++) {
        audio_buffer[i] *= 0.5;
    }
}

int main(int argc, char **argv) {
    // Open audio file for reading
    int audio_fd = open("audio.wav", O_RDONLY);
    if (audio_fd == -1) {
        perror("Failed to open audio file");
        exit(EXIT_FAILURE);
    }
    
    // Get audio file size
    struct stat audio_stat;
    if (fstat(audio_fd, &audio_stat) == -1) {
        perror("Failed to get audio file size");
        exit(EXIT_FAILURE);
    }
    size_t audio_size = audio_stat.st_size;
    
    // Map audio file to memory
    void *audio_ptr = mmap(NULL, audio_size, PROT_READ, MAP_PRIVATE, audio_fd, 0);
    if (audio_ptr == MAP_FAILED) {
        perror("Failed to map audio file to memory");
        exit(EXIT_FAILURE);
    }
    
    // Close audio file descriptor
    close(audio_fd);
    
    // Calculate number of audio samples in file
    size_t num_samples = audio_size / (sizeof(float) * NUM_CHANNELS);
    
    // Allocate memory for output buffer
    void *output_buffer = malloc(BUFFER_SIZE);
    if (output_buffer == NULL) {
        perror("Failed to allocate memory for output buffer");
        exit(EXIT_FAILURE);
    }
    
    // Loop through audio samples, processing each buffer of data
    for (size_t i = 0; i < num_samples; i += BUFFER_SIZE / (sizeof(float) * NUM_CHANNELS)) {
        size_t buffer_size = BUFFER_SIZE;
        if (i + buffer_size / (sizeof(float) * NUM_CHANNELS) > num_samples) {
            buffer_size = (num_samples - i) * sizeof(float) * NUM_CHANNELS;
        }
        
        // Copy data from memory-mapped file to output buffer
        memcpy(output_buffer, (char *) audio_ptr + i * sizeof(float) * NUM_CHANNELS, buffer_size);
        
        // Process audio buffer
        process_audio(output_buffer, buffer_size);
        
        // Write processed audio buffer to output file
        write(STDOUT_FILENO, output_buffer, buffer_size);
    }
    
    // Unmap audio file from memory
    if (munmap(audio_ptr, audio_size) == -1) {
        perror("Failed to unmap audio file from memory");
        exit(EXIT_FAILURE);
    }
    
    // Free output buffer memory
    free(output_buffer);
    
    return EXIT_SUCCESS;
}