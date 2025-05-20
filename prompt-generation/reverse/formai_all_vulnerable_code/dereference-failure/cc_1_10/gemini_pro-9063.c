//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the unit types
typedef enum {
  UNIT_METERS,
  UNIT_KILOMETERS,
  UNIT_FEET,
  UNIT_MILES,
  UNIT_CELSIUS,
  UNIT_FAHRENHEIT,
  UNIT_KELVIN
} UnitType;

// Define the conversion functions
double meters_to_kilometers(double meters) {
  return meters / 1000.0;
}

double kilometers_to_meters(double kilometers) {
  return kilometers * 1000.0;
}

double feet_to_meters(double feet) {
  return feet * 0.3048;
}

double meters_to_feet(double meters) {
  return meters * 3.28084;
}

double celsius_to_fahrenheit(double celsius) {
  return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
  return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double kelvin_to_celsius(double kelvin) {
  return kelvin - 273.15;
}

double celsius_to_kelvin(double celsius) {
  return celsius + 273.15;
}

// Define the main function
int main() {
  // Get the input from the user
  char input[100];
  printf("Enter the value and unit (e.g., 100 meters): ");
  scanf("%s", input);

  // Parse the input
  char *value_str = strtok(input, " ");
  char *unit_str = strtok(NULL, " ");

  // Convert the value to a double
  double value = atof(value_str);

  // Convert the unit to an enum
  UnitType unit;
  if (!strcmp(unit_str, "meters")) {
    unit = UNIT_METERS;
  } else if (!strcmp(unit_str, "kilometers")) {
    unit = UNIT_KILOMETERS;
  } else if (!strcmp(unit_str, "feet")) {
    unit = UNIT_FEET;
  } else if (!strcmp(unit_str, "miles")) {
    unit = UNIT_MILES;
  } else if (!strcmp(unit_str, "celsius")) {
    unit = UNIT_CELSIUS;
  } else if (!strcmp(unit_str, "fahrenheit")) {
    unit = UNIT_FAHRENHEIT;
  } else if (!strcmp(unit_str, "kelvin")) {
    unit = UNIT_KELVIN;
  } else {
    printf("Invalid unit: %s\n", unit_str);
    return 1;
  }

  // Convert the value to the new unit
  double converted_value;
  switch (unit) {
    case UNIT_METERS:
      converted_value = meters_to_kilometers(value);
      printf("%f kilometers\n", converted_value);
      break;
    case UNIT_KILOMETERS:
      converted_value = kilometers_to_meters(value);
      printf("%f meters\n", converted_value);
      break;
    case UNIT_FEET:
      converted_value = feet_to_meters(value);
      printf("%f meters\n", converted_value);
      break;
    case UNIT_MILES:
      converted_value = meters_to_feet(value);
      printf("%f feet\n", converted_value);
      break;
    case UNIT_CELSIUS:
      converted_value = celsius_to_fahrenheit(value);
      printf("%f fahrenheit\n", converted_value);
      break;
    case UNIT_FAHRENHEIT:
      converted_value = fahrenheit_to_celsius(value);
      printf("%f celsius\n", converted_value);
      break;
    case UNIT_KELVIN:
      converted_value = kelvin_to_celsius(value);
      printf("%f celsius\n", converted_value);
      break;
  }

  return 0;
}