//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the date
typedef struct {
  int year;
  int month;
  int day;
} Date;

// Define the function to convert a string to a date
Date string_to_date(char *string) {
  Date date;

  // Get the year
  date.year = atoi(strtok(string, "-"));

  // Get the month
  date.month = atoi(strtok(NULL, "-"));

  // Get the day
  date.day = atoi(strtok(NULL, "-"));

  return date;
}

// Define the function to convert a date to a string
char *date_to_string(Date date) {
  char *string = malloc(11);

  // Convert the year to a string
  sprintf(string, "%d", date.year);

  // Convert the month to a string
  sprintf(string + 4, "-%02d", date.month);

  // Convert the day to a string
  sprintf(string + 7, "-%02d", date.day);

  return string;
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the user has provided a date
  if (argc < 2) {
    printf("Please provide a date in the format YYYY-MM-DD.\n");
    return 1;
  }

  // Convert the date to a string
  Date date = string_to_date(argv[1]);

  // Print the date
  printf("The date is %s.\n", date_to_string(date));

  return 0;
}