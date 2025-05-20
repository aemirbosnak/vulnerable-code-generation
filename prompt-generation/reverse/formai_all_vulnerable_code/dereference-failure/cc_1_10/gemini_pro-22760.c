//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Star system structure
typedef struct {
    int num_stars;
    float* masses;
    float* positions[3];
    float* velocities[3];
} StarSystem;

// Create a new star system with the given number of stars
StarSystem* create_star_system(int num_stars) {
    StarSystem* system = malloc(sizeof(StarSystem));
    system->num_stars = num_stars;

    // Allocate memory for the star masses, positions, and velocities
    system->masses = malloc(sizeof(float) * num_stars);
    for (int i = 0; i < 3; i++) {
        system->positions[i] = malloc(sizeof(float) * num_stars);
        system->velocities[i] = malloc(sizeof(float) * num_stars);
    }

    // Initialize the star masses, positions, and velocities
    srand(time(NULL));
    for (int i = 0; i < num_stars; i++) {
        system->masses[i] = (float)rand() / RAND_MAX;
        for (int j = 0; j < 3; j++) {
            system->positions[j][i] = (float)rand() / RAND_MAX;
            system->velocities[j][i] = (float)rand() / RAND_MAX;
        }
    }

    return system;
}

// Free the memory allocated for the star system
void free_star_system(StarSystem* system) {
    free(system->masses);
    for (int i = 0; i < 3; i++) {
        free(system->positions[i]);
        free(system->velocities[i]);
    }
    free(system);
}

// Update the star system for the given time step
void update_star_system(StarSystem* system, float dt) {
    // Calculate the gravitational forces between the stars
    for (int i = 0; i < system->num_stars; i++) {
        for (int j = i + 1; j < system->num_stars; j++) {
            // Calculate the distance between the stars
            float dx = system->positions[0][i] - system->positions[0][j];
            float dy = system->positions[1][i] - system->positions[1][j];
            float dz = system->positions[2][i] - system->positions[2][j];
            float distance = sqrtf(dx * dx + dy * dy + dz * dz);

            // Calculate the gravitational force between the stars
            float force = system->masses[i] * system->masses[j] / (distance * distance);

            // Apply the force to the stars
            system->velocities[0][i] += force * dx / distance * dt;
            system->velocities[1][i] += force * dy / distance * dt;
            system->velocities[2][i] += force * dz / distance * dt;
            system->velocities[0][j] -= force * dx / distance * dt;
            system->velocities[1][j] -= force * dy / distance * dt;
            system->velocities[2][j] -= force * dz / distance * dt;
        }
    }

    // Update the star positions
    for (int i = 0; i < system->num_stars; i++) {
        for (int j = 0; j < 3; j++) {
            system->positions[j][i] += system->velocities[j][i] * dt;
        }
    }
}

// Print the star system to the console
void print_star_system(StarSystem* system) {
    printf("Star system:\n");
    for (int i = 0; i < system->num_stars; i++) {
        printf("Star %d:\n", i);
        printf("  Mass: %f\n", system->masses[i]);
        printf("  Position: (%f, %f, %f)\n", system->positions[0][i], system->positions[1][i], system->positions[2][i]);
        printf("  Velocity: (%f, %f, %f)\n\n", system->velocities[0][i], system->velocities[1][i], system->velocities[2][i]);
    }
}

int main() {
    // Create a new star system with 10 stars
    StarSystem* system = create_star_system(10);

    // Update the star system for 1000 time steps
    for (int i = 0; i < 1000; i++) {
        update_star_system(system, 0.01f);
    }

    // Print the star system to the console
    print_star_system(system);

    // Free the memory allocated for the star system
    free_star_system(system);

    return 0;
}