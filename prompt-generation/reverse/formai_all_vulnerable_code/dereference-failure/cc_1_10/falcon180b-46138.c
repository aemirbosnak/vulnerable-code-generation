//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MONTHS 12
#define DAYS_PER_MONTH 31

char* months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char* weekdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int is_leap_year(int year) {
    if (year % 4 == 0 && year % 100!= 0) {
        return 1;
    } else if (year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int get_days_in_month(int month, int year) {
    if (month == 2) {
        if (is_leap_year(year)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int get_weekday(int day, int month, int year) {
    int days_in_month = get_days_in_month(month, year);
    int day_of_week = (day + 13 - 1) % 7; // Adjust for 0-based to 1-based weekday
    return day_of_week;
}

int main() {
    time_t now = time(NULL);
    struct tm* current_time = localtime(&now);

    int year = 1900 + current_time->tm_year;
    int month = current_time->tm_mon + 1; // Adjust for 0-based to 1-based month
    int day = current_time->tm_mday;

    printf("In fair Verona, where we lay our scene,\n");
    printf("On this %s day of the %s month in the year of our Lord %d,\n", weekdays[get_weekday(day, month, year)], months[month - 1], year);
    printf("The sun doth shine and Juliet's heart beats with love for her Romeo.\n");

    return 0;
}