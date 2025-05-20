//FormAI DATASET v1.0 Category: Audio processing ; Style: excited
//Audio processing program to enhance voice quality
//Get ready to hear the difference!

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <math.h>

//Define variables
int sample_rate = 44100;
int cutoff_freq = 3000;
int num_samples = 44100;
int max_amp = 32767;
float *input_buf;
float *output_buf;

//Filter function to enhance voice
void filter(float* input, float* output) {
    float R = 1.0 - (3.0 * cutoff_freq) / sample_rate;
    float b0 = 1.0 - R;
    float a1 = -R;
    float prev_input = 0;
    float prev_output = 0;
    for (int i = 0; i < num_samples; i++) {
        output[i] = b0 * input[i] - a1 * prev_input + R * prev_output;
        prev_input = input[i];
        prev_output = output[i];
    }
}

//Signal handler for interrupt
void interrupt_handler(int sig) {
    printf("\nInterrupted by user. Exiting...\n");
    free(input_buf);
    free(output_buf);
    exit(0);
}

//Main function
int main() {

    //Allocate memory for input and output buffers
    input_buf = (float*) malloc(num_samples * sizeof(float));
    output_buf = (float*) malloc(num_samples * sizeof(float));

    //Generate sine wave as input signal
    for (int i = 0; i < num_samples; i++) {
        input_buf[i] = sin(2.0 * M_PI * cutoff_freq * i / sample_rate);
    }

    //Filter the input signal to enhance voice quality
    filter(input_buf, output_buf);

    //Scale output signal and convert to integer values
    for (int i = 0; i < num_samples; i++) {
        output_buf[i] *= max_amp;
    }

    //Register signal handler for interrupt
    signal(SIGINT, interrupt_handler);

    //Play output signal using system command
    FILE *pipe = popen("play -t raw -r 44100 -e signed -b 16 -c 1 -", "w");
    fwrite(output_buf, sizeof(short), num_samples, pipe);
    pclose(pipe);
    
    //Free memory and exit program
    free(input_buf);
    free(output_buf);
    return 0;
}