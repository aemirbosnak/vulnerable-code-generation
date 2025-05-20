//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the supported date formats.
#define DATE_FORMAT_1 "dd/mm/yyyy"
#define DATE_FORMAT_2 "yyyy-mm-dd"

// Define the supported date components.
#define DATE_COMPONENT_DAY 1
#define DATE_COMPONENT_MONTH 2
#define DATE_COMPONENT_YEAR 3

// Define the number of days in each month.
int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Define the names of the months.
char *monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Convert a date from one format to another.
char *convertDate(char *date, char *srcFormat, char *destFormat) {
  // Check if the input date is valid.
  if (strlen(date) != 10 || date[2] != '/' || date[5] != '/' || srcFormat == NULL || destFormat == NULL) {
    return NULL;
  }

  // Parse the input date.
  int day = atoi(date);
  int month = atoi(date + 3);
  int year = atoi(date + 6);

  // Convert the date to the destination format.
  char *newDate = malloc(11);
  if (newDate == NULL) {
    return NULL;
  }

  if (strcmp(destFormat, DATE_FORMAT_1) == 0) {
    sprintf(newDate, "%02d/%02d/%04d", day, month, year);
  } else if (strcmp(destFormat, DATE_FORMAT_2) == 0) {
    sprintf(newDate, "%04d-%02d-%02d", year, month, day);
  } else {
    free(newDate);
    return NULL;
  }

  return newDate;
}

// Print the usage information.
void printUsage() {
  printf("Usage: dateConverter <date> <srcFormat> <destFormat>\n");
  printf("Supported date formats:\n");
  printf(" - %s\n", DATE_FORMAT_1);
  printf(" - %s\n", DATE_FORMAT_2);
}

// Main function.
int main(int argc, char **argv) {
  // Check if the number of arguments is valid.
  if (argc != 4) {
    printUsage();
    return 1;
  }

  // Convert the date.
  char *newDate = convertDate(argv[1], argv[2], argv[3]);
  if (newDate == NULL) {
    printf("Error: Invalid date or format.\n");
    return 1;
  }

  // Print the converted date.
  printf("Converted date: %s\n", newDate);

  free(newDate);
  return 0;
}