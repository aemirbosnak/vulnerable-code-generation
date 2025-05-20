//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TIME_TRAVELS 100
#define TIME_TRAVEL_DELTA 60

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

void print_time(const Time* time) {
    printf("%d-%02d-%02d %02d:%02d:%02d\n", time->year, time->month, time->day, time->hour, time->minute, time->second);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <time_travel_count>\n", argv[0]);
        return 1;
    }

    int time_travel_count = atoi(argv[1]);
    Time time = {2021, 1, 1, 0, 0, 0};
    Time time_travel_destinations[MAX_TIME_TRAVELS];

    printf("Enter %d time travel destinations:\n", time_travel_count);
    for (int i = 0; i < time_travel_count; i++) {
        printf("Destination %d: ", i + 1);
        scanf("%d-%02d-%02d %02d:%02d:%02d", &time_travel_destinations[i].year, &time_travel_destinations[i].month, &time_travel_destinations[i].day, &time_travel_destinations[i].hour, &time_travel_destinations[i].minute, &time_travel_destinations[i].second);
    }

    for (int i = 0; i < time_travel_count; i++) {
        printf("Time travel %d:\n", i + 1);
        time.year = time_travel_destinations[i].year;
        time.month = time_travel_destinations[i].month;
        time.day = time_travel_destinations[i].day;
        time.hour = time_travel_destinations[i].hour;
        time.minute = time_travel_destinations[i].minute;
        time.second = time_travel_destinations[i].second;
        print_time(&time);
        printf("Press enter to continue...\n");
        getchar();
    }

    return 0;
}