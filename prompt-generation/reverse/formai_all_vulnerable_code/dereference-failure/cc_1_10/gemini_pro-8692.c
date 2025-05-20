//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: Donald Knuth
/* A Donald Knuth Style Weather Simulation Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_IN_YEAR 365.25
#define HOURS_IN_DAY 24
#define MINUTES_IN_HOUR 60
#define SECONDS_IN_MINUTE 60

/* Temperature data structure */
typedef struct {
  double temperature;  /* Temperature in degrees Celsius */
  double humidity;     /* Humidity in percentage */
  double wind_speed;   /* Wind speed in kilometers per hour */
  double rainfall;     /* Rainfall in millimeters */
} WeatherData;

/* Function to generate random weather data */
WeatherData generate_weather_data(void) {
  WeatherData data;

  /* Generate random temperature */
  data.temperature = (rand() % 100) / 10.0;

  /* Generate random humidity */
  data.humidity = (rand() % 100) / 100.0;

  /* Generate random wind speed */
  data.wind_speed = (rand() % 100) / 10.0;

  /* Generate random rainfall */
  data.rainfall = (rand() % 100) / 100.0;

  return data;
}

/* Function to simulate the weather for a given number of days */
void simulate_weather(int days) {
  int i, j;

  /* Allocate memory for the weather data */
  WeatherData *data = malloc(sizeof(WeatherData) * days * HOURS_IN_DAY * MINUTES_IN_HOUR * SECONDS_IN_MINUTE);

  /* Generate random weather data for each day, hour, minute, and second */
  for (i = 0; i < days; i++) {
    for (j = 0; j < HOURS_IN_DAY; j++) {
      for (int k = 0; k < MINUTES_IN_HOUR; k++) {
        for (int l = 0; l < SECONDS_IN_MINUTE; l++) {
          data[i * HOURS_IN_DAY * MINUTES_IN_HOUR * SECONDS_IN_MINUTE + j * MINUTES_IN_HOUR * SECONDS_IN_MINUTE + k * SECONDS_IN_MINUTE + l] = generate_weather_data();
        }
      }
    }
  }

  /* Free the memory allocated for the weather data */
  free(data);
}

/* Main function */
int main(void) {
  /* Seed the random number generator */
  srand(time(NULL));

  /* Simulate the weather for a given number of days */
  simulate_weather(DAYS_IN_YEAR);

  return 0;
}