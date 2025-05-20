//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define MAX_DATE_LEN 20
#define MAX_MONTH_LEN 9
#define MAX_YEAR_LEN 4

enum {
    JANUARY = 1,
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

struct tm get_date(const char* date_str) {
    struct tm result = {0};
    char* p = strptime(date_str, "%d %b %Y", &result);
    if (p == NULL || *p!= '\0') {
        printf("Invalid date format: %s\n", date_str);
        exit(1);
    }
    return result;
}

const char* month_name(int month) {
    static const char* names[] = {
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };
    return names[month - 1];
}

void print_date(struct tm date) {
    printf("%s, %d %s %d\n", month_name(date.tm_mon + 1), date.tm_mday, (date.tm_mon == 11? "December" : ""), date.tm_year + 1900);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <date>\n", argv[0]);
        exit(1);
    }

    char date_str[MAX_DATE_LEN + 1] = {0};
    strncpy(date_str, argv[1], MAX_DATE_LEN);

    struct tm date = get_date(date_str);
    print_date(date);

    return 0;
}