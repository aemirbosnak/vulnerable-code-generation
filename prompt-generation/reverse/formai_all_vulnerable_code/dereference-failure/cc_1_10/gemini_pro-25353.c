//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  METRIC,
  IMPERIAL
} UnitSystem;

typedef enum {
  LENGTH,
  VOLUME,
  TEMPERATURE
} UnitType;

typedef struct {
  char *name;
  UnitSystem system;
  UnitType type;
  double factor;
} Unit;

Unit units[] = {
  { "meter", METRIC, LENGTH, 1.0 },
  { "kilometer", METRIC, LENGTH, 1000.0 },
  { "inch", IMPERIAL, LENGTH, 2.54 },
  { "foot", IMPERIAL, LENGTH, 30.48 },
  { "yard", IMPERIAL, LENGTH, 91.44 },
  { "liter", METRIC, VOLUME, 1.0 },
  { "gallon", IMPERIAL, VOLUME, 3.78541 },
  { "cup", IMPERIAL, VOLUME, 0.236588 },
  { "celsius", METRIC, TEMPERATURE, 0.0 },
  { "fahrenheit", IMPERIAL, TEMPERATURE, 32.0 }
};

double convert(double value, Unit from, Unit to) {
  if (from.system != to.system) {
    printf("Error: cannot convert between different unit systems.\n");
    exit(EXIT_FAILURE);
  }

  if (from.type != to.type) {
    printf("Error: cannot convert between different unit types.\n");
    exit(EXIT_FAILURE);
  }

  return value * from.factor / to.factor;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s value from to\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  double value = atof(argv[1]);
  char *from_name = argv[2];
  char *to_name = argv[3];

  Unit from = { NULL, METRIC, LENGTH, 0.0 };
  Unit to = { NULL, IMPERIAL, LENGTH, 0.0 };

  for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
    if (strcmp(from_name, units[i].name) == 0) {
      from = units[i];
    }

    if (strcmp(to_name, units[i].name) == 0) {
      to = units[i];
    }
  }

  if (from.name == NULL || to.name == NULL) {
    printf("Error: invalid unit name.\n");
    exit(EXIT_FAILURE);
  }

  double result = convert(value, from, to);

  printf("%f %s is equal to %f %s\n", value, from.name, result, to.name);

  return EXIT_SUCCESS;
}