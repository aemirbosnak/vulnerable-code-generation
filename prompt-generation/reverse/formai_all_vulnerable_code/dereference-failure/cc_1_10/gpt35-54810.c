//FormAI DATASET v1.0 Category: Physics simulation ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num_particles = 10;
    float time_step = 0.01;

    float* particle_x_positions = (float*)malloc(num_particles * sizeof(float));
    float* particle_velocities = (float*)malloc(num_particles * sizeof(float));
    float* particle_accelerations = (float*)malloc(num_particles * sizeof(float));

    srand(time(NULL)); // seed the random number generator with time

    //initialize particle positions randomly between 0 and 1
    for(int i=0; i<num_particles; i++)
    {
        particle_x_positions[i] = (float)rand()/(float)(RAND_MAX/1);
    }

    //initialize particle velocities randomly between -1 and 1
    for(int i=0; i<num_particles; i++)
    {
        particle_velocities[i] = (float)rand()/(float)(RAND_MAX/2) - 1;
    }

    //initialize particle accelerations to 0
    for(int i=0; i<num_particles; i++)
    {
        particle_accelerations[i] = 0;
    }

    printf("Initial particle positions:\n");
    for(int i=0; i<num_particles; i++)
    {
        printf("%f ", particle_x_positions[i]);
    }
    printf("\n");

    //simulate particle motion
    for(float time=0; time<1; time+=time_step)
    {
        //calculate particle accelerations
        for(int i=0; i<num_particles; i++)
        {
            particle_accelerations[i] = 0.5 * sin(2 * 3.14159 * particle_x_positions[i]);
        }

        //calculate particle velocities
        for(int i=0; i<num_particles; i++)
        {
            particle_velocities[i] += particle_accelerations[i] * time_step;
        }

        //calculate particle positions
        for(int i=0; i<num_particles; i++)
        {
            particle_x_positions[i] += particle_velocities[i] * time_step;
        }
    }

    printf("Final particle positions:\n");
    for(int i=0; i<num_particles; i++)
    {
        printf("%f ", particle_x_positions[i]);
    }
    printf("\n");

    free(particle_x_positions);
    free(particle_velocities);
    free(particle_accelerations);

    return 0;
}