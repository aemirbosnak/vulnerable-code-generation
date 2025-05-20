//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: Ken Thompson
#include <time.h>
#include <stdlib.h>

static char *months[] = {
    [0] = "January",
    [1] = "February",
    [2] = "March",
    [3] = "April",
    [4] = "May",
    [5] = "June",
    [6] = "July",
    [7] = "August",
    [8] = "September",
    [9] = "October",
    [10] = "November",
    [11] = "December"
};

static char *dow[] = {
    [0] = "Sunday",
    [1] = "Monday",
    [2] = "Tuesday",
    [3] = "Wednesday",
    [4] = "Thursday",
    [5] = "Friday",
    [6] = "Saturday"
};

static char *shortdow[] = {
    [0] = "Sun",
    [1] = "Mon",
    [2] = "Tue",
    [3] = "Wed",
    [4] = "Thu",
    [5] = "Fri",
    [6] = "Sat"
};

int
main(void)
{
    time_t t;
    struct tm *tm;

    t = time(NULL);
    tm = localtime(&t);

    printf("Today is %s %s %d %s %d %s %d:%02d:%02d.\n",
           dow[tm->tm_wday],
           shortdow[tm->tm_wday],
           tm->tm_mday,
           months[tm->tm_mon],
           tm->tm_year + 1900,
           ctime(&t),
           tm->tm_hour,
           tm->tm_min,
           tm->tm_sec);

    return 0;
}