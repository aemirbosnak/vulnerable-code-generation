//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the weather types
#define SUNNY 0
#define CLOUDY 1
#define RAINING 2
#define SNOWING 3

// Define the temperature range
#define MIN_TEMP -20
#define MAX_TEMP 40

// Define the wind speed range
#define MIN_WIND 0
#define MAX_WIND 100

// Define the precipitation range
#define MIN_PRECIP 0
#define MAX_PRECIP 100

// Generate a random number
#define RAND(min, max) ((rand() % (max - min + 1)) + min)

// Simulate the weather
void simulate_weather() {
  // Get the current time
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  // Get the current temperature
  int temp = RAND(MIN_TEMP, MAX_TEMP);

  // Get the current wind speed
  int wind = RAND(MIN_WIND, MAX_WIND);

  // Get the current precipitation
  int precip = RAND(MIN_PRECIP, MAX_PRECIP);

  // Get the current weather type
  int weather_type;
  if (precip > 50) {
    weather_type = RAINING;
  } else if (precip > 20) {
    weather_type = SNOWING;
  } else if (wind > 50) {
    weather_type = CLOUDY;
  } else {
    weather_type = SUNNY;
  }

  // Print the weather forecast
  printf("The weather forecast for %s, %d-%02d-%02d is:\n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
  printf("Temperature: %d degrees Celsius\n", temp);
  printf("Wind speed: %d kilometers per hour\n", wind);
  printf("Precipitation: %d millimeters\n", precip);
  switch (weather_type) {
    case SUNNY:
      printf("Weather: Sunny\n");
      break;
    case CLOUDY:
      printf("Weather: Cloudy\n");
      break;
    case RAINING:
      printf("Weather: Raining\n");
      break;
    case SNOWING:
      printf("Weather: Snowing\n");
      break;
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Simulate the weather
  simulate_weather();

  return 0;
}