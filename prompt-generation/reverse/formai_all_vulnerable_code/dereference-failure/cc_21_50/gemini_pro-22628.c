//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the conversion factors
#define CM_TO_INCH 0.393701
#define INCH_TO_CM 2.54
#define KG_TO_LB 2.20462
#define LB_TO_KG 0.453592
#define CELSIUS_TO_FAHRENHEIT 1.8
#define FAHRENHEIT_TO_CELSIUS 0.555556

// Define the unit types
typedef enum {
  CM,
  INCH,
  KG,
  LB,
  CELSIUS,
  FAHRENHEIT
} unit_type;

// Define the unit names
const char *unit_names[] = {
  "cm",
  "inch",
  "kg",
  "lb",
  "celsius",
  "fahrenheit"
};

// Define the conversion function
double convert(double value, unit_type from_unit, unit_type to_unit) {
  switch (from_unit) {
    case CM:
      switch (to_unit) {
        case INCH:
          return value * CM_TO_INCH;
        case KG:
        case LB:
        case CELSIUS:
        case FAHRENHEIT:
          return value;  // No conversion needed
      }
    case INCH:
      switch (to_unit) {
        case CM:
          return value * INCH_TO_CM;
        case KG:
        case LB:
        case CELSIUS:
        case FAHRENHEIT:
          return value;  // No conversion needed
      }
    case KG:
      switch (to_unit) {
        case LB:
          return value * KG_TO_LB;
        case CM:
        case INCH:
        case CELSIUS:
        case FAHRENHEIT:
          return value;  // No conversion needed
      }
    case LB:
      switch (to_unit) {
        case KG:
          return value * LB_TO_KG;
        case CM:
        case INCH:
        case CELSIUS:
        case FAHRENHEIT:
          return value;  // No conversion needed
      }
    case CELSIUS:
      switch (to_unit) {
        case FAHRENHEIT:
          return value * CELSIUS_TO_FAHRENHEIT;
        case CM:
        case INCH:
        case KG:
        case LB:
          return value;  // No conversion needed
      }
    case FAHRENHEIT:
      switch (to_unit) {
        case CELSIUS:
          return value * FAHRENHEIT_TO_CELSIUS;
        case CM:
        case INCH:
        case KG:
        case LB:
          return value;  // No conversion needed
      }
  }

  return 0;  // Should never reach here
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the number of arguments is correct
  if (argc != 4) {
    printf("Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
    return 1;
  }

  // Get the arguments
  double value = atof(argv[1]);
  unit_type from_unit = -1;
  unit_type to_unit = -1;

  // Parse the unit types
  for (int i = 0; i < sizeof(unit_names) / sizeof(char *); i++) {
    if (strcmp(argv[2], unit_names[i]) == 0) {
      from_unit = i;
    }
    if (strcmp(argv[3], unit_names[i]) == 0) {
      to_unit = i;
    }
  }

  // Check if the unit types are valid
  if (from_unit == -1 || to_unit == -1) {
    printf("Invalid unit type\n");
    return 1;
  }

  // Convert the value
  double converted_value = convert(value, from_unit, to_unit);

  // Print the result
  printf("%f %s = %f %s\n", value, unit_names[from_unit], converted_value, unit_names[to_unit]);

  return 0;
}