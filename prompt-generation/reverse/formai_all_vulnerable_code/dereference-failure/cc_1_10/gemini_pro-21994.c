//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the months of the year
char *months[] = {"January", "February", "March", "April", "May", "June",
                   "July", "August", "September", "October", "November", "December"};

// Define the days of the week
char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define the number of days in each month
int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Function to convert a date from the format "dd/mm/yyyy" to the format "yyyy-mm-dd"
char *convertDate(char *date) {
  // Allocate memory for the new date string
  char *newDate = malloc(11 * sizeof(char));

  // Copy the year from the old date string to the new date string
  strncpy(newDate, date + 6, 4);

  // Copy the month from the old date string to the new date string
  strncpy(newDate + 4, date + 3, 2);

  // Copy the day from the old date string to the new date string
  strncpy(newDate + 6, date, 2);

  // Return the new date string
  return newDate;
}

// Function to get the day of the week for a given date
char *getDayOfWeek(char *date) {
  // Convert the date to the format "yyyy-mm-dd"
  char *newDate = convertDate(date);

  // Create a tm struct to store the date and time
  struct tm tm;

  // Set the tm struct to the date and time
  strptime(newDate, "%Y-%m-%d", &tm);

  // Get the day of the week from the tm struct
  int dayOfWeek = tm.tm_wday;

  // Return the day of the week
  return days[dayOfWeek];
}

// Function to get the number of days between two dates
int getDaysBetweenDates(char *date1, char *date2) {
  // Convert the dates to the format "yyyy-mm-dd"
  char *newDate1 = convertDate(date1);
  char *newDate2 = convertDate(date2);

  // Create two tm structs to store the dates and times
  struct tm tm1;
  struct tm tm2;

  // Set the tm structs to the dates and times
  strptime(newDate1, "%Y-%m-%d", &tm1);
  strptime(newDate2, "%Y-%m-%d", &tm2);

  // Calculate the number of days between the two dates
  int daysBetweenDates = difftime(mktime(&tm2), mktime(&tm1)) / (60 * 60 * 24);

  // Return the number of days between the two dates
  return daysBetweenDates;
}

// Function to get the next date
char *getNextDate(char *date) {
  // Convert the date to the format "yyyy-mm-dd"
  char *newDate = convertDate(date);

  // Create a tm struct to store the date and time
  struct tm tm;

  // Set the tm struct to the date and time
  strptime(newDate, "%Y-%m-%d", &tm);

  // Add one day to the tm struct
  tm.tm_mday++;

  // Convert the tm struct back to a date string
  char *nextDate = malloc(11 * sizeof(char));
  strftime(nextDate, 11, "%Y-%m-%d", &tm);

  // Return the next date
  return nextDate;
}

// Function to get the previous date
char *getPreviousDate(char *date) {
  // Convert the date to the format "yyyy-mm-dd"
  char *newDate = convertDate(date);

  // Create a tm struct to store the date and time
  struct tm tm;

  // Set the tm struct to the date and time
  strptime(newDate, "%Y-%m-%d", &tm);

  // Subtract one day from the tm struct
  tm.tm_mday--;

  // Convert the tm struct back to a date string
  char *previousDate = malloc(11 * sizeof(char));
  strftime(previousDate, 11, "%Y-%m-%d", &tm);

  // Return the previous date
  return previousDate;
}

// Function to test the date converter
int main() {
  // Create a date string
  char *date = "15/03/2023";

  // Convert the date to the format "yyyy-mm-dd"
  char *newDate = convertDate(date);

  // Print the new date
  printf("New date: %s\n", newDate);

  // Get the day of the week for the new date
  char *dayOfWeek = getDayOfWeek(newDate);

  // Print the day of the week
  printf("Day of the week: %s\n", dayOfWeek);

  // Get the number of days between the new date and today
  int daysBetweenDates = getDaysBetweenDates(newDate, "2023-03-17");

  // Print the number of days between the two dates
  printf("Days between dates: %d\n", daysBetweenDates);

  // Get the next date
  char *nextDate = getNextDate(newDate);

  // Print the next date
  printf("Next date: %s\n", nextDate);

  // Get the previous date
  char *previousDate = getPreviousDate(newDate);

  // Print the previous date
  printf("Previous date: %s\n", previousDate);

  // Free the allocated memory
  free(newDate);
  free(nextDate);
  free(previousDate);

  return 0;
}