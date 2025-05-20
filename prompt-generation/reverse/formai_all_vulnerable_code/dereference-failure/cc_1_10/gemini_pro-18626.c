//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: ephemeral
/* Ephemeral Date Converter */

#include <stdio.h>
#include <string.h>
#include <time.h>

typedef enum {
    GREGORIAN,
    JULIAN
} Calendar;

typedef struct {
    int year;
    int month;
    int day;
} Date;

static char *months[] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
};

static int days_in_month[] = {
    31, 28, 31, 30,
    31, 30, 31, 31,
    30, 31, 30, 31
};

static int is_leap_year(int year) {
    /* A leap year is a year divisible by 4 but not by 100, or a year divisible by 400. */
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

static inline int days_since_epoch(Date d) {
    /* Calculate the number of days since the start of the Gregorian calendar. */
    int days = d.year * 365 + d.year / 4 - d.year / 100 + d.year / 400;
    days += d.month * 30 + d.day;
    if (is_leap_year(d.year) && d.month >= 3) days += 1;
    return days;
}

static Date date_from_days(int days) {
    /* Convert the number of days since the start of the Gregorian calendar to a date. */
    Date d = {0};
    d.year = 1 + days / 365;
    days %= 365;
    while (days >= (is_leap_year(d.year) ? 366 : 365)) {
        days -= (is_leap_year(d.year) ? 366 : 365);
        d.year += 1;
    }
    while (days >= 30) {
        days -= 30;
        d.month += 1;
    }
    d.day = 1 + days;
    return d;
}

static void print_date(const char *label, Date d, Calendar calendar) {
    /* Print a date in a human-readable format. */
    printf("%-10s: %d %s %d\n", label, d.day, months[d.month - 1], d.year);
    if (calendar == JULIAN) printf(" (Julian)\n");
}

int main(int argc, char *argv[]) {
    /* Get the date from the command line. */
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <year> <month> <day>\n", argv[0]);
        return 1;
    }
    Date d = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3])};

    /* Convert the date to the Gregorian calendar. */
    Date gregorian = d;
    if (gregorian.year < 1582 || (gregorian.year == 1582 && (gregorian.month == 10 || (gregorian.month == 10 && gregorian.day > 14))))
        gregorian.day -= 10;

    /* Print the date in both calendars. */
    print_date("Date", d, JULIAN);
    print_date("Gregorian", gregorian, GREGORIAN);

    /* Calculate the number of days between the two dates. */
    int days_between = days_since_epoch(gregorian) - days_since_epoch(d);
    printf("Days between: %d\n", days_between);

    /* Add 10 days to the Julian date and convert it to the Gregorian calendar. */
    d.day += 10;
    gregorian = date_from_days(days_since_epoch(d));
    printf("Add 10 days to Julian and convert:\n");
    print_date("Julian", d, JULIAN);
    print_date("Gregorian", gregorian, GREGORIAN);

    return 0;
}