//FormAI DATASET v1.0 Category: Audio processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Structures for wave file headers and format information
typedef struct s_wave_header {
    char chunk_id[4];
    unsigned int chunk_size;
    char format[4];
    char subchunk1_id[4];
    unsigned int subchunk1_size;
    unsigned short int audio_format;
    unsigned short int num_channels;
    unsigned int sample_rate;
    unsigned int byte_rate;
    unsigned short int block_align;
    unsigned short int bits_per_sample;
    char subchunk2_id[4];
    unsigned int subchunk2_size;
} wave_header;

typedef struct s_wave_format {
    unsigned short int audio_format;
    unsigned short int num_channels;
    unsigned int sample_rate;
    unsigned int byte_rate;
    unsigned short int block_align;
    unsigned short int bits_per_sample;
} wave_format;

// Function prototypes
wave_header read_wave_header(FILE* wave_file);
void write_wave_header(FILE* wave_file, wave_header header);
short* read_wave_data(FILE* wave_file, wave_header header);
void write_wave_data(FILE* wave_file, short* data, wave_header header);
void delay(short* data, int delay_length, float mix, float feedback);

int main(int argc, char** argv) {
    if(argc != 5) {
        printf("Usage: %s input_file output_file delay_length feedback\n", argv[0]);
        exit(1);
    }
    
    // Read in parameters
    char* input_file = argv[1];
    char* output_file = argv[2];
    int delay_length = atoi(argv[3]);
    float feedback = atof(argv[4]);
    
    // Open input file and read header and data
    FILE* input = fopen(input_file, "rb");
    wave_header input_header = read_wave_header(input);
    short* input_data = read_wave_data(input, input_header);
    fclose(input);
    
    // Process the audio using the delay effect
    delay(input_data, delay_length, 0.5, feedback);
    
    // Write out processed audio to output file
    FILE* output = fopen(output_file, "wb");
    write_wave_header(output, input_header);
    write_wave_data(output, input_data, input_header);
    fclose(output);
    
    // Free up memory for audio data
    free(input_data);
    
    return 0;
}

// Function to read in a wave file header
wave_header read_wave_header(FILE* wave_file) {
    wave_header header;
    fread(&header, sizeof(header), 1, wave_file);
    return header;
}

// Function to write out a wave file header
void write_wave_header(FILE* wave_file, wave_header header) {
    fwrite(&header, sizeof(header), 1, wave_file);
}

// Function to read in wave file data
short* read_wave_data(FILE* wave_file, wave_header header) {
    int num_samples = header.subchunk2_size / (header.bits_per_sample / 8);
    short* data = (short*)malloc(num_samples * sizeof(short));
    fread(data, sizeof(short), num_samples, wave_file);
    return data;
}

// Function to write out wave file data
void write_wave_data(FILE* wave_file, short* data, wave_header header) {
    int num_samples = header.subchunk2_size / (header.bits_per_sample / 8);
    fwrite(data, sizeof(short), num_samples, wave_file);
}

// Function to perform the delay effect on audio data
void delay(short* data, int delay_length, float mix, float feedback) {
    int num_samples = delay_length + strlen(data);
    short* delay_buffer = (short*)calloc(num_samples, sizeof(short));
    for(int i = 0; i < strlen(data); i++) {
        delay_buffer[i + delay_length] = data[i] + (short)(feedback * delay_buffer[i]);
        data[i] = (1 - mix) * data[i] + mix * delay_buffer[i];
    }
    free(delay_buffer);
}