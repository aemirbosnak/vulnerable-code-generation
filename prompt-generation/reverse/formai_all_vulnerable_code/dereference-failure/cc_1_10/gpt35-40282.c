//FormAI DATASET v1.0 Category: Digital signal processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This program takes an audio file input and applies a low pass filter on the audio signal. */
#define PI 3.14159265358979323846

/* Function to read the contents of a WAV file */
void read_wav_file(FILE *file, short int *audio_samples, int num_samples)
{
    int i;
    short int data_chunk_header[2];
    short int chunk_size;
    short int audio_format;
    short int num_channels;
    int sample_rate;
    int byte_rate;
    short int block_align;
    short int bits_per_sample;
    
    /* Read header info */
    fread(data_chunk_header, sizeof(data_chunk_header), 1, file);
    fread(&chunk_size, sizeof(chunk_size), 1, file);
    fread(&audio_format, sizeof(audio_format), 1, file);
    fread(&num_channels, sizeof(num_channels), 1, file);
    fread(&sample_rate, sizeof(sample_rate), 1, file);
    fread(&byte_rate, sizeof(byte_rate), 1, file);
    fread(&block_align, sizeof(block_align), 1, file);
    fread(&bits_per_sample, sizeof(bits_per_sample), 1, file);
    fseek(file, chunk_size-16, SEEK_CUR);
    
    /* Read audio samples */
    for (i=0; i<num_samples; i++) {
        fread(&audio_samples[i], sizeof(audio_samples[i]), 1, file);
    }
}

/* Function to write the contents of a WAV file */
void write_wav_file(FILE *file, short int *audio_samples, int num_samples, int sample_rate)
{
    short int data_chunk_header[] = {'d', 'a'};
    int chunk_size = num_samples*sizeof(short int) + 36;
    short int format_chunk_header[] = {'f', 'm'};
    int format_chunk_size = 16;
    short int audio_format = 1;
    short int num_channels = 1;
    int byte_rate = sample_rate*sizeof(short int);
    short int block_align = sizeof(short int);
    short int bits_per_sample = 16;
    short int data_chunk[] = {'d', 'a'};
    
    /* Write header info */
    fwrite("RIFF", 4, 1, file);
    fwrite(&chunk_size, sizeof(chunk_size), 1, file);
    fwrite("WAVE", 4, 1, file);
    
    fwrite(format_chunk_header, sizeof(format_chunk_header), 1, file);
    fwrite(&format_chunk_size, sizeof(format_chunk_size), 1, file);
    fwrite(&audio_format, sizeof(audio_format), 1, file);
    fwrite(&num_channels, sizeof(num_channels), 1, file);
    fwrite(&sample_rate, sizeof(sample_rate), 1, file);
    fwrite(&byte_rate, sizeof(byte_rate), 1, file);
    fwrite(&block_align, sizeof(block_align), 1, file);
    fwrite(&bits_per_sample, sizeof(bits_per_sample), 1, file);
    
    fwrite(data_chunk, sizeof(data_chunk), 1, file);
    fwrite(&num_samples, sizeof(num_samples), 1, file);
    
    /* Write audio samples */
    for (int i=0; i<num_samples; i++) {
        fwrite(&audio_samples[i], sizeof(audio_samples[i]), 1, file);;
    }
}

/* Function to apply a low pass filter on an audio signal */
void low_pass_filter(short int *audio_samples, int num_samples, float cutoff_frequency, int sample_rate)
{
    float RC = 1.0/(2*PI*cutoff_frequency);
    float dt = 1.0/sample_rate;
    float alpha = RC/(RC+dt);

    float y_prev = audio_samples[0];
    for (int i=1; i<num_samples; i++) {
        audio_samples[i] = alpha*audio_samples[i] + (1-alpha)*y_prev;
        y_prev = audio_samples[i];
    }
}

int main()
{
    FILE *audio_file;
    short int *audio_samples;
    int num_samples;
    int sample_rate;

    /* Open input audio file */
    audio_file = fopen("input.wav", "rb");
    if (!audio_file) {
        printf("Error opening audio file.\n");
        return 1;
    }

    /* Read input audio file */
    fseek(audio_file, 0, SEEK_END);
    num_samples = ftell(audio_file)/sizeof(short int);
    audio_samples = (short int *)malloc(num_samples*sizeof(short int));
    fseek(audio_file, 0, SEEK_SET);
    read_wav_file(audio_file, audio_samples, num_samples);
    fclose(audio_file);

    /* Apply low pass filter */
    sample_rate = num_samples/5;
    low_pass_filter(audio_samples, num_samples, 1000.0, sample_rate);

    /* Open output audio file */
    audio_file = fopen("output.wav", "wb");
    if (!audio_file) {
        printf("Error opening audio file.\n");
        return 1;
    }

    /* Write output audio file */
    write_wav_file(audio_file, audio_samples, num_samples, sample_rate);
    fclose(audio_file);

    /* Free memory */
    free(audio_samples);

    return 0;
}