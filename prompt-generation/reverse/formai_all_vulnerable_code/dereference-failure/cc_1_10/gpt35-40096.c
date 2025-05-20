//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert month name to number
int get_month_number(char *month_name) {
    int month_number = 0;
    if (strcmp(month_name, "January") == 0) {
        month_number = 1;
    } else if (strcmp(month_name, "February") == 0) {
        month_number = 2;
    } else if (strcmp(month_name, "March") == 0) {
        month_number = 3;
    } else if (strcmp(month_name, "April") == 0) {
        month_number = 4;
    } else if (strcmp(month_name, "May") == 0) {
        month_number = 5;
    } else if (strcmp(month_name, "June") == 0) {
        month_number = 6;
    } else if (strcmp(month_name, "July") == 0) {
        month_number = 7;
    } else if (strcmp(month_name, "August") == 0) {
        month_number = 8;
    } else if (strcmp(month_name, "September") == 0) {
        month_number = 9;
    } else if (strcmp(month_name, "October") == 0) {
        month_number = 10;
    } else if (strcmp(month_name, "November") == 0) {
        month_number = 11;
    } else if (strcmp(month_name, "December") == 0) {
        month_number = 12;
    }
    return month_number;
}

// function to convert date string to date components
void convert_date_string(char *date_string, int *day, int *month, int *year) {
    char *token = strtok(date_string, " ");

    // get day
    *day = atoi(token);

    // get month
    token = strtok(NULL, " ");
    *month = get_month_number(token);

    // get year
    token = strtok(NULL, " ");
    *year = atoi(token);
}

// function to convert date components to date string
void convert_date_components(int day, int month, int year, char *date_string) {
    char month_name[10];
    switch (month) {
        case 1:
            strcpy(month_name, "January");
            break;
        case 2:
            strcpy(month_name, "February");
            break;
        case 3:
            strcpy(month_name, "March");
            break;
        case 4:
            strcpy(month_name, "April");
            break;
        case 5:
            strcpy(month_name, "May");
            break;
        case 6:
            strcpy(month_name, "June");
            break;
        case 7:
            strcpy(month_name, "July");
            break;
        case 8:
            strcpy(month_name, "August");
            break;
        case 9:
            strcpy(month_name, "September");
            break;
        case 10:
            strcpy(month_name, "October");
            break;
        case 11:
            strcpy(month_name, "November");
            break;
        case 12:
            strcpy(month_name, "December");
            break;
    }
    sprintf(date_string, "%d %s %d", day, month_name, year);
}

int main() {
    char date_string[20];
    char converted_date_string[20];
    int day, month, year;

    // read date string from user
    printf("Enter date (dd mm yyyy): ");
    fgets(date_string, 20, stdin);
    date_string[strcspn(date_string, "\n")] = 0;

    // convert date string to date components
    convert_date_string(date_string, &day, &month, &year);

    // display date components
    printf("Day: %d\n", day);
    printf("Month: %d\n", month);
    printf("Year: %d\n", year);

    // convert date components to date string
    convert_date_components(day, month, year, converted_date_string);

    // display converted date string
    printf("Converted Date: %s", converted_date_string);

    return 0;
}