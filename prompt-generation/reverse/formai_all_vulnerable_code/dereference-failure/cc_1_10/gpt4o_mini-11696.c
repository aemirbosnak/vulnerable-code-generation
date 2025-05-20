//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", prog_name);
}

void apply_gain(int16_t *buffer, size_t size, float gain) {
    for (size_t i = 0; i < size; i++) {
        int32_t sample = (int32_t)buffer[i] * gain;
        if (sample > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (sample < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = (int16_t)sample;
        }
    }
}

int read_wav_header(FILE *file, uint32_t *data_size) {
    char header[44];
    if (fread(header, sizeof(char), 44, file) < 44) {
        fprintf(stderr, "Failed to read WAV header: %s\n", strerror(errno));
        return -1;
    }
  
    // Check for the "RIFF" and "WAVE" header
    if (strncmp(header, "RIFF", 4) != 0 || strncmp(header + 8, "WAVE", 4) != 0) {
        fprintf(stderr, "Invalid WAV file format.\n");
        return -1;
    }
    
    // Get the data size
    uint32_t chunk_size = *(uint32_t *)(header + 40);
    *data_size = chunk_size;

    return 0;
}

int write_wav_header(FILE *file, uint32_t data_size) {
    char header[44] = {
        'R', 'I', 'F', 'F',
        0, 0, 0, 0, // Placeholder for file size
        'W', 'A', 'V', 'E',
        'f', 'm', 't', ' ',
        16, 0, 0, 0, // Subchunk1Size (16 for PCM)
        1, 0,        // AudioFormat (PCM)
        1, 0,        // NumChannels (1 for mono)
        44100 & 0xff, (44100 >> 8) & 0xff, (44100 >> 16) & 0xff, (44100 >> 24) & 0xff, // SampleRate
        2, 0, 0, 0,  // ByteRate (SampleRate * NumChannels * BitsPerSample/8)
        2, 0,        // BlockAlign (NumChannels * BitsPerSample/8)
        16, 0,       // BitsPerSample
        'd', 'a', 't', 'a',
        0, 0, 0, 0   // Placeholder for data chunk size
    };

    // Write header
    if (fwrite(header, sizeof(char), 44, file) < 44) {
        fprintf(stderr, "Failed to write WAV header: %s\n", strerror(errno));
        return -1;
    }
    
    // Update the header for actual sizes
    fseek(file, 4, SEEK_SET);
    uint32_t file_size = 36 + data_size;
    fwrite(&file_size, sizeof(uint32_t), 1, file);
    
    fseek(file, 40, SEEK_SET);
    fwrite(&data_size, sizeof(uint32_t), 1, file);
    
    fseek(file, 0, SEEK_END); // Reset back to end for writing data
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);

    FILE *in_file = fopen(input_file, "rb");
    if (!in_file) {
        perror("Could not open input file");
        return EXIT_FAILURE;
    }

    uint32_t data_size;
    if (read_wav_header(in_file, &data_size) != 0) {
        fclose(in_file);
        return EXIT_FAILURE;
    }

    size_t num_samples = data_size / sizeof(int16_t);
    int16_t *buffer = malloc(num_samples * sizeof(int16_t));
    if (!buffer) {
        perror("Could not allocate memory for samples");
        fclose(in_file);
        return EXIT_FAILURE;
    }

    if (fread(buffer, sizeof(int16_t), num_samples, in_file) != num_samples) {
        fprintf(stderr, "Failed to read audio data: %s\n", strerror(errno));
        free(buffer);
        fclose(in_file);
        return EXIT_FAILURE;
    }
    
    fclose(in_file);

    // Apply gain to the samples
    apply_gain(buffer, num_samples, gain);

    FILE *out_file = fopen(output_file, "wb");
    if (!out_file) {
        perror("Could not open output file");
        free(buffer);
        return EXIT_FAILURE;
    }

    if (write_wav_header(out_file, data_size) != 0) {
        fclose(out_file);
        free(buffer);
        return EXIT_FAILURE;
    }

    fwrite(buffer, sizeof(int16_t), num_samples, out_file);
    free(buffer);
    fclose(out_file);

    printf("Processed audio written to %s with gain %.2f\n", output_file, gain);
    return EXIT_SUCCESS;
}