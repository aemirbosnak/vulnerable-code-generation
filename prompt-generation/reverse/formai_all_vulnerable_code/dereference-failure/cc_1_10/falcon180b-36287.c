//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LENGTH 20
#define MAX_MONTH_LENGTH 9
#define MAX_YEAR_LENGTH 4
#define MAX_DAY_LENGTH 2
#define MAX_MONTH_NAME_LENGTH 9
#define MAX_DAY_NAME_LENGTH 9
#define MAX_TIME_LENGTH 8
#define MAX_TIMEZONE_LENGTH 6
#define MAX_DATETIME_LENGTH 30

typedef struct {
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
    char timezone[MAX_TIMEZONE_LENGTH];
} DateTime;

typedef struct {
    char month[MAX_MONTH_LENGTH];
    char day[MAX_DAY_LENGTH];
    char year[MAX_YEAR_LENGTH];
} Date;

typedef struct {
    char month_name[MAX_MONTH_NAME_LENGTH];
    char day_name[MAX_DAY_NAME_LENGTH];
} DayName;

void parse_date(const char* date_str, Date* date) {
    char* month_name = malloc(MAX_MONTH_NAME_LENGTH * sizeof(char));
    char* day_name = malloc(MAX_DAY_NAME_LENGTH * sizeof(char));
    strptime(date_str, "%Y-%m-%d", date);
    strftime(month_name, MAX_MONTH_NAME_LENGTH, "%B", date);
    strftime(day_name, MAX_DAY_NAME_LENGTH, "%A", date);
    printf("Date: %s, %s %d, %s\n", month_name, day_name, date->day, date->year);
}

void parse_time(const char* time_str, DateTime* datetime) {
    strptime(time_str, "%H:%M:%S", &datetime->time);
    strftime(datetime->timezone, MAX_TIMEZONE_LENGTH, "%Z", datetime);
    printf("Time: %s %s\n", datetime->time, datetime->timezone);
}

int main() {
    char input[MAX_DATETIME_LENGTH];
    printf("Enter a date and time (YYYY-MM-DD HH:MM:SS): ");
    fgets(input, MAX_DATETIME_LENGTH, stdin);
    Date date;
    DateTime datetime;
    parse_date(input, &date);
    parse_time(input, &datetime);
    return 0;
}