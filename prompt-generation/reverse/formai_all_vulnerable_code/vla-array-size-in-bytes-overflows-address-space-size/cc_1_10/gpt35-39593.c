//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAV_CONST 0.0000000000667

int main()
{
    srand(time(NULL)); // seed the random number generator
    
    int num_planets;
    printf("Enter the number of planets in the solar system: ");
    scanf("%d", &num_planets);
    
    double masses[num_planets];
    double positions[num_planets][3]; // 3D positions
    double velocities[num_planets][3]; // 3D velocities
    
    for(int i=0; i<num_planets; i++)
    {
        printf("\nEnter the mass of planet %d in kg: ", i+1);
        scanf("%lf", &masses[i]);
        
        // randomly generate initial position and velocity
        positions[i][0] = 50000 * (rand()/(double)RAND_MAX - 0.5);
        positions[i][1] = 50000 * (rand()/(double)RAND_MAX - 0.5);
        positions[i][2] = 50000 * (rand()/(double)RAND_MAX - 0.5);
        velocities[i][0] = 1000 * (rand()/(double)RAND_MAX - 0.5);
        velocities[i][1] = 1000 * (rand()/(double)RAND_MAX - 0.5);
        velocities[i][2] = 1000 * (rand()/(double)RAND_MAX - 0.5);
    }
    
    double time_step = 0.01; // in seconds
    double time = 0;
    double force_vec[3]; // 3D force vector
    double force_mag;
    
    while(1)
    {
        // update positions using current velocities
        for(int i=0; i<num_planets; i++)
        {
            positions[i][0] += velocities[i][0] * time_step;
            positions[i][1] += velocities[i][1] * time_step;
            positions[i][2] += velocities[i][2] * time_step;
        }
        
        // calculate forces on each planet
        for(int i=0; i<num_planets; i++)
        {
            force_vec[0] = force_vec[1] = force_vec[2] = 0;
            
            for(int j=0; j<num_planets; j++)
            {
                if(i == j) continue; // skip self
                double distance_vec[3] = {positions[j][0]-positions[i][0], positions[j][1]-positions[i][1], positions[j][2]-positions[i][2]};
                double distance = sqrt(distance_vec[0]*distance_vec[0] + distance_vec[1]*distance_vec[1] + distance_vec[2]*distance_vec[2]);
                force_mag = GRAV_CONST * masses[i] * masses[j] / (distance * distance);
                force_vec[0] += force_mag * distance_vec[0] / distance;
                force_vec[1] += force_mag * distance_vec[1] / distance;
                force_vec[2] += force_mag * distance_vec[2] / distance;
            }
            
            // update velocities using forces on this planet
            velocities[i][0] += force_vec[0] / masses[i] * time_step;
            velocities[i][1] += force_vec[1] / masses[i] * time_step;
            velocities[i][2] += force_vec[2] / masses[i] * time_step;
        }
        
        printf("\nTime: %f seconds\n", time);
        for(int i=0; i<num_planets; i++)
        {
            printf("\nPlanet %d:", i+1);
            printf("\n  Mass: %lf kg", masses[i]);
            printf("\n  Position: (%lf, %lf, %lf) km", positions[i][0]/1000, positions[i][1]/1000, positions[i][2]/1000);
            printf("\n  Velocity: (%lf, %lf, %lf) m/s", velocities[i][0], velocities[i][1], velocities[i][2]);
        }
        
        time += time_step;
    }
    
    return 0;
}