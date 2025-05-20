//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name;
  double (*convert)(double);
} Unit;

double convert_celsius_to_fahrenheit(double celsius) {
  return celsius * 9 / 5 + 32;
}

double convert_fahrenheit_to_celsius(double fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

double convert_meters_to_feet(double meters) {
  return meters * 3.28084;
}

double convert_feet_to_meters(double feet) {
  return feet / 3.28084;
}

double convert_kilograms_to_pounds(double kilograms) {
  return kilograms * 2.20462;
}

double convert_pounds_to_kilograms(double pounds) {
  return pounds / 2.20462;
}

Unit units[] = {
  { "Celsius", convert_celsius_to_fahrenheit },
  { "Fahrenheit", convert_fahrenheit_to_celsius },
  { "Meters", convert_meters_to_feet },
  { "Feet", convert_feet_to_meters },
  { "Kilograms", convert_kilograms_to_pounds },
  { "Pounds", convert_pounds_to_kilograms },
};

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
    return EXIT_FAILURE;
  }

  double value = atof(argv[1]);
  char *from_unit = argv[2];
  char *to_unit = argv[3];

  Unit *from = NULL;
  Unit *to = NULL;

  for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
    if (strcmp(units[i].name, from_unit) == 0) {
      from = &units[i];
    }
    if (strcmp(units[i].name, to_unit) == 0) {
      to = &units[i];
    }
  }

  if (from == NULL || to == NULL) {
    fprintf(stderr, "Invalid unit: %s or %s\n", from_unit, to_unit);
    return EXIT_FAILURE;
  }

  double result = from->convert(value);
  result = to->convert(result);
  
  printf("%f %s is equivalent to %f %s\n", value, from_unit, result, to_unit);

  return EXIT_SUCCESS;
}