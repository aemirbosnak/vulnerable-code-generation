//FormAI DATASET v1.0 Category: Physics simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G 6.67e-11     // Gravitational constant

// Function to calculate net force on an object
void calculate_forces(double* pos, double* mass, double* force, int num_objects)
{
    for(int i=0; i<num_objects; i++)
    {
        for(int j=i+1; j<num_objects; j++)
        {
            double dx = pos[j*3] - pos[i*3];
            double dy = pos[j*3+1] - pos[i*3+1];
            double dz = pos[j*3+2] - pos[i*3+2];
            double r = sqrt(dx*dx + dy*dy + dz*dz);
            double f = G*mass[i]*mass[j]/(r*r);

            force[i*3] += f*dx/r;
            force[i*3+1] += f*dy/r;
            force[i*3+2] += f*dz/r;

            force[j*3] -= f*dx/r;
            force[j*3+1] -= f*dy/r;
            force[j*3+2] -= f*dz/r;
        }
    }
}

// Function to update object positions and velocities
void update_objects(double* pos, double* vel, double* force, double* mass, double dt, int num_objects)
{
    for(int i=0; i<num_objects; i++)
    {
        double ax = force[i*3]/mass[i];
        double ay = force[i*3+1]/mass[i];
        double az = force[i*3+2]/mass[i];

        vel[i*3] += ax*dt;
        vel[i*3+1] += ay*dt;
        vel[i*3+2] += az*dt;

        pos[i*3] += vel[i*3]*dt + 0.5*ax*dt*dt;
        pos[i*3+1] += vel[i*3+1]*dt + 0.5*ay*dt*dt;
        pos[i*3+2] += vel[i*3+2]*dt + 0.5*az*dt*dt;
    }
}

// Main program
int main()
{
    srand(time(NULL)); // Initialize random seed

    int num_objects = 5;
    double* pos = (double*)malloc(3*num_objects*sizeof(double));
    double* vel = (double*)malloc(3*num_objects*sizeof(double));
    double* mass = (double*)malloc(num_objects*sizeof(double));
    double* force = (double*)calloc(3*num_objects, sizeof(double));
    double dt = 1.0; // Timestep

    // Initialize positions, velocities, masses of objects
    for(int i=0; i<num_objects; i++)
    {
        pos[i*3] = (double)rand()/RAND_MAX*10.0 - 5.0;
        pos[i*3+1] = (double)rand()/RAND_MAX*10.0 - 5.0;
        pos[i*3+2] = (double)rand()/RAND_MAX*10.0 - 5.0;

        vel[i*3] = (double)rand()/RAND_MAX*2.0 - 1.0;
        vel[i*3+1] = (double)rand()/RAND_MAX*2.0 - 1.0;
        vel[i*3+2] = (double)rand()/RAND_MAX*2.0 - 1.0;

        mass[i] = (double)rand()/RAND_MAX*100.0 + 1.0;
    }

    // Run simulation for 1000 timesteps
    for(int i=0; i<1000; i++)
    {
        calculate_forces(pos, mass, force, num_objects);
        update_objects(pos, vel, force, mass, dt, num_objects);

        // Print current positions of objects
        printf("Timestep %d:\n", i+1);
        for(int j=0; j<num_objects; j++)
        {
            printf("Object %d: (%f, %f, %f)\n", j+1, pos[j*3], pos[j*3+1], pos[j*3+2]);
        }
    }

    free(pos);
    free(vel);
    free(mass);
    free(force);

    return 0;
}