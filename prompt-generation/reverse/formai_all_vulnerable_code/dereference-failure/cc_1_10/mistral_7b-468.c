//MISTRAL-7B DATASET v1.0 Category: Weather simulation ; Style: Cryptic
#define _CRYPTIC_WEATHER_SIM_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WEATHER_TYPES 4
#define MAX_TEMP_RANGE 50
#define SEED 1337

typedef enum WeatherType {
    SUN,
    RAIN,
    SNOW,
    CLOUDY
} WeatherType;

typedef struct Weather {
    WeatherType type;
    int temperature;
} Weather;

Weather *createWeather();
void destroyWeather(Weather *weather);
WeatherType getRandomWeatherType();
int getRandomNumber(int max);
void printWeather(Weather *weather);

int main() {
    srand(SEED);
    Weather *weather = createWeather();
    printWeather(weather);
    destroyWeather(weather);
    return 0;
}

Weather *createWeather() {
    Weather *weather = (Weather *)calloc(1, sizeof(Weather));
    weather->type = getRandomWeatherType();
    weather->temperature = getRandomNumber(MAX_TEMP_RANGE);
    return weather;
}

void destroyWeather(Weather *weather) {
    free(weather);
}

WeatherType getRandomWeatherType() {
    int type = rand() % MAX_WEATHER_TYPES;
    switch (type) {
        case 0:
            return SUN;
        case 1:
            return RAIN;
        case 2:
            return SNOW;
        case 3:
            return CLOUDY;
    }
}

int getRandomNumber(int max) {
    int min = 0;
    return rand() % (max + 1) + min;
}

void printWeather(Weather *weather) {
    switch (weather->type) {
        case SUN:
            printf("The sun is shining with a temperature of %d degrees.\n", weather->temperature);
            break;
        case RAIN:
            printf("It is raining with a temperature of %d degrees.\n", weather->temperature);
            break;
        case SNOW:
            printf("It is snowing with a temperature of %d degrees.\n", weather->temperature);
            break;
        case CLOUDY:
            printf("The sky is cloudy with a temperature of %d degrees.\n", weather->temperature);
            break;
    }
}