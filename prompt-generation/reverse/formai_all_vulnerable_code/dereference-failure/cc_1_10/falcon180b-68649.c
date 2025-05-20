//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LENGTH 100
#define DAYS_IN_MONTH(month, year) ((month) == 2 && ((year) % 4 == 0 && (year) % 100!= 0)? 29 : ((month) == 4 || (month) == 6 || (month) == 9 || (month) == 11)? 30 : 31)

typedef struct {
    int day;
    int month;
    int year;
} Date;

char *get_month_name(int month) {
    static char *month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return month_names[month - 1];
}

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100!= 0) || year % 400 == 0;
}

int is_valid_date(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return 0;
    }
    if (day < 1 || day > DAYS_IN_MONTH(month, year)) {
        return 0;
    }
    return 1;
}

void print_date(Date date) {
    printf("%s %d, %d\n", get_month_name(date.month), date.day, date.year);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <day> <month> <year>\n", argv[0]);
        return 1;
    }
    Date date;
    date.day = atoi(argv[1]);
    date.month = atoi(argv[2]);
    date.year = atoi(argv[3]);
    if (!is_valid_date(date.day, date.month, date.year)) {
        printf("Invalid date.\n");
        return 1;
    }
    print_date(date);
    return 0;
}