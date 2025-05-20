//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void calculateDate(int days, int year)
{
  int month = 0;

  if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
  {
    monthDays[1] = 29;
  }

  while (days > monthDays[month])
  {
    days -= monthDays[month];
    month++;
  }

  printf("\n'Tis %d day of %s, Anno Domini %d\n", days, (month == 0) ? "January" : 
                                                      (month == 1) ? "February" :
                                                      (month == 2) ? "March" : 
                                                      (month == 3) ? "April" :
                                                      (month == 4) ? "May" : 
                                                      (month == 5) ? "June" : 
                                                      (month == 6) ? "July" : 
                                                      (month == 7) ? "August" : 
                                                      (month == 8) ? "September" :
                                                      (month == 9) ? "October" : 
                                                      (month == 10) ? "November" : "December", year);
}

int main()
{
  char input[30];
  int days, year;

  printf("Greetings! I am Juliet, a natural language date converter henceforth.\n");
  printf("Pray, unroll the scroll of date and year to translate: ");

  fgets(input, 30, stdin); 

  char *day_ndx = strchr(input, ',');
  day_ndx += 2; // To get the number after ", "

  char *year_ndx = strchr(day_ndx, ' ');
  year_ndx += 1; // To get the first number in "Year: XXXX"

  // Extracting Date
  days = atoi(day_ndx);

  // Extracting Year
  year = atoi(year_ndx);

  // Calculating Month
  calculateDate(days, year);

  return 0;
}