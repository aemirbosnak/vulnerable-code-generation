//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DAYS 30

typedef struct {
    char date[11]; // YYYY-MM-DD format
    float temperature; // in degrees Celsius
    float humidity; // in percentage
    char conditions[20]; // e.g., Sunny, Rainy, Cloudy
} WeatherData;

void fillWeatherData(WeatherData* data) {
    const char* conditions[] = {"Sunny", "Rainy", "Cloudy", "Snowy", "Windy"};
    
    // Get current time
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    
    // Fill in weather data for the next MAX_DAYS
    for (int i = 0; i < MAX_DAYS; i++) {
        // Increment day
        tm_info->tm_mday += 1;
        mktime(tm_info); // Normalize date
        
        // Format date
        strftime(data[i].date, sizeof(data[i].date), "%Y-%m-%d", tm_info);
        
        // Random temperature between -10 and 35 degrees Celsius
        data[i].temperature = ((float)(rand() % 461) - 100) / 10.0; 
        
        // Random humidity between 20 and 100 percent
        data[i].humidity = (float)(rand() % 81 + 20); 
        
        // Select random weather conditions
        strcpy(data[i].conditions, conditions[rand() % 5]);
    }
}

void displayWeatherData(WeatherData* data) {
    printf("%-12s %-15s %-10s %-15s\n", "Date", "Temperature(C)", "Humidity(%)", "Conditions");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < MAX_DAYS; i++) {
        printf("%-12s %-15.1f %-10.1f %-15s\n", data[i].date, data[i].temperature, data[i].humidity, data[i].conditions);
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator

    WeatherData weatherData[MAX_DAYS];
    
    fillWeatherData(weatherData);
    displayWeatherData(weatherData);
    
    return 0;
}