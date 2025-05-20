//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sndfile.h>

#define SAMPLE_RATE 44100
#define MAX_VOLUME 32767.0

// Structure to hold audio data
typedef struct {
    float *buffer;
    int length;
} AudioData;

// Function to load an audio file
AudioData load_audio(const char *filename) {
    SF_INFO sfinfo;
    SNDFILE *file = sf_open(filename, SFM_READ, &sfinfo);
    if (!file) {
        fprintf(stderr, "Error reading file: %s\n", sf_strerror(NULL));
        exit(EXIT_FAILURE);
    }

    AudioData audioData;
    audioData.length = sfinfo.frames * sfinfo.channels;
    audioData.buffer = malloc(audioData.length * sizeof(float));

    sf_readf_float(file, audioData.buffer, sfinfo.frames);
    sf_close(file);

    return audioData;
}

// Function to save an audio file
void save_audio(const char *filename, AudioData audioData, int channels) {
    SF_INFO sfinfo;
    sfinfo.frames = audioData.length / channels;
    sfinfo.samplerate = SAMPLE_RATE;
    sfinfo.channels = channels;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

    SNDFILE *file = sf_open(filename, SFM_WRITE, &sfinfo);
    if (!file) {
        fprintf(stderr, "Error writing file: %s\n", sf_strerror(NULL));
        exit(EXIT_FAILURE);
    }

    sf_writef_float(file, audioData.buffer, sfinfo.frames);
    sf_close(file);
}

// Function to apply a simple gain to the audio data
void apply_gain(AudioData *audioData, float gain) {
    for (int i = 0; i < audioData->length; i++) {
        audioData->buffer[i] *= gain;
        // Clipping
        if (audioData->buffer[i] > 1.0) audioData->buffer[i] = 1.0;
        else if (audioData->buffer[i] < -1.0) audioData->buffer[i] = -1.0;
    }
}

// Function to apply a sine wave modulation
void apply_sine_modulation(AudioData *audioData, float frequency) {
    for (int i = 0; i < audioData->length; i++) {
        float modulation = 0.5 * sinf(2 * M_PI * frequency * (i / (float)SAMPLE_RATE));
        audioData->buffer[i] += modulation;
        // Clipping
        if (audioData->buffer[i] > 1.0) audioData->buffer[i] = 1.0;
        else if (audioData->buffer[i] < -1.0) audioData->buffer[i] = -1.0;
    }
}

// Main function
int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);

    AudioData audioData = load_audio(input_file);
    
    printf("Loaded %d samples from %s\n", audioData.length, input_file);
    
    apply_gain(&audioData, gain);
    
    float sine_frequency = 440.0; // A4 note
    apply_sine_modulation(&audioData, sine_frequency);
    
    save_audio(output_file, audioData, 1);
    
    printf("Processed and saved %d samples to %s\n", audioData.length, output_file);

    free(audioData.buffer);
    return 0;
}