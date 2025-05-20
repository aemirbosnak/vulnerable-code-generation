//Falcon2-11B DATASET v1.0 Category: Audio processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void process_audio(char *input_file, char *output_file, int sampling_rate, int filter_cutoff) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");

    if (!input ||!output) {
        fprintf(stderr, "Error opening files\n");
        exit(1);
    }

    int num_samples = 0;
    int num_bytes = 0;

    while (fread(&num_bytes, sizeof(int), 1, input) == 1) {
        num_samples += num_bytes / 4; // each sample is 4 bytes
    }

    float *input_data = malloc(sizeof(float) * num_samples);
    float *output_data = malloc(sizeof(float) * num_samples);

    if (!input_data ||!output_data) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }

    for (int i = 0; i < num_samples; i++) {
        fread(&input_data[i], sizeof(float), 1, input);
    }

    for (int i = 0; i < num_samples; i++) {
        float filtered_sample = input_data[i] * (1.0 - cos(M_PI * filter_cutoff * i / sampling_rate));
        output_data[i] = filtered_sample;
    }

    fwrite(&num_samples, sizeof(int), 1, output);

    for (int i = 0; i < num_samples; i++) {
        fwrite(&output_data[i], sizeof(float), 1, output);
    }

    fclose(input);
    fclose(output);

    free(input_data);
    free(output_data);
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <sampling_rate> <filter_cutoff>\n", argv[0]);
        exit(1);
    }

    process_audio(argv[1], argv[2], atoi(argv[3]), atof(argv[4]));

    return 0;
}