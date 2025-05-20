//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
// In the desolate wasteland of the post-apocalypse, where rubble and anguish dance,
// a solitary scavenger scours for sustenance, armed with naught but a trusty C compiler.

#include <stdio.h>
#include <string.h>

typedef enum UnitType {
  POUNDS,
  OUNCES,
  POUNDS_PER_SQUARE_INCH,
  KILOPASCALS,
  GALLONS,
  LITERS
} UnitType;

struct Unit {
  UnitType type;
  char *singular;
  char *plural;
  double conversion_factor;
};

const struct Unit units[] = {
  { .type = POUNDS,   .singular = "pound",   .plural = "pounds",   .conversion_factor = 1.0 },
  { .type = OUNCES,   .singular = "ounce",   .plural = "ounces",   .conversion_factor = 0.0625 },
  { .type = POUNDS_PER_SQUARE_INCH, .singular = "psi",       .plural = "psi",       .conversion_factor = 6894.757 },
  { .type = KILOPASCALS,  .singular = "kPa",      .plural = "kPa",      .conversion_factor = 1.0 },
  { .type = GALLONS,   .singular = "gallon",  .plural = "gallons",  .conversion_factor = 3.785412 },
  { .type = LITERS,    .singular = "liter",   .plural = "liters",   .conversion_factor = 1.0 }
};

void print_conversion(const char *input, const struct Unit *from, const struct Unit *to) {
  double value = atof(input);
  printf("Converting %f %s to %s: %.6f\n", value, from->plural, to->plural, value * from->conversion_factor / to->conversion_factor);
}

int main(int argc, char **argv) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
    return 1;
  }

  const char *input = argv[1];
  const char *from_unit_str = argv[2];
  const char *to_unit_str = argv[3];

  const struct Unit *from_unit = NULL;
  const struct Unit *to_unit = NULL;

  for (int i = 0; i < sizeof(units) / sizeof(*units); i++) {
    if (strcmp(units[i].singular, from_unit_str) == 0 || strcmp(units[i].plural, from_unit_str) == 0) {
      from_unit = &units[i];
    }

    if (strcmp(units[i].singular, to_unit_str) == 0 || strcmp(units[i].plural, to_unit_str) == 0) {
      to_unit = &units[i];
    }
  }

  if (from_unit == NULL || to_unit == NULL) {
    fprintf(stderr, "Invalid unit(s): %s, %s\n", from_unit_str, to_unit_str);
    return 1;
  }

  print_conversion(input, from_unit, to_unit);

  return 0;
}