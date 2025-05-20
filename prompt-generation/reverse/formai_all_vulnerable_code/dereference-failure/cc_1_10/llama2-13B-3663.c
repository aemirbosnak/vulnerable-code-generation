//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WEATHER_MAX 10
#define WEATHER_FACTOR 3

// Struct to store weather data
typedef struct {
    char day[5];
    char weather[20];
    int temperature;
    int humidity;
} weather_t;

// Function to generate weather data
weather_t *generate_weather(void) {
    weather_t *w;
    srand(time(NULL));
    w = malloc(sizeof(weather_t));
    w->day[0] = 'M'; // Monday
    w->day[1] = 'o'; // or
    w->day[2] = 'n'; // day
    w->day[3] = 'd'; // of
    w->day[4] = 'a'; // the
    // Generate weather condition
    switch (rand() % WEATHER_MAX) {
        case 0:
            w->weather[0] = "Sunny";
            w->temperature = 25;
            w->humidity = 40;
            break;
        case 1:
            w->weather[0] = "Cloudy";
            w->temperature = 18;
            w->humidity = 60;
            break;
        case 2:
            w->weather[0] = "Rainy";
            w->temperature = 12;
            w->humidity = 80;
            break;
        case 3:
            w->weather[0] = "Windy";
            w->temperature = 20;
            w->humidity = 50;
            break;
        default:
            w->weather[0] = "Overcast";
            w->temperature = 15;
            w->humidity = 70;
            break;
    }
    return w;
}

int main(void) {
    weather_t *weather;
    int i;

    // Generate weather data
    weather = generate_weather();

    // Print weather data
    printf("Weather for %s\n", weather->day);
    printf("Weather Condition: %s\n", weather->weather);
    printf("Temperature: %d\n", weather->temperature);
    printf("Humidity: %d\n", weather->humidity);

    // Simulate weather for 7 days
    for (i = 0; i < 7; i++) {
        weather = generate_weather();
        printf("Day %d: %s\n", i + 1, weather->day);
        printf("Weather Condition: %s\n", weather->weather);
        printf("Temperature: %d\n", weather->temperature);
        printf("Humidity: %d\n", weather->humidity);
    }

    return 0;
}