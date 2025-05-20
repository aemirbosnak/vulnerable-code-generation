//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdlib.h>
#include <stdio.h>

// Define the number of days in each month
int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Define the names of the months
char *monthNames[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};

// Get the number of days in a month
int getDaysInMonth(int month, int year) {
  if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
    return 29;
  } else {
    return daysInMonth[month];
  }
}

// Get the name of a month
char *getMonthName(int month) {
  return monthNames[month];
}

// Convert a date from the format "dd/mm/yyyy" to the format "yyyy-mm-dd"
char *convertDate(char *date) {
  char *newDate = malloc(11);
  sscanf(date, "%d/%d/%d", &newDate[8], &newDate[5], &newDate[0]);
  newDate[4] = '-';
  newDate[7] = '-';
  return newDate;
}

// Print a date in the format "yyyy-mm-dd"
void printDate(char *date) {
  printf("%s\n", date);
}

int main() {
  // Get the date from the user
  char date[11];
  printf("Enter a date in the format \"dd/mm/yyyy\": ");
  scanf("%s", date);

  // Convert the date to the format "yyyy-mm-dd"
  char *newDate = convertDate(date);

  // Print the new date
  printDate(newDate);

  // Free the memory allocated for the new date
  free(newDate);

  return 0;
}