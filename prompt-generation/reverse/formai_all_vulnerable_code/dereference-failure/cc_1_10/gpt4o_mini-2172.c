//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define DURATION 5 // 5 seconds
#define FREQUENCY 440 // A4 note
#define MAX_SAMPLES SAMPLE_RATE * DURATION
#define PI 3.14159265358979323846

// A noble knight’s structure, representing the sine wave of sound
typedef struct {
    double *samples;
    int length;
} SoundWave;

// A spell to enchant the sound wave
SoundWave* create_sine_wave(double frequency, int sample_rate, int duration) {
    SoundWave *wave = malloc(sizeof(SoundWave));
    wave->length = sample_rate * duration;
    wave->samples = malloc(wave->length * sizeof(double));
    
    for (int i = 0; i < wave->length; i++) {
        wave->samples[i] = sin(2 * PI * frequency * ((double)i / sample_rate));
    }
    
    return wave;
}

// The bard’s craft to save the sound to a file
void save_to_wav(const char *filename, SoundWave *wave) {
    FILE *file = fopen(filename, "wb");
    
    // WAV Header
    unsigned char header[44] = {
        'R','I','F','F', 0,0,0,0, 'W','A','V','E', 
        'f','m','t',' ', 16,0,0,0, 1,0, 1,0, 
        0,0,0,0, 0x20,0xB1,0,0, 0x20,0xB1,0,0, 
        'd','a','t','a', 0,0,0,0
    };

    int byte_rate = SAMPLE_RATE * sizeof(short);
    *(int*)&header[28] = sizeof(short) * 8; // bits per sample
    *(int*)&header[24] = byte_rate; // byte rate
    *(int*)&header[22] = 1; // mono
    *(int*)&header[4] = 36 + wave->length * sizeof(short); // file size
    *(int*)&header[40] = wave->length * sizeof(short); // data chunk size

    fwrite(header, sizeof(unsigned char), 44, file);

    for (int i = 0; i < wave->length; i++) {
        short sample = (short)(wave->samples[i] * 32767);
        fwrite(&sample, sizeof(short), 1, file);
    }
    
    fclose(file);
}

// A fiery spell to destroy the sound wave
void destroy_sound_wave(SoundWave *wave) {
    free(wave->samples);
    free(wave);
}

int main() {
    printf("In a kingdom of sound, a sine wave shall be crafted!\n");

    // The knight of frequencies shall take form
    SoundWave *sine_wave = create_sine_wave(FREQUENCY, SAMPLE_RATE, DURATION);
    printf("A sine wave of frequency %d Hz created for %d seconds!\n", FREQUENCY, DURATION);

    // The bard saves the crafted sound to a magical file
    save_to_wav("sine_wave.wav", sine_wave);
    printf("The sound has been saved to 'sine_wave.wav'!\n");

    // The spells conclude, the knight rests
    destroy_sound_wave(sine_wave);
    printf("The knight of sound has completed its quest!\n");

    return 0;
}