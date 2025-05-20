//FormAI DATASET v1.0 Category: Digital signal processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

double * create_signal(int length);
void apply_window_hanning(double *signal, int length);
void apply_echo(double *signal, int length, int delay, double decay);
void normalize_signal(double *signal, int length);

int main()
{
    // Create a signal with length of 512 samples
    double *signal = create_signal(512);
    
    // Apply Hanning window to the signal
    apply_window_hanning(signal, 512);
    
    // Apply an echo effect with delay of 64 samples and decay of 0.5
    apply_echo(signal, 512, 64, 0.5);
    
    // Normalize the signal to have maximum amplitude of 1
    normalize_signal(signal, 512);
    
    // Print the resulting signal
    for (int i=0; i<512; i++)
    {
        printf("%f\n", signal[i]);
    }
    
    // Free the memory allocated for the signal
    free(signal);
    
    return 0;
}

double * create_signal(int length)
{
    double *signal = (double *) malloc(length * sizeof(double));
    
    for (int i=0; i<length; i++)
    {
        signal[i] = sin(2*PI*i/length);
    }
    
    return signal;
}

void apply_window_hanning(double *signal, int length)
{
    for (int i=0; i<length; i++)
    {
        signal[i] *= 0.5 * (1 - cos(2*PI*i/length-1));
    }
}

void apply_echo(double *signal, int length, int delay, double decay)
{
    double *echo = (double *) malloc(length * sizeof(double));
    
    for (int i=0; i<length; i++)
    {
        if (i-delay < 0)
        {
            echo[i] = signal[i];
        }
        else
        {
            echo[i] = signal[i] + decay * signal[i-delay];
        }
    }
    
    for (int i=0; i<length; i++)
    {
        signal[i] += echo[i];
    }
    
    free(echo);
}

void normalize_signal(double *signal, int length)
{
    double max_amplitude = 0;
    
    for (int i=0; i<length; i++)
    {
        if (fabs(signal[i]) > max_amplitude)
        {
            max_amplitude = fabs(signal[i]);
        }
    }
    
    for (int i=0; i<length; i++)
    {
        signal[i] /= max_amplitude;
    }
}