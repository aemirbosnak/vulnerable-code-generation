//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TEMP_LEN 10

void print_usage(char *argv[]) {
  printf("Usage: %s [OPTION]... [TEMPERATURE]...\n\n", argv[0]);
  printf("  -c, --celsius      convert to Celsius\n");
  printf("  -f, --fahrenheit    convert to Fahrenheit\n");
  printf("  -h, --help         display this help\n\n");
}

int main(int argc, char *argv[]) {
  int c_flag = 0;
  int f_flag = 0;
  int i;

  // parse command-line options
  for (i = 1; i < argc; i++) {
    if (!strcmp(argv[i], "-c") || !strcmp(argv[i], "--celsius")) {
      c_flag = 1;
    } else if (!strcmp(argv[i], "-f") || !strcmp(argv[i], "--fahrenheit")) {
      f_flag = 1;
    } else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
      print_usage(argv);
      return EXIT_SUCCESS;
    } else {
      // invalid option
      fprintf(stderr, "Invalid option: %s\n", argv[i]);
      print_usage(argv);
      return EXIT_FAILURE;
    }
  }

  // check if both flags are set
  if (c_flag && f_flag) {
    fprintf(stderr, "Error: cannot specify both Celsius and Fahrenheit flags\n");
    return EXIT_FAILURE;
  }

  // check if no flags are set
  if (!c_flag && !f_flag) {
    fprintf(stderr, "Error: must specify either Celsius (-c) or Fahrenheit (-f) flag\n");
    return EXIT_FAILURE;
  }

  // convert temperatures
  for (i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      // skip options
      continue;
    }

    char *endptr;
    double temp = strtod(argv[i], &endptr);

    if (*endptr != '\0') {
      // invalid temperature
      fprintf(stderr, "Error: invalid temperature: %s\n", argv[i]);
      return EXIT_FAILURE;
    }

    if (c_flag) {
      // convert to Celsius
      double celsius = temp - 32.0 * 5.0 / 9.0;
      printf("%.2f°C\n", celsius);
    } else {
      // convert to Fahrenheit
      double fahrenheit = temp + 32.0 * 9.0 / 5.0;
      printf("%.2f°F\n", fahrenheit);
    }
  }

  return EXIT_SUCCESS;
}