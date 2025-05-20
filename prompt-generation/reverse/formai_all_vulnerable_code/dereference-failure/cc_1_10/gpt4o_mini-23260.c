//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sndfile.h>

#define SR 44100 // Sample Rate
#define NUM_SAMPLES 44100 // Number of samples per second of audio
#define PI 3.14159265358979323846

void apply_waveshaper(float *buffer, int num_samples, float gain) {
    for (int i = 0; i < num_samples; i++) {
        // Simple waveshaping: apply a nonlinear transformation
        float x = buffer[i] * gain;
        if (x > 1.0f) x = 1.0f;
        else if (x < -1.0f) x = -1.0f;
        buffer[i] = x / (1 + fabs(x)); // Nonlinear shaping
    }
}

void apply_reverb(float *input, float *output, int num_samples, float decay) {
    int delay = 22050; // 0.5 seconds delay at 44100 Hz
    for (int i = 0; i < num_samples; i++) {
        output[i] = input[i];
        if (i >= delay) {
            output[i] += decay * output[i - delay];
        }
    }
}

void generate_sine_wave(float *buffer, int num_samples, float frequency) {
    for (int i = 0; i < num_samples; i++) {
        buffer[i] = sin(2.0 * PI * frequency * ((float)i / SR));
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <output.wav> <frequency>\n", argv[0]);
        return 1;
    }
    
    float frequency = atof(argv[2]);
    
    // Allocate buffer for audio
    float *audio_buffer = (float *)malloc(NUM_SAMPLES * sizeof(float));
    float *processed_buffer = (float *)malloc(NUM_SAMPLES * sizeof(float));
    
    // Generate a sine wave
    generate_sine_wave(audio_buffer, NUM_SAMPLES, frequency);
    
    // Apply waveshaping
    apply_waveshaper(audio_buffer, NUM_SAMPLES, 2.0f); // Gain of 2 for shaping
    
    // Apply reverb
    apply_reverb(audio_buffer, processed_buffer, NUM_SAMPLES, 0.3f); // 30% decay
    
    // Write to file
    SNDFILE *file;
    SF_INFO sfinfo;
    sfinfo.frames = NUM_SAMPLES;
    sfinfo.samplerate = SR;
    sfinfo.channels = 1; // Mono
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
    
    file = sf_open(argv[1], SFM_WRITE, &sfinfo);
    if (!file) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(file));
        free(audio_buffer);
        free(processed_buffer);
        return 1;
    }
    
    // Write processed audio to file
    sf_writef_float(file, processed_buffer, NUM_SAMPLES);
    
    // Clean up
    sf_close(file);
    free(audio_buffer);
    free(processed_buffer);
    
    printf("Audio processing completed! Output saved to %s\n", argv[1]);
    
    return 0;
}