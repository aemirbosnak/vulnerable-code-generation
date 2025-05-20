//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  INVALID_UNIT,
  METERS,
  KILOMETERS,
  CENTIMETERS,
  INCHES,
  FEET,
  YARDS,
  MILES
} unit_t;

typedef struct {
  char *name;
  double factor;
} unit_info_t;

unit_info_t unit_infos[] = {
  {"meters", 1.0},
  {"kilometers", 1000.0},
  {"centimeters", 0.01},
  {"inches", 0.0254},
  {"feet", 0.3048},
  {"yards", 0.9144},
  {"miles", 1609.34}
};

const int num_units = sizeof(unit_infos) / sizeof(unit_infos[0]);

unit_t get_unit(const char *unit_name) {
  for (int i = 0; i < num_units; i++) {
    if (strcmp(unit_name, unit_infos[i].name) == 0) {
      return i;
    }
  }

  return INVALID_UNIT;
}

double convert_unit(double value, unit_t from_unit, unit_t to_unit) {
  if (from_unit == INVALID_UNIT || to_unit == INVALID_UNIT) {
    return -1.0;
  }

  return value * unit_infos[from_unit].factor / unit_infos[to_unit].factor;
}

int main(int argc, char **argv) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
    return EXIT_FAILURE;
  }

  double value = atof(argv[1]);
  unit_t from_unit = get_unit(argv[2]);
  unit_t to_unit = get_unit(argv[3]);

  double converted_value = convert_unit(value, from_unit, to_unit);
  if (converted_value < 0.0) {
    fprintf(stderr, "Invalid unit conversion\n");
    return EXIT_FAILURE;
  }

  printf("%f %s = %f %s\n", value, unit_infos[from_unit].name, converted_value, unit_infos[to_unit].name);

  return EXIT_SUCCESS;
}