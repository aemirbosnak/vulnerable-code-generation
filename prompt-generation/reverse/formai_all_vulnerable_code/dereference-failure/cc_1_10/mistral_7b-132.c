//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: random
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define FILENAME_LENGTH 10
#define WINDOW_SIZE 5
#define NUM_SAMPLES 128

typedef int16_t sample_t;

void moving_average(sample_t* buffer, int32_t window_size, int32_t sample_index, sample_t* output) {
    int32_t i;
    int32_t sum = 0;

    for (i = 0; i < window_size; i++) {
        sum += buffer[sample_index - i];
    }

    *output = sum / window_size;
}

int main() {
    FILE* input_file;
    FILE* output_file;
    sample_t input_data[NUM_SAMPLES];
    sample_t output_data[NUM_SAMPLES];
    int32_t i;

    // Open input file
    strcpy(input_file, "input.bin");
    input_file = fopen(input_file, "rb");
    if (input_file == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    // Read input data
    fread(input_data, sizeof(sample_t), NUM_SAMPLES, input_file);
    fclose(input_file);

    // Perform moving average filter
    for (i = 0; i < NUM_SAMPLES; i++) {
        moving_average(input_data, WINDOW_SIZE, i, &output_data[i]);
    }

    // Open output file
    strcpy(output_file, "output.bin");
    output_file = fopen(output_file, "wb");
    if (output_file == NULL) {
        printf("Failed to open output file.\n");
        return 1;
    }

    // Write output data
    fwrite(output_data, sizeof(sample_t), NUM_SAMPLES, output_file);
    fclose(output_file);

    printf("Filtering completed successfully.\n");
    return 0;
}