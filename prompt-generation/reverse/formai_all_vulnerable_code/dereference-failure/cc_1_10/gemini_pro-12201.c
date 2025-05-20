//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YEAR_LEN 4
#define MONTH_LEN 2
#define DAY_LEN 2
#define DATE_LEN (YEAR_LEN + MONTH_LEN + DAY_LEN)

int main(int argc, char **argv) {
  int year, month, day;
  char date[DATE_LEN + 1];

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <YYYYMMDD>\n", argv[0]);
    return EXIT_FAILURE;
  }

  if (strlen(argv[1]) != DATE_LEN) {
    fprintf(stderr, "Error: Invalid date format. Must be YYYYMMDD.\n");
    return EXIT_FAILURE;
  }

  // Extract year, month, and day from the input string.
  strncpy(date, argv[1], DATE_LEN);
  date[DATE_LEN] = '\0'; // Null-terminate the string.

  year = atoi(date);
  month = atoi(date + YEAR_LEN);
  day = atoi(date + YEAR_LEN + MONTH_LEN);

  // Validate the date.
  if (year < 1900 || year > 2100) {
    fprintf(stderr, "Error: Invalid year. Must be between 1900 and 2100.\n");
    return EXIT_FAILURE;
  }
  if (month < 1 || month > 12) {
    fprintf(stderr, "Error: Invalid month. Must be between 1 and 12.\n");
    return EXIT_FAILURE;
  }
  if (day < 1 || day > 31) {
    fprintf(stderr, "Error: Invalid day. Must be between 1 and 31.\n");
    return EXIT_FAILURE;
  }

  // Print the date in a human-readable format.
  printf("%d-%02d-%02d\n", year, month, day);

  return EXIT_SUCCESS;
}