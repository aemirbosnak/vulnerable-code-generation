//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BLOCK_SIZE 1024
#define NUM_BLOCKS 10
#define MAX_AMPLITUDE 0.5

typedef struct {
    int index;
    double amplitude;
    int done;
} tone_t;

void generate_tone(tone_t *tone) {
    tone->index = 0;
    tone->amplitude = 0.0;
    tone->done = 0;
}

double get_next_sample(tone_t *tone) {
    double sample;
    if (tone->index >= BLOCK_SIZE) {
        tone->done = 1;
        return 0.0;
    }
    sample = tone->amplitude * sin(2 * M_PI * ((double) tone->index / BLOCK_SIZE));
    tone->index++;
    return sample;
}

int main() {
    FILE *input_file, *output_file;
    short input_buffer[BLOCK_SIZE];
    double output_buffer[BLOCK_SIZE];
    tone_t tone1, tone2;

    input_file = fopen("input.wav", "rb");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    output_file = fopen("output.wav", "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    generate_tone(&tone1);
    generate_tone(&tone2);

    for (int i = 0; i < NUM_BLOCKS; i++) {
        fread(input_buffer, sizeof(short), BLOCK_SIZE, input_file);
        for (int j = 0; j < BLOCK_SIZE; j++) {
            double sample1 = get_next_sample(&tone1);
            double sample2 = get_next_sample(&tone2);
            if (sample1 == 0.0 && sample2 == 0.0) {
                generate_tone(&tone1);
                generate_tone(&tone2);
            }
            output_buffer[j] = input_buffer[j] + sample1 + sample2;
            if (output_buffer[j] > MAX_AMPLITUDE) {
                output_buffer[j] = MAX_AMPLITUDE;
            } else if (output_buffer[j] < -MAX_AMPLITUDE) {
                output_buffer[j] = -MAX_AMPLITUDE;
            }
        }
        fwrite(output_buffer, sizeof(double), BLOCK_SIZE, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}