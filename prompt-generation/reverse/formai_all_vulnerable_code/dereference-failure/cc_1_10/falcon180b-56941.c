//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MONTHS 12

struct date {
    int day;
    int month;
    int year;
};

void print_date(struct date d) {
    printf("%d/%d/%d\n", d.month, d.day, d.year);
}

int is_leap_year(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100!= 0)) {
        return 1;
    } else {
        return 0;
    }
}

int days_in_month(int month, int year) {
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

struct date parse_date(char *str) {
    struct date d;
    char *token;
    int i;

    token = strtok(str, "/");
    d.month = atoi(token);
    token = strtok(NULL, "/");
    d.day = atoi(token);
    token = strtok(NULL, "/");
    d.year = atoi(token);

    if (d.month < 1 || d.month > MONTHS) {
        printf("Invalid month\n");
        exit(1);
    }

    if (d.day < 1 || d.day > days_in_month(d.month, d.year)) {
        printf("Invalid day\n");
        exit(1);
    }

    if (d.year < 1000 || d.year > 9999) {
        printf("Invalid year\n");
        exit(1);
    }

    return d;
}

int main() {
    char input[100];
    struct date d;

    printf("Enter a date in the format MM/DD/YYYY: ");
    fgets(input, sizeof(input), stdin);
    d = parse_date(input);
    print_date(d);

    return 0;
}