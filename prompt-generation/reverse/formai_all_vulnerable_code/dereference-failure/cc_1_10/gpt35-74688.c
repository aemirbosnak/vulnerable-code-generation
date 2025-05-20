//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t current_time;
  struct tm * current_tm;
  int years_to_travel, selection;
  char choice;

  // Get and print current time
  current_time = time(NULL);
  current_tm = localtime(&current_time);
  printf("Current Date and Time: %s", asctime(current_tm));

  // Request user input for years to travel
  printf("How many years into the future would you like to travel?\n");
  scanf("%d", &years_to_travel);

  // Add years to current time
  current_tm->tm_year += years_to_travel;
  current_time = mktime(current_tm);

  // Print future time
  printf("Future Date and Time: %s", asctime(localtime(&current_time)));

  // Ask user if they want to see more options
  printf("Would you like to see more options? (y or n)\n");
  scanf(" %c", &choice);

  // Continue to show options until user chooses to exit
  while (choice == 'y') {
    printf("\n1. Travel to a specific year\n");
    printf("2. Travel to a specific month and year\n");
    printf("3. Exit\n");
    scanf("%d", &selection);

    if (selection == 1) {
      int year;
      printf("Enter the year you would like to travel to:\n");
      scanf("%d", &year);
      current_tm->tm_year = year-1900; // tm_year is years since 1900
      current_time = mktime(current_tm);
      printf("Date and Time in %d: %s", year, asctime(localtime(&current_time)));
    }
    else if (selection == 2) {
      int year, month;
      printf("Enter the month (1-12) and year you would like to travel to:\n");
      scanf("%d%d", &month, &year);
      current_tm->tm_mon = month-1; // tm_mon is 0-11, January is 0
      current_tm->tm_year = year-1900;
      current_time = mktime(current_tm);
      printf("Date and Time in %d/%d: %s", month, year, asctime(localtime(&current_time)));
    }
    else if (selection == 3) {
      printf("Thank you for using the Time Travel Simulator!\n");
      return 0;
    }
    else {
      printf("Please enter a valid option.\n");
    }

    // Ask user if they want to see more options
    printf("Would you like to see more options? (y or n)\n");
    scanf(" %c", &choice);
  }

  printf("Thank you for using the Time Travel Simulator!\n");
  return 0;
}