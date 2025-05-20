//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WEATHER_TYPES 10
#define WEATHER_DESCRIPTIONS 5

// Structure to hold weather information
typedef struct {
    int type;    // Weather type (0-9)
    char desc[50]; // Weather description
} weather_t;

// Function to generate random weather information
weather_t* get_weather() {
    int i, j;
    weather_t* weather;

    // Generate a random weather type (0-9)
    srand(time(NULL));
    weather->type = (rand() % WEATHER_TYPES);

    // Generate a random weather description (0-4)
    weather->desc[0] = 'A'; // Always a capital letter
    for (j = 1; j < 5; j++) {
        weather->desc[j] = 'a' + (rand() % 26);
    }

    // Return the weather structure
    return weather;
}

// Function to print the weather
void print_weather(weather_t* weather) {
    printf("Today's weather is: %s\n", weather->desc);
}

int main() {
    weather_t* weather;

    // Create a weather structure and print it
    weather = get_weather();
    print_weather(weather);

    // Create 5 more weather structures and print them
    weather = get_weather();
    print_weather(weather);

    for (int i = 0; i < 4; i++) {
        weather = get_weather();
        print_weather(weather);
    }

    return 0;
}