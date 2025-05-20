//MISTRAL-7B DATASET v1.0 Category: Weather simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    float temperature;
    float humidity;
    float pressure;
} Weather;

Weather* create_weather() {
    Weather* w = malloc(sizeof(Weather));
    w->temperature = NAN;
    w->humidity = NAN;
    w->pressure = NAN;
    return w;
}

void destroy_weather(Weather* w) {
    free(w);
}

void update_weather(Weather* w, float temperature, float humidity, float pressure) {
    w->temperature = temperature;
    w->humidity = humidity;
    w->pressure = pressure;
}

float random_float(float min, float max) {
    return (rand() / (float)RAND_MAX) * (max - min) + min;
}

void print_weather(Weather* w) {
    printf("Temperature: %.2f\n", w->temperature);
    printf("Humidity: %.2f%%\n", w->humidity);
    printf("Pressure: %.2f hPa\n", w->pressure);
}

int main() {
    srand(time(NULL));
    Weather* weather = create_weather();

    for (int i = 0; i < 10; i++) {
        float temperature = random_float(15.0f, 30.0f);
        float humidity = random_float(30.0f, 80.0f);
        float pressure = random_float(980.0f, 1010.0f);

        update_weather(weather, temperature, humidity, pressure);
        print_weather(weather);

        sleep(1); // Sleep for 1 second to simulate time passing
    }

    destroy_weather(weather);

    return 0;
}