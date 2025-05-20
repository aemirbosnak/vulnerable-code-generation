//FormAI DATASET v1.0 Category: Weather simulation ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int temp, windSpeed; //temperature and wind speed variables
    char weather[10]; //string variable to hold weather type
    
    srand(time(NULL)); //random seed based on time
    
    //generate random temperature between -25 and 40 degrees Celsius
    temp = (rand() % 65) - 25;
    
    //generate random wind speed between 0 and 50 km/h
    windSpeed = rand() % 51;
    
    //determine weather type based on temperature and wind speed
    if(temp <= 0){
        if(windSpeed < 20){
            strcpy(weather, "Snowy"); //if temperature is below freezing and wind speed is low, it's snowy
        } else {
            strcpy(weather, "Blizzard"); //if temperature is below freezing and wind speed is high, it's a blizzard
        }
    } else if(temp < 10){
        if(windSpeed < 20){
            strcpy(weather, "Rainy"); //if temperature is above freezing but below 10 degrees Celsius and wind speed is low, it's rainy
        } else {
            strcpy(weather, "Thunderstorm"); //if temperature is above freezing but below 10 degrees Celsius and wind speed is high, it's a thunderstorm
        }
    } else if(temp < 20){
        if(windSpeed < 20){
            strcpy(weather, "Cloudy"); //if temperature is between 10 and 20 degrees Celsius and wind speed is low, it's cloudy
        } else {
            strcpy(weather, "Windy"); //if temperature is between 10 and 20 degrees Celsius and wind speed is high, it's windy
        }
    } else {
        if(windSpeed < 20){
            strcpy(weather, "Sunny"); //if temperature is above 20 degrees Celsius and wind speed is low, it's sunny
        } else {
            strcpy(weather, "Dusty"); //if temperature is above 20 degrees Celsius and wind speed is high, it's dusty
        }
    }
    
    //output simulation results
    printf("Temperature:\t%d degrees Celsius\n", temp);
    printf("Wind Speed:\t%d km/h\n", windSpeed);
    printf("Weather:\t%s\n", weather);
    
    return 0;
}