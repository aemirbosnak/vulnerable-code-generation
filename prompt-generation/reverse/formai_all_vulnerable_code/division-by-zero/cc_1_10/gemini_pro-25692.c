//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STARS 1000
#define MAX_PLANETS 100

struct star {
    char name[32];
    int x, y, z;
    int size;
    int color;
};

struct planet {
    char name[32];
    int star_id;
    int x, y, z;
    int size;
    int color;
};

struct universe {
    struct star stars[MAX_STARS];
    struct planet planets[MAX_PLANETS];
    int num_stars;
    int num_planets;
};

void generate_universe(struct universe *u) {
    srand(time(NULL));
    u->num_stars = rand() % MAX_STARS;
    u->num_planets = rand() % MAX_PLANETS;
    for (int i = 0; i < u->num_stars; i++) {
        sprintf(u->stars[i].name, "Star %d", i);
        u->stars[i].x = rand() % 1000;
        u->stars[i].y = rand() % 1000;
        u->stars[i].z = rand() % 1000;
        u->stars[i].size = rand() % 10;
        u->stars[i].color = rand() % 10;
    }
    for (int i = 0; i < u->num_planets; i++) {
        sprintf(u->planets[i].name, "Planet %d", i);
        u->planets[i].star_id = rand() % u->num_stars;
        u->planets[i].x = rand() % 1000;
        u->planets[i].y = rand() % 1000;
        u->planets[i].z = rand() % 1000;
        u->planets[i].size = rand() % 10;
        u->planets[i].color = rand() % 10;
    }
}

void print_universe(struct universe *u) {
    for (int i = 0; i < u->num_stars; i++) {
        printf("Star %d: (%d, %d, %d), size %d, color %d\n",
               i, u->stars[i].x, u->stars[i].y, u->stars[i].z,
               u->stars[i].size, u->stars[i].color);
    }
    for (int i = 0; i < u->num_planets; i++) {
        printf("Planet %d: (%d, %d, %d), size %d, color %d\n",
               i, u->planets[i].x, u->planets[i].y, u->planets[i].z,
               u->planets[i].size, u->planets[i].color);
    }
}

int main() {
    struct universe u;
    generate_universe(&u);
    print_universe(&u);
    return 0;
}