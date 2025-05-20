//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert month in text to number
int monthToNum(char month[]) {
  if (strcmp(month, "January") == 0) return 1;
  else if (strcmp(month, "February") == 0) return 2;
  else if (strcmp(month, "March") == 0) return 3;
  else if (strcmp(month, "April") == 0) return 4;
  else if (strcmp(month, "May") == 0) return 5;
  else if (strcmp(month, "June") == 0) return 6;
  else if (strcmp(month, "July") == 0) return 7;
  else if (strcmp(month, "August") == 0) return 8;
  else if (strcmp(month, "September") == 0)return 9;
  else if (strcmp(month, "October") == 0) return 10;
  else if (strcmp(month, "November") == 0) return 11;
  else if (strcmp(month, "December") == 0) return 12;
  else return 0;
}

// function to convert number month to text
char* numToMonth(int monthNum) {
  switch(monthNum) {
    case 1: return "January";
    case 2: return "February";
    case 3: return "March";
    case 4: return "April";
    case 5: return "May";
    case 6: return "June";
    case 7: return "July";
    case 8: return "August";
    case 9: return "September";
    case 10: return "October";
    case 11: return "November";
    case 12: return "December";
    default: return "Invalid month";
  }
}

int main() {
  char date[20];
  int day, month, year;

  printf("Enter a date in the format dd-mm-yyyy: ");
  scanf("%s", date);

  // extract day, month and year from input string
  day = atoi(strtok(date, "-"));
  month = atoi(strtok(NULL, "-"));
  year = atoi(strtok(NULL, "-"));

  // convert month in number format to text
  char* monthStr = numToMonth(month);

  // display converted date
  printf("The date is: %d %s %d\n", day, monthStr, year);

  return 0;
}