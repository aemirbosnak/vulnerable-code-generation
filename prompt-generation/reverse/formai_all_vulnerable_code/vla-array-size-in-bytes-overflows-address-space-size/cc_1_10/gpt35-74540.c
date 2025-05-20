//FormAI DATASET v1.0 Category: Weather simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_CITY_LENGTH 50
#define MAX_TEMP_LENGTH 5

typedef struct {
    char name[MAX_CITY_LENGTH];
    int temperature;
} City;

int get_random_temperature(int min_temp, int max_temp) {
    return rand() % (max_temp - min_temp + 1) + min_temp;
}

void print_city(City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d\n", city.temperature);
}

int main() {
    int num_cities;
    printf("Enter the number of cities to simulate: ");
    scanf("%d", &num_cities);

    srand(time(NULL)); // Seed for random numbers

    // Create an array of cities and initialize temperatures
    City cities[num_cities];
    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i+1);
        scanf("%s", cities[i].name);
        cities[i].temperature = get_random_temperature(-10, 40);
    }

    // Simulate the weather by increasing/decreasing temperature by a random amount
    for (int i = 0; i < num_cities; i++) {
        int temp_change = get_random_temperature(-5, 5);
        cities[i].temperature += temp_change;
        printf("The temperature in %s has changed by %d degrees\n", cities[i].name, temp_change);
    }

    // Print the final temperatures for each city
    printf("\nFinal temperatures:\n");
    for (int i = 0; i < num_cities; i++) {
        print_city(cities[i]);
    }

    return 0;
}