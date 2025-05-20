//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

#define MAX_MONTH_LENGTH 31
#define MAX_YEAR_LENGTH 4
#define MAX_DATE_LENGTH 10
#define MAX_TIME_LENGTH 8
#define MAX_TIME_ZONE_LENGTH 6

static char *month_names[] = {
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
};

static char *day_names[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

static char *time_zone_names[] = {
    "UTC-12:00", "UTC-11:00", "UTC-10:00", "UTC-09:30", "UTC-09:00", "UTC-08:00", "UTC-07:00", "UTC-06:00", "UTC-05:00", "UTC-04:30", "UTC-04:00", "UTC-03:30", "UTC-03:00", "UTC-02:00", "UTC-01:00", "UTC+00:00", "UTC+01:00", "UTC+02:00", "UTC+03:00", "UTC+03:30", "UTC+04:00", "UTC+04:30", "UTC+05:00", "UTC+05:30", "UTC+05:45", "UTC+06:00", "UTC+06:30", "UTC+07:00", "UTC+08:00", "UTC+08:45", "UTC+09:00", "UTC+09:30", "UTC+10:00", "UTC+10:30", "UTC+11:00", "UTC+12:00", "UTC+12:45", "UTC+13:00", "UTC+14:00"
};

static char *weekday_names[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

static char *ampm_names[] = {
    "AM", "PM"
};

static char *date_format = "%A, %d %B %Y %I:%M %p %Z";
static char *time_format = "%I:%M %p %Z";

void set_date_format(const char *format) {
    strncpy(date_format, format, sizeof(date_format));
}

void set_time_format(const char *format) {
    strncpy(time_format, format, sizeof(time_format));
}

char *format_date(struct tm *tm) {
    char buffer[MAX_DATE_LENGTH];
    strftime(buffer, sizeof(buffer), date_format, tm);
    return strdup(buffer);
}

char *format_time(struct tm *tm) {
    char buffer[MAX_TIME_LENGTH];
    strftime(buffer, sizeof(buffer), time_format, tm);
    return strdup(buffer);
}

int main() {
    setlocale(LC_ALL, "");

    struct tm tm;
    time_t now = time(NULL);
    localtime_r(&now, &tm);

    char *date_string = format_date(&tm);
    char *time_string = format_time(&tm);

    printf("Today's date and time is %s, %s.\n", date_string, time_string);

    return 0;
}