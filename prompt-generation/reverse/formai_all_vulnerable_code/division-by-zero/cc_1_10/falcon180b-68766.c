//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365
#define MIN_TEMP -20
#define MAX_TEMP 40

int main() {
    int i, j;
    int days = 0;
    int min_temp, max_temp;
    int temp_change;
    int curr_temp;
    int sunny_days = 0;
    int rainy_days = 0;
    int cloudy_days = 0;

    srand(time(NULL));

    // Initialize temperature range
    min_temp = MIN_TEMP + rand() % (MAX_TEMP - MIN_TEMP + 1);
    max_temp = MAX_TEMP + rand() % (MAX_TEMP - MIN_TEMP + 1);

    // Loop through each day
    while (days < MAX_DAYS) {
        curr_temp = min_temp + rand() % (max_temp - min_temp + 1);

        // Determine weather condition
        if (curr_temp >= 25) {
            printf("Day %d: Sunny and hot with a temperature of %d\n", days+1, curr_temp);
            sunny_days++;
        } else if (curr_temp >= 15 && curr_temp < 25) {
            printf("Day %d: Partly cloudy with a temperature of %d\n", days+1, curr_temp);
            cloudy_days++;
        } else {
            printf("Day %d: Rainy and cool with a temperature of %d\n", days+1, curr_temp);
            rainy_days++;
        }

        // Update temperature range for next day
        temp_change = rand() % 5 - 2;
        min_temp += temp_change;
        if (min_temp < MIN_TEMP) {
            min_temp = MIN_TEMP;
        }
        max_temp += temp_change;
        if (max_temp > MAX_TEMP) {
            max_temp = MAX_TEMP;
        }

        days++;
    }

    // Print summary of weather conditions
    printf("\nWeather summary:\n");
    printf("Sunny days: %d\n", sunny_days);
    printf("Rainy days: %d\n", rainy_days);
    printf("Cloudy days: %d\n", cloudy_days);

    return 0;
}