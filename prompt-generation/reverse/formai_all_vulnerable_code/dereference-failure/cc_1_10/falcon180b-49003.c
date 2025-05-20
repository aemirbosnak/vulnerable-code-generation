//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TIME_TRAVELERS 10
#define TIME_TRAVEL_DELAY 2

typedef struct {
    int id;
    int destination_year;
    time_t departure_time;
    time_t arrival_time;
} TimeTraveler;

void *time_travel(void *arg) {
    TimeTraveler *traveler = (TimeTraveler *) arg;
    time_t current_time = time(NULL);

    while (current_time < traveler->departure_time) {
        printf("Time traveler %d is preparing for departure to the year %d...\n", traveler->id, traveler->destination_year);
        sleep(1);
        current_time = time(NULL);
    }

    printf("Time traveler %d has departed to the year %d.\n", traveler->id, traveler->destination_year);
    sleep(TIME_TRAVEL_DELAY);

    while (current_time < traveler->arrival_time) {
        printf("Time traveler %d is traveling through time...\n", traveler->id);
        sleep(1);
        current_time = time(NULL);
    }

    printf("Time traveler %d has arrived in the year %d.\n", traveler->id, traveler->destination_year);
    return NULL;
}

int main() {
    int num_time_travelers = 0;
    TimeTraveler travelers[MAX_TIME_TRAVELERS];

    printf("Enter the number of time travelers (up to %d): ", MAX_TIME_TRAVELERS);
    scanf("%d", &num_time_travelers);

    for (int i = 0; i < num_time_travelers; i++) {
        printf("Enter the departure year for time traveler %d: ", i+1);
        scanf("%d", &travelers[i].destination_year);

        time_t current_time = time(NULL);
        struct tm *now = localtime(&current_time);
        now->tm_year += travelers[i].destination_year;
        travelers[i].departure_time = mktime(now);

        printf("Time traveler %d will depart at %s.\n", i+1, ctime(&travelers[i].departure_time));
    }

    pthread_t threads[MAX_TIME_TRAVELERS];

    for (int i = 0; i < num_time_travelers; i++) {
        pthread_create(&threads[i], NULL, time_travel, &travelers[i]);
    }

    for (int i = 0; i < num_time_travelers; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}