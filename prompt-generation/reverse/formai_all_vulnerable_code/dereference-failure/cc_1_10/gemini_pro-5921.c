//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the temperature conversion formula
#define CELSIUS_TO_FAHRENHEIT(celsius) ((celsius * 9) / 5) + 32
#define FAHRENHEIT_TO_CELSIUS(fahrenheit) ((fahrenheit - 32) * 5) / 9

// Define the temperature unit enum
typedef enum {
  CELSIUS,
  FAHRENHEIT
} temperature_unit;

// Define the temperature converter struct
typedef struct {
  temperature_unit unit;
  float value;
} temperature;

// Create a new temperature converter
temperature* create_temperature(temperature_unit unit, float value) {
  temperature* temp = malloc(sizeof(temperature));
  temp->unit = unit;
  temp->value = value;
  return temp;
}

// Convert the temperature to the specified unit
temperature* convert_temperature(temperature* temp, temperature_unit unit) {
  if (temp->unit == unit) {
    return temp;
  } else {
    if (temp->unit == CELSIUS) {
      temp->value = CELSIUS_TO_FAHRENHEIT(temp->value);
    } else if (temp->unit == FAHRENHEIT) {
      temp->value = FAHRENHEIT_TO_CELSIUS(temp->value);
    }
    temp->unit = unit;
    return temp;
  }
}

// Print the temperature in the specified format
void print_temperature(temperature* temp, char* format) {
  if (strcmp(format, "%C") == 0) {
    printf("%.2f degrees Celsius\n", temp->value);
  } else if (strcmp(format, "%F") == 0) {
    printf("%.2f degrees Fahrenheit\n", temp->value);
  } else {
    printf("Invalid format\n");
  }
}

// Destroy the temperature converter
void destroy_temperature(temperature* temp) {
  free(temp);
}

// Main function
int main() {
  // Create a temperature converter
  temperature* temp = create_temperature(CELSIUS, 20.0);

  // Convert the temperature to Fahrenheit
  temp = convert_temperature(temp, FAHRENHEIT);

  // Print the temperature in Fahrenheit
  print_temperature(temp, "%F");

  // Convert the temperature back to Celsius
  temp = convert_temperature(temp, CELSIUS);

  // Print the temperature in Celsius
  print_temperature(temp, "%C");

  // Destroy the temperature converter
  destroy_temperature(temp);

  return 0;
}