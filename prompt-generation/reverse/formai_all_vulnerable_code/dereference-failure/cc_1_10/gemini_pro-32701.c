//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
#define INCHES_TO_CENTIMETERS 2.54
#define CENTIMETERS_TO_INCHES 0.393701
#define POUNDS_TO_KILOGRAMS 0.453592
#define KILOGRAMS_TO_POUNDS 2.20462
#define MILES_TO_KILOMETERS 1.60934
#define KILOMETERS_TO_MILES 0.621371

// Define the unit types
typedef enum {
  INCHES,
  CENTIMETERS,
  POUNDS,
  KILOGRAMS,
  MILES,
  KILOMETERS
} unit_type;

// Define the unit names
static const char *unit_names[] = {
  "inches",
  "centimeters",
  "pounds",
  "kilograms",
  "miles",
  "kilometers"
};

// Convert a value from one unit to another
double convert(double value, unit_type from, unit_type to) {
  switch (from) {
    case INCHES:
      switch (to) {
        case INCHES:
          return value;
        case CENTIMETERS:
          return value * INCHES_TO_CENTIMETERS;
        default:
          return -1;
      }
    case CENTIMETERS:
      switch (to) {
        case INCHES:
          return value * CENTIMETERS_TO_INCHES;
        case CENTIMETERS:
          return value;
        default:
          return -1;
      }
    case POUNDS:
      switch (to) {
        case POUNDS:
          return value;
        case KILOGRAMS:
          return value * POUNDS_TO_KILOGRAMS;
        default:
          return -1;
      }
    case KILOGRAMS:
      switch (to) {
        case POUNDS:
          return value * KILOGRAMS_TO_POUNDS;
        case KILOGRAMS:
          return value;
        default:
          return -1;
      }
    case MILES:
      switch (to) {
        case MILES:
          return value;
        case KILOMETERS:
          return value * MILES_TO_KILOMETERS;
        default:
          return -1;
      }
    case KILOMETERS:
      switch (to) {
        case MILES:
          return value * KILOMETERS_TO_MILES;
        case KILOMETERS:
          return value;
        default:
          return -1;
      }
    default:
      return -1;
  }
}

// Print a usage message
void usage() {
  printf("Usage: unit_converter <value> <from_unit> <to_unit>\n");
  printf("Example: unit_converter 100 inches centimeters\n");
  printf("Valid units:\n");
  for (int i = 0; i < 6; i++) {
    printf("  %s\n", unit_names[i]);
  }
}

// Main function
int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc != 4) {
    usage();
    return 1;
  }

  // Parse the arguments
  double value = atof(argv[1]);
  unit_type from = -1;
  unit_type to = -1;
  for (int i = 0; i < 6; i++) {
    if (strcmp(argv[2], unit_names[i]) == 0) {
      from = i;
    }
    if (strcmp(argv[3], unit_names[i]) == 0) {
      to = i;
    }
  }

  // Check the unit types
  if (from == -1 || to == -1) {
    usage();
    return 1;
  }

  // Convert the value
  double result = convert(value, from, to);

  // Print the result
  printf("%.2f %s is %.2f %s\n", value, unit_names[from], result, unit_names[to]);

  return 0;
}