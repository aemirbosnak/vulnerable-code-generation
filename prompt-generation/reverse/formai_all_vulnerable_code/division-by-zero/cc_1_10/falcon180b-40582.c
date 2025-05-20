//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 100
#define MAX_TIME_PERIODS 100

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} TimePeriod;

int main() {
    int numTimeTravels, i;
    TimePeriod timePeriods[MAX_TIME_PERIODS];
    char choice;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the number of time periods you would like to travel to: ");
    scanf("%d", &numTimeTravels);

    for (i = 0; i < numTimeTravels; i++) {
        printf("Enter the details for time period %d:\n", i+1);
        printf("Year: ");
        scanf("%d", &timePeriods[i].year);
        printf("Month: ");
        scanf("%d", &timePeriods[i].month);
        printf("Day: ");
        scanf("%d", &timePeriods[i].day);
        printf("Hour: ");
        scanf("%d", &timePeriods[i].hour);
        printf("Minute: ");
        scanf("%d", &timePeriods[i].minute);
        printf("Second: ");
        scanf("%d", &timePeriods[i].second);
    }

    printf("Please enter your choice of time travel:\n");
    printf("A) Travel to a specific time period\n");
    printf("B) Randomly travel through time\n");
    scanf(" %c", &choice);

    if (choice == 'A') {
        int timePeriodIndex;

        printf("Enter the index of the time period you would like to travel to: ");
        scanf("%d", &timePeriodIndex);

        struct tm time = {0};
        time.tm_year = timePeriods[timePeriodIndex-1].year - 1900;
        time.tm_mon = timePeriods[timePeriodIndex-1].month - 1;
        time.tm_mday = timePeriods[timePeriodIndex-1].day;
        time.tm_hour = timePeriods[timePeriodIndex-1].hour;
        time.tm_min = timePeriods[timePeriodIndex-1].minute;
        time.tm_sec = timePeriods[timePeriodIndex-1].second;

        printf("You are now traveling through time to %d-%d-%d %d:%d:%d...\n",
               time.tm_year+1900, time.tm_mon+1, time.tm_mday,
               time.tm_hour, time.tm_min, time.tm_sec);

        mktime(&time);
    } else if (choice == 'B') {
        int numRandomTravels;

        printf("Enter the number of random time periods you would like to travel to: ");
        scanf("%d", &numRandomTravels);

        srand(time(NULL));

        for (i = 0; i < numRandomTravels; i++) {
            int randomIndex = rand() % numTimeTravels;

            time_t now = time(NULL);
            struct tm *t = localtime(&now);

            printf("You are now traveling through time to %d-%d-%d %d:%d:%d...\n",
                   t->tm_year+1900, t->tm_mon+1, t->tm_mday,
                   t->tm_hour, t->tm_min, t->tm_sec);

            mktime(t);
        }
    }

    return 0;
}