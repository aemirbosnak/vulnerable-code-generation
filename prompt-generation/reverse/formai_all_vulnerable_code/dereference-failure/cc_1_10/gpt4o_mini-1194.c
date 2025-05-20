//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define DURATION 2 // duration in seconds
#define FREQUENCY 440 // frequency in Hz for A4 note

typedef struct {
    unsigned int sample_rate;
    unsigned int num_samples;
    short *data;
} AudioBuffer;

// Function to create an audio buffer for our sonorous melody
AudioBuffer* create_audio_buffer(unsigned int sample_rate, int duration) {
    AudioBuffer* buffer = (AudioBuffer*)malloc(sizeof(AudioBuffer));
    buffer->sample_rate = sample_rate;
    buffer->num_samples = sample_rate * duration;
    buffer->data = (short*)malloc(buffer->num_samples * sizeof(short));
    
    return buffer;
}

// Function to forge a pure tone
void generate_tone(AudioBuffer* buffer, double frequency) {
    for (unsigned int i = 0; i < buffer->num_samples; i++) {
        double time = (double)i / buffer->sample_rate;
        buffer->data[i] = (short)(32767 * sin(2.0 * M_PI * frequency * time));
    }
}

// Function to save our melody to a WAV file
void save_to_wav(const char* filename, AudioBuffer* buffer) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Could not create WAV file");
        return;
    }
    
    // WAV file header
    fwrite("RIFF", 1, 4, file);
    int file_size = 36 + buffer->num_samples * sizeof(short);
    fwrite(&file_size, sizeof(file_size), 1, file);
    fwrite("WAVE", 1, 4, file);
    fwrite("fmt ", 1, 4, file);
    int chunk_size = 16;
    fwrite(&chunk_size, sizeof(chunk_size), 1, file);
    short audio_format = 1; // PCM
    fwrite(&audio_format, sizeof(audio_format), 1, file);
    short channels = 1; // mono
    fwrite(&channels, sizeof(channels), 1, file);
    fwrite(&buffer->sample_rate, sizeof(buffer->sample_rate), 1, file);
    int byte_rate = buffer->sample_rate * channels * sizeof(short);
    fwrite(&byte_rate, sizeof(byte_rate), 1, file);
    short block_align = channels * sizeof(short);
    fwrite(&block_align, sizeof(block_align), 1, file);
    short bits_per_sample = 16; // 16 bits
    fwrite(&bits_per_sample, sizeof(bits_per_sample), 1, file);
    fwrite("data", 1, 4, file);
    int data_size = buffer->num_samples * sizeof(short);
    fwrite(&data_size, sizeof(data_size), 1, file);
    
    // Write audio samples
    fwrite(buffer->data, sizeof(short), buffer->num_samples, file);
    fclose(file);
}

// Function to free our memory
void free_audio_buffer(AudioBuffer* buffer) {
    free(buffer->data);
    free(buffer);
}

// Main function to conjure our musical spell
int main() {
    printf("Hearken, noble scribe! Prepare thyself for a melodious creation...\n");

    // Create our audio buffer
    AudioBuffer* melody = create_audio_buffer(SAMPLE_RATE, DURATION);
    printf("Filling the audio buffer with ethereal tones...\n");

    // Generate the tone of A4
    generate_tone(melody, FREQUENCY);
    printf("The tone has been summoned!\n");

    // Save the spell upon a WAV scroll
    const char* filename = "medieval_melody.wav";
    save_to_wav(filename, melody);
    printf("The symphony has been inscribed in the file: %s\n", filename);

    // Release the resources from this realm
    free_audio_buffer(melody);
    printf("The resources have been purged. Until we meet again!\n");

    return 0;
}