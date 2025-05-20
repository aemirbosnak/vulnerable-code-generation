//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sndfile.h>
#include <math.h>

#define BUFFER_SIZE 1024

typedef struct {
    double* data;
    sf_count_t frames;
    int channels;
} AudioSignal;

AudioSignal* load_audio(const char* filename) {
    SF_INFO sfinfo;
    SNDFILE* infile = sf_open(filename, SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    AudioSignal* signal = (AudioSignal*)malloc(sizeof(AudioSignal));
    signal->frames = sfinfo.frames;
    signal->channels = sfinfo.channels;
    signal->data = (double*)malloc(signal->frames * signal->channels * sizeof(double));

    sf_readf_double(infile, signal->data, signal->frames);
    sf_close(infile);

    return signal;
}

void free_audio(AudioSignal* signal) {
    if (signal) {
        free(signal->data);
        free(signal);
    }
}

void apply_reverb(AudioSignal* signal, double decay) {
    if (!signal || signal->channels < 1) return;

    double* output = (double*)malloc(signal->frames * signal->channels * sizeof(double));
    for (sf_count_t i = 0; i < signal->frames; ++i) {
        for (int ch = 0; ch < signal->channels; ++ch) {
            double input_value = signal->data[i * signal->channels + ch];
            if (i == 0) {
                output[i * signal->channels + ch] = input_value;
            } else {
                output[i * signal->channels + ch] = input_value + (decay * output[(i - 1) * signal->channels + ch]);
            }
        }
    }

    memcpy(signal->data, output, signal->frames * signal->channels * sizeof(double));
    free(output);
}

void save_audio(const char* filename, AudioSignal* signal) {
    SF_INFO sfinfo;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
    sfinfo.channels = signal->channels;
    sfinfo.samplerate = 44100; // Assuming standard SR
    SNDFILE* outfile = sf_open(filename, SFM_WRITE, &sfinfo);
    
    if (!outfile) {
        fprintf(stderr, "Error opening file %s for writing\n", filename);
        return;
    }

    sf_writef_double(outfile, signal->data, signal->frames);
    sf_close(outfile);
}

void print_audio_info(AudioSignal* signal) {
    if (signal) {
        printf("Audio Info:\n");
        printf("Frames: %lld\n", signal->frames);
        printf("Channels: %d\n", signal->channels);
    }
}

int main(int argc, char** argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <reverb_decay>\n", argv[0]);
        return 1;
    }

    const char* input_file = argv[1];
    const char* output_file = argv[2];
    double reverb_decay = atof(argv[3]);

    AudioSignal* audio_signal = load_audio(input_file);
    if (!audio_signal) {
        return 1;
    }

    print_audio_info(audio_signal);
    apply_reverb(audio_signal, reverb_decay);
    save_audio(output_file, audio_signal);

    free_audio(audio_signal);
    printf("Processed audio saved to %s\n", output_file);
    
    return 0;
}