//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 50

struct date {
    int day;
    int month;
    int year;
};

// function to check if a year is a leap year
int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

// function to get the number of days in a month
int get_days_in_month(int month, int year) {
    if (month == 2) {
        if (is_leap_year(year)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

// function to convert a date string to a date struct
struct date parse_date(char *date_str) {
    struct date d;
    char *token;
    token = strtok(date_str, "/");
    d.month = atoi(token);
    token = strtok(NULL, "/");
    d.day = atoi(token);
    token = strtok(NULL, "/");
    d.year = atoi(token);
    return d;
}

// function to convert a date struct to a date string
char *format_date(struct date d) {
    char *date_str = malloc(MAX_LENGTH * sizeof(char));
    sprintf(date_str, "%02d/%02d/%04d", d.month, d.day, d.year);
    return date_str;
}

// function to add a number of days to a date
struct date add_days_to_date(struct date d, int days) {
    int days_in_month, days_left;
    while (days > 0) {
        days_in_month = get_days_in_month(d.month, d.year);
        days_left = days_in_month - d.day + 1;
        if (days_left <= days) {
            d.day += days_left;
            if (d.month == 12) {
                d.month = 1;
                d.year++;
            }
            else {
                d.month++;
            }
            days -= days_left;
        }
        else {
            d.day += days;
            days = 0;
        }
    }
    return d;
}

int main() {
    char date_str[MAX_LENGTH];
    int days_to_add;
    struct date d, new_d;
    printf("Enter a date (MM/DD/YYYY): ");
    fgets(date_str, MAX_LENGTH, stdin);
    date_str[strlen(date_str) - 1] = '\0'; // remove newline character
    d = parse_date(date_str);
    printf("Enter the number of days to add: ");
    scanf("%d", &days_to_add);
    new_d = add_days_to_date(d, days_to_add);
    printf("The new date is: %s\n", format_date(new_d));
    return 0;
}