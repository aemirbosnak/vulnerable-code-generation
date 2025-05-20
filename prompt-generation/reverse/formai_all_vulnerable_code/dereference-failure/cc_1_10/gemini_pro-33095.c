//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Declare the days of the week and months of the year as strings
char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Declare the function to convert a date from the format dd/mm/yyyy to the format yyyy-mm-dd
char *convertDate(char *date)
{
  // Allocate memory for the new date string
  char *newDate = malloc(11);

  // Copy the year from the old date string to the new date string
  strncpy(newDate, date + 6, 4);

  // Add a hyphen to the new date string
  newDate[4] = '-';

  // Copy the month from the old date string to the new date string
  strncpy(newDate + 5, date + 3, 2);

  // Add a hyphen to the new date string
  newDate[7] = '-';

  // Copy the day from the old date string to the new date string
  strncpy(newDate + 8, date, 2);

  // Return the new date string
  return newDate;
}

// Declare the function to print the current date and time
void printDateTime()
{
  // Get the current time
  time_t t = time(NULL);

  // Convert the current time to a string
  char *timeString = ctime(&t);

  // Print the current date and time
  printf("Current date and time: %s\n", timeString);
}

// Declare the main function
int main()
{
  // Print a greeting
  printf("Welcome to the date converter!\n");

  // Get the date from the user
  char date[11];
  printf("Enter a date in the format dd/mm/yyyy: ");
  scanf("%s", date);

  // Convert the date from the format dd/mm/yyyy to the format yyyy-mm-dd
  char *newDate = convertDate(date);

  // Print the converted date
  printf("Converted date: %s\n", newDate);

  // Print the current date and time
  printDateTime();

  // Free the memory allocated for the new date string
  free(newDate);

  return 0;
}