//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TIME_TRAVELS 100
#define TIME_TRAVEL_SPEED 1.21 // 1.21 gigawatts!

struct time_travel {
    time_t departure;
    time_t arrival;
    int duration;
};

int main() {
    srand(time(NULL));

    struct time_travel time_travels[MAX_TIME_TRAVELS];
    int num_time_travels = 0;

    while (num_time_travels < MAX_TIME_TRAVELS) {
        time_t departure = rand() % (time(NULL) + 1000000000);
        time_t arrival = departure + rand() % 1000000000;

        if (arrival < departure) {
            arrival += 86400; // add a day to avoid negative time difference
        }

        int duration = difftime(arrival, departure);

        if (duration > 0) {
            time_travels[num_time_travels] = (struct time_travel) {
               .departure = departure,
               .arrival = arrival,
               .duration = duration
            };

            num_time_travels++;
        }
    }

    for (int i = 0; i < num_time_travels; i++) {
        struct time_travel time_travel = time_travels[i];

        printf("Time travel #%d:\n", i + 1);
        printf("Departure: %s", ctime(&time_travel.departure));
        printf("Arrival: %s\n", ctime(&time_travel.arrival));
        printf("Duration: %d seconds\n\n", time_travel.duration);
    }

    return 0;
}