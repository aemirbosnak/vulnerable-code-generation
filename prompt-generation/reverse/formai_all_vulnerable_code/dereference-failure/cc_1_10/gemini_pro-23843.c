//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to convert a date from the format "dd/mm/yyyy" to the format "yyyy-mm-dd"
char *convertDate(char *date) {
    char *newDate = malloc(11);
    char *day = strtok(date, "/");
    char *month = strtok(NULL, "/");
    char *year = strtok(NULL, "/");
    sprintf(newDate, "%s-%s-%s", year, month, day);
    return newDate;
}

// Function to get the current date in the format "dd/mm/yyyy"
char *getCurrentDate() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *date = malloc(11);
    sprintf(date, "%02d/%02d/%04d", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    return date;
}

// Function to get the next date in the format "dd/mm/yyyy"
char *getNextDate(char *date) {
    char *newDate = malloc(11);
    char *day = strtok(date, "/");
    char *month = strtok(NULL, "/");
    char *year = strtok(NULL, "/");
    int dayInt = atoi(day);
    int monthInt = atoi(month);
    int yearInt = atoi(year);
    if (dayInt == 31) {
        if (monthInt == 12) {
            dayInt = 1;
            monthInt = 1;
            yearInt++;
        } else {
            dayInt = 1;
            monthInt++;
        }
    } else {
        dayInt++;
    }
    sprintf(newDate, "%02d/%02d/%04d", dayInt, monthInt, yearInt);
    return newDate;
}

// Function to get the previous date in the format "dd/mm/yyyy"
char *getPreviousDate(char *date) {
    char *newDate = malloc(11);
    char *day = strtok(date, "/");
    char *month = strtok(NULL, "/");
    char *year = strtok(NULL, "/");
    int dayInt = atoi(day);
    int monthInt = atoi(month);
    int yearInt = atoi(year);
    if (dayInt == 1) {
        if (monthInt == 1) {
            dayInt = 31;
            monthInt = 12;
            yearInt--;
        } else {
            dayInt = 30 + (monthInt % 2);
            monthInt--;
        }
    } else {
        dayInt--;
    }
    sprintf(newDate, "%02d/%02d/%04d", dayInt, monthInt, yearInt);
    return newDate;
}

int main() {
    char *date = "15/02/2023";
    char *newDate = convertDate(date);
    printf("The date in the format \"yyyy-mm-dd\" is: %s\n", newDate);
    char *currentDate = getCurrentDate();
    printf("The current date in the format \"dd/mm/yyyy\" is: %s\n", currentDate);
    char *nextDate = getNextDate(currentDate);
    printf("The next date in the format \"dd/mm/yyyy\" is: %s\n", nextDate);
    char *previousDate = getPreviousDate(currentDate);
    printf("The previous date in the format \"dd/mm/yyyy\" is: %s\n", previousDate);
    return 0;
}