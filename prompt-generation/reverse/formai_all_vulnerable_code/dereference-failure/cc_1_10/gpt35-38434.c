//FormAI DATASET v1.0 Category: Weather simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 50
#define MIN_TEMP -10
#define MAX_WIND_SPEED 20
#define MIN_WIND_SPEED 0

typedef struct {
    int temperature;
    int wind_speed;
    char* weather_type;
} WeatherData;

char* getWeatherType(int temperature, int wind_speed)
{
    if (temperature <= -10)
        return "Blizzard";
    else if (temperature <= 0 && wind_speed >= 10)
        return "Snowstorm";
    else if (temperature <= 0)
        return "Snowy";
    else if (temperature <= 10 && wind_speed >= 10)
        return "Windy";
    else if (temperature <= 10)
        return "Cloudy";
    else if (temperature <= 20 && wind_speed >= 10)
        return "Breezy";
    else if (temperature <= 20)
        return "Sunny";
    else if (temperature <= 30 && wind_speed >= 10)
        return "Dry and Windy";
    else if (temperature <= 30)
        return "Warm";
    else if (temperature <= 40 && wind_speed >= 10)
        return "Dry and Hot";
    else if (temperature <= 40)
        return "Hot";
    else
        return "Extreme Heat";
}

WeatherData* generateWeatherData()
{
    srand(time(NULL));

    int temperature = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;
    int wind_speed = (rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1)) + MIN_WIND_SPEED;
    char* weather_type = getWeatherType(temperature, wind_speed);

    WeatherData* data = (WeatherData*)malloc(sizeof(WeatherData));
    data->temperature = temperature;
    data->wind_speed = wind_speed;
    data->weather_type = weather_type;

    return data;
}

void printWeatherData(WeatherData* data)
{
    printf("Temperature: %d°C\n", data->temperature);
    printf("Wind Speed: %d km/h\n", data->wind_speed);
    printf("Weather Type: %s\n", data->weather_type);
}

int main() 
{
    printf("Welcome to the Weather Simulator!\n");

    WeatherData* data = generateWeatherData();

    printWeatherData(data);

    free(data);

    return 0;
}