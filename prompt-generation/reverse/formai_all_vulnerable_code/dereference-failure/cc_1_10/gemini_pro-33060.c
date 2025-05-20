//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_PLANETS 100
#define MAX_RESOURCES 10

typedef struct {
    int x;
    int y;
    int z;
} vector3;

typedef struct {
    char *name;
    vector3 pos;
    int resources[MAX_RESOURCES];
    int population;
} planet;

planet planets[MAX_PLANETS];

void generate_planets(int n) {
    for (int i = 0; i < n; i++) {
        planets[i].name = malloc(10);
        sprintf(planets[i].name, "Planet %d", i);
        planets[i].pos.x = rand() % 1000;
        planets[i].pos.y = rand() % 1000;
        planets[i].pos.z = rand() % 1000;
        for (int j = 0; j < MAX_RESOURCES; j++) {
            planets[i].resources[j] = rand() % 100;
        }
        planets[i].population = rand() % 10000;
    }
}

void print_planets(int n) {
    for (int i = 0; i < n; i++) {
        printf("Planet %s:\n", planets[i].name);
        printf("  Position: (%d, %d, %d)\n", planets[i].pos.x, planets[i].pos.y, planets[i].pos.z);
        printf("  Resources: ");
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("%d ", planets[i].resources[j]);
        }
        printf("\n");
        printf("  Population: %d\n", planets[i].population);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    generate_planets(5);
    print_planets(5);
    return 0;
}