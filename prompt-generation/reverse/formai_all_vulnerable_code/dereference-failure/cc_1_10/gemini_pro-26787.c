//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a date from MM/DD/YYYY to YYYYMMDD
int convertDate(char *date) {
  int year, month, day;
  char *token;

  // Parse the date string
  token = strtok(date, "/");
  month = atoi(token);
  token = strtok(NULL, "/");
  day = atoi(token);
  token = strtok(NULL, "/");
  year = atoi(token);

  // Convert the date to YYYYMMDD format
  return (year * 10000) + (month * 100) + day;
}

// Function to print the date in MM/DD/YYYY format
void printDate(int date) {
  int year, month, day;

  // Extract the year, month, and day from the date
  year = date / 10000;
  month = (date % 10000) / 100;
  day = date % 100;

  // Print the date in MM/DD/YYYY format
  printf("%02d/%02d/%04d\n", month, day, year);
}

int main() {
  char date[11];
  int convertedDate;

  // Get the date from the user
  printf("Enter a date in MM/DD/YYYY format: ");
  scanf("%s", date);

  // Convert the date to YYYYMMDD format
  convertedDate = convertDate(date);

  // Print the converted date
  printf("The converted date is: ");
  printDate(convertedDate);

  return 0;
}