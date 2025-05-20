//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double temperature;
    double humidity;
    double wind_speed;
    double wind_direction;
    double precipitation;
} WeatherData;

typedef struct {
    WeatherData* data;
    int size;
    int capacity;
} WeatherDataset;

WeatherDataset* create_weather_dataset(int capacity) {
    WeatherDataset* dataset = malloc(sizeof(WeatherDataset));
    dataset->data = malloc(sizeof(WeatherData) * capacity);
    dataset->size = 0;
    dataset->capacity = capacity;
    return dataset;
}

void destroy_weather_dataset(WeatherDataset* dataset) {
    free(dataset->data);
    free(dataset);
}

void add_weather_data(WeatherDataset* dataset, WeatherData data) {
    if (dataset->size == dataset->capacity) {
        dataset->capacity *= 2;
        dataset->data = realloc(dataset->data, sizeof(WeatherData) * dataset->capacity);
    }
    dataset->data[dataset->size++] = data;
}

WeatherData get_random_weather_data() {
    WeatherData data;
    data.temperature = (double)rand() / RAND_MAX * 100;
    data.humidity = (double)rand() / RAND_MAX;
    data.wind_speed = (double)rand() / RAND_MAX * 100;
    data.wind_direction = (double)rand() / RAND_MAX * 360;
    data.precipitation = (double)rand() / RAND_MAX;
    return data;
}

void simulate_weather(WeatherDataset* dataset, int num_days) {
    for (int i = 0; i < num_days; i++) {
        add_weather_data(dataset, get_random_weather_data());
    }
}

void print_weather_dataset(WeatherDataset* dataset) {
    for (int i = 0; i < dataset->size; i++) {
        WeatherData data = dataset->data[i];
        printf("Day %d: %.1fF, %.1f%% humidity, %.1f mph wind @ %.1f degrees, %.1f inches precipitation\n",
            i + 1, data.temperature, data.humidity * 100, data.wind_speed, data.wind_direction, data.precipitation);
    }
}

int main() {
    srand(time(NULL));

    int num_days = 10;
    WeatherDataset* dataset = create_weather_dataset(num_days);

    simulate_weather(dataset, num_days);

    print_weather_dataset(dataset);

    destroy_weather_dataset(dataset);

    return 0;
}