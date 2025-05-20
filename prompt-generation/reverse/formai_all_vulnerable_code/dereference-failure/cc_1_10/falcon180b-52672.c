//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DATE_LENGTH 20
#define DATE_FORMAT "%Y-%m-%d"
#define TIME_FORMAT "%H:%M:%S"

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Date;

void initialize_date(Date *date) {
    date->year = 0;
    date->month = 0;
    date->day = 0;
    date->hour = 0;
    date->minute = 0;
    date->second = 0;
}

void set_date_from_string(Date *date, const char *date_str) {
    char buffer[MAX_DATE_LENGTH];
    strncpy(buffer, date_str, MAX_DATE_LENGTH);
    buffer[MAX_DATE_LENGTH - 1] = '\0';
    if (sscanf(buffer, DATE_FORMAT, &date->year, &date->month, &date->day)!= 3) {
        printf("Invalid date format: %s\n", date_str);
        exit(1);
    }
}

void set_time_from_string(Date *date, const char *time_str) {
    char buffer[MAX_DATE_LENGTH];
    strncpy(buffer, time_str, MAX_DATE_LENGTH);
    buffer[MAX_DATE_LENGTH - 1] = '\0';
    if (sscanf(buffer, TIME_FORMAT, &date->hour, &date->minute, &date->second)!= 3) {
        printf("Invalid time format: %s\n", time_str);
        exit(1);
    }
}

void print_date(Date date) {
    printf("Date: %d-%02d-%02d\n", date.year, date.month, date.day);
    printf("Time: %02d:%02d:%02d\n", date.hour, date.minute, date.second);
}

int main(int argc, char *argv[]) {
    Date date;
    initialize_date(&date);

    if (argc < 3) {
        printf("Usage: %s <date> <time>\n", argv[0]);
        exit(1);
    }

    set_date_from_string(&date, argv[1]);
    set_time_from_string(&date, argv[2]);

    printf("Input date: %s\n", argv[1]);
    printf("Input time: %s\n", argv[2]);
    printf("Formatted date: ");
    print_date(date);

    return 0;
}