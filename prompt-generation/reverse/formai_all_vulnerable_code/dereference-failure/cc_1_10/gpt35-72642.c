//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap_year(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return 1;
    } else {
        return 0;
    }
}

int get_day_in_year(int day, int month, int year) {
    int day_in_year = 0;
    int i;
    for (i = 0; i < month - 1; i++) {
        day_in_year += month_days[i];
    }
    if (is_leap_year(year) && month > 2) {
        day_in_year += 1;
    }
    day_in_year += day;
    return day_in_year;    
}

int* convert_date(char* date_string) {

    int* date_array = malloc(sizeof(int) * 3);

    char* token = strtok(date_string, "/");
    int i = 0, day = 0, month = 0, year = 0;
    while (token != NULL) {
        if (i == 0) {
            day = atoi(token);
        } else if (i == 1) {
            month = atoi(token);
        } else if (i == 2) {
            year = atoi(token);
        }
        i++;
        token = strtok(NULL, "/");
    }

    if (month < 1 || month > 12) {
        return NULL;
    }
    if (day < 1 || day > month_days[month - 1] || (is_leap_year(year) && month == 2 && day > 29)) {
        return NULL;
    }

    date_array[0] = day;
    date_array[1] = month;
    date_array[2] = year;

    return date_array;
}

int main() {

    char date_string[11];
    int* date_array;
    int day_in_year;

    printf("Enter a date in the format DD/MM/YYYY: ");
    fgets(date_string, 11, stdin);

    date_array = convert_date(date_string);
    if (date_array == NULL) {
        printf("Invalid date!\n");
        return 0;
    }

    day_in_year = get_day_in_year(date_array[0], date_array[1], date_array[2]);

    printf("%d %s %d is day number %d in the year %d.\n", date_array[0], months[date_array[1] - 1], date_array[2], day_in_year, date_array[2]);

    free(date_array);
    return 0;
}