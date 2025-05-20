//FormAI DATASET v1.0 Category: Digital signal processing ; Style: detailed
#include <stdio.h>

// function to compute the moving average of a signal
void moving_average(float *signal, int signal_length, int window_size, float *result)
{
    int i, j;
    float sum;
    
    // loop through all signal samples
    for (i = 0; i < signal_length; i++)
    {
        sum = 0;
        
        // compute an average over the window
        for (j = 0; j < window_size; j++)
        {
            if (i - j < 0)
            {
                sum += signal[0];
            }
            else
            {
                sum += signal[i - j];
            }
        }
        
        // save the result
        result[i] = sum / (float)window_size;
    }
}

int main()
{
    // define a signal to process
    float signal[] = {0.5, 2.4, -1.2, 0.8, -0.3, 1.1, -0.7, 0.5, -2.1, 1.2};
    int signal_length = 10;
    
    // define a moving average window
    int window_size = 3;
    
    // allocate memory for result
    float *result = (float*) malloc(signal_length * sizeof(float));
    
    // compute the moving average of the signal
    moving_average(signal, signal_length, window_size, result);
    
    // print the original signal and the filtered signal
    printf("Original signal:\n");
    for (int i = 0; i < signal_length; i++)
    {
        printf("%f, ", signal[i]);
    }
    printf("\nFiltered signal:\n");
    for (int i = 0; i < signal_length; i++)
    {
        printf("%f, ", result[i]);
    }
    printf("\n");
    
    // free memory
    free(result);
    
    return 0;
}