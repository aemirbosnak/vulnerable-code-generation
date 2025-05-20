//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <wctype.h>
#include <wchar.h>
#include <stdbool.h>

#define MAX_MONTH_NAME_LENGTH 9
#define MAX_WEEKDAY_NAME_LENGTH 9

enum {
    JANUARY = 0,
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

enum {
    SUNDAY = 0,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

struct tm get_current_time(void);
void set_locale(void);
char *get_month_name(int month);
char *get_weekday_name(int weekday);
void print_date(struct tm date);

int main(void) {
    set_locale();
    struct tm current_time = get_current_time();
    print_date(current_time);
    return 0;
}

struct tm get_current_time(void) {
    time_t current_time = time(NULL);
    struct tm *tm = localtime(&current_time);
    return *tm;
}

void set_locale(void) {
    setlocale(LC_TIME, "");
}

char *get_month_name(int month) {
    static char month_names[12][MAX_MONTH_NAME_LENGTH] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    return month_names[month];
}

char *get_weekday_name(int weekday) {
    static char weekday_names[7][MAX_WEEKDAY_NAME_LENGTH] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
        "Friday", "Saturday"
    };
    return weekday_names[weekday];
}

void print_date(struct tm date) {
    printf("Today is %s, %d %s %d\n",
           get_weekday_name(date.tm_wday),
           date.tm_mday,
           get_month_name(date.tm_mon + 1),
           date.tm_year + 1900);
}