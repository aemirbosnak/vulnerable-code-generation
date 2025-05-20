//FormAI DATASET v1.0 Category: Date and time ; Style: shocked
#include <stdio.h>
#include <time.h>

int main()
{
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
 
    // Print the date in the format of day/month/year
    printf("Today's date is %d/%d/%d\n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);

    // Print the current time in the 12-hour format
    if (tm->tm_hour < 12) {
        printf("The current time is %d:%02d AM\n", tm->tm_hour, tm->tm_min);
    }
    else {
        printf("The current time is %d:%02d PM\n", tm->tm_hour - 12, tm->tm_min);
    }

    // Print the current time with seconds and microseconds
    printf("The current time with seconds and microseconds is %d:%02d:%02d.%06ld\n", tm->tm_hour, tm->tm_min, tm->tm_sec, 
           (long) (t * 1000000 % 1000000));

    // Print the current day of the week
    printf("Today is ");
    switch (tm->tm_wday) {
        case 0:
            printf("Sunday");
            break;
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
        default:
            printf("Error");
            break;
    }
    printf("\n");

    return 0;
}