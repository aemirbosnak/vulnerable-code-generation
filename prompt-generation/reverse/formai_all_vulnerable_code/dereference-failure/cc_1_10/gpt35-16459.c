//FormAI DATASET v1.0 Category: Audio processing ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SAMPLING_RATE 44100 // 44.1 kHz
#define DURATION 5 // 5 seconds
#define AMPLITUDE 1.0f // Max amplitude

#define PI 3.14159265358979323846 // The value of pi

typedef struct {
    float* data;
    unsigned int length;
} AudioData;

// Function to generate sine wave
float* generateSineWave(float frequency, float duration) {
    unsigned int samples = duration * SAMPLING_RATE;
    float* data = (float*)malloc(sizeof(float) * samples);

    for(unsigned int i=0; i<samples; i++) {
        float t = (float)i / (float)SAMPLING_RATE;
        data[i] = AMPLITUDE * sin(2.0f * PI * frequency * t);
    }

    return data;
}

// Function to apply low-pass filter on audio data
AudioData applyLowPassFilter(AudioData audio, float cutoffFrequency) {
    AudioData filteredAudio;
    filteredAudio.length = audio.length;
    filteredAudio.data = (float*)malloc(sizeof(float) * audio.length);
    float RC = 1.0f / (2.0f * PI * cutoffFrequency);
    float dt = 1.0f / SAMPLING_RATE;
    float alpha = dt / (RC + dt);

    filteredAudio.data[0] = audio.data[0];
    for(unsigned int i=1; i<audio.length; i++) {
        filteredAudio.data[i] = filteredAudio.data[i-1] + alpha * (audio.data[i] - filteredAudio.data[i-1]);
    }

    return filteredAudio;
}

int main() {
    float frequency = 500.0f; // 500 Hz sine wave
    float duration = DURATION; // 5 seconds long
    float cutoffFrequency = 100.0f; // 100 Hz cutoff frequency

    // Generate sine wave
    float* data = generateSineWave(frequency, duration);
    AudioData audio = {data, duration * SAMPLING_RATE};

    // Apply low-pass filter
    AudioData filteredAudio = applyLowPassFilter(audio, cutoffFrequency);

    // Save filtered audio to file
    FILE* file = fopen("filteredAudio.bin", "wb");
    fwrite(filteredAudio.data, sizeof(float), filteredAudio.length, file);
    fclose(file);

    free(data);
    free(filteredAudio.data);
    return 0;
}