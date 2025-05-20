//FormAI DATASET v1.0 Category: Audio processing ; Style: energetic
/* This program applies energetic audio processing to a wav file, increasing the tempo and adding distortion */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.1415926535

// function to read wav file data
int read_wav(char *file_name, float **data, int *length)
{
    FILE *file;
    int i, channels, sample_rate, bits_per_sample;
    unsigned int bytes_per_sample, riff_size, chunk_size;
    char format[4];

    // open file
    file = fopen(file_name, "rb");
    if (!file)
    {
        printf("Failed to open file: %s\n", file_name);
        return -1;
    }

    // read header
    fread(format, sizeof(char), 4, file);
    fread(&riff_size, sizeof(unsigned int), 1, file);
    fread(format, sizeof(char), 4, file);
    fread(format, sizeof(char), 4, file);
    fread(format, sizeof(char), 4, file);
    fread(&chunk_size, sizeof(unsigned int), 1, file);
    fread(&channels, sizeof(short int), 1, file);
    fread(&sample_rate, sizeof(int), 1, file);
    fread(format, sizeof(char), 4, file);
    fread(&bits_per_sample, sizeof(short int), 1, file);
    fread(format, sizeof(char), 4, file);

    bytes_per_sample = bits_per_sample / 8;

    *length = chunk_size / bytes_per_sample;
    *data = (float *) malloc(*length * sizeof(float));

    // read data
    for (i = 0; i < *length; i++)
    {
        fread((*data) + i, bytes_per_sample, 1, file);
    }

    fclose(file);

    return sample_rate;
}

// function to write data to wav file
void write_wav(char *file_name, float *data, int length, int sample_rate)
{
    FILE *file;
    int bits_per_sample = 16, riff_size = length * bits_per_sample / 8 + 36, chunk_size = length * bits_per_sample / 8;
    short int format_type = 1, channels = 1;
    char format[4] = "WAVE";

    // open file
    file = fopen(file_name, "wb");
    if (!file)
    {
        printf("Failed to open file: %s\n", file_name);
        return;
    }

    // write header
    fwrite(format, sizeof(char), 4, file);
    fwrite(&riff_size, sizeof(unsigned int), 1, file);
    fwrite(format, sizeof(char), 4, file);
    fwrite(format, sizeof(char), 4, file);
    fwrite("fmt ", sizeof(char), 4, file);
    fwrite("\x10\x00\x00\x00", sizeof(int), 1, file);
    fwrite(&format_type, sizeof(short int), 1, file);
    fwrite(&channels, sizeof(short int), 1, file);
    fwrite(&sample_rate, sizeof(int), 1, file);
    fwrite("\x00\x7D\x00\x00", sizeof(int), 1, file);
    fwrite("\x02\x00\x10\x00", sizeof(short int), 1, file);
    fwrite("data", sizeof(char), 4, file);
    fwrite(&chunk_size, sizeof(unsigned int), 1, file);

    // write data
    for (int i = 0; i < length; i++)
    {
        short int sample = data[i] * 32767;
        fwrite(&sample, sizeof(short int), 1, file);
    }

    fclose(file);
}

// function to apply distortion to signal
void apply_distortion(float *signal, int length, float drive)
{
    for (int i = 0; i < length; i++)
    {
        float x = signal[i] * drive;
        signal[i] = tanh(x) / tanh(drive);
    }
}

// function to increase tempo of signal
float *increase_tempo(float *signal, int length, float factor)
{
    int new_length = (int) ((float) length / factor);
    float *new_signal = (float *) malloc(new_length * sizeof(float));

    for (int i = 0; i < new_length; i++)
    {
        float x = (float) i * factor;
        int index1 = (int) floor(x);
        int index2 = (int) ceil(x);

        if (index2 >= length)
        {
            index1--;
            index2--;
        }

        float a = x - index1;
        float b = 1 - a;

        new_signal[i] = a * signal[index2] + b * signal[index1];
    }

    return new_signal;
}

// function to apply filter to signal
void apply_filter(float *signal, int length, int cut_off)
{
    float alpha = 1 - exp(-2 * PI * cut_off / SAMPLE_RATE);
    float y_prev = 0;

    for (int i = 0; i < length; i++)
    {
        float y = alpha * signal[i] + (1 - alpha) * y_prev;
        y_prev = y;
        signal[i] = y;
    }
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Usage: %s [input file] [output file] [drive] [tempo] [filter]\n", argv[0]);
        printf("drive: distortion drive (0 to 1)\n");
        printf("tempo: tempo factor (0 to 2)\n");
        printf("filter: cut off frequency (0 to 22050 Hz)\n");
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    float drive = argc >= 4 ? atof(argv[3]) : 0.5;
    float tempo = argc >= 5 ? atof(argv[4]) : 1.0;
    int cut_off = argc >= 6 ? atoi(argv[5]) : 0;

    // read wav data
    float *data;
    int length, sample_rate;
    sample_rate = read_wav(input_file, &data, &length);
    if (sample_rate == -1)
    {
        return 1;
    }

    // apply energetic processing
    apply_distortion(data, length, drive);
    float *new_data = increase_tempo(data, length, tempo);
    apply_filter(new_data, length / tempo, cut_off);
    
    // write processed data to wav file
    write_wav(output_file, new_data, length / tempo, sample_rate);
    
    free(data);
    free(new_data);

    printf("File processed successfully!\n");

    return 0;
}