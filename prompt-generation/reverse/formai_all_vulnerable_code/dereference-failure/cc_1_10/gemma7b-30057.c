//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULES 10

typedef struct Schedule {
    char name[20];
    int hour;
    int minute;
    struct Schedule* next;
} Schedule;

Schedule* head = NULL;

void addSchedule(char* name, int hour, int minute) {
    Schedule* newSchedule = (Schedule*)malloc(sizeof(Schedule));
    strcpy(newSchedule->name, name);
    newSchedule->hour = hour;
    newSchedule->minute = minute;
    newSchedule->next = head;
    head = newSchedule;
}

void printSchedules() {
    Schedule* currentSchedule = head;
    printf("List of schedules:\n");
    while (currentSchedule) {
        printf("%s (%d:%d)\n", currentSchedule->name, currentSchedule->hour, currentSchedule->minute);
        currentSchedule = currentSchedule->next;
    }
}

void findSchedule(char* name) {
    Schedule* currentSchedule = head;
    while (currentSchedule) {
        if (strcmp(currentSchedule->name, name) == 0) {
            printf("Schedule found: %s (%d:%d)\n", currentSchedule->name, currentSchedule->hour, currentSchedule->minute);
            return;
        }
        currentSchedule = currentSchedule->next;
    }
    printf("Schedule not found.\n");
}

int main() {
    addSchedule("Breakfast", 8, 0);
    addSchedule("Work", 9, 0);
    addSchedule("Lunch", 13, 0);
    addSchedule("Tea", 15, 0);
    addSchedule("Dinner", 19, 0);

    printSchedules();

    findSchedule("Lunch");

    return 0;
}