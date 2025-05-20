//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fp = fopen("fitness_tracker.txt", "w");
    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    int reps, sets, weight;
    char exercise[10];
    int days;

    printf("Welcome to the C Fitness Tracker!\n");
    printf("Please enter the number of sets: ");
    scanf("%d", &sets);
    printf("Please enter the number of reps: ");
    scanf("%d", &reps);
    printf("Please enter the weight in pounds: ");
    scanf("%d", &weight);
    printf("Please enter the exercise: ");
    scanf("%s", exercise);
    printf("Please enter the number of days: ");
    scanf("%d", &days);

    for (int i = 1; i <= days; i++) {
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        int hour = timeinfo->tm_hour;
        int minute = timeinfo->tm_min;
        int second = timeinfo->tm_sec;

        char date[20];
        strftime(date, 20, "%Y-%m-%d %H:%M:%S", timeinfo);
        printf("Date: %s\n", date);
        printf("Weight: %d\n", weight);
        printf("Exercise: %s\n", exercise);
        printf("Reps: %d\n", reps);
        printf("Sets: %d\n", sets);
        printf("Time: %02d:%02d:%02d\n", hour, minute, second);

        fprintf(fp, "Date: %s\n", date);
        fprintf(fp, "Weight: %d\n", weight);
        fprintf(fp, "Exercise: %s\n", exercise);
        fprintf(fp, "Reps: %d\n", reps);
        fprintf(fp, "Sets: %d\n", sets);
        fprintf(fp, "Time: %02d:%02d:%02d\n", hour, minute, second);
        fprintf(fp, "\n");
    }

    fclose(fp);
    printf("Fitness Tracker Data saved successfully!\n");

    return 0;
}