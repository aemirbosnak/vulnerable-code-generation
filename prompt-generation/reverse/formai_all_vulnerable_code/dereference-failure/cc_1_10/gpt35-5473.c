//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct date{
    int day;
    int month;
    int year;
} date;

int isLeapYear(int year){
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        return 1;
    else
        return 0;
}

int maxDaysOfMonth(int month, int year){
    if (month == 2 && isLeapYear(year))
        return 29;
    else
        return monthDays[month-1];
}
  
int countLeapYears(date d){
    int years = d.year;
  
    if (d.month <= 2)
        years--;
  
    return years / 4 - years / 100 + years / 400;
}

int dateDifference(date today, date birthday)
{
    int daysInY1 = 0, daysInY2 = 0;
  
    daysInY1 += birthday.day;
    
    daysInY2 += today.day;
 
    for (int i = 1; i < birthday.month; i++)
        daysInY1 += maxDaysOfMonth(i, birthday.year);
  
    for (int i = 1; i < today.month; i++)
        daysInY2 += maxDaysOfMonth(i, today.year);
  
    daysInY1 += 365 * birthday.year + countLeapYears(birthday);
    daysInY2 += 365 * today.year + countLeapYears(today);
  
    return (daysInY2 - daysInY1);
}

date convertDate(char *inputDate){
    date newDate;
    char *splitDate;

    splitDate = strtok(inputDate, "-");
    newDate.day = atoi(splitDate);

    splitDate = strtok(NULL, "-");
    newDate.month = atoi(splitDate);

    splitDate = strtok(NULL, "-");
    newDate.year = atoi(splitDate);

    return newDate;
}

int main(){
    char input[11];
    date today, birthday;
    int difference;

    printf("Enter today's date (format: DD-MM-YYYY): ");
    fgets(input, 11, stdin);
    today = convertDate(input);
  
    printf("Enter your birthday (format: DD-MM-YYYY): ");
    fgets(input, 11, stdin);
    birthday = convertDate(input);
  
    difference = dateDifference(today, birthday);
    printf("\nYou have been alive for %d days.\n", difference);
  
    return 0;
}