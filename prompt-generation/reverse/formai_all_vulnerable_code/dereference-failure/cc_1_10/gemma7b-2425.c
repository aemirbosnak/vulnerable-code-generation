//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SCHEDULES 3
#define MAX_SCHEDULE_TIME 60

typedef struct Schedule {
    char name[20];
    int start, end;
    struct Schedule* next;
} Schedule;

Schedule* head = NULL;

void addSchedule(char* name, int start, int end) {
    Schedule* newSchedule = (Schedule*)malloc(sizeof(Schedule));
    strcpy(newSchedule->name, name);
    newSchedule->start = start;
    newSchedule->end = end;
    newSchedule->next = NULL;

    if (head == NULL) {
        head = newSchedule;
    } else {
        head->next = newSchedule;
    }
}

void printSchedules() {
    Schedule* currentSchedule = head;
    while (currentSchedule) {
        printf("%s: %d - %d\n", currentSchedule->name, currentSchedule->start, currentSchedule->end);
        currentSchedule = currentSchedule->next;
    }
}

int main() {
    addSchedule("Breakfast", 8, 10);
    addSchedule("Work", 9, 17);
    addSchedule("Dinner", 18, 20);

    printSchedules();

    time_t currentTime = time(NULL);
    int currentHour = currentTime / 3600;

    for (Schedule* currentSchedule = head; currentSchedule; currentSchedule = currentSchedule->next) {
        if (currentHour >= currentSchedule->start && currentHour <= currentSchedule->end) {
            printf("It is currently %d:00, therefore you should be %s.\n", currentHour, currentSchedule->name);
        }
    }

    return 0;
}