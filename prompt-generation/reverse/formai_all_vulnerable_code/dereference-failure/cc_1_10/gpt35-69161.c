//FormAI DATASET v1.0 Category: Educational ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_CITIES 5
#define MAX_DISTANCE 1000
#define MAX_RESOURCES 100
#define MAX_SUPPLIES 5

typedef struct City {
    char* name;
    int distanceToNextCity;
    int resources;
} City;

typedef struct Caravan {
    City* currentCity;
    int supplies[MAX_SUPPLIES];
} Caravan;

enum Supplies {
    FOOD,
    WATER,
    FUEL,
    AMMO,
    MEDICINE
};

City cities[NUM_OF_CITIES];

// The function to initialize the cities
void initCities() {
    cities[0].name = "New York";
    cities[0].distanceToNextCity = 300;
    cities[0].resources = MAX_RESOURCES;

    cities[1].name = "Chicago";
    cities[1].distanceToNextCity = 200;
    cities[1].resources = MAX_RESOURCES;

    cities[2].name = "Denver";
    cities[2].distanceToNextCity = 400;
    cities[2].resources = MAX_RESOURCES;

    cities[3].name = "Las Vegas";
    cities[3].distanceToNextCity = 500;
    cities[3].resources = MAX_RESOURCES;

    cities[4].name = "Los Angeles";
    cities[4].distanceToNextCity = MAX_DISTANCE;
    cities[4].resources = MAX_RESOURCES;
}

// The function to initialize the caravan
Caravan* initCaravan() {
    Caravan* caravan = malloc(sizeof(Caravan));
    caravan->currentCity = &cities[0]; // Start in New York
    for (int i = 0; i < MAX_SUPPLIES; i++) {
        caravan->supplies[i] = 0;
    }
    return caravan;
}

// The function to print the city information
void printCity(City* city) {
    printf("City: %s.\nDistance to next city: %d miles.\nResources: %d.\n\n", city->name, city->distanceToNextCity, city->resources);
}

// The function to print the caravan information
void printCaravan(Caravan* caravan) {
    printf("Current location: %s.\nSupplies:\n\tFood: %d.\n\tWater: %d.\n\tFuel: %d.\n\tAmmo: %d.\n\tMedicine: %d.\n", 
        caravan->currentCity->name, 
        caravan->supplies[FOOD], 
        caravan->supplies[WATER], 
        caravan->supplies[FUEL], 
        caravan->supplies[AMMO], 
        caravan->supplies[MEDICINE]
    );
}

// The function to randomly generate resources in a city
void generateResources(City* city) {
    city->resources = rand() % MAX_RESOURCES + 1;
}

// The function to move the caravan to the next city
void travelToNextCity(Caravan* caravan) {
    caravan->currentCity = &cities[1]; // For simplicity, always move to Chicago
    printf("Moving to the next city...\n\n");
}

int main() {
    srand(time(0)); // Seed the random number generator

    initCities();
    Caravan* caravan = initCaravan();

    printf("Welcome to the post-apocalyptic world of C!\n\n");

    while (1) {
        printf("What would you like to do?\n"
               "1. Check your supplies.\n"
               "2. Check the city information.\n"
               "3. Move to the next city.\n"
               "4. Quit.\n");

        char input[10];
        fgets(input, 10, stdin);

        switch (atoi(input)) {
            case 1:
                printCaravan(caravan);
                break;

            case 2:
                printCity(caravan->currentCity);
                break;

            case 3:
                travelToNextCity(caravan);
                break;

            case 4:
                printf("Thanks for playing!\n");
                return 0;

            default:
                printf("Invalid input. Please try again.\n\n");
        }
    }
}