//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

struct tm get_current_time() {
    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);
    return *timeinfo;
}

char* get_day_of_week(int day) {
    static char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days[day];
}

char* get_month_name(int month) {
    static char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month];
}

void print_date(struct tm date) {
    printf("Today is %s, %d %s %d\n", get_day_of_week(date.tm_wday), date.tm_mday, get_month_name(date.tm_mon + 1), date.tm_year + 1900);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s [date]\n", argv[0]);
        return 1;
    }

    char input_date[MAX_STRING_LENGTH];
    strcpy(input_date, argv[1]);

    struct tm date = get_current_time();

    if (sscanf(input_date, "%d %s %d", &date.tm_mday, date.tm_mon + 1, &date.tm_year)!= 3) {
        printf("Invalid date format\n");
        return 1;
    }

    if (date.tm_mday < 1 || date.tm_mday > 31 || date.tm_mon < 0 || date.tm_mon > 11) {
        printf("Invalid date\n");
        return 1;
    }

    print_date(date);

    return 0;
}