//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the unit types
typedef enum {
  UNIT_METERS,
  UNIT_CENTIMETERS,
  UNIT_INCHES,
  UNIT_FEET,
  UNIT_YARDS,
  UNIT_MILES,
  UNIT_KILOMETERS
} unit_type;

// Define the conversion factors
static const double conversion_factors[] = {
  1.0,
  0.01,
  0.0254,
  0.3048,
  0.9144,
  1609.34,
  1000.0
};

// Print the usage information
static void print_usage() {
  printf("Usage: unit_converter <input_value> <input_unit> <output_unit>\n");
  printf("Where:\n");
  printf("  <input_value> is the value to be converted\n");
  printf("  <input_unit> is the unit of the input value\n");
  printf("  <output_unit> is the unit to which the value should be converted\n");
  printf("Available units:\n");
  printf("  m (meters)\n");
  printf("  cm (centimeters)\n");
  printf("  in (inches)\n");
  printf("  ft (feet)\n");
  printf("  yd (yards)\n");
  printf("  mi (miles)\n");
  printf("  km (kilometers)\n");
}

// Convert the input value from the input unit to the output unit
static double convert_unit(double input_value, unit_type input_unit, unit_type output_unit) {
  // Check if the input unit is valid
  if (input_unit < 0 || input_unit >= UNIT_KILOMETERS) {
    printf("Error: Invalid input unit\n");
    print_usage();
    exit(EXIT_FAILURE);
  }

  // Check if the output unit is valid
  if (output_unit < 0 || output_unit >= UNIT_KILOMETERS) {
    printf("Error: Invalid output unit\n");
    print_usage();
    exit(EXIT_FAILURE);
  }

  // Convert the input value to meters
  double meters = input_value * conversion_factors[input_unit];

  // Convert the meters to the output unit
  double output_value = meters / conversion_factors[output_unit];

  return output_value;
}

// Get the unit type from the string representation
static unit_type get_unit_type(char *unit_string) {
  if (strcmp(unit_string, "m") == 0) {
    return UNIT_METERS;
  } else if (strcmp(unit_string, "cm") == 0) {
    return UNIT_CENTIMETERS;
  } else if (strcmp(unit_string, "in") == 0) {
    return UNIT_INCHES;
  } else if (strcmp(unit_string, "ft") == 0) {
    return UNIT_FEET;
  } else if (strcmp(unit_string, "yd") == 0) {
    return UNIT_YARDS;
  } else if (strcmp(unit_string, "mi") == 0) {
    return UNIT_MILES;
  } else if (strcmp(unit_string, "km") == 0) {
    return UNIT_KILOMETERS;
  } else {
    printf("Error: Invalid unit string: %s\n", unit_string);
    print_usage();
    exit(EXIT_FAILURE);
  }
}

// Get the input value from the command line
static double get_input_value(char *input_string) {
  double input_value;
  if (sscanf(input_string, "%lf", &input_value) != 1) {
    printf("Error: Invalid input value: %s\n", input_string);
    print_usage();
    exit(EXIT_FAILURE);
  }
  return input_value;
}

int main(int argc, char *argv[]) {
  // Check if the correct number of arguments were provided
  if (argc != 4) {
    printf("Error: Incorrect number of arguments\n");
    print_usage();
    exit(EXIT_FAILURE);
  }

  // Get the input value, input unit, and output unit from the command line
  double input_value = get_input_value(argv[1]);
  unit_type input_unit = get_unit_type(argv[2]);
  unit_type output_unit = get_unit_type(argv[3]);

  // Convert the input value from the input unit to the output unit
  double output_value = convert_unit(input_value, input_unit, output_unit);

  // Print the output value
  printf("%f %s\n", output_value, argv[3]);

  return 0;
}