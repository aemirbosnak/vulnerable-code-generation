//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    short int input_buffer[BUFFER_SIZE], output_buffer[BUFFER_SIZE];
    int i, j, k, n;
    float gain, pan;

    printf("Enter input filename: ");
    scanf("%s", input_filename);

    printf("Enter output filename: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "rb");
    output_file = fopen(output_filename, "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    rewind(input_file);

    int num_samples = file_size / (2 * sizeof(short int));

    for (i = 0; i < num_samples; i++) {
        fread(input_buffer, sizeof(short int), BUFFER_SIZE, input_file);

        for (j = 0; j < BUFFER_SIZE; j++) {
            gain = 1.0f;
            pan = 0.0f;

            if (i % 2 == 0) {
                gain = 0.5f;
                pan = 0.5f;
            } else {
                gain = 1.5f;
                pan = -0.5f;
            }

            output_buffer[j] = (int) (gain * input_buffer[j] * 32767.0f);

            if (j % 2 == 0) {
                output_buffer[j] = (int) (output_buffer[j] * cos(M_PI * pan) + output_buffer[j + 1] * sin(M_PI * pan));
            } else {
                output_buffer[j] = (int) (output_buffer[j] * cos(M_PI * pan) - output_buffer[j - 1] * sin(M_PI * pan));
            }
        }

        fwrite(output_buffer, sizeof(short int), BUFFER_SIZE, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Processing completed successfully.\n");

    return 0;
}