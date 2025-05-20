//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define YEAR_FORMAT "%Y"
#define MONTH_FORMAT "%m"
#define DAY_FORMAT "%d"
#define HOUR_FORMAT "%H"
#define MINUTE_FORMAT "%M"

typedef struct Date {
    int year;
    int month;
    int day;
    int hour;
    int minute;
} Date;

Date convert_string_to_date(char *date_string) {
    Date date;

    char *year_str = strtok(date_string, "-");
    date.year = atoi(year_str);

    char *month_str = strtok(NULL, "-");
    date.month = atoi(month_str);

    char *day_str = strtok(NULL, "-");
    date.day = atoi(day_str);

    char *hour_str = strtok(NULL, ":");
    date.hour = atoi(hour_str);

    char *minute_str = strtok(NULL, ":");
    date.minute = atoi(minute_str);

    return date;
}

char *convert_date_to_string(Date date) {
    char *date_string = malloc(20);

    sprintf(date_string, "%d-%m-%Y", date.day, date.month, date.year);

    if (date.hour) {
        sprintf(date_string + strlen(date_string), " %H:%M", date.hour, date.minute);
    }

    return date_string;
}

int main() {
    char *date_string = "12-14-2023 15:30";
    Date date = convert_string_to_date(date_string);
    char *date_string_out = convert_date_to_string(date);

    printf("Original date string: %s\n", date_string);
    printf("Converted date string: %s\n", date_string_out);

    free(date_string_out);
    return 0;
}