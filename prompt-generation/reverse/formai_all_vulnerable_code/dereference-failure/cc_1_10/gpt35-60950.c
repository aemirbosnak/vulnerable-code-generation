//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: standalone
#include <stdio.h>
#include <string.h>

// Define the maximum length for the input date string
#define MAX_DATE_LENGTH 20

// Function declarations
int isLeapYear(int year);
int getDaysInMonth(int month, int year);
int convertMonthToInt(char* month);
void convertInputDate(char* input_date, int* day, int* month, int* year);
void convertOutputDate(int day, int month, int year, char* output_date);


int main() {
  // Declare variables to store the input and output dates
  char input_date[MAX_DATE_LENGTH];
  char output_date[MAX_DATE_LENGTH];
  int day, month, year;

  // Prompt the user to enter a date in the format "dd Month YYYY"
  printf("Enter a date (in the format \"dd Month YYYY\"): ");
  scanf("%[^\n]%*c", input_date);

  // Convert the input date string to day, month, and year integers
  convertInputDate(input_date, &day, &month, &year);

  // Convert the day, month, and year integers back to a formatted date string
  convertOutputDate(day, month, year, output_date);

  // Print the output date string
  printf("%s\n", output_date);

  return 0;
}

/**
 * Check if a given year is a leap year
 */
int isLeapYear(int year) {
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        return 1;
      } else {
        return 0;
      }
    } else {
      return 1;
    }
  } else {
    return 0;
  }
}

/**
 * Get the number of days in a given month for a given year
 */
int getDaysInMonth(int month, int year) {
  switch (month) {
    case 2:
      if (isLeapYear(year)) {
        return 29;
      } else {
        return 28;
      }
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    default:
      return 31;
  }
}

/**
 * Convert a three-letter month string to its corresponding integer value
 */
int convertMonthToInt(char* month) {
  if (strcmp(month, "Jan") == 0) {
    return 1;
  } else if (strcmp(month, "Feb") == 0) {
    return 2;
  } else if (strcmp(month, "Mar") == 0) {
    return 3;
  } else if (strcmp(month, "Apr") == 0) {
    return 4;
  } else if (strcmp(month, "May") == 0) {
    return 5;
  } else if (strcmp(month, "Jun") == 0) {
    return 6;
  } else if (strcmp(month, "Jul") == 0) {
    return 7;
  } else if (strcmp(month, "Aug") == 0) {
    return 8;
  } else if (strcmp(month, "Sep") == 0) {
    return 9;
  } else if (strcmp(month, "Oct") == 0) {
    return 10;
  } else if (strcmp(month, "Nov") == 0) {
    return 11;
  } else {
    return 12;
  }
}

/**
 * Convert the input date string to day, month, and year integers
 */
void convertInputDate(char* input_date, int* day, int* month, int* year) {
  char temp_day[3];
  char temp_month[4];
  char temp_year[5];

  // Extract the day, month, and year from the input date string
  sscanf(input_date, "%2s %3s %4s", temp_day, temp_month, temp_year);

  // Convert the temporary day, month, and year strings to integers
  *day = atoi(temp_day);
  *month = convertMonthToInt(temp_month);
  *year = atoi(temp_year);
}

/**
 * Convert the day, month, and year integers back to a formatted date string
 */
void convertOutputDate(int day, int month, int year, char* output_date) {
  char month_name[4];

  // Convert the month integer to a three-letter month string
  switch (month) {
    case 1:
      strcpy(month_name, "Jan");
      break;
    case 2:
      strcpy(month_name, "Feb");
      break;
    case 3:
      strcpy(month_name, "Mar");
      break;
    case 4:
      strcpy(month_name, "Apr");
      break;
    case 5:
      strcpy(month_name, "May");
      break;
    case 6:
      strcpy(month_name, "Jun");
      break;
    case 7:
      strcpy(month_name, "Jul");
      break;
    case 8:
      strcpy(month_name, "Aug");
      break;
    case 9:
      strcpy(month_name, "Sep");
      break;
    case 10:
      strcpy(month_name, "Oct");
      break;
    case 11:
      strcpy(month_name, "Nov");
      break;
    case 12:
      strcpy(month_name, "Dec");
      break;
  }

  // Format the output date string
  sprintf(output_date, "%02d %s %04d", day, month_name, year);
}