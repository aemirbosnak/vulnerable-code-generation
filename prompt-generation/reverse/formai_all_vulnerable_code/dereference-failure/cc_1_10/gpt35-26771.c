//FormAI DATASET v1.0 Category: Audio processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function to generate a sinusoidal wave of specified frequency and sampling rate
void generate_sine_wave(double** buffer, double frequency, double sampling_rate, double duration) {
    int num_samples = (int)(duration * sampling_rate);
    *buffer = (double*)malloc(num_samples * sizeof(double));
    for(int i=0; i<num_samples; i++) {
        double t = (double)i / sampling_rate;
        (*buffer)[i] = sin(2 * M_PI * frequency * t);
    }
}

//Function to normalize the amplitude of the audio signal
void normalize_amplitude(double* buffer, int buffer_size) {
    double max_amp = 0;
    for(int i=0; i<buffer_size; i++) {
        if(fabs(buffer[i]) > max_amp) {
            max_amp = fabs(buffer[i]);
        }
    }
    for(int i=0; i<buffer_size; i++) {
        buffer[i] /= max_amp;
    }
}

//Function to add two audio signals
void add_audio_signal(double* signal1, double* signal2, int signal_size) {
    for(int i=0; i<signal_size; i++) {
        signal1[i] += signal2[i];
    }
}

int main() {
    double* buffer1, *buffer2;
    double frequency1 = 440; //A4
    double frequency2 = 523.2; //C5
    double sampling_rate = 44100;
    double duration = 0.5; //in seconds
    
    generate_sine_wave(&buffer1, frequency1, sampling_rate, duration);
    generate_sine_wave(&buffer2, frequency2, sampling_rate, duration);

    normalize_amplitude(buffer1, (int)(duration * sampling_rate));
    normalize_amplitude(buffer2, (int)(duration * sampling_rate));

    add_audio_signal(buffer1, buffer2, (int)(duration * sampling_rate));

    FILE* output_file = fopen("output.pcm", "wb");
    fwrite(buffer1, sizeof(double), (int)(duration * sampling_rate), output_file);
    fclose(output_file);

    free(buffer1);
    free(buffer2);

    return 0;
}