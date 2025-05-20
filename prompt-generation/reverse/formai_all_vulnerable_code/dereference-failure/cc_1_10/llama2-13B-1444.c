//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define DAYS_IN_A_WEEK 7
#define SLEEP_HOURS_PER_NIGHT 8

typedef struct {
    char day[30];
    char mood[30];
    int hours_sleep;
    int hours_awake;
    int activities[5];
} user_data;

user_data user;

void init_user_data() {
    strcpy(user.day, "Sunday");
    strcpy(user.mood, "Happy");
    user.hours_sleep = 7;
    user.hours_awake = 16;
    user.activities[0] = 3; // hours of exercise
    user.activities[1] = 2; // hours of work
    user.activities[2] = 1; // hours of relaxation
    user.activities[3] = 2; // hours of leisure
    user.activities[4] = 1; // hours of sleep
}

void log_activity(int activity) {
    user.activities[activity]++;
}

void log_mood() {
    char mood_str[30];
    gets(mood_str); // prompt user to enter their current mood
    strcpy(user.mood, mood_str);
}

void log_sleep() {
    int hours_sleep;
    gets(&hours_sleep); // prompt user to enter the number of hours slept
    user.hours_sleep = hours_sleep;
}

void display_stats() {
    printf("Weekly Activity Summary:\n");
    printf("Total hours spent on activities: %d\n", user.activities[0] + user.activities[1] + user.activities[2] + user.activities[3] + user.activities[4]);
    printf("Average hours slept per night: %d\n", user.hours_sleep / DAYS_IN_A_WEEK);
    printf("Average hours awake per day: %d\n", user.hours_awake / DAYS_IN_A_WEEK);
    printf("Mood distribution: %s\n", user.mood);
}

int main() {
    init_user_data();

    while (1) {
        log_activity(0); // exercise
        log_activity(1); // work
        log_activity(2); // relaxation
        log_activity(3); // leisure
        log_activity(4); // sleep

        log_mood();
        log_sleep();

        display_stats();
    }

    return 0;
}