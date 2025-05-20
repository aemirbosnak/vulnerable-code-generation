//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define UNITS 5

typedef struct {
  char *name;
  double factor;
} unit_t;

unit_t units[] = {
  {"meters", 1.0},
  {"kilometers", 1000.0},
  {"inches", 25.4},
  {"feet", 304.8},
  {"miles", 1609.34}
};

typedef struct {
  double value;
  int from;
  int to;
} conversion_t;

void *convert(void *arg) {
  conversion_t *conv = (conversion_t *)arg;
  conv->value = conv->value * units[conv->from].factor / units[conv->to].factor;
  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s value from to\n", argv[0]);
    return EXIT_FAILURE;
  }

  double value = atof(argv[1]);
  int from = -1;
  int to = -1;
  for (int i = 0; i < UNITS; i++) {
    if (strcmp(argv[2], units[i].name) == 0) {
      from = i;
    }
    if (strcmp(argv[3], units[i].name) == 0) {
      to = i;
    }
  }

  if (from == -1 || to == -1) {
    fprintf(stderr, "Invalid unit(s): %s, %s\n", argv[2], argv[3]);
    return EXIT_FAILURE;
  }

  conversion_t conv = {
    .value = value,
    .from = from,
    .to = to
  };

  pthread_t thread;
  pthread_create(&thread, NULL, convert, &conv);
  pthread_join(thread, NULL);

  printf("%f %s = %f %s\n", value, units[from].name, conv.value, units[to].name);

  return EXIT_SUCCESS;
}