//MISTRAL-7B DATASET v1.0 Category: Weather simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_TOWNS 5
#define NUM_MONTHS 12

typedef struct {
    char name[30];
    int x, y;
} Town;

Town towns[NUM_TOWNS] = {
    {"Aldwych", 2, 4},
    {"Bramshaw", 6, 8},
    {"Crenshaw", 1, 6},
    {"Drakesden", 5, 3},
    {"Eastwick", 7, 7}
};

typedef enum { SUN, RAIN, SNOW, FOG } Weather;

typedef struct {
    Weather weather;
    int temperature;
} MonthlyWeather;

MonthlyWeather monthlyWeather[NUM_TOWNS][NUM_MONTHS];

void initializeWeather() {
    int i, j;

    for (i = 0; i < NUM_TOWNS; i++) {
        for (j = 0; j < NUM_MONTHS; j++) {
            monthlyWeather[i][j].weather = SUN;
            monthlyWeather[i][j].temperature = 15 + rand() % 11;
        }
    }
}

void printWeather(const Town *town) {
    const MonthlyWeather *currentWeather;
    char *weatherDescription;

    currentWeather = &monthlyWeather[town - towns][time(NULL) / 30];

    switch (currentWeather->weather) {
        case SUN:
            weatherDescription = "The sun shines upon the verdant fields of ";
            break;
        case RAIN:
            weatherDescription = "The heavens weep upon the quaint cottages of ";
            break;
        case SNOW:
            weatherDescription = "The white blankets of snow cover the thatched roofs of ";
            break;
        case FOG:
            weatherDescription = "The thick fog enshrouds the stone walls of ";
            break;
    }

    printf("%s%s\n", weatherDescription, town->name);
    printf("This month, the temperature hovers around %d degrees.\n", currentWeather->temperature);
}

int main() {
    srand(time(NULL));
    initializeWeather();

    while (1) {
        int choice;
        Town *selectedTown;

        printf("Enter the number of a town to check the current weather: ");
        scanf("%d", &choice);

        if (choice > NUM_TOWNS || choice < 1) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        selectedTown = &towns[choice - 1];
        printWeather(selectedTown);
    }

    return 0;
}