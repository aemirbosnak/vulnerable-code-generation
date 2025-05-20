//FormAI DATASET v1.0 Category: Audio processing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

/* C Audio Processing Example */

int main()
{
    // Read in audio file data
    int8_t *audio_data;
    int audio_data_size = 44100;
    audio_data = malloc(sizeof(int8_t)*audio_data_size);

    // TODO: read in audio file here...

    // Apply a gain of 2 to the audio data
    for (int i = 0; i < audio_data_size; i++){
        audio_data[i] *= 2;
    }

    // Apply a low-pass filter to the audio data
    double cutoff_frequency = 5000.0;
    double sample_rate = 44100.0;
    double delta_time = 1.0/sample_rate;
    double RC = 1.0/(2.0 * M_PI * cutoff_frequency);
    double alpha = delta_time / (RC + delta_time);

    // Filter coefficients
    double a0 = 1.0 - alpha;
    double a1 = -(1.0 - alpha);
    double b0 = alpha;
    double b1 = 0.0;

    // Apply the filter
    double x_n = 0.0;
    double x_n1 = 0.0;
    double y_n = 0.0;
    double y_n1 = 0.0;
    for (int i = 0; i < audio_data_size; i++){
        x_n = (double) audio_data[i];
        y_n = b0 * x_n + b1 * x_n1 - a1 * y_n1;

        // Write back to array
        audio_data[i] = (int8_t) y_n;

        // Update variables
        x_n1 = x_n;
        y_n1 = y_n;
    }

    // Write out audio data to file
    FILE *out_file;
    out_file = fopen("processed_audio.raw", "wb");
    fwrite(audio_data, sizeof(int8_t), audio_data_size, out_file);
    fclose(out_file);

    free(audio_data);

    return 0;
}