//FormAI DATASET v1.0 Category: Audio processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 256

int main()
{
    FILE *file_in, *file_out;

    file_in = fopen("audio_in.wav", "rb");
    file_out = fopen("audio_out.wav", "wb");

    if (!file_in || !file_out) {
        perror("Error opening files");
        return 1;
    }

    // Read WAV file header
    char buffer[BUFFER_SIZE];
    fread(buffer, BUFFER_SIZE, 1, file_in);
    fwrite(buffer, BUFFER_SIZE, 1, file_out);

    // Process audio samples
    int sample_rate = buffer[24] |
                      buffer[25] << 8 |
                      buffer[26] << 16 |
                      buffer[27] << 24;

    int samples_per_channel = (buffer[40] |
                               buffer[41] << 8 |
                               buffer[42] << 16 |
                               buffer[43] << 24) /
                              (buffer[34] |
                               buffer[35] << 8);

    srand(time(NULL));
    int i, j;
    char sample_buffer[2];
    for (i = 0; i < samples_per_channel; i++) {
        for (j = 0; j < 2; j++)
            fread(&sample_buffer[j], 1, 1, file_in);

        // Apply random noise
        sample_buffer[0] += rand() % 21 - 10;
        sample_buffer[1] += rand() % 21 - 10;

        fwrite(&sample_buffer[0], 1, 1, file_out);
        fwrite(&sample_buffer[1], 1, 1, file_out);
    }

    fclose(file_in);
    fclose(file_out);

    printf("Audio processing complete.\n");

    return 0;
}