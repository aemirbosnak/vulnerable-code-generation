//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Sector {
    Point *stars;
    int num_stars;
} Sector;

typedef struct Galaxy {
    Sector *sectors;
    int num_sectors;
} Galaxy;

Galaxy *generate_galaxy(int num_sectors, int num_stars_per_sector) {
    srand(time(NULL));

    // Allocate memory for the galaxy.
    Galaxy *galaxy = malloc(sizeof(Galaxy));

    // Allocate memory for the sectors.
    galaxy->sectors = malloc(num_sectors * sizeof(Sector));

    // Allocate memory for the stars in each sector.
    for (int i = 0; i < num_sectors; i++) {
        galaxy->sectors[i].stars = malloc(num_stars_per_sector * sizeof(Point));
    }

    // Generate the stars in each sector.
    for (int i = 0; i < num_sectors; i++) {
        for (int j = 0; j < num_stars_per_sector; j++) {
            galaxy->sectors[i].stars[j].x = rand() % 1000;
            galaxy->sectors[i].stars[j].y = rand() % 1000;
        }
    }

    // Return the galaxy.
    return galaxy;
}

void print_galaxy(Galaxy *galaxy) {
    for (int i = 0; i < galaxy->num_sectors; i++) {
        printf("Sector %d:\n", i);
        for (int j = 0; j < galaxy->sectors[i].num_stars; j++) {
            printf("  Star %d: (%d, %d)\n", j, galaxy->sectors[i].stars[j].x, galaxy->sectors[i].stars[j].y);
        }
    }
}

void free_galaxy(Galaxy *galaxy) {
    for (int i = 0; i < galaxy->num_sectors; i++) {
        free(galaxy->sectors[i].stars);
    }
    free(galaxy->sectors);
    free(galaxy);
}

int main() {
    // Generate a galaxy.
    Galaxy *galaxy = generate_galaxy(10, 100);

    // Print the galaxy.
    print_galaxy(galaxy);

    // Free the galaxy.
    free_galaxy(galaxy);

    return 0;
}