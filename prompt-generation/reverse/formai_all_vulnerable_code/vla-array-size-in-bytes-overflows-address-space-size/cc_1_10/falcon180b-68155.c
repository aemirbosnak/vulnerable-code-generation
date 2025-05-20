//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_DISTANCE 1000
#define MAX_POPULATION 1000000
#define MIN_POPULATION 1000
#define MAX_TECHNOLOGY 1000
#define MIN_TECHNOLOGY 1
#define MAX_YEARS 1000
#define MIN_YEARS 1

struct alien {
    int distance;
    int population;
    int technology;
};

void generate_alien(struct alien *a) {
    a->distance = rand() % MAX_DISTANCE + 1;
    a->population = rand() % (MAX_POPULATION - MIN_POPULATION + 1) + MIN_POPULATION;
    a->technology = rand() % (MAX_TECHNOLOGY - MIN_TECHNOLOGY + 1) + MIN_TECHNOLOGY;
}

int main() {
    srand(time(NULL));

    int num_aliens;
    printf("Enter the number of aliens: ");
    scanf("%d", &num_aliens);

    struct alien aliens[num_aliens];

    for (int i = 0; i < num_aliens; i++) {
        generate_alien(&aliens[i]);
    }

    int num_years;
    printf("Enter the number of years to simulate: ");
    scanf("%d", &num_years);

    int invasions = 0;

    for (int year = 1; year <= num_years; year++) {
        for (int j = 0; j < num_aliens; j++) {
            if (aliens[j].distance == year) {
                invasions++;
            }
        }
    }

    double probability = (double) invasions / num_years;

    printf("The probability of an alien invasion within %d years is %.2f%%\n", num_years, probability * 100);

    return 0;
}