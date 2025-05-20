//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_ALIENS 1000
#define MAX_NUM_ATTACKS 1000
#define MAX_NUM_CITIES 1000
#define MAX_NUM_YEARS 100
#define MAX_NUM_DATA (MAX_NUM_YEARS * MAX_NUM_CITIES)

typedef struct {
    int num_aliens;
    int num_attacks;
} AlienAttack;

typedef struct {
    int num_attacks;
    int num_cities;
} CityAttack;

typedef struct {
    int num_attacks;
    int num_cities;
    int num_years;
} YearAttack;

typedef struct {
    AlienAttack *alien_attacks;
    CityAttack *city_attacks;
    YearAttack *year_attacks;
} AttackData;

void generate_random_data(AttackData *data) {
    srand(time(NULL));
    for (int i = 0; i < MAX_NUM_ALIENS; i++) {
        data->alien_attacks[i].num_attacks = rand() % MAX_NUM_ATTACKS;
    }
    for (int i = 0; i < MAX_NUM_CITIES; i++) {
        data->city_attacks[i].num_attacks = rand() % MAX_NUM_ATTACKS;
        data->city_attacks[i].num_cities = rand() % MAX_NUM_CITIES;
    }
    for (int i = 0; i < MAX_NUM_YEARS; i++) {
        data->year_attacks[i].num_attacks = rand() % MAX_NUM_ATTACKS;
        data->year_attacks[i].num_cities = rand() % MAX_NUM_CITIES;
        data->year_attacks[i].num_years = i;
    }
}

void print_data(AttackData *data) {
    printf("Number of aliens: %d\n", data->alien_attacks[0].num_attacks);
    printf("Number of attacks per alien: %d\n", data->alien_attacks[0].num_attacks);
    printf("Number of cities: %d\n", data->city_attacks[0].num_cities);
    printf("Number of attacks per city: %d\n", data->city_attacks[0].num_attacks);
    printf("Number of years: %d\n", data->year_attacks[0].num_years);
    printf("Number of attacks per year: %d\n", data->year_attacks[0].num_attacks);
}

int main() {
    AttackData data;
    generate_random_data(&data);
    print_data(&data);
    return 0;
}