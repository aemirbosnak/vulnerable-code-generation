//FormAI DATASET v1.0 Category: Audio processing ; Style: portable
/*
 * This program demonstrates audio processing using C. The program reads the audio signal from a file,
 * applies a filter and writes the processed signal to another file. The filter used is a simple low-pass 
 * filter with a cutoff frequency of 3000 Hz.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 1024

int main(int argc, const char * argv[]) {
    
    char *input_filename, *output_filename;
    FILE *input_file, *output_file;
    short int buffer[BUFFER_SIZE];
    double omega_cutoff = 2 * M_PI * 3000 / 44100; // cutoff frequency is 3000 Hz for a sampling rate of 44100 Hz
    double a0, a1, a2, b1, b2, w0, cos_w0, sin_w0, alpha, a_coef[3], b_coef[3];
    double x_prev[2] = {0, 0}, y_prev[2] = {0, 0}; //previous input and output samples of the filter
    int i, n_samples;
    
    //check if input and output file names are given as command line arguments
    if(argc != 3) {
        printf("Usage: %s input_filename output_filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    input_filename = (char*) argv[1];
    output_filename = (char*) argv[2];
    
    //open input file for reading
    input_file = fopen(input_filename, "rb");
    
    if(input_file == NULL) {
        printf("Error: Unable to open %s\n", input_filename);
        exit(EXIT_FAILURE);
    }
    
    //open output file for writing
    output_file = fopen(output_filename, "wb");
    
    if(output_file == NULL) {
        printf("Error: Unable to open %s\n", output_filename);
        exit(EXIT_FAILURE);
    }
    
    //calculate filter coefficient values
    w0 = omega_cutoff;
    cos_w0 = cos(w0);
    sin_w0 = sin(w0);
    alpha = sin_w0 / (2 * 0.707); // 0.707 is the cutoff frequency gain
    
    b_coef[0] = (1 - cos_w0) / 2;
    b_coef[1] = 1 - cos_w0;
    b_coef[2] = (1 - cos_w0) / 2;
    a_coef[0] = 1 + alpha;
    a_coef[1] = (-2 * cos_w0) / a_coef[0];
    a_coef[2] = (1 - alpha) / a_coef[0];
    
    //read audio samples from input file, filter and write to output file
    while(!feof(input_file)) {
        n_samples = fread(buffer, sizeof(short int), BUFFER_SIZE, input_file);
        
        for(i = 0; i < n_samples; i++) {
            //apply filter to input sample
            y_prev[0] = y_prev[1];
            y_prev[1] = (b_coef[0] / a_coef[0]) * buffer[i] + (b_coef[1] / a_coef[0]) * x_prev[0] + (b_coef[2] / a_coef[0]) * x_prev[1] 
                        - (a_coef[1] / a_coef[0]) * y_prev[0] - (a_coef[2] / a_coef[0]) * y_prev[1];
            x_prev[1] = x_prev[0];
            x_prev[0] = buffer[i];
            
            //write filtered sample to output file
            fwrite(&y_prev[1], sizeof(short int), 1, output_file);
        }
    }
    
    //close input and output files
    fclose(input_file);
    fclose(output_file);
    
    printf("Audio processing completed successfully!\n");
    return 0;
}