//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MONTH_NAMES "January February March April May June July August September October November December"
#define WEEK_DAY_NAMES "Sunday Monday Tuesday Wednesday Thursday Friday Saturday"

void print_help() {
    printf("Usage:./date_converter [date_string]\n");
    printf("Date string format: yyyy-mm-dd\n");
    printf("Example: 2021-08-15\n");
}

void convert_date_to_words(char* date_string) {
    struct tm* tm_struct = NULL;
    time_t time = 0;

    if (strlen(date_string)!= 10 || sscanf(date_string, "%d-%d-%d", &time, &tm_struct->tm_mon, &tm_struct->tm_mday)!= 3) {
        printf("Invalid date format\n");
        return;
    }

    tm_struct->tm_year = time / 10000 - 1900;
    tm_struct->tm_mon -= 1;
    tm_struct->tm_wday = 0;

    time = mktime(tm_struct);

    if (time == -1) {
        printf("Invalid date\n");
        return;
    }

    printf("Today is ");

    if (tm_struct->tm_wday == 0) {
        printf("Sunday");
    } else {
        printf("%s", WEEK_DAY_NAMES + (tm_struct->tm_wday * 8));
    }

    printf(", ");

    if (tm_struct->tm_mon == 0) {
        tm_struct->tm_mon = 12;
        tm_struct->tm_year--;
    }

    printf("%s %d, %d\n", MONTH_NAMES + (tm_struct->tm_mon * 3), tm_struct->tm_mday, tm_struct->tm_year + 1900);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        print_help();
        return 1;
    }

    convert_date_to_words(argv[1]);

    return 0;
}