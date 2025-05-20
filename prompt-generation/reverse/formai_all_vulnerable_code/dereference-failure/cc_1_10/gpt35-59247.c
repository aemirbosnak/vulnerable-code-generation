//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: safe
#include <stdio.h>

// function to convert English month name to its equivalent integer
int getMonthNumber(char *month) {
    if (strcmp(month, "January") == 0) {
        return 1;
    } else if (strcmp(month, "February") == 0) {
        return 2;
    } else if (strcmp(month, "March") == 0) {
        return 3;
    } else if (strcmp(month, "April") == 0) {
        return 4;
    } else if (strcmp(month, "May") == 0) {
        return 5;
    } else if (strcmp(month, "June") == 0) {
        return 6;
    } else if (strcmp(month, "July") == 0) {
        return 7;
    } else if (strcmp(month, "August") == 0) {
        return 8;
    } else if (strcmp(month, "September") == 0) {
        return 9;
    } else if (strcmp(month, "October") == 0) {
        return 10;
    } else if (strcmp(month, "November") == 0) {
        return 11;
    } else if (strcmp(month, "December") == 0) {
        return 12;
    } else {
        return 0;
    }
}

// main function to convert date string to integer values
int convertDate(char* dateString) {
    char *dayPtr, *monthPtr, *yearPtr;
    int day, month, year;
    dayPtr = strtok(dateString, "/");
    monthPtr = strtok(NULL, "/");
    yearPtr = strtok(NULL, "\n");
    day = atoi(dayPtr);
    month = getMonthNumber(monthPtr);
    year = atoi(yearPtr);
    return day + month*100 + year*10000;
}

int main() {
    char dateString[20];
    printf("Enter date in format dd/mmm/yyyy: ");
    fgets(dateString, 20, stdin);
    printf("Date in integer format is: %d\n", convertDate(dateString));
    return 0;
}