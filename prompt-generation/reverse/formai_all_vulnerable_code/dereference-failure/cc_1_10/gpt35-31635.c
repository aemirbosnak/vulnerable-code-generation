//FormAI DATASET v1.0 Category: Audio processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define MAX_VOLUME 32767

int main(void) {
    FILE *input_file, *output_file;
    char input_filename[256], output_filename[256];
    short int buffer[BUFFER_SIZE];
    float volume_factor;
    int samples_read, i;

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", input_filename);

    // Open input file in read mode
    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: Unable to open input file!\n");
        return EXIT_FAILURE;
    }

    // Get output file name from user
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    // Open output file in write mode
    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error: Unable to open output file!\n");
        return EXIT_FAILURE;
    }

    // Get volume factor from user
    printf("Enter volume factor (0.0 to 1.0): ");
    scanf("%f", &volume_factor);

    // Read samples from input file, process and write to output file
    while ((samples_read = fread(buffer, sizeof(short int), BUFFER_SIZE, input_file)) > 0) {
        for (i = 0; i < samples_read; i++) {
            // Scale sample by volume_factor and clip if necessary
            buffer[i] = (short int)(volume_factor * buffer[i]);
            if (buffer[i] > MAX_VOLUME) {
                buffer[i] = MAX_VOLUME;
            } else if (buffer[i] < -MAX_VOLUME) {
                buffer[i] = -MAX_VOLUME;
            }
        }
        fwrite(buffer, sizeof(short int), samples_read, output_file);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}