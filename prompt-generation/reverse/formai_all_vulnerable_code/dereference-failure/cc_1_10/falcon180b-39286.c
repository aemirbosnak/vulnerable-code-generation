//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TIME_TRAVELS 1000
#define TIME_TRAVEL_DELTA 1 // in seconds

struct time_travel {
    int time;
    int destination_time;
};

void print_time_travels(struct time_travel *time_travels, int num_time_travels) {
    for (int i = 0; i < num_time_travels; i++) {
        printf("Traveled from %d to %d\n", time_travels[i].time, time_travels[i].destination_time);
    }
}

int main() {
    srand(time(NULL));

    int num_time_travels = rand() % MAX_TIME_TRAVELS + 1;
    struct time_travel *time_travels = malloc(sizeof(struct time_travel) * num_time_travels);

    for (int i = 0; i < num_time_travels; i++) {
        time_travels[i].time = rand() % 10000; // random time between 0 and 9999
        time_travels[i].destination_time = time_travels[i].time + rand() % 10000; // random destination time between 0 and 9999
    }

    printf("You are about to embark on a journey through time!\n");
    printf("You will travel %d times.\n", num_time_travels);

    for (int i = 0; i < num_time_travels; i++) {
        int seconds_to_travel = abs(time_travels[i].destination_time - time_travels[i].time) / TIME_TRAVEL_DELTA;

        for (int j = 0; j < seconds_to_travel; j++) {
            int current_time = time_travels[i].time + j * TIME_TRAVEL_DELTA;
            printf("You are now traveling to the year %d...\n", current_time);
            sleep(1);
        }

        printf("You have arrived in the year %d!\n", time_travels[i].destination_time);
        sleep(2);
    }

    print_time_travels(time_travels, num_time_travels);

    free(time_travels);

    return 0;
}