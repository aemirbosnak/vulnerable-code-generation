//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* month_names[] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};

int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

int days_in_year(int year) {
    if (is_leap_year(year)) {
        return 366;
    } else {
        return 365;
    }
}

int days_in_month_for_year(int month, int year) {
    if (month == 1 && is_leap_year(year)) {
        return 29;
    } else {
        return days_in_month[month];
    }
}

int day_number_from_date(int day, int month, int year) {
    int total_days = 0;
    for (int i = 1; i < month; i++) {
        total_days += days_in_month_for_year(i - 1, year);
    }
    total_days += day;
    return total_days;
}

char* date_string_from_day_number(int day_number, int year) {
    int current_day = day_number;
    int current_month = 0;
    while (current_day > days_in_month_for_year(current_month, year)) {
        current_day -= days_in_month_for_year(current_month, year);
        current_month++;
    }
    char* date_string = malloc(sizeof(char) * 20);
    sprintf(date_string, "%d %s %d", current_day, month_names[current_month], year);
    return date_string;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <day number> [year]\n", argv[0]);
        return 1;
    }

    int day_number = atoi(argv[1]);
    if (day_number < 1 || day_number > 366) {
        printf("Error: day number must be between 1 and 366\n");
        return 1;
    }

    int year = 2022;
    if (argc > 2) {
        year = atoi(argv[2]);
    }

    if (day_number > days_in_year(year)) {
        printf("Error: day number %d is invalid for year %d\n", day_number, year);
        return 1;
    }

    char* date_string = date_string_from_day_number(day_number, year);
    printf("%s\n", date_string);
    free(date_string);

    return 0;
}