//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Weather types
enum weather_type {
  SUNNY,
  CLOUDY,
  RAINING,
  SNOWING
};

// Weather data
struct weather {
  enum weather_type type;
  int temperature;
  int humidity;
  int wind_speed;
};

// Get a random weather type
enum weather_type get_random_weather_type() {
  int type = rand() % 4;
  return type;
}

// Get a random temperature
int get_random_temperature() {
  int temperature = rand() % 30 + 1;
  return temperature;
}

// Get a random humidity
int get_random_humidity() {
  int humidity = rand() % 100;
  return humidity;
}

// Get a random wind speed
int get_random_wind_speed() {
  int wind_speed = rand() % 10 + 1;
  return wind_speed;
}

// Create a new weather object
struct weather* create_weather() {
  struct weather* weather = malloc(sizeof(*weather));
  weather->type = get_random_weather_type();
  weather->temperature = get_random_temperature();
  weather->humidity = get_random_humidity();
  weather->wind_speed = get_random_wind_speed();
  return weather;
}

// Free a weather object
void free_weather(struct weather* weather) {
  free(weather);
}

// Print the weather data
void print_weather(const struct weather* weather) {
  char* type_string;
  switch (weather->type) {
    case SUNNY:
      type_string = "Sunny";
      break;
    case CLOUDY:
      type_string = "Cloudy";
      break;
    case RAINING:
      type_string = "Raining";
      break;
    case SNOWING:
      type_string = "Snowing";
      break;
  }
  printf("Weather: %s\n", type_string);
  printf("Temperature: %d degrees Celsius\n", weather->temperature);
  printf("Humidity: %d%%\n", weather->humidity);
  printf("Wind speed: %d km/h\n", weather->wind_speed);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create a new weather object
  struct weather* weather = create_weather();

  // Print the weather data
  print_weather(weather);

  // Free the weather object
  free_weather(weather);

  return 0;
}