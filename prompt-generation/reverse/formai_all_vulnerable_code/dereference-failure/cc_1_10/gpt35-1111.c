//FormAI DATASET v1.0 Category: Audio processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to my Audio processing program!\n");
    printf("This program will read an audio file, amplify the volume and write the new audio file.\n");
    
    FILE *audio_file;
    audio_file = fopen("audio.wav", "rb");
    
    if(audio_file == NULL) {
        printf("Error Opening File.\n");
        return -1;
    }
    
    int volume_level = 2;
    
    char header[44];
    fread(header, sizeof(char), 44, audio_file);
    printf("The header of the audio file is:\n%s", header);
    
    int sample_rate, bit_rate, audio_data_size;
    fseek(audio_file, 24, SEEK_SET);
    fread(&sample_rate, sizeof(int), 1, audio_file);
    printf("The sample rate of the audio file is: %d\n", sample_rate);
    
    fseek(audio_file, 34, SEEK_SET);
    fread(&bit_rate, sizeof(int), 1, audio_file);
    printf("The bit rate of the audio file is: %d\n", bit_rate);
    
    fseek(audio_file, 40, SEEK_SET);
    fread(&audio_data_size, sizeof(int), 1, audio_file);
    printf("The audio data size of the audio file is: %d\n", audio_data_size);
    
    char *audio_buffer = malloc(audio_data_size * sizeof(char));
    fread(audio_buffer, sizeof(char), audio_data_size, audio_file);
    
    for(int i=0; i<audio_data_size; i+=2) {
        short *sample = (short *) (audio_buffer + i);
        *sample = *sample * volume_level;
    }
    
    fclose(audio_file);
    
    FILE *new_audio_file;
    new_audio_file = fopen("new_audio.wav", "wb");
    
    fwrite(header, sizeof(char), 44, new_audio_file);
    fwrite(audio_buffer, sizeof(char), audio_data_size, new_audio_file);

    printf("Audio Processing completed successfully, new_audio.wav file is created with amplified audio data.\n");
    
    fclose(new_audio_file);
    free(audio_buffer);
    
    return 0;
}