//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert month name to month number
int monthNumber(char *month){
  char *months[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
  int i;
  for (i = 0; i < 12; i++){
    if (strcmp(month, months[i]) == 0){
      return i + 1;
    }
  }
  return -1;
}

// Function to check if given year is a leap year
int isLeapYear(int year){
  return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

// Function to get number of days in a month
int getNumberOfDays(int year, int month){
  if (month == 2){
    return (isLeapYear(year) ? 29 : 28);
  }
  else if (month == 4 || month == 6 || month == 9 || month == 11){
    return 30;
  }
  else{
    return 31;
  }
}

int main(){
  char dateString[30];
  int day, month, year;
  printf("Enter date in natural language (e.g. August 18th, 2022): ");
  fgets(dateString, sizeof(dateString), stdin);

  char *monthString = strtok(dateString, " ");
  strtok(NULL, " ");
  char *dayString = strtok(NULL, ",");
  strtok(NULL, " ");
  char *yearString = strtok(NULL, "\n");

  // Convert month string to month number
  month = monthNumber(monthString);

  // Convert day string to integer
  dayString[strlen(dayString)-2] = '\0';
  day = atoi(dayString);

  // Convert year string to integer
  year = atoi(yearString);

  // Get number of days in given month and year
  int numberOfDays = getNumberOfDays(year, month);

  // Check if given date is valid
  if (month < 1 || month > 12){
    printf("Invalid month\n");
    return 0;
  }
  else if (day < 1 || day > numberOfDays){
    printf("Invalid day\n");
    return 0;
  }
  else if (year < 1 || year > 9999){
    printf("Invalid year\n");
    return 0;
  }

  printf("The date entered in C-style format is: %02d/%02d/%d\n", month, day, year);

  return 0;
}