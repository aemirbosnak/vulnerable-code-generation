//FormAI DATASET v1.0 Category: Fractal Generation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds);
}

int main(void)
{
    int width = 500; // set the width of the frame
    int height = 500; // set the height of the frame
    int max_iteration = 100; // set the maximum number of iteration
    double range_min_real = -2.0; // set the minimum real value
    double range_max_real = 1.0; // set the maximum real value
    double range_min_imag = -1.5; // set the minimum imaginary value
    double range_max_imag = 1.5; // set the maximum imaginary value
    
    double real_increment = (range_max_real - range_min_real) / width; // calculate the increment of real value
    double imag_increment = (range_max_imag - range_min_imag) / height; // calculate the increment of imaginary value
    
    int **fractal; // initialize a two-dimensional array to store the fractal
    
    fractal = calloc(width, sizeof(int *));
    
    for(int i = 0; i < width; i++)
    {
        fractal[i] = calloc(height, sizeof(int));
    }
    
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            double c_real = range_min_real + i * real_increment; // calculate the real value of c
            double c_imag = range_min_imag + j * imag_increment; // calculate the imaginary value of c
            
            double z_real = 0.0; // initialize the real value of z
            double z_imag = 0.0; // initialize the imaginary value of z
            
            int iteration = 0; // initialize the iteration
            
            while (iteration < max_iteration && z_real * z_real + z_imag * z_imag < 4.0)
            {
                double z_real_temp = z_real * z_real - z_imag * z_imag + c_real; // calculate the real value of z_temp
                double z_imag_temp = 2 * z_real * z_imag + c_imag; // calculate the imaginary value of z_temp
                
                z_real = z_real_temp; // update the real value of z
                z_imag = z_imag_temp; // update the imaginary value of z
                
                iteration++; // increment the iteration
            }
            
            fractal[i][j] = iteration; // store the iteration in the array
        }
    }
    
    printf("Generated a %d x %d fractal image.\n", width, height);
    
    for(int j = 0; j < height; j++)
    {
        for(int i = 0; i < width; i++)
        {
            if(fractal[i][j] == max_iteration)
            {
                printf("*"); // print the character if the point is in the set
            }
            else
            {
                printf(" "); // print the space if the point is not in the set
            }
        }
        
        printf("\n");
        
        delay(2); // delay for visual effect
    }
    
    return 0;
}