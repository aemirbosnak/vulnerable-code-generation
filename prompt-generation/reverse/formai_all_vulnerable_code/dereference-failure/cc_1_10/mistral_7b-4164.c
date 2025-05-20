//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI M_PI

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point pos;
    double size, speed, angle;
} Ship;

typedef struct {
    Point pos;
    double size, speed, angle, health;
} Alien;

Ship player_ship;
Alien* aliens;
int num_aliens;

void calculate_probability() {
    double distance, probability;

    for (int i = 0; i < num_aliens; i++) {
        distance = sqrt(pow(player_ship.pos.x - aliens[i].pos.x, 2) + pow(player_ship.pos.y - aliens[i].pos.y, 2));
        probability = 1 / (1 + pow(M_E, -(distance / player_ship.speed)));
        printf("Probability of Alien %d invasion: %.12f\n", i + 1, probability);
    }
}

void init_aliens() {
    int i;
    double x, y;

    num_aliens = 5;
    aliens = malloc(num_aliens * sizeof(Alien));

    for (i = 0; i < num_aliens; i++) {
        x = (double) rand() / RAND_MAX * (100 - 50) + 50;
        y = (double) rand() / RAND_MAX * (100 - 50) + 50;
        aliens[i] = (Alien){{x, y}, 10.0, 1.5, 0.0, 100.0};
    }
}

void update_aliens() {
    double dx, dy;
    int i;

    for (i = 0; i < num_aliens; i++) {
        dx = cos(aliens[i].angle) * aliens[i].speed;
        dy = sin(aliens[i].angle) * aliens[i].speed;

        aliens[i].pos.x += dx;
        aliens[i].pos.y += dy;

        if (aliens[i].pos.x < 0 || aliens[i].pos.x > 100 || aliens[i].pos.y < 0 || aliens[i].pos.y > 100) {
            aliens[i].health = 0;
        }
    }
}

void print_aliens() {
    int i;

    for (i = 0; i < num_aliens; i++) {
        printf("Alien %d: (%lf, %lf) Health: %lf\n", i + 1, aliens[i].pos.x, aliens[i].pos.y, aliens[i].health);
    }
}

int main() {
    srand(time(NULL));

    player_ship = (Ship){{50, 50}, 20.0, 0.0};

    init_aliens();

    int choice;

    while (1) {
        printf("\n1. Calculate Invasion Probability\n2. Print Alien Positions\n3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculate_probability();
                break;
            case 2:
                print_aliens();
                break;
            case 3:
                free(aliens);
                return 0;
            default:
                printf("Invalid choice!\n");
        }

        update_aliens();
    }

    free(aliens);
    return 0;
}