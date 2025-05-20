//FormAI DATASET v1.0 Category: Audio processing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

// function to read in audio file data (16-bit PCM, little-endian)
// and return the data as a float array (-1.0 to 1.0 range)
float* read_audio(const char* filename, uint32_t* num_samples, uint32_t* sample_rate) {
    FILE* f = fopen(filename, "rb");

    uint32_t chunk_id;
    fread(&chunk_id, sizeof(chunk_id), 1, f);
    if (chunk_id != 0x46464952) { // "RIFF"
        printf("Error: file is not a valid WAV file.\n");
        return NULL;
    }

    uint32_t file_size;
    fread(&file_size, sizeof(file_size), 1, f);

    uint32_t format;
    fread(&format, sizeof(format), 1, f);
    if (format != 0x45564157) { // "WAVE"
        printf("Error: file is not a valid WAV file.\n");
        return NULL;
    }

    uint32_t subchunk_1_id;
    fread(&subchunk_1_id, sizeof(subchunk_1_id), 1, f);
    if (subchunk_1_id != 0x20746d66) { // "fmt "
        printf("Error: file is not a valid WAV file.\n");
        return NULL;
    }

    uint32_t subchunk_1_size;
    fread(&subchunk_1_size, sizeof(subchunk_1_size), 1, f);

    uint16_t audio_format;
    fread(&audio_format, sizeof(audio_format), 1, f);
    if (audio_format != 1) {
        printf("Error: file is not in PCM format.\n");
        return NULL;
    }

    uint16_t num_channels;
    fread(&num_channels, sizeof(num_channels), 1, f);

    fread(sample_rate, sizeof(*sample_rate), 1, f);

    uint32_t byte_rate;
    fread(&byte_rate, sizeof(byte_rate), 1, f);

    uint16_t block_align;
    fread(&block_align, sizeof(block_align), 1, f);

    uint16_t bits_per_sample;
    fread(&bits_per_sample, sizeof(bits_per_sample), 1, f);
    if (bits_per_sample != 16) {
        printf("Error: file is not 16-bit.\n");
        return NULL;
    }

    uint32_t subchunk_2_id;
    fread(&subchunk_2_id, sizeof(subchunk_2_id), 1, f);
    if (subchunk_2_id != 0x61746164) { // "data"
        printf("Error: file is not a valid WAV file.\n");
        return NULL;
    }

    uint32_t data_size;
    fread(&data_size, sizeof(data_size), 1, f);
    *num_samples = data_size / 2;

    float* audio_data = calloc(*num_samples, sizeof(float));

    int16_t* audio_data_int = malloc(data_size);
    fread(audio_data_int, data_size, 1, f);

    fclose(f);

    for (uint32_t i = 0; i < *num_samples; i++) {
        audio_data[i] = (float)audio_data_int[i] / 32768.0f;
    }

    free(audio_data_int);

    return audio_data;
}

// function to write audio data to a file, given a float array (-1.0 to 1.0 range)
// and the number of samples and sample rate
void write_audio(const char* filename, float* data, uint32_t num_samples, uint32_t sample_rate) {
    int16_t* data_int = malloc(num_samples * sizeof(int16_t));
    for (uint32_t i = 0; i < num_samples; i++) {
        data_int[i] = (int16_t)(data[i] * 32768.0f);
    }

    FILE* f = fopen(filename, "wb");

    uint32_t chunk_id = 0x46464952; // "RIFF"
    fwrite(&chunk_id, sizeof(chunk_id), 1, f);

    uint32_t file_size = num_samples * 2 + 36;
    fwrite(&file_size, sizeof(file_size), 1, f);

    uint32_t format = 0x45564157; // "WAVE"
    fwrite(&format, sizeof(format), 1, f);

    uint32_t subchunk_1_id = 0x20746d66; // "fmt "
    fwrite(&subchunk_1_id, sizeof(subchunk_1_id), 1, f);

    uint32_t subchunk_1_size = 16;
    fwrite(&subchunk_1_size, sizeof(subchunk_1_size), 1, f);

    uint16_t audio_format = 1; // PCM
    fwrite(&audio_format, sizeof(audio_format), 1, f);

    uint16_t num_channels = 1;
    fwrite(&num_channels, sizeof(num_channels), 1, f);

    fwrite(&sample_rate, sizeof(sample_rate), 1, f);

    uint32_t byte_rate = sample_rate * num_channels * 2;
    fwrite(&byte_rate, sizeof(byte_rate), 1, f);

    uint16_t block_align = num_channels * 2;
    fwrite(&block_align, sizeof(block_align), 1, f);

    uint16_t bits_per_sample = 16;
    fwrite(&bits_per_sample, sizeof(bits_per_sample), 1, f);

    uint32_t subchunk_2_id = 0x61746164; // "data"
    fwrite(&subchunk_2_id, sizeof(subchunk_2_id), 1, f);

    uint32_t data_size = num_samples * 2;
    fwrite(&data_size, sizeof(data_size), 1, f);

    fwrite(data_int, num_samples * sizeof(int16_t), 1, f);

    fclose(f);

    free(data_int);
}

int main(int argc, char** argv) {
    uint32_t num_samples, sample_rate;
    float* audio_data = read_audio("input.wav", &num_samples, &sample_rate);

    // apply gain (increase volume)
    float gain = 2.0f;
    for (uint32_t i = 0; i < num_samples; i++) {
        audio_data[i] *= gain;
    }

    // apply low-pass filter at 500 Hz
    float cutoff_freq = 500.0f;
    float dt = 1.0f / sample_rate;
    float RC = 1.0f / (cutoff_freq * 2.0f * M_PI);
    float alpha = dt / (RC + dt);
    float y_prev = 0.0f;
    for (uint32_t i = 0; i < num_samples; i++) {
        float y = alpha * audio_data[i] + (1.0f - alpha) * y_prev;
        y_prev = y;
        audio_data[i] = y;
    }

    write_audio("output.wav", audio_data, num_samples, sample_rate);

    free(audio_data);

    return 0;
}