//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Space System
typedef struct {
    int x, y, z;
} Coords;

typedef struct {
    char *name;
    Coords coords;
    int mass;
    int radius;
} Planet;

typedef struct {
    char *name;
    Coords coords;
    Planet *planets;
    int num_planets;
} StarSystem;

// Universe
typedef struct {
    StarSystem *systems;
    int num_systems;
} Universe;

// Gameplay
typedef struct {
    Coords coords;
    int fuel;
    int speed;
} Spaceship;

// Function Declarations
Universe *create_universe(int num_systems);
void destroy_universe(Universe *universe);
void print_universe(Universe *universe);
void move_spaceship(Spaceship *spaceship, Universe *universe);

// Main Function
int main() {
    // Set random seed
    srand(time(NULL));

    // Create universe
    Universe *universe = create_universe(10);

    // Print universe
    print_universe(universe);

    // Create spaceship
    Spaceship spaceship = {
        .coords = {0, 0, 0},
        .fuel = 100,
        .speed = 10
    };

    // Move spaceship
    move_spaceship(&spaceship, universe);

    // Destroy universe
    destroy_universe(universe);

    return 0;
}

// Universe Functions
Universe *create_universe(int num_systems) {
    Universe *universe = malloc(sizeof(Universe));
    universe->systems = malloc(sizeof(StarSystem) * num_systems);
    universe->num_systems = num_systems;

    for (int i = 0; i < num_systems; i++) {
        StarSystem *system = &universe->systems[i];
        system->name = malloc(10);
        sprintf(system->name, "System %d", i);
        system->coords.x = rand() % 100;
        system->coords.y = rand() % 100;
        system->coords.z = rand() % 100;
        system->num_planets = rand() % 10;
        system->planets = malloc(sizeof(Planet) * system->num_planets);

        for (int j = 0; j < system->num_planets; j++) {
            Planet *planet = &system->planets[j];
            planet->name = malloc(10);
            sprintf(planet->name, "Planet %d", j);
            planet->coords.x = rand() % 100;
            planet->coords.y = rand() % 100;
            planet->coords.z = rand() % 100;
            planet->mass = rand() % 100;
            planet->radius = rand() % 10;
        }
    }

    return universe;
}

void destroy_universe(Universe *universe) {
    for (int i = 0; i < universe->num_systems; i++) {
        StarSystem *system = &universe->systems[i];
        free(system->name);
        for (int j = 0; j < system->num_planets; j++) {
            Planet *planet = &system->planets[j];
            free(planet->name);
        }
        free(system->planets);
    }
    free(universe->systems);
    free(universe);
}

void print_universe(Universe *universe) {
    for (int i = 0; i < universe->num_systems; i++) {
        StarSystem *system = &universe->systems[i];
        printf("System %s:\n", system->name);
        printf("  Coords: (%d, %d, %d)\n", system->coords.x, system->coords.y, system->coords.z);
        for (int j = 0; j < system->num_planets; j++) {
            Planet *planet = &system->planets[j];
            printf("  Planet %s:\n", planet->name);
            printf("    Coords: (%d, %d, %d)\n", planet->coords.x, planet->coords.y, planet->coords.z);
            printf("    Mass: %d\n", planet->mass);
            printf("    Radius: %d\n", planet->radius);
        }
    }
}

// Gameplay Functions
void move_spaceship(Spaceship *spaceship, Universe *universe) {
    // Get current system
    StarSystem *current_system = NULL;
    for (int i = 0; i < universe->num_systems; i++) {
        StarSystem *system = &universe->systems[i];
        if (system->coords.x == spaceship->coords.x && system->coords.y == spaceship->coords.y && system->coords.z == spaceship->coords.z) {
            current_system = system;
            break;
        }
    }

    // Get destination system
    StarSystem *destination_system = NULL;
    printf("Enter destination system name: ");
    char destination_name[10];
    scanf("%s", destination_name);
    for (int i = 0; i < universe->num_systems; i++) {
        StarSystem *system = &universe->systems[i];
        if (strcmp(system->name, destination_name) == 0) {
            destination_system = system;
            break;
        }
    }

    // Calculate distance
    int distance = abs(current_system->coords.x - destination_system->coords.x) + abs(current_system->coords.y - destination_system->coords.y) + abs(current_system->coords.z - destination_system->coords.z);

    // Check if there is enough fuel
    if (distance > spaceship->fuel) {
        printf("Not enough fuel to reach destination.\n");
        return;
    }

    // Update spaceship coords
    spaceship->coords.x = destination_system->coords.x;
    spaceship->coords.y = destination_system->coords.y;
    spaceship->coords.z = destination_system->coords.z;

    // Update spaceship fuel
    spaceship->fuel -= distance;
}