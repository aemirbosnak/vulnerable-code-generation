//FormAI DATASET v1.0 Category: Audio processing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double *data;    // Double precision audio data
    int length;      // Length of audio data
} Audio;

/*
 * Applies a retro effect to the audio by applying a low-pass filter
 * and a bit-crusher effect.
 */
void apply_retroness(Audio *audio, double cutoff, int bit_depth) {
    int i, j;
    double lp_alpha = 2 * PI * cutoff / 44100;  // Low-pass filter alpha value
    double lp_output = 0;                      // Low-pass filter output
    int bit_mask = (1 << bit_depth) - 1;        // Bit mask for crushing bits
    double quantization_error = 0;             // Error from bit crusher
    double quantized_sample;                   // Quantized sample value
    
    // Allocate memory for temporary audio data
    double *temp_data = (double *)malloc(sizeof(double) * audio->length);
    if (temp_data == NULL) {
        printf("Error: Failed to allocate memory for temporary audio data.\n");
        return;
    }
    
    // Apply low-pass filter to audio data
    for (i = 0; i < audio->length; i++) {
        lp_output += lp_alpha * (audio->data[i] - lp_output);
        temp_data[i] = lp_output;
    }
    
    // Apply bit-crusher effect to audio data
    for (i = 0; i < audio->length; i++) {
        quantized_sample = round(temp_data[i] * bit_mask) / bit_mask;
        quantization_error += temp_data[i] - quantized_sample;
        temp_data[i] = quantized_sample;
    }
    
    // Add quantization error to final sample
    for (i = 0; i < audio->length; i++) {
        temp_data[i] += quantization_error / audio->length;
    }
    
    // Free memory from temporary audio data
    free(audio->data);
    audio->data = temp_data;
}

int main() {
    // Read audio file into memory
    FILE *file = fopen("audio.wav", "rb");
    if (file == NULL) {
        printf("Error: Failed to open audio file.\n");
        return -1;
    }
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);
    char *wav_data = (char *)malloc(sizeof(char) * file_size);
    if (wav_data == NULL) {
        printf("Error: Failed to allocate memory for audio file.\n");
        fclose(file);
        return -1;
    }
    fread(wav_data, 1, file_size, file);
    fclose(file);
    
    // Convert audio file to double-precision audio
    Audio audio;
    audio.length = (file_size - 44) / 2;
    audio.data = (double *)malloc(sizeof(double) * audio.length);
    if (audio.data == NULL) {
        printf("Error: Failed to allocate memory for audio data.\n");
        free(wav_data);
        return -1;
    }
    int i, j;
    short int *wav_data_short = (short int *)(wav_data + 44);
    for (i = 0, j = 0; i < audio.length; i++, j += 2) {
        audio.data[i] = (double)wav_data_short[j] / 32768;
    }
    free(wav_data);
    
    // Apply retro effect to audio
    apply_retroness(&audio, 2000, 8);
    
    // Convert double-precision audio to audio file
    char *file_data = (char *)malloc(sizeof(char) * (audio.length * 2 + 44));
    if (file_data == NULL) {
        printf("Error: Failed to allocate memory for audio file.\n");
        free(audio.data);
        return -1;
    }
    memcpy(file_data, wav_data, 44);
    short int *file_data_short = (short int *)(file_data + 44);
    for (i = 0, j = 0; i < audio.length; i++, j += 2) {
        file_data_short[j] = (short int)(audio.data[i] * 32768);
    }
    
    // Write audio file to disk
    FILE *out_file = fopen("audio_retroness.wav", "wb");
    if (out_file == NULL) {
        printf("Error: Failed to open output audio file.\n");
        free(file_data);
        free(audio.data);
        return -1;
    }
    fwrite(file_data, 1, audio.length * 2 + 44, out_file);
    fclose(out_file);
    
    // Free memory from audio data and file data
    free(audio.data);
    free(file_data);
    
    return 0;
}