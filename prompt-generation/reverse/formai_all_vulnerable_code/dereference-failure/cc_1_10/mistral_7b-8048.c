//MISTRAL-7B DATASET v1.0 Category: Weather simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DAYS 14
#define LOVE_THRESHOLD 7

typedef struct {
    int day;
    int love;
    int weather;
} WeatherData;

void generate_weather(WeatherData *weather_data) {
    int i;
    for (i = 0; i < NUM_DAYS; i++) {
        weather_data[i].day = i + 1;
        weather_data[i].weather = rand() % 3;
        if (weather_data[i].weather == 0) {
            printf("Day %d: Sunny\n", weather_data[i].day);
        } else if (weather_data[i].weather == 1) {
            printf("Day %d: Rainy\n", weather_data[i].day);
        } else {
            printf("Day %d: Cloudy\n", weather_data[i].day);
        }

        if (i > 0 && weather_data[i].weather != weather_data[i-1].weather) {
            weather_data[i].love = rand() % 11;
            printf("Day %d: Love level: %d\n", weather_data[i].day, weather_data[i].love);
        } else {
            weather_data[i].love = weather_data[i-1].love;
            printf("Day %d: Love level: %d\n", weather_data[i].day, weather_data[i].love);
        }

        if (weather_data[i].love > LOVE_THRESHOLD && weather_data[i].weather == 0) {
            printf("Day %d: Romeo and Juliet meet under the sun and fall deeper in love.\n", weather_data[i].day);
        } else if (weather_data[i].love < LOVE_THRESHOLD && weather_data[i].weather == 0) {
            printf("Day %d: Romeo and Juliet long for each other under the sun, but their families' feud keeps them apart.\n", weather_data[i].day);
        }

        if (weather_data[i].love > LOVE_THRESHOLD && weather_data[i].weather == 1) {
            printf("Day %d: Romeo and Juliet meet in the rain and share a tender moment.\n", weather_data[i].day);
        } else if (weather_data[i].love < LOVE_THRESHOLD && weather_data[i].weather == 1) {
            printf("Day %d: Romeo and Juliet are kept apart by the rain and their families' feud.\n", weather_data[i].day);
        }

        if (weather_data[i].love > LOVE_THRESHOLD && weather_data[i].weather == 2) {
            printf("Day %d: Romeo and Juliet share a quiet moment under the clouds, reflecting on their love.\n", weather_data[i].day);
        } else if (weather_data[i].love < LOVE_THRESHOLD && weather_data[i].weather == 2) {
            printf("Day %d: Romeo and Juliet are unable to meet under the clouds, as their families' feud continues to loom.\n", weather_data[i].day);
        }
    }
}

int main() {
    srand(time(NULL));
    WeatherData weather[NUM_DAYS];
    generate_weather(weather);
    return 0;
}