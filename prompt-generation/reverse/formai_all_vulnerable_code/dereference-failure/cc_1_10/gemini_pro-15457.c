//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    int fuel;
} Ship;

typedef struct {
    int width, height;
    Point *stars;
    int num_stars;
} Galaxy;

Galaxy *create_galaxy(int width, int height, int num_stars) {
    Galaxy *galaxy = malloc(sizeof(Galaxy));
    galaxy->width = width;
    galaxy->height = height;
    galaxy->num_stars = num_stars;
    galaxy->stars = malloc(sizeof(Point) * num_stars);
    for (int i = 0; i < num_stars; i++) {
        galaxy->stars[i].x = rand() % width;
        galaxy->stars[i].y = rand() % height;
    }
    return galaxy;
}

void free_galaxy(Galaxy *galaxy) {
    free(galaxy->stars);
    free(galaxy);
}

Ship *create_ship(int x, int y, int fuel) {
    Ship *ship = malloc(sizeof(Ship));
    ship->pos.x = x;
    ship->pos.y = y;
    ship->fuel = fuel;
    return ship;
}

void free_ship(Ship *ship) {
    free(ship);
}

void move_ship(Ship *ship, int dx, int dy) {
    ship->pos.x += dx;
    ship->pos.y += dy;
    ship->fuel--;
}

int main() {
    srand(time(NULL));

    Galaxy *galaxy = create_galaxy(100, 100, 100);
    Ship *ship = create_ship(50, 50, 100);

    while (ship->fuel > 0) {
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        move_ship(ship, dx, dy);

        int closest_star_idx = -1;
        int closest_star_dist = 1000000;
        for (int i = 0; i < galaxy->num_stars; i++) {
            int dx = ship->pos.x - galaxy->stars[i].x;
            int dy = ship->pos.y - galaxy->stars[i].y;
            int dist = dx * dx + dy * dy;
            if (dist < closest_star_dist) {
                closest_star_dist = dist;
                closest_star_idx = i;
            }
        }

        if (closest_star_dist < 100) {
            printf("You have reached a star!\n");
            ship->fuel += 100;
        }
    }

    printf("You have run out of fuel!\n");

    free_ship(ship);
    free_galaxy(galaxy);

    return 0;
}