//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP -50
#define MAX_TEMP 50
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100
#define MIN_WIND_SPEED 0
#define MAX_WIND_SPEED 30
#define MIN_RAINFALL 0
#define MAX_RAINFALL 100

struct Weather {
    int temperature;
    int humidity;
    int wind_speed;
    int rainfall;
};

void generate_random_weather(struct Weather *weather) {
    srand(time(NULL));
    weather->temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    weather->humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
    weather->wind_speed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;
    weather->rainfall = rand() % (MAX_RAINFALL - MIN_RAINFALL + 1) + MIN_RAINFALL;
}

void print_weather(struct Weather weather) {
    printf("Temperature: %d\n", weather.temperature);
    printf("Humidity: %d\n", weather.humidity);
    printf("Wind Speed: %d\n", weather.wind_speed);
    printf("Rainfall: %d\n", weather.rainfall);
}

int main() {
    int num_weathers;
    printf("Enter the number of weathers to generate: ");
    scanf("%d", &num_weathers);

    struct Weather *weathers = malloc(num_weathers * sizeof(struct Weather));

    for (int i = 0; i < num_weathers; i++) {
        generate_random_weather(&weathers[i]);
        print_weather(weathers[i]);
    }

    free(weathers);
    return 0;
}