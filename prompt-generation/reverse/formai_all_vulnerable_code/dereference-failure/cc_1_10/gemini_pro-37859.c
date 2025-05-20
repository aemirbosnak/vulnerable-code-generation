//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define Y2K 2000
#define JULIAN_DAY_OFFSET 2440588

typedef struct {
    int year;
    int month;
    int day;
} Date;

int isleap(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int days_in_month(int year, int month) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            return 28 + isleap(year);
        default:
            return 30;
    }
}

Date add_days(Date date, int days) {
    int year = date.year;
    int month = date.month;
    int day = date.day;

    while (days > 0) {
        ++day;
        if (day > days_in_month(year, month)) {
            ++month;
            day = 1;
            if (month > 12) {
                ++year;
                month = 1;
            }
        }
        --days;
    }

    date.year = year;
    date.month = month;
    date.day = day;

    return date;
}

Date subtract_days(Date date, int days) {
    int year = date.year;
    int month = date.month;
    int day = date.day;

    while (days > 0) {
        --day;
        if (day < 1) {
            --month;
            if (month < 1) {
                --year;
                month = 12;
            }
            day = days_in_month(year, month);
        }
        --days;
    }

    date.year = year;
    date.month = month;
    date.day = day;

    return date;
}

int julian_day(Date date) {
    int a = (14 - date.month) / 12;
    int y = date.year + 4800 - a;
    int m = date.month + 12 * a - 3;
    return date.day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - JULIAN_DAY_OFFSET;
}

Date from_julian_day(int julian_day) {
    int a = julian_day + JULIAN_DAY_OFFSET;
    int b = a + 1524;
    int c = (4 * b) / 146097;
    int d = b - ((146097 * c) / 4);
    int e = (4 * d) / 1461;
    int m = d - ((1461 * e) / 4);
    int r = (2 * m + 1) / 12;
    int y = c - 4800 + r;
    int mo = m - (12 * r);
    int ddd = a - ((365 * y) + (y / 4) - (y / 100) + (y / 400) + (30 * mo) / 12) - 1;

    Date date;
    date.year = y;
    date.month = mo;
    date.day = ddd;

    return date;
}

char *day_of_week(int julian_day) {
    return "Sunday\0Monday\0Tuesday\0Wednesday\0Thursday\0Friday\0Saturday"[3 * (julian_day % 7)];
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <julian day>\n", argv[0]);
        return 1;
    }

    int julian_day = atoi(argv[1]);
    Date date = from_julian_day(julian_day);

    printf("Julian day: %d\n", julian_day);
    printf("Date: %d-%d-%d\n", date.year, date.month, date.day);
    printf("Day of week: %s\n", day_of_week(julian_day));

    return 0;
}