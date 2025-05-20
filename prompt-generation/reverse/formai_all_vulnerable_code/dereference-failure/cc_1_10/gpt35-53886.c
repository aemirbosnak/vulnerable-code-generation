//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables
char input_date[20];
char output_date[20];

// function prototypes
int is_leap(int year);
int days_in_month(int month, int year);
void convert_date();

// main function
int main() {
    printf("Enter a date in natural language (e.g. January 1st, 2022): ");
    fgets(input_date, 20, stdin);  // get input date from user
    convert_date();  // call convert_date() to convert date to numeric format
    printf("The date in numeric format is: %s\n", output_date);
    return 0;
}

// function to check if a year is a leap year
int is_leap(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return 1;  // year is a leap year
    } else {
        return 0;  // year is not a leap year
    }
}

// function to get the number of days in a month
int days_in_month(int month, int year) {
    int days[12] = {31, 28 + is_leap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month - 1];
}

// function to convert date to numeric format
void convert_date() {
    char *month_names[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char *suffix[4] = {"st", "nd", "rd", "th"};
    int month, day, year;
    char *token;
    char *delim = " ,";

    // get month, day, and year from input date
    token = strtok(input_date, delim);  // get month
    for (int i = 0; i < 12; i++) {
        if (strcmp(token, month_names[i]) == 0) {
            month = i + 1;
        }
    }

    token = strtok(NULL, delim);  // get day
    day = atoi(token);
    if (day >= 11 && day <= 13) {
        sprintf(output_date, "%d-%02d-%02d", year, month, day);  // no suffix for 11th, 12th, and 13th
        return;
    }
    switch (day % 10) {
        case 1:
            strcat(token, suffix[0]);
            break;
        case 2:
            strcat(token, suffix[1]);
            break;
        case 3:
            strcat(token, suffix[2]);
            break;
        default:
            strcat(token, suffix[3]);
            break;
    }

    token = strtok(NULL, delim);  // get year
    year = atoi(token);

    // check for valid input date
    if (month < 1 || month > 12 || day < 1 || day > days_in_month(month, year) || year < 1) {
        printf("Error: Invalid input date!\n");
        exit(1);
    }

    // convert date to numeric format
    sprintf(output_date, "%d-%02d-%02d", year, month, day);
    return;
}