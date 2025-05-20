//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_X 0
#define MAX_X 100
#define MIN_Y 0
#define MAX_Y 100

struct planet {
    char *name;
    int x;
    int y;
};

struct spaceship {
    char *name;
    int x;
    int y;
    int fuel;
};

void generate_planets(struct planet *planets, int num_planets) {
    srand(time(NULL));

    for (int i = 0; i < num_planets; i++) {
        planets[i].name = malloc(16);
        sprintf(planets[i].name, "Planet %d", i + 1);

        planets[i].x = rand() % (MAX_X - MIN_X + 1) + MIN_X;
        planets[i].y = rand() % (MAX_Y - MIN_Y + 1) + MIN_Y;
    }
}

void generate_spaceship(struct spaceship *spaceship) {
    spaceship->name = "Starship Enterprise";
    spaceship->x = 0;
    spaceship->y = 0;
    spaceship->fuel = 1000;
}

void print_planets(struct planet *planets, int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %s: (%d, %d)\n", planets[i].name, planets[i].x, planets[i].y);
    }
}

void print_spaceship(struct spaceship *spaceship) {
    printf("Spaceship %s: (%d, %d), Fuel: %d\n", spaceship->name, spaceship->x, spaceship->y, spaceship->fuel);
}

int main() {
    const int NUM_PLANETS = 10;

    struct planet planets[NUM_PLANETS];
    generate_planets(planets, NUM_PLANETS);

    struct spaceship spaceship;
    generate_spaceship(&spaceship);

    print_planets(planets, NUM_PLANETS);
    print_spaceship(&spaceship);

    return 0;
}