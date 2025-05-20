//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_STRING_LENGTH 1000
#define MONTH_NAMES_LENGTH 12

enum {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

char* month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void convert_date(char* input_date, struct tm* date_struct) {
    char* token = strtok(input_date, " ");
    int day = atoi(token);

    token = strtok(NULL, " ");
    int month = 0;
    for (int i = 0; i < MONTH_NAMES_LENGTH; i++) {
        if (strcmp(token, month_names[i]) == 0) {
            month = i + 1;
            break;
        }
    }

    token = strtok(NULL, " ");
    int year = atoi(token);

    date_struct->tm_mday = day;
    date_struct->tm_mon = month - 1;
    date_struct->tm_year = year - 1900;
    date_struct->tm_yday = 0;
    date_struct->tm_wday = 0;
    date_struct->tm_isdst = 0;
}

void print_date(struct tm* date_struct) {
    printf("Today is %s, %d %s %d.\n", month_names[date_struct->tm_mon + 1], date_struct->tm_mday, month_names[date_struct->tm_mon], date_struct->tm_year + 1900);
}

int main() {
    char input_date[MAX_STRING_LENGTH];

    printf("Enter a date in the format 'Day Month Year': ");
    fgets(input_date, MAX_STRING_LENGTH, stdin);

    struct tm date_struct;
    memset(&date_struct, 0, sizeof(struct tm));
    convert_date(input_date, &date_struct);

    time_t current_time = mktime(&date_struct);
    printf("The current time is: ");
    ctime(&current_time);

    print_date(&date_struct);

    return 0;
}