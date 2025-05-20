//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define NUM_ASTEROIDS 10
#define NUM_THRUSTERS 2

// Struct for representing a point in 3D space
typedef struct Point3D {
    double x;
    double y;
    double z;
} Point3D;

// Struct for representing an asteroid
typedef struct Asteroid {
    int id;
    Point3D position;
    Point3D velocity;
} Asteroid;

// Struct for representing a spaceship
typedef struct Spaceship {
    int id;
    Point3D position;
    Point3D velocity;
    int health;
    int fuel;
    int num_asteroids_destroyed;
    pthread_t threads[NUM_THRUSTERS];
} Spaceship;

// Function to initialize an asteroid with random values
void init_asteroid(Asteroid* asteroid, int id) {
    asteroid->id = id;
    asteroid->position.x = (double) rand() / RAND_MAX * 100.0;
    asteroid->position.y = (double) rand() / RAND_MAX * 100.0;
    asteroid->position.z = (double) rand() / RAND_MAX * 100.0;
    asteroid->velocity.x = (double) rand() / RAND_MAX * 5.0;
    asteroid->velocity.y = (double) rand() / RAND_MAX * 5.0;
    asteroid->velocity.z = (double) rand() / RAND_MAX * 5.0;
}

// Function to initialize a spaceship with random values
void init_spaceship(Spaceship* spaceship, int id) {
    spaceship->id = id;
    spaceship->position.x = (double) rand() / RAND_MAX * 100.0;
    spaceship->position.y = (double) rand() / RAND_MAX * 100.0;
    spaceship->position.z = (double) rand() / RAND_MAX * 100.0;
    spaceship->velocity.x = 0.0;
    spaceship->velocity.y = 0.0;
    spaceship->velocity.z = 0.0;
    spaceship->health = 100;
    spaceship->fuel = 100;
    spaceship->num_asteroids_destroyed = 0;
}

// Function to simulate the movement of an asteroid
void* move_asteroid(void* obj) {
    Asteroid* asteroid = (Asteroid*) obj;
    while (true) {
        asteroid->position.x += asteroid->velocity.x;
        asteroid->position.y += asteroid->velocity.y;
        asteroid->position.z += asteroid->velocity.z;
        if (asteroid->position.x < 0.0 || asteroid->position.x > 100.0) {
            asteroid->velocity.x *= -1.0;
        }
        if (asteroid->position.y < 0.0 || asteroid->position.y > 100.0) {
            asteroid->velocity.y *= -1.0;
        }
        if (asteroid->position.z < 0.0 || asteroid->position.z > 100.0) {
            asteroid->velocity.z *= -1.0;
        }
        sleep(1);
    }
    return NULL;
}

// Function to simulate the thrust of a spaceship in a certain direction
void* thrust_spaceship(void* obj) {
    Spaceship* spaceship = (Spaceship*) obj;
    while (true) {
        char c = getchar();
        switch (c) {
            case 'w':
                spaceship->velocity.z += 1.0;
                spaceship->fuel--;
                break;
            case 's':
                spaceship->velocity.z -= 1.0;
                spaceship->fuel--;
                break;
            case 'a':
                spaceship->velocity.x -= 1.0;
                spaceship->fuel--;
                break;
            case 'd':
                spaceship->velocity.x += 1.0;
                spaceship->fuel--;
                break;
            case 'q':
                spaceship->velocity.y += 1.0;
                spaceship->fuel--;
                break;
            case 'e':
                spaceship->velocity.y -= 1.0;
                spaceship->fuel--;
                break;
            default:
                break;
        }
        if (spaceship->fuel == 0) {
            printf("Spaceship %d out of fuel!\n", spaceship->id);
            pthread_exit(NULL);
        }
        sleep(1);
    }
    return NULL;
}

int main() {
    Asteroid* asteroids[NUM_ASTEROIDS];
    Spaceship* spaceship = (Spaceship*) malloc(sizeof(Spaceship));
    init_spaceship(spaceship, 1);

    // Create and initialize asteroids
    for (int i = 0; i < NUM_ASTEROIDS; i++) {
        asteroids[i] = (Asteroid*) malloc(sizeof(Asteroid));
        init_asteroid(asteroids[i], i+1);
    }

    // Create threads for each asteroid to simulate movement
    pthread_t asteroid_threads[NUM_ASTEROIDS];
    for (int i = 0; i < NUM_ASTEROIDS; i++) {
        pthread_create(&asteroid_threads[i], NULL, move_asteroid, (void*) asteroids[i]);
    }

    // Create threads for each thruster on the spaceship
    for (int i = 0; i < NUM_THRUSTERS; i++) {
        pthread_create(&spaceship->threads[i], NULL, thrust_spaceship, (void*) spaceship);
    }

    // Main game loop
    while (true) {
        // Check for collision between spaceship and asteroids
        for (int i = 0; i < NUM_ASTEROIDS; i++) {
            double dx = spaceship->position.x - asteroids[i]->position.x;
            double dy = spaceship->position.y - asteroids[i]->position.y;
            double dz = spaceship->position.z - asteroids[i]->position.z;
            double dist = sqrt(dx*dx + dy*dy + dz*dz);
            if (dist < 10.0) {
                printf("Spaceship %d collided with asteroid %d!\n", spaceship->id, asteroids[i]->id);
                spaceship->health -= 10;
                if (spaceship->health == 0) {
                    printf("Game over!\n");
                    exit(0);
                }
                asteroids[i]->velocity.x += spaceship->velocity.x / 2.0;
                asteroids[i]->velocity.y += spaceship->velocity.y / 2.0;
                asteroids[i]->velocity.z += spaceship->velocity.z / 2.0;
                spaceship->velocity.x = -(spaceship->velocity.x / 2.0);
                spaceship->velocity.y = -(spaceship->velocity.y / 2.0);
                spaceship->velocity.z = -(spaceship->velocity.z / 2.0);
            }
        }
        // Check for destroyed asteroids
        for (int i = 0; i < NUM_ASTEROIDS; i++) {
            if (asteroids[i]->id != -1) {
                double dx = spaceship->position.x - asteroids[i]->position.x;
                double dy = spaceship->position.y - asteroids[i]->position.y;
                double dz = spaceship->position.z - asteroids[i]->position.z;
                double dist = sqrt(dx*dx + dy*dy + dz*dz);
                if (dist < 5.0) {
                    printf("Spaceship %d destroyed asteroid %d!\n", spaceship->id, asteroids[i]->id);
                    spaceship->num_asteroids_destroyed++;
                    asteroids[i]->id = -1;
                }
            }
        }
        // Print status of spaceship
        printf("Spaceship %d position: (%0.2f, %0.2f, %0.2f)\n", spaceship->id, spaceship->position.x, spaceship->position.y, spaceship->position.z);
        printf("Spaceship %d velocity: (%0.2f, %0.2f, %0.2f)\n", spaceship->id, spaceship->velocity.x, spaceship->velocity.y, spaceship->velocity.z);
        printf("Spaceship %d health: %d\n", spaceship->id, spaceship->health);
        printf("Spaceship %d fuel: %d\n", spaceship->id, spaceship->fuel);
        printf("Spaceship %d asteroids destroyed: %d\n", spaceship->id, spaceship->num_asteroids_destroyed);
        printf("Press w, a, s, d, q, or e to thrust the spaceship.\n");
        sleep(1);
    }

    // Clean up memory and exit program
    for (int i = 0; i < NUM_ASTEROIDS; i++) {
        free(asteroids[i]);
    }
    free(spaceship);
    return 0;
}