//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_INVASIONS 1000

struct city {
    char name[50];
    int population;
    int defense;
    int invaded;
};

struct invasion {
    int year;
    int city_index;
};

void generate_cities(struct city* cities, int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        sprintf(cities[i].name, "City %d", i + 1);
        cities[i].population = rand() % 1000000;
        cities[i].defense = rand() % 100;
        cities[i].invaded = 0;
    }
}

void generate_invasions(struct invasion* invasions, int num_invasions, int num_cities) {
    for (int i = 0; i < num_invasions; i++) {
        int city_index = rand() % num_cities;
        invasions[i].city_index = city_index;
        int year = rand() % 100;
        while (year < 2021) {
            year += rand() % 10;
        }
        invasions[i].year = year;
    }
}

int main() {
    srand(time(NULL));

    int num_cities, num_invasions;
    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);
    struct city cities[num_cities];
    generate_cities(cities, num_cities);

    printf("Enter the number of invasions: ");
    scanf("%d", &num_invasions);
    struct invasion invasions[num_invasions];
    generate_invasions(invasions, num_invasions, num_cities);

    int total_invasions = 0;
    for (int i = 0; i < num_invasions; i++) {
        struct city* city = &cities[invasions[i].city_index];
        if (city->invaded == 0) {
            total_invasions++;
            city->invaded = 1;
        }
    }

    double probability = (double) total_invasions / num_invasions * 100;
    printf("The probability of an alien invasion is %.2f%%\n", probability);

    return 0;
}