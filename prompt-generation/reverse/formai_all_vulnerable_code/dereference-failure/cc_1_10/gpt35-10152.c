//FormAI DATASET v1.0 Category: Audio processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *input_file;
    FILE *output_file;
    char input_filename[BUFFER_SIZE];
    char output_filename[BUFFER_SIZE];
    int sample_rate = 44100; // default sample rate

    if (argc < 3) {
        printf("Usage: %s input_file output_file [sample_rate]\n", argv[0]);
        return 1;
    }

    strncpy(input_filename, argv[1], BUFFER_SIZE);
    strncpy(output_filename, argv[2], BUFFER_SIZE);

    if (argc >= 4) {
        sample_rate = atoi(argv[3]);
    }

    input_file = fopen(input_filename, "rb");
    if (!input_file) {
        printf("Could not open input file '%s'\n", input_filename);
        return 2;
    }

    output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Could not open output file '%s'\n", output_filename);
        fclose(input_file);
        return 3;
    }

    // get file size
    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    // allocate memory for input buffer
    char *input_buffer = (char *)malloc(file_size);
    if (!input_buffer) {
        printf("Could not allocate memory for input buffer\n");
        fclose(input_file);
        fclose(output_file);
        return 4;
    }

    // read input file into input buffer
    fread(input_buffer, 1, file_size, input_file);

    // write output file header
    // WAV format header
    char wave_header[44] = {
        'R', 'I', 'F', 'F',  // RIFF header
        0x00, 0x00, 0x00, 0x00,  // total file size (bytes) - 8
        'W', 'A', 'V', 'E',  // WAV chunk header
        'f', 'm', 't', ' ',  // fmt sub-chunk header
        0x10, 0x00, 0x00, 0x00,  // fmt sub-chunk size
        0x01, 0x00, 0x01, 0x00,  // audio format (PCM), num channels (1)
        0x80, 0x3e, 0x00, 0x00,  // sample rate (44100 Hz)
        0x00, 0x7d, 0x00, 0x00,  // byte rate (44100 Hz * 1 * 2 Bytes per sample)
        0x02, 0x00, 0x10, 0x00,  // block align (1 * 2 Bytes per sample), bits per sample (16)
        'd', 'a', 't', 'a',  // data sub-chunk header
        0x00, 0x00, 0x00, 0x00,  // data sub-chunk size (bytes)
    };
    int data_size = file_size - 44; // subtract header size
    memcpy(&wave_header[4], &data_size, 4); // update total file size
    memcpy(&wave_header[24], &sample_rate, 4); // update sample rate
    fwrite(wave_header, 1, 44, output_file); // write header

    // allocate memory for output buffer
    short *output_buffer = (short *)malloc(data_size);
    if (!output_buffer) {
        printf("Could not allocate memory for output buffer\n");
        fclose(input_file);
        fclose(output_file);
        free(input_buffer);
        return 5;
    }

    // process audio data
    int i, sample_count = data_size / 2; // each sample is 2 bytes
    short *input_samples = (short *)input_buffer;
    for (i = 0; i < sample_count; i++) {
        // apply gain to each sample
        input_samples[i] *= 2;
        // clip each sample to range [-32768, 32767]
        if (input_samples[i] < -32768) {
            input_samples[i] = -32768;
        }
        if (input_samples[i] > 32767) {
            input_samples[i] = 32767;
        }
        // store modified sample in output buffer
        output_buffer[i] = input_samples[i];
    }

    // write output data
    fwrite(output_buffer, 2, sample_count, output_file);

    // cleanup and exit
    fclose(input_file);
    fclose(output_file);
    free(input_buffer);
    free(output_buffer);
    return 0;
}