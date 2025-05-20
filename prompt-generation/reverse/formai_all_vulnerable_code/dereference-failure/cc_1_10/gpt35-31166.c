//FormAI DATASET v1.0 Category: Audio processing ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    int sample_rate;
    int num_samples;
    float *data;
} Audio;

// Function to create a sine wave of a given frequency and duration
Audio create_sine_wave(float frequency, float duration, int sample_rate) {
    int num_samples = (int)(duration * sample_rate);
    float *data = (float*)malloc(sizeof(float) * num_samples);
    for (int i = 0; i < num_samples; i++) {
        float time = (float)i / sample_rate;
        data[i] = sin(2.0 * PI * frequency * time);
    }
    Audio audio = {sample_rate, num_samples, data};
    return audio;
}

// Function to add two audio signals together
Audio add_audio(Audio audio1, Audio audio2) {
    if (audio1.sample_rate != audio2.sample_rate || audio1.num_samples != audio2.num_samples) {
        printf("Audio files must have the same sample rate and duration to be added together\n");
        exit(1);
    }
    float *data = (float*)malloc(sizeof(float) * audio1.num_samples);
    for (int i = 0; i < audio1.num_samples; i++) {
        data[i] = audio1.data[i] + audio2.data[i];
    }
    Audio audio = {audio1.sample_rate, audio1.num_samples, data};
    return audio;
}

// Function to apply a low-pass filter to an audio signal
Audio lowpass_filter(Audio audio, int cutoff_frequency) {
    float alpha = (float)audio.sample_rate / (2.0 * PI * cutoff_frequency + audio.sample_rate);
    float *data = (float*)malloc(sizeof(float) * audio.num_samples);
    float prev = 0.0;
    for (int i = 0; i < audio.num_samples; i++) {
        data[i] = prev + alpha * (audio.data[i] - prev);
        prev = data[i];
    }
    Audio filtered_audio = {audio.sample_rate, audio.num_samples, data};
    return filtered_audio;
}

int main() {
    // Create a 440 Hz sine wave of 1 second duration and a sample rate of 44100 Hz
    Audio audio1 = create_sine_wave(440.0, 1.0, 44100);
    // Create a 880 Hz sine wave of 1 second duration and a sample rate of 44100 Hz
    Audio audio2 = create_sine_wave(880.0, 1.0, 44100);
    // Add the two sine waves together
    Audio audio3 = add_audio(audio1, audio2);
    // Apply a low-pass filter to the resulting signal with a cutoff frequency of 1000 Hz
    Audio filtered_audio = lowpass_filter(audio3, 1000);
    
    // Output the original and filtered audio data to a file for visualization
    FILE *original_file = fopen("original_audio.txt", "w");
    FILE *filtered_file = fopen("filtered_audio.txt", "w");
    for (int i = 0; i < audio1.num_samples; i++) {
        fprintf(original_file, "%f\n", audio3.data[i]);
        fprintf(filtered_file, "%f\n", filtered_audio.data[i]);
    }
    fclose(original_file);
    fclose(filtered_file);
    
    // Free the memory allocated for the audio data
    free(audio1.data);
    free(audio2.data);
    free(audio3.data);
    free(filtered_audio.data);
    
    return 0;
}