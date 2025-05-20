//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sndfile.h>

#define SAMPLE_RATE 44100
#define AMPLITUDE 0.5
#define FREQUENCY 440.0
#define DURATION 5.0

void generate_sine_wave(double *buffer, int length, double frequency, double amplitude, int sample_rate) {
    for (int i = 0; i < length; i++) {
        buffer[i] = amplitude * sin(2 * M_PI * frequency * ((double)i / sample_rate));
    }
}

void apply_echo(double *buffer, int length, double delay, double decay) {
    int delay_samples = (int)(delay * SAMPLE_RATE);
    for (int i = delay_samples; i < length; i++) {
        buffer[i] += decay * buffer[i - delay_samples];
    }
}

void save_to_wav(const char *filename, double *buffer, int length) {
    SF_INFO sfinfo;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
    sfinfo.samplerate = SAMPLE_RATE;
    sfinfo.channels = 1;

    SNDFILE *outfile = sf_open(filename, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(NULL));
        exit(EXIT_FAILURE);
    }

    int16_t *output_buffer = malloc(length * sizeof(int16_t));
    for (int i = 0; i < length; i++) {
        output_buffer[i] = (int16_t)(buffer[i] * 32767);
    }

    sf_writef_short(outfile, output_buffer, length);
    sf_close(outfile);
    free(output_buffer);
}

void transform_wave(double *buffer, int length, double stretch_factor) {
    int new_length = (int)(length * stretch_factor);
    double *temp_buffer = malloc(new_length * sizeof(double));

    for (int i = 0; i < new_length; i++) {
        int original_index = (int)(i / stretch_factor);
        if (original_index < length) {
            temp_buffer[i] = buffer[original_index];
        } else {
            temp_buffer[i] = 0.0; // Fill in with silence if beyond original length
        }
    }
    
    memcpy(buffer, temp_buffer, new_length * sizeof(double)); // Copy back to original buffer
    free(temp_buffer);
}

int main() {
    // Create a sine wave buffer
    int length = (int)(DURATION * SAMPLE_RATE);
    double *sine_wave = malloc(length * sizeof(double));

    generate_sine_wave(sine_wave, length, FREQUENCY, AMPLITUDE, SAMPLE_RATE);
    printf("Sine wave generated.\n");

    // Apply an echo effect
    apply_echo(sine_wave, length, 0.2, 0.5);
    printf("Echo applied.\n");

    // Save the sine wave with echo to a WAV file
    save_to_wav("output.wav", sine_wave, length);
    printf("WAV file saved as output.wav.\n");

    // Stretch the wave for dramatic effect
    double stretch_factor = 1.5;
    transform_wave(sine_wave, length, stretch_factor);
    printf("Wave transformed with a stretch factor of %.2f.\n", stretch_factor);

    // Save the transformed wave to a new WAV file
    save_to_wav("stretched_output.wav", sine_wave, (int)(length * stretch_factor));
    printf("Transformed WAV file saved as stretched_output.wav.\n");

    // Clean up memory
    free(sine_wave);
    return 0;
}