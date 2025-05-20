//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct tm get_date(char* date_str) {
    struct tm result = {0};
    int i = 0;
    char* token = strtok(date_str, " ");

    while (token!= NULL) {
        if (i == 0) {
            result.tm_mday = atoi(token);
        } else if (i == 1) {
            result.tm_mon = atoi(token) - 1;
        } else if (i == 2) {
            result.tm_year = atoi(token) - 1900;
        }
        i++;
        token = strtok(NULL, " ");
    }

    result.tm_year += 1900;
    result.tm_mon++;

    return result;
}

char* get_day_of_week(struct tm date) {
    static char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    return days[date.tm_wday];
}

char* get_month_name(int month) {
    static char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    return months[month];
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <date>\n", argv[0]);
        return 1;
    }

    char* date_str = argv[1];
    struct tm date = get_date(date_str);
    printf("Today is %s, %d %s %d\n", get_day_of_week(date), date.tm_mday, get_month_name(date.tm_mon), date.tm_year);

    return 0;
}