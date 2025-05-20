//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the months of the year with their corresponding number of days
int month_length[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Function to check if the year is a leap year
int isLeapYear(int year) {
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Function to convert a date from YYYY-MM-DD format to DD/MM/YYYY format
char* convertDate(char* date) {
  // Extract the year, month, and day from the date string
  int year = atoi(strtok(date, "-"));
  int month = atoi(strtok(NULL, "-"));
  int day = atoi(strtok(NULL, "-"));

  // Check if the date is valid
  if (year < 1 || month < 1 || month > 12 || day < 1 || day > month_length[month - 1]) {
    return "Invalid date";
  }

  // Check if the year is a leap year and adjust the number of days in February accordingly
  if (isLeapYear(year) && month == 2) {
    month_length[1] = 29;
  }

  // Convert the date to DD/MM/YYYY format
  char* newDate = malloc(11);
  sprintf(newDate, "%02d/%02d/%04d", day, month, year);

  // Return the converted date
  return newDate;
}

// Main function
int main() {
  // Get the current date and time
  time_t t = time(NULL);
  struct tm* tm = localtime(&t);

  // Convert the current date to DD/MM/YYYY format using our function
  char* currentDate = convertDate(asctime(tm));

  // Print the converted date
  printf("Today's date in DD/MM/YYYY format is: %s\n", currentDate);

  // Free the memory allocated for the converted date
  free(currentDate);

  return 0;
}