//Gemma-7B DATASET v1.0 Category: Physics simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a decentralized array of 10 particles
    int nParticles = 10;
    double *x = (double *)malloc(nParticles * sizeof(double));
    double *y = (double *)malloc(nParticles * sizeof(double));
    double *z = (double *)malloc(nParticles * sizeof(double));

    // Initialize the positions of the particles
    for (int i = 0; i < nParticles; i++)
    {
        x[i] = rand() % 10;
        y[i] = rand() % 10;
        z[i] = rand() % 10;
    }

    // Simulate the motion of the particles
    for (int t = 0; t < 1000; t++)
    {
        // Calculate the forces acting on each particle
        for (int i = 0; i < nParticles; i++)
        {
            double fX = 0.0;
            double fY = 0.0;
            double fZ = 0.0;

            // Calculate the forces due to the other particles
            for (int j = 0; j < nParticles; j++)
            {
                if (i != j)
                {
                    double dx = x[i] - x[j];
                    double dy = y[i] - y[j];
                    double dz = z[i] - z[j];

                    double distance = sqrt(dx * dx + dy * dy + dz * dz);

                    double force = 1.0 / distance;

                    fX += force * dx;
                    fY += force * dy;
                    fZ += force * dz;
                }
            }

            // Update the particle's position
            x[i] += fX * t / 1000.0;
            y[i] += fY * t / 1000.0;
            z[i] += fZ * t / 1000.0;
        }
    }

    // Print the final positions of the particles
    for (int i = 0; i < nParticles; i++)
    {
        printf("Particle %d: (%f, %f, %f)\n", i, x[i], y[i], z[i]);
    }

    // Free the memory allocated for the particles
    free(x);
    free(y);
    free(z);

    return 0;
}