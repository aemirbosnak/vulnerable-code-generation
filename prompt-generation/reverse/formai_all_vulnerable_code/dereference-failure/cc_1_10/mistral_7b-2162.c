//MISTRAL-7B DATASET v1.0 Category: Weather simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

typedef struct Weather {
    float temperature;
    char weather[20];
} Weather;

void generate_weather(Weather* weather) {
    weather->temperature = (rand() % 30) + 5.0;
    time_t t;
    struct tm* current_time;

    time(&t);
    current_time = localtime(&t);

    int hour = current_time->tm_hour;

    if (hour >= 6 && hour < 12) {
        strcpy(weather->weather, "Sunny Morning");
    } else if (hour >= 12 && hour < 18) {
        strcpy(weather->weather, "Sunny Afternoon");
    } else if (hour >= 18 && hour < 20) {
        strcpy(weather->weather, "Sunset");
    } else {
        strcpy(weather->weather, "Night");
    }
}

int main() {
    srand(time(NULL));
    Weather my_weather;

    printf("-------------------------\n");
    printf("| Welcome to Weatherland! |\n");
    printf("-------------------------\n");

    while (1) {
        generate_weather(&my_weather);
        printf("\nCurrent Weather:\n");
        printf("Temperature: %.2f degrees Celsius\n", my_weather.temperature);
        printf("Weather: %s\n", my_weather.weather);
        printf("\nPress 'r' to get a new weather or 'q' to quit\n");
        char input;
        scanf(" %c", &input);
        if (input == 'q') {
            break;
        } else if (input != 'r') {
            printf("Invalid input. Press 'r' to get a new weather.\n");
        }
    }

    printf("\nThanks for using Weatherland! Have a great day!\n");
    return 0;
}