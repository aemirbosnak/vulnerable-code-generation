//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a date in natural language to a numerical format
void convertDate(char date[]) {
  char months[12][10] = {"January", "February", "March", "April", "May", "June", 
                         "July", "August", "September", "October", "November", "December"};
  int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  // Get the day, month, and year from the input string
  char *token;
  token = strtok(date, " ");
  char *day = token;
  token = strtok(NULL, " ");
  char *month = token;
  token = strtok(NULL, " ");
  char *year = token;
  
  // Convert the month name to its corresponding numerical value
  int i;
  for (i = 0; i < 12; i++) {
    if (strcmp(month, months[i]) == 0) {
      break;
    }
  }
  
  // Calculate the number of days since January 1st of the input year
  int days = atoi(day);
  for (int j = 0; j < i; j++) {
    days += monthDays[j];
  }
  if (i > 1) {
    // Account for leap years
    if (((atoi(year) % 4 == 0) && (atoi(year) % 100 != 0)) || (atoi(year) % 400 == 0)) {
      days++;
    }
  }
  
  // Print the result
  printf("\n%s %s %s converts to day %d of the year %s.\n", month, day, year, days, year);
}

int main() {
  printf("Welcome to my cheerful date converter!\n");
  char inputDate[25];
  printf("\nEnter a date in natural language format (e.g. June 16 2022): ");
  fgets(inputDate, sizeof(inputDate), stdin);
  inputDate[strcspn(inputDate, "\n")] = 0;  // Remove newline character
  
  convertDate(inputDate);
  
  return 0;
}