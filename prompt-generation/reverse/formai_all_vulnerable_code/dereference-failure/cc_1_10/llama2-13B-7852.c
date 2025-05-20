//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_TEMP 30
#define MIN_TEMP -20
#define MAX_HUM 100
#define MIN_HUM 20
#define MAX_WIND 50
#define MIN_WIND 0
#define MAX_PREC 100
#define MIN_PREC 0

// Structure to hold weather data
typedef struct {
    int temp;
    int hum;
    int wind;
    int prec;
} weather_data_t;

// Function to generate random weather data
weather_data_t *generate_weather() {
    int temp_range = (int)(random() % (MAX_TEMP - MIN_TEMP + 1));
    int hum_range = (int)(random() % (MAX_HUM - MIN_HUM + 1));
    int wind_range = (int)(random() % (MAX_WIND - MIN_WIND + 1));
    int prec_range = (int)(random() % (MAX_PREC - MIN_PREC + 1));

    weather_data_t *wd = malloc(sizeof(weather_data_t));
    wd->temp = MIN_TEMP + temp_range;
    wd->hum = MIN_HUM + hum_range;
    wd->wind = MIN_WIND + wind_range;
    wd->prec = MIN_PREC + prec_range;

    return wd;
}

// Function to print weather data
void print_weather(weather_data_t *wd) {
    printf("Weather Data:\n");
    printf("Temperature: %d\n", wd->temp);
    printf("Humidity: %d\n", wd->hum);
    printf("Wind Speed: %d\n", wd->wind);
    printf("Preccipitation: %d\n", wd->prec);
}

int main() {
    srand(time(NULL));

    weather_data_t *wd1 = generate_weather();
    weather_data_t *wd2 = generate_weather();
    weather_data_t *wd3 = generate_weather();

    print_weather(wd1);
    print_weather(wd2);
    print_weather(wd3);

    return 0;
}