//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define NUM_DAYS_IN_MONTH(month) ((month == 2 && isLeapYear(year))? 29 : (month == 4 || month == 6 || month == 9 || month == 11)? 30 : 31)

int isLeapYear(int year) {
    if (year % 4 == 0 && year % 100!= 0) {
        return 1;
    } else if (year % 400 == 0) {
        return 1;
    }
    return 0;
}

void getDate(int *day, int *month, int *year) {
    printf("Enter date (DD/MM/YYYY): ");
    char input[MAX_WORD_LENGTH];
    fgets(input, MAX_WORD_LENGTH, stdin);

    char *token = strtok(input, "/");
    *day = atoi(token);

    token = strtok(NULL, "/");
    *month = atoi(token);

    token = strtok(NULL, "/");
    *year = atoi(token);
}

void convertDateToWords(int day, int month, int year) {
    int numDays = NUM_DAYS_IN_MONTH(month);

    printf("Today's date is ");

    if (day == 1) {
        printf("the first");
    } else if (day == numDays) {
        printf("the %dth", numDays);
    } else if (day < 10) {
        printf("the %dth", day);
    } else if (day < 20) {
        printf("the %dth", day);
    } else {
        printf("the %dth", day);
    }

    switch (month) {
        case 1:
            printf(" of January");
            break;
        case 2:
            printf(" of February");
            break;
        case 3:
            printf(" of March");
            break;
        case 4:
            printf(" of April");
            break;
        case 5:
            printf(" of May");
            break;
        case 6:
            printf(" of June");
            break;
        case 7:
            printf(" of July");
            break;
        case 8:
            printf(" of August");
            break;
        case 9:
            printf(" of September");
            break;
        case 10:
            printf(" of October");
            break;
        case 11:
            printf(" of November");
            break;
        case 12:
            printf(" of December");
            break;
    }

    printf(", %d", year);
}

int main() {
    int day, month, year;
    getDate(&day, &month, &year);
    convertDateToWords(day, month, year);
    return 0;
}