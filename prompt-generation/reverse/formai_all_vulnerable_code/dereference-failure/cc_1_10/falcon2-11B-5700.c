//Falcon2-11B DATASET v1.0 Category: Time Travel Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    struct tm t1, t2;
    int days = 0;
    int years = 0;

    if (argc == 3)
    {
        days = atoi(argv[1]);
        years = atoi(argv[2]);
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "days") == 0)
        {
            days = atoi(argv[2]);
        }
        else if (strcmp(argv[1], "years") == 0)
        {
            years = atoi(argv[2]);
        }
        else
        {
            printf("Invalid input. Please enter either 'days' or 'years'.\n");
            return 1;
        }
    }

    time_t now = time(NULL);
    t1 = *localtime(&now);

    if (years > 0)
    {
        t2 = t1;
        t2.tm_year += years;
        t2 = *localtime(&t2);
        now = mktime(&t2);
    }
    else if (years < 0)
    {
        t2 = t1;
        t2.tm_year -= years;
        t2 = *localtime(&t2);
        now = mktime(&t2);
    }
    else if (days > 0)
    {
        t2 = t1;
        t2.tm_year = t1.tm_year;
        t2.tm_mon = t1.tm_mon;
        t2.tm_mday += days;
        t2 = *localtime(&t2);
        now = mktime(&t2);
    }
    else if (days < 0)
    {
        t2 = t1;
        t2.tm_year = t1.tm_year;
        t2.tm_mon = t1.tm_mon;
        t2.tm_mday -= days;
        t2 = *localtime(&t2);
        now = mktime(&t2);
    }
    else
    {
        printf("Invalid input. Please enter either 'days' or 'years'.\n");
        return 1;
    }

    printf("Current time: %s\n", asctime(&now));

    return 0;
}