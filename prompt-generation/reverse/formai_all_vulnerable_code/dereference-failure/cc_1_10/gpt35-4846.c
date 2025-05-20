//FormAI DATASET v1.0 Category: Weather simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //seed for random generator
    float temperature = 20.0;
    int humidity = 50;
    int wind_speed = 10;
    char wind_direction[] = "North";
    char sky_state[] = "Clear";
    
    printf("Welcome to the Weather Simulation\n");
    printf("The current temperature is %.2f C\n", temperature);
    printf("The current humidity is %d percent\n", humidity);
    printf("The current wind speed is %d km/h\n", wind_speed);
    printf("The current wind direction is %s\n", wind_direction);
    printf("The sky is %s\n\n", sky_state);
    
    int i; //loop variable
    
    for(i = 1; i <= 10; i++)
    {
        //randomize temperature
        temperature += (float)(rand() % 6 - 2) / 10.0;
        if(temperature < 10.0) temperature = 10.0;
        if(temperature > 35.0) temperature = 35.0;
        
        //randomize humidity
        humidity += rand() % 11 - 5;
        if(humidity < 0) humidity = 0;
        if(humidity > 100) humidity = 100;
        
        //randomize wind direction
        int direction_code = rand() % 8;
        const char* directions[] = {"North", "Northeast", "East", "Southeast", "South", "Southwest", "West", "Northwest"};
        strcpy(wind_direction, directions[direction_code]);
        
        //randomize wind speed
        wind_speed += rand() % 5 - 2;
        if(wind_speed < 5) wind_speed = 5;
        if(wind_speed > 30) wind_speed = 30;
        
        //randomize sky state
        int sky_code = rand() % 10;
        const char* sky_states[] = {"Clear", "Mostly clear", "Partly cloudy", "Mostly cloudy", "Cloudy", "Foggy", "Hazy", "Scattered thunderstorms", "Thunderstorms", "Showers"};
        strcpy(sky_state, sky_states[sky_code]);
        
        //print updated weather information
        printf("Time: %d\n", i);
        printf("Temperature: %.2f C\n", temperature);
        printf("Humidity: %d percent\n", humidity);
        printf("Wind Speed: %d km/h\n", wind_speed);
        printf("Wind Direction: %s\n", wind_direction);
        printf("Sky State: %s\n\n", sky_state);
    }
    
    printf("Thank you for using the Weather Simulation\n");
    return 0;
}