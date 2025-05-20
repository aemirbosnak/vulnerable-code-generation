//FormAI DATASET v1.0 Category: Physics simulation ; Style: detailed
#include<stdio.h> 
#include<stdlib.h> 

// Constant variables to represent acceleration due to gravity and time step
const double g = 9.81;
const double dt = 0.01;

// Function to calculate new velocity and position of a particle after time t given initial velocity and position
void simulate(double *x, double *v, double t)
{
    double a = -g;
    *v += a * t;
    *x += *v * t + 0.5 * a * t * t;
}

int main()
{
    // Mass of the particle
    const double m = 1;
    
    // Initial velocity and position of the particle
    double v0 = 10;
    double x0 = 0;
    
    // Array to store the position of the particle over time
    double* pos = (double*) malloc(1000 * sizeof(double));
    pos[0] = x0;
    
    // Array to store the time elapsed
    double* time = (double*) malloc(1000 * sizeof(double));
    time[0] = 0;
    
    // Simulate the motion of the particle
    for(int i=1; i<1000; i++)
    {
        double t = i * dt;
        simulate(&pos[i-1], &v0, dt);
        pos[i] = pos[i-1];
        time[i] = t;
    }
    
    // Print the trajectory of the particle
    printf("Time (s)\t Position (m)\n");
    for(int i=0; i<1000; i++)
    {
        printf("%.2f\t\t %.2f\n", time[i], pos[i]);
    }
    
    // Free dynamically allocated memory
    free(pos);
    free(time);
    
    return 0;
}