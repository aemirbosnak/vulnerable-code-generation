//FormAI DATASET v1.0 Category: Audio processing ; Style: systematic
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int16_t* read_wave_file(char *filename, uint32_t *sample_rate, uint32_t *num_samples);
void write_wave_file(char *filename, int16_t *data, uint32_t sample_rate, uint32_t num_samples);

int main(void) {
    char *input_wave_file = "test.wav";
    char *output_wave_file = "processed.wav";
    
    uint32_t sample_rate;
    uint32_t num_samples;
    
    // Read input wave file
    int16_t *input_data = read_wave_file(input_wave_file, &sample_rate, &num_samples);
    if (!input_data) {
        printf("ERROR: failed to read input wave file %s\n", input_wave_file);
        return 1;
    }
    
    // Define processing parameters
    float tone_frequency = 1000;    // Tone frequency in Hz
    float tone_amplitude = 0.5;     // Tone amplitude (0-1)
    
    // Generate tone signal
    int16_t *tone_data = malloc(sizeof(int16_t) * num_samples);
    if (!tone_data) {
        printf("ERROR: failed to allocate memory for tone signal\n");
        free(input_data);
        return 1;
    }
    float time_step = 1.0 / sample_rate;
    float time = 0;
    for (uint32_t i = 0; i < num_samples; i++) {
        tone_data[i] = (int16_t)(tone_amplitude * 32767.0 * sin(2.0 * PI * tone_frequency * time));
        time += time_step;
    }
    
    // Add tone signal to input signal
    for (uint32_t i = 0; i < num_samples; i++) {
        input_data[i] += tone_data[i];
    }
    
    // Write output wave file
    write_wave_file(output_wave_file, input_data, sample_rate, num_samples);
    
    // Free memory
    free(input_data);
    free(tone_data);
    
    printf("Finished processing wave file %s\n", input_wave_file);
    
    return 0;
}

int16_t* read_wave_file(char *filename, uint32_t *sample_rate, uint32_t *num_samples) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }
    
    char chunk_id[5];
    uint32_t chunk_size;
    char format[5];
    char subchunk1_id[5];
    uint32_t subchunk1_size;
    uint16_t audio_format;
    uint16_t num_channels;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
    char subchunk2_id[5];
    uint32_t subchunk2_size;
    
    fread(chunk_id, sizeof(char), 4, file);
    fread(&chunk_size, sizeof(uint32_t), 1, file);
    fread(format, sizeof(char), 4, file);
    fread(subchunk1_id, sizeof(char), 4, file);
    fread(&subchunk1_size, sizeof(uint32_t), 1, file);
    fread(&audio_format, sizeof(uint16_t), 1, file);
    fread(&num_channels, sizeof(uint16_t), 1, file);
    fread(sample_rate, sizeof(uint32_t), 1, file);
    fread(&byte_rate, sizeof(uint32_t), 1, file);
    fread(&block_align, sizeof(uint16_t), 1, file);
    fread(&bits_per_sample, sizeof(uint16_t), 1, file);
    fread(subchunk2_id, sizeof(char), 4, file);
    fread(&subchunk2_size, sizeof(uint32_t), 1, file);
    
    *num_samples = subchunk2_size / (bits_per_sample / 8);
    int16_t *data = malloc(sizeof(int16_t) * (*num_samples));
    if (!data) {
        return NULL;
    }
    fread(data, sizeof(int16_t), (*num_samples), file);
    
    fclose(file);
    
    return data;
}

void write_wave_file(char *filename, int16_t *data, uint32_t sample_rate, uint32_t num_samples) {
    FILE *file = fopen(filename, "wb");
    
    char chunk_id[5] = "RIFF";
    uint32_t chunk_size = 36 + num_samples * sizeof(int16_t);
    char format[5] = "WAVE";
    char subchunk1_id[5] = "fmt ";
    uint32_t subchunk1_size = 16;
    uint16_t audio_format = 1;
    uint16_t num_channels = 1;
    uint32_t byte_rate = sample_rate * num_channels * sizeof(int16_t);
    uint16_t block_align = num_channels * sizeof(int16_t);
    uint16_t bits_per_sample = 16;
    char subchunk2_id[5] = "data";
    uint32_t subchunk2_size = num_samples * sizeof(int16_t);
    
    fwrite(chunk_id, sizeof(char), 4, file);
    fwrite(&chunk_size, sizeof(uint32_t), 1, file);
    fwrite(format, sizeof(char), 4, file);
    fwrite(subchunk1_id, sizeof(char), 4, file);
    fwrite(&subchunk1_size, sizeof(uint32_t), 1, file);
    fwrite(&audio_format, sizeof(uint16_t), 1, file);
    fwrite(&num_channels, sizeof(uint16_t), 1, file);
    fwrite(&sample_rate, sizeof(uint32_t), 1, file);
    fwrite(&byte_rate, sizeof(uint32_t), 1, file);
    fwrite(&block_align, sizeof(uint16_t), 1, file);
    fwrite(&bits_per_sample, sizeof(uint16_t), 1, file);
    fwrite(subchunk2_id, sizeof(char), 4, file);
    fwrite(&subchunk2_size, sizeof(uint32_t), 1, file);
    fwrite(data, sizeof(int16_t), num_samples, file);
    
    fclose(file);
}