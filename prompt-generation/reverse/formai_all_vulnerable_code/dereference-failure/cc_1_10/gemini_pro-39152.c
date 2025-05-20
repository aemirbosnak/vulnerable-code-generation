//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct star {
    char name[32];
    int x, y, z;
    float size;
    char type;
};

struct star_system {
    char name[32];
    int num_stars;
    struct star *stars;
};

struct galaxy {
    char name[32];
    int num_systems;
    struct star_system *systems;
};

struct universe {
    int num_galaxies;
    struct galaxy *galaxies;
};

struct ship {
    char name[32];
    int x, y, z;
    float speed;
    int fuel;
    int weapons;
    int shields;
    int crew;
};

struct player {
    char name[32];
    struct ship *ship;
    int credits;
    int reputation;
};

void create_universe(struct universe *universe) {
    srand(time(NULL));
    universe->num_galaxies = rand() % 100 + 1;
    universe->galaxies = malloc(sizeof(struct galaxy) * universe->num_galaxies);
    for (int i = 0; i < universe->num_galaxies; i++) {
        sprintf(universe->galaxies[i].name, "Galaxy %d", i + 1);
        universe->galaxies[i].num_systems = rand() % 100 + 1;
        universe->galaxies[i].systems = malloc(sizeof(struct star_system) * universe->galaxies[i].num_systems);
        for (int j = 0; j < universe->galaxies[i].num_systems; j++) {
            sprintf(universe->galaxies[i].systems[j].name, "System %d", j + 1);
            universe->galaxies[i].systems[j].num_stars = rand() % 10 + 1;
            universe->galaxies[i].systems[j].stars = malloc(sizeof(struct star) * universe->galaxies[i].systems[j].num_stars);
            for (int k = 0; k < universe->galaxies[i].systems[j].num_stars; k++) {
                sprintf(universe->galaxies[i].systems[j].stars[k].name, "Star %d", k + 1);
                universe->galaxies[i].systems[j].stars[k].x = rand() % 1000 - 500;
                universe->galaxies[i].systems[j].stars[k].y = rand() % 1000 - 500;
                universe->galaxies[i].systems[j].stars[k].z = rand() % 1000 - 500;
                universe->galaxies[i].systems[j].stars[k].size = rand() % 10 + 1;
                universe->galaxies[i].systems[j].stars[k].type = 'A' + rand() % 26;
            }
        }
    }
}

void create_player(struct player *player) {
    printf("What is your name, captain?\n");
    scanf("%s", player->name);
    printf("Welcome aboard, Captain %s. Let's get you a ship.\n", player->name);
    player->ship = malloc(sizeof(struct ship));
    printf("What would you like to name your ship?\n");
    scanf("%s", player->ship->name);
    player->ship->x = 0;
    player->ship->y = 0;
    player->ship->z = 0;
    player->ship->speed = 100;
    player->ship->fuel = 1000;
    player->ship->weapons = 10;
    player->ship->shields = 100;
    player->ship->crew = 100;
    player->credits = 1000;
    player->reputation = 0;
}

void print_universe(struct universe *universe) {
    for (int i = 0; i < universe->num_galaxies; i++) {
        printf("Galaxy %d:\n", i + 1);
        for (int j = 0; j < universe->galaxies[i].num_systems; j++) {
            printf("\tSystem %d:\n", j + 1);
            for (int k = 0; k < universe->galaxies[i].systems[j].num_stars; k++) {
                printf("\t\tStar %d: %s (%.1f solar masses, type %c)\n", k + 1, universe->galaxies[i].systems[j].stars[k].name, universe->galaxies[i].systems[j].stars[k].size, universe->galaxies[i].systems[j].stars[k].type);
            }
        }
    }
}

void print_player(struct player *player) {
    printf("Captain %s:\n", player->name);
    printf("\tShip: %s\n", player->ship->name);
    printf("\tCredits: %d\n", player->credits);
    printf("\tReputation: %d\n", player->reputation);
}

int main() {
    struct universe universe;
    struct player player;
    create_universe(&universe);
    create_player(&player);
    print_universe(&universe);
    print_player(&player);
    return 0;
}