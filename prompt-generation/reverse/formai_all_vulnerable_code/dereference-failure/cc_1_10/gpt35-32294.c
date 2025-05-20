//FormAI DATASET v1.0 Category: Fractal Generation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    double real;
    double imag;
} Complex;

void* calculate_fractal(void* arg);

int main() {
    // Initialize variables for image size and fractal iteration limit
    const int WIDTH = 500;
    const int HEIGHT = 500;
    const int MAX_ITERATIONS = 256;
    
    // Initialize variables for plotting the fractal
    Complex c;
    Complex z;
    int x, y, i;
    int pixel_color;
    
    // Initialize array to hold the pixel data for the image
    int pixels[WIDTH][HEIGHT];
    
    // Initialize thread and attribute variables
    pthread_t threads[WIDTH*HEIGHT];
    pthread_attr_t attr;
    void* status;
    
    // Initialize attributes to be set to detachable
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    // Create threads to calculate pixels of the fractal
    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH; x++) {
            // Set the complex number c based on the pixel coordinates
            c.real = (double)x / WIDTH * 3.5 - 2.5;
            c.imag = (double)y / HEIGHT * 2 - 1;
            
            // Create a thread to calculate the pixel color
            int* thread_args = (int*)malloc(sizeof(int)*3);
            thread_args[0] = x;
            thread_args[1] = y;
            thread_args[2] = MAX_ITERATIONS;
            pthread_create(&threads[y*WIDTH + x], &attr, calculate_fractal, (void*)thread_args);
        }
    }
    
    // Wait for all threads to finish and set the pixel colors in the array
    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH; x++) {
            pthread_join(threads[y*WIDTH + x], &status);
            pixels[x][y] = (int)status;
            free(status);
        }
    }
    
    // Output the pixel data to a file
    FILE* fp = fopen("fractal.pgm", "w");
    fprintf(fp, "P2\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_ITERATIONS);
    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH; x++) {
            fprintf(fp, "%d ", pixels[x][y]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    
    // Clean up threads and attributes
    pthread_attr_destroy(&attr);
    pthread_exit(NULL);
}

void* calculate_fractal(void* arg) {
    // Unpack thread arguments
    int* args = (int*)arg;
    int x = args[0];
    int y = args[1];
    int max_iterations = args[2];
    free(args);
    
    // Set the complex number c based on the pixel coordinates
    Complex c;
    c.real = (double)x / 500 * 3.5 - 2.5;
    c.imag = (double)y / 500 * 2 - 1;
    
    // Initialize z to (0,0) and calculate the fractal iteration count
    Complex z;
    z.real = 0;
    z.imag = 0;
    int iterations = 0;
    while(z.real*z.real + z.imag*z.imag < 4 && iterations < max_iterations) {
        double temp = z.real*z.real - z.imag*z.imag + c.real;
        z.imag = 2*z.real*z.imag + c.imag;
        z.real = temp;
        iterations++;
    }
    
    // Return the pixel color as the number of iterations required to escape
    int* result = (int*)malloc(sizeof(int));
    *result = iterations;
    pthread_exit((void*)result);
}