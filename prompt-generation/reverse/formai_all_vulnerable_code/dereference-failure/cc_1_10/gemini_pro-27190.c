//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define the weather conditions
enum weather_conditions {
  SUNNY,
  CLOUDY,
  RAINY,
  STORMY
};

// Define the data structure for the weather simulation
struct weather_simulation {
  enum weather_conditions condition;
  int temperature;
  int humidity;
  int wind_speed;
};

// Create a new weather simulation
struct weather_simulation *create_weather_simulation() {
  struct weather_simulation *weather = malloc(sizeof(struct weather_simulation));
  if (!weather) {
    return NULL;
  }

  // Initialize the weather conditions
  weather->condition = SUNNY;
  weather->temperature = 20;
  weather->humidity = 50;
  weather->wind_speed = 10;

  return weather;
}

// Destroy a weather simulation
void destroy_weather_simulation(struct weather_simulation *weather) {
  free(weather);
}

// Update the weather simulation
void update_weather_simulation(struct weather_simulation *weather) {
  // Update the weather conditions
  switch (weather->condition) {
    case SUNNY:
      if (rand() % 100 < 10) {
        weather->condition = CLOUDY;
      }
      break;
    case CLOUDY:
      if (rand() % 100 < 30) {
        weather->condition = RAINY;
      } else if (rand() % 100 < 10) {
        weather->condition = SUNNY;
      }
      break;
    case RAINY:
      if (rand() % 100 < 50) {
        weather->condition = STORMY;
      } else if (rand() % 100 < 20) {
        weather->condition = CLOUDY;
      }
      break;
    case STORMY:
      if (rand() % 100 < 50) {
        weather->condition = RAINY;
      } else if (rand() % 100 < 10) {
        weather->condition = CLOUDY;
      }
      break;
  }

  // Update the temperature
  weather->temperature += (rand() % 10) - 5;

  // Update the humidity
  weather->humidity += (rand() % 10) - 5;

  // Update the wind speed
  weather->wind_speed += (rand() % 10) - 5;
}

// Print the weather simulation
void print_weather_simulation(struct weather_simulation *weather) {
  printf("Weather conditions: ");
  switch (weather->condition) {
    case SUNNY:
      printf("Sunny\n");
      break;
    case CLOUDY:
      printf("Cloudy\n");
      break;
    case RAINY:
      printf("Rainy\n");
      break;
    case STORMY:
      printf("Stormy\n");
      break;
  }

  printf("Temperature: %d degrees Celsius\n", weather->temperature);
  printf("Humidity: %d percent\n", weather->humidity);
  printf("Wind speed: %d kilometers per hour\n", weather->wind_speed);
}

int main() {
  // Create a weather simulation
  struct weather_simulation *weather = create_weather_simulation();

  // Update the weather simulation 10 times
  for (int i = 0; i < 10; i++) {
    update_weather_simulation(weather);
  }

  // Print the weather simulation
  print_weather_simulation(weather);

  // Destroy the weather simulation
  destroy_weather_simulation(weather);

  return 0;
}