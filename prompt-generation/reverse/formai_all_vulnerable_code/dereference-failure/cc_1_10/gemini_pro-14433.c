//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
  char *name;
  double factor;
} unit_t;

unit_t units[] = {
  {"mm", 1.0},
  {"cm", 10.0},
  {"m", 1000.0},
  {"km", 1000000.0},
  {"in", 25.4},
  {"ft", 304.8},
  {"yd", 914.4},
  {"mi", 1609344.0},
  {"oz", 28.3495},
  {"lb", 453.592},
};

int main(int argc, char **argv) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
    return EXIT_FAILURE;
  }

  double value = atof(argv[1]);
  char *from_unit = argv[2];
  char *to_unit = argv[3];

  int from_unit_index = -1;
  int to_unit_index = -1;

  for (int i = 0; i < MAX_UNITS; i++) {
    if (strcmp(from_unit, units[i].name) == 0) {
      from_unit_index = i;
    } else if (strcmp(to_unit, units[i].name) == 0) {
      to_unit_index = i;
    }
  }

  if (from_unit_index == -1) {
    fprintf(stderr, "Invalid from unit: %s\n", from_unit);
    return EXIT_FAILURE;
  }

  if (to_unit_index == -1) {
    fprintf(stderr, "Invalid to unit: %s\n", to_unit);
    return EXIT_FAILURE;
  }

  double result = value * units[from_unit_index].factor / units[to_unit_index].factor;

  printf("%f %s = %f %s\n", value, from_unit, result, to_unit);

  return EXIT_SUCCESS;
}