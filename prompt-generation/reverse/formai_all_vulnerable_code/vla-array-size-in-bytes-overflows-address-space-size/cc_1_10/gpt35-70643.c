//FormAI DATASET v1.0 Category: Weather simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main() {
    int weather_count;
    printf("How many days of weather data would you like to simulate? ");
    scanf("%d", &weather_count);

    double temperature[weather_count];
    double humidity[weather_count];
    double pressure[weather_count];

    printf("Please enter the temperature, humidity, and pressure (in that order) for each day.\n");

    for (int i = 0; i < weather_count; i++) {
        printf("Day %d:\n", i+1);
        scanf("%lf %lf %lf", &temperature[i], &humidity[i], &pressure[i]);
    }

    double avg_temp = 0.0;
    double avg_humidity = 0.0;
    double avg_pressure = 0.0;

    for (int i = 0; i < weather_count; i++) {
        avg_temp += temperature[i];
        avg_humidity += humidity[i];
        avg_pressure += pressure[i];
    }

    avg_temp /= weather_count;
    avg_humidity /= weather_count;
    avg_pressure /= weather_count;

    printf("\nWeather Simulation Results:\n");
    printf("Average Temperature: %.2lf degrees Celsius\n", avg_temp);
    printf("Average Humidity: %.2lf %%\n", avg_humidity);
    printf("Average Pressure: %.2lf kPa\n\n", avg_pressure);

    if (avg_temp > 30.0 && avg_humidity > 70.0) {
        printf("The weather conditions are not suitable for outdoor activities.\n");
    } else if (avg_temp < 10.0) {
        printf("The weather conditions are not suitable for outdoor activities.\n");
    } else if (avg_pressure < 95.0) {
        printf("There may be a storm coming, be careful.\n");
    } else {
        printf("The weather conditions are suitable for outdoor activities.\n");
    }

    return 0;
}