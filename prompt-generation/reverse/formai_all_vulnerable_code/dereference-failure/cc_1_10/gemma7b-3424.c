//Gemma-7B DATASET v1.0 Category: Physics simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PARTICLES 100

typedef struct Particle
{
    int x, y, z;
    float mass;
    struct Particle* next;
} Particle;

void initializeParticles(Particle* head)
{
    head = malloc(MAX_PARTICLES * sizeof(Particle));
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        head[i].x = rand() % 1000;
        head[i].y = rand() % 1000;
        head[i].z = rand() % 1000;
        head[i].mass = rand() % 10 + 1;
    }
}

void updateParticles(Particle* head)
{
    for (Particle* particle = head; particle; particle = particle->next)
    {
        particle->x += rand() % 5 - 2;
        particle->y += rand() % 5 - 2;
        particle->z += rand() % 5 - 2;
    }
}

void printParticles(Particle* head)
{
    for (Particle* particle = head; particle; particle = particle->next)
    {
        printf("Particle: x = %d, y = %d, z = %d, mass = %.2f\n", particle->x, particle->y, particle->z, particle->mass);
    }
}

int main()
{
    Particle* head = NULL;
    initializeParticles(head);
    updateParticles(head);
    printParticles(head);

    return 0;
}