//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>

int getDaysInMonth(int month, int year) {

    bool leapYear = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);

    int daysInMonth;
    switch(month) {
        case 2:
            daysInMonth = leapYear ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 31;
            break;          
    }

    return daysInMonth;
}

void convertNaturalLanguageDate(char* date) {
    int month, day, year;

    // Get the month
    if (strstr(date, "January")) {
        month = 1;
    } else if (strstr(date, "February")) {
        month = 2;
    } else if (strstr(date, "March")) {
        month = 3;
    } else if (strstr(date, "April")) {
        month = 4;
    } else if (strstr(date, "May")) {
        month = 5;
    } else if (strstr(date, "June")) {
        month = 6;
    } else if (strstr(date, "July")) {
        month = 7;
    } else if (strstr(date, "August")) {
        month = 8;
    } else if (strstr(date, "September")) {
        month = 9;
    } else if (strstr(date, "October")) {
        month = 10;
    } else if (strstr(date, "November")) {
        month = 11;
    } else {
        month = 12;
    }

    // Get the day
    char* ptr = strstr(date, "th");
    *ptr = '\0';
    sscanf(date, "%d", &day);

    // Get the year
    ptr = strstr(date, " ");
    sscanf(ptr+1, "%d", &year);

    // Check if the date is valid
    int daysInMonth = getDaysInMonth(month, year);
    if (day < 1 || day > daysInMonth) {
        printf("Invalid date.\n");
        return;
    }

    // Print the date in the DD/MM/YYYY format
    printf("%d/%d/%d\n", day, month, year);
}

int main() {
    char date1[] = "December 31st, 2021";
    char date2[] = "February 29th, 2020";
    char date3[] = "April 31st, 2022";
    char date4[] = "June 10th, 2023";

    convertNaturalLanguageDate(date1);
    convertNaturalLanguageDate(date2);
    convertNaturalLanguageDate(date3);
    convertNaturalLanguageDate(date4);

    return 0;
}