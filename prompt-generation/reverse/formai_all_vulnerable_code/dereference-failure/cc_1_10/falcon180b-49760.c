//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define MAX_AMPLITUDE 32767

int main() {

    FILE *input_file;
    FILE *output_file;
    short int input_buffer[BUFFER_SIZE];
    short int output_buffer[BUFFER_SIZE];

    input_file = fopen("input.wav", "rb");
    output_file = fopen("output.wav", "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    fseek(input_file, 44, SEEK_SET); // Skip header

    while (fread(input_buffer, sizeof(short int), BUFFER_SIZE, input_file)!= 0) {

        for (int i = 0; i < BUFFER_SIZE; i++) {

            output_buffer[i] = input_buffer[i] * 2; // Amplify by 2x

            if (output_buffer[i] > MAX_AMPLITUDE) {
                output_buffer[i] = MAX_AMPLITUDE;
            } else if (output_buffer[i] < -MAX_AMPLITUDE) {
                output_buffer[i] = -MAX_AMPLITUDE;
            }

        }

        fwrite(output_buffer, sizeof(short int), BUFFER_SIZE, output_file);

    }

    fclose(input_file);
    fclose(output_file);

    printf("Done.\n");

    return 0;

}