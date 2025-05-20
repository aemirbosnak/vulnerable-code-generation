//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the unit conversion functions
double inches_to_centimeters(double inches) {
  return inches * 2.54;
}

double centimeters_to_inches(double centimeters) {
  return centimeters / 2.54;
}

double pounds_to_kilograms(double pounds) {
  return pounds * 0.453592;
}

double kilograms_to_pounds(double kilograms) {
  return kilograms / 0.453592;
}

double fahrenheit_to_celsius(double fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

double celsius_to_fahrenheit(double celsius) {
  return (celsius * 9 / 5) + 32;
}

// Define the unit conversion table
struct unit_conversion {
  char *name;
  double (*convert_to_base)(double);
  double (*convert_from_base)(double);
};

struct unit_conversion unit_conversions[] = {
  { "inches", inches_to_centimeters, centimeters_to_inches },
  { "centimeters", centimeters_to_inches, inches_to_centimeters },
  { "pounds", pounds_to_kilograms, kilograms_to_pounds },
  { "kilograms", kilograms_to_pounds, pounds_to_kilograms },
  { "fahrenheit", fahrenheit_to_celsius, celsius_to_fahrenheit },
  { "celsius", celsius_to_fahrenheit, fahrenheit_to_celsius }
};

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the user provided enough arguments
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <value> <unit>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the value and unit from the command line
  double value = atof(argv[1]);
  char *unit = argv[2];

  // Find the unit conversion in the table
  struct unit_conversion *conversion = NULL;
  for (int i = 0; i < sizeof(unit_conversions) / sizeof(struct unit_conversion); i++) {
    if (strcmp(unit, unit_conversions[i].name) == 0) {
      conversion = &unit_conversions[i];
      break;
    }
  }

  // Check if the unit was found
  if (conversion == NULL) {
    fprintf(stderr, "Error: Invalid unit '%s'\n", unit);
    return EXIT_FAILURE;
  }

  // Convert the value to the base unit
  double base_value = conversion->convert_to_base(value);

  // Convert the value to all other units
  for (int i = 0; i < sizeof(unit_conversions) / sizeof(struct unit_conversion); i++) {
    if (unit_conversions[i].name != unit) {
      printf("%f %s = %f %s\n", value, unit, unit_conversions[i].convert_from_base(base_value), unit_conversions[i].name);
    }
  }

  return EXIT_SUCCESS;
}