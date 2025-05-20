//FormAI DATASET v1.0 Category: Audio processing ; Style: Romeo and Juliet
// A Romeo and Juliet style C Audio Processing Example Program

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILENAME "romeo_juliet.wav"
#define FRAME_SIZE 512

int main() {
    FILE *file;
    char c;

    // Open the audio file for reading and writing
    file = fopen(FILENAME, "rb+");
    if (!file) {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    // Grab the first byte of the file
    fseek(file, 0, SEEK_SET);
    c = fgetc(file);

    // Check to see if this file is Romeo or Juliet
    if (islower(c)) {
        printf("This is Romeo's file.\n");
    } else if (isupper(c)) {
        printf("This is Juliet's file.\n");
    } else {
        printf("Unknown file type.\n");
        exit(EXIT_FAILURE);
    }

    // Read the audio data
    fseek(file, 0, SEEK_SET);
    short int sample[FRAME_SIZE];
    while (fread(sample, sizeof(short int), FRAME_SIZE, file)) {
        // Process the audio data
        for (int i = 0; i < FRAME_SIZE; i++) {
            if (c == 'R') {
                // Romeo's processing
                sample[i] *= 2;
                if (sample[i] > 32767) {
                    sample[i] = 32767;
                }
            } else {
                // Juliet's processing
                sample[i] /= 2;
            }
        }

        // Write the processed audio data back to the file
        fseek(file, -FRAME_SIZE * sizeof(short int), SEEK_CUR);
        fwrite(sample, sizeof(short int), FRAME_SIZE, file);
    }

    // Close the file
    fclose(file);

    // Catch up with the other's processing
    if (c == 'R') {
        printf("Romeo has finished processing.\n");
        printf("Waiting for Juliet to finish...\n");
        while (fgetc(file) != 'J') {
            // Do nothing, just wait for Juliet to finish processing
        }
        printf("Juliet has finished processing.\n");
    } else {
        printf("Juliet has finished processing.\n");
        printf("Sending file back to Romeo...\n");
        fseek(file, 0, SEEK_SET);
        fputc('J', file);
    }

    return 0;
}