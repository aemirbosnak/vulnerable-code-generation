//FormAI DATASET v1.0 Category: Audio processing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// Audio processing function
void audio_processing(float* buffer, uint32_t num_samples, float gain, float cutoff_freq) {
    // Apply gain to buffer
    for (uint32_t i = 0; i < num_samples; i++) {
        buffer[i] *= gain;
    }

    // Apply low-pass filter to buffer
    float RC = 1.0f / (cutoff_freq * 2.0f * M_PI); // Calculate RC constant
    float dt = 1.0f / 44100.0f; // Sample time
    float alpha = dt / (RC + dt); // Filter coefficient
    float prev_output = 0.0f; // Previous output value

    for (uint32_t i = 0; i < num_samples; i++) {
        float output = alpha * buffer[i] + (1.0f - alpha) * prev_output; // Calculate filtered output
        prev_output = output; // Store output for next iteration
        buffer[i] = output; // Assign output to buffer
    }
}

int main() {
    // Generate test audio data
    uint32_t num_samples = 44100; // 1 second of audio at 44.1 kHz
    float* audio_data = malloc(num_samples * sizeof(float));

    float amplitude = 1.0f;
    float freq = 440.0f; // A4 note frequency
    float phase = 0.0f;
    float sample_rate = 44100.0f;

    for (uint32_t i = 0; i < num_samples; i++) {
        float sample = amplitude * sin(2.0f * M_PI * freq * i / sample_rate + phase); // Generate sine wave sample
        audio_data[i] = sample;
    }

    // Apply audio processing
    float gain = 2.0f;
    float cutoff_freq = 1000.0f; // Hz
    audio_processing(audio_data, num_samples, gain, cutoff_freq);

    // Output processed audio data
    for (uint32_t i = 0; i < num_samples; i++) {
        printf("%f\n", audio_data[i]);
    }

    // Free memory
    free(audio_data);

    return 0;
}