//FormAI DATASET v1.0 Category: Audio processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 512 // Buffer size for reading audio file

int main() {
    FILE *input_file, *output_file;
    short buffer[BUFFER_SIZE];
    double amplitude = 1.0; // Amplitude of audio signal
    double frequency = 440.0; // Frequency of audio signal
    double duration = 5.0; // Duration of audio signal in seconds
    double theta = 0.0, delta_theta = 2.0 * M_PI * frequency / 44100.0; // Theta and delta theta for generating sine wave
    int samples = duration * 44100; // Total number of audio samples to be generated
    int i, j;
    
    // Open input file in read mode
    input_file = fopen("input.wav", "rb");
    if(input_file == NULL) {
        printf("Error opening input file\n");
        return -1;
    }
    
    // Open output file in write mode
    output_file = fopen("output.wav", "wb");
    if(output_file == NULL) {
        printf("Error opening output file\n");
        return -1;
    }
    
    // Read audio data from input file and write to output file
    while(fread(buffer, sizeof(short), BUFFER_SIZE, input_file) == BUFFER_SIZE) {
        // Audio processing code starts here
        
        // Amplify audio signal
        for(i = 0; i < BUFFER_SIZE; i++) {
            buffer[i] *= amplitude;
        }
        
        // Generate sine wave and mix with audio signal
        for(i = 0; i < BUFFER_SIZE; i++) {
            buffer[i] += amplitude * sin(theta);
            theta += delta_theta;
            if(theta >= 2.0 * M_PI) {
                theta -= 2.0 * M_PI;
            }
        }
        
        // Audio processing code ends here
        
        fwrite(buffer, sizeof(short), BUFFER_SIZE, output_file);
    }
    
    // Close files
    fclose(input_file);
    fclose(output_file);
    
    return 0;
}