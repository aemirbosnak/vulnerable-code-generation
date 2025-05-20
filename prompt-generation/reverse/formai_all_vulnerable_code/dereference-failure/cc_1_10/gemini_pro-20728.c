//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
  // Check for negative Celsius values
  if (celsius < -273.15) {
    fprintf(stderr, "Error: Celsius temperature cannot be below absolute zero.\n");
    exit(EXIT_FAILURE);
  }

  // Perform the conversion
  return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
  // Check for negative Fahrenheit values
  if (fahrenheit < -459.67) {
    fprintf(stderr, "Error: Fahrenheit temperature cannot be below absolute zero.\n");
    exit(EXIT_FAILURE);
  }

  // Perform the conversion
  return (fahrenheit - 32) * 5 / 9;
}

// Main function
int main(int argc, char *argv[]) {
  // Check for the correct number of arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <temperature> [c/f]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get the temperature and unit from the command line
  float temperature = atof(argv[1]);
  char unit = argv[2][0];

  // Convert the temperature based on the specified unit
  float converted_temperature;
  switch (unit) {
  case 'c':
    converted_temperature = celsius_to_fahrenheit(temperature);
    break;
  case 'f':
    converted_temperature = fahrenheit_to_celsius(temperature);
    break;
  default:
    fprintf(stderr, "Error: Invalid unit specified. Use 'c' for Celsius or 'f' for Fahrenheit.\n");
    exit(EXIT_FAILURE);
  }

  // Print the converted temperature
  printf("Converted temperature: %.2f %s\n", converted_temperature, unit == 'c' ? "F" : "C");

  return EXIT_SUCCESS;
}