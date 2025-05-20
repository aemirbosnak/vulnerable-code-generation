//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  char *name;
  double multiplier;
} unit_type;

unit_type units[] = {
  {"m", 1.0},
  {"km", 1000.0},
  {"cm", 0.01},
  {"mm", 0.001},
  {"in", 0.0254},
  {"ft", 0.3048},
  {"yd", 0.9144},
  {"mile", 1609.344},
  {"lb", 0.453592},
  {"kg", 1.0},
  {"g", 0.001},
  {"oz", 0.0283495},
  {"C", 1.0},
  {"F", 1.8},
  {"K", 1.0},
  {NULL, 0.0}
};

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "usage: %s number unit1 [unit2]\n", argv[0]);
    return EXIT_FAILURE;
  }

  double value = atof(argv[1]);
  char *unit1 = argv[2];
  char *unit2 = argv[3];

  unit_type *u1 = NULL;
  unit_type *u2 = NULL;

  for (int i = 0; units[i].name != NULL; i++) {
    if (strcmp(unit1, units[i].name) == 0) {
      u1 = &units[i];
    } else if (strcmp(unit2, units[i].name) == 0) {
      u2 = &units[i];
    }
  }

  if (u1 == NULL) {
    fprintf(stderr, "invalid unit: %s\n", unit1);
    return EXIT_FAILURE;
  }

  if (u2 == NULL) {
    fprintf(stderr, "invalid unit: %s\n", unit2);
    return EXIT_FAILURE;
  }

  double converted_value = value * u1->multiplier / u2->multiplier;

  printf("%f %s = %f %s\n", value, unit1, converted_value, unit2);

  return EXIT_SUCCESS;
}