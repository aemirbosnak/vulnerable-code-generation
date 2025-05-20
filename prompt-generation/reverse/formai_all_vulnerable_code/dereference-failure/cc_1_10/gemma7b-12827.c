//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HISTORY_SIZE 10

typedef struct TimeTravelRecord {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    struct TimeTravelRecord* next;
} TimeTravelRecord;

TimeTravelRecord* createTimeTravelRecord(int year, int month, int day, int hour, int minute) {
    TimeTravelRecord* newRecord = malloc(sizeof(TimeTravelRecord));
    newRecord->year = year;
    newRecord->month = month;
    newRecord->day = day;
    newRecord->hour = hour;
    newRecord->minute = minute;
    newRecord->next = NULL;

    return newRecord;
}

void addTimeTravelRecord(TimeTravelRecord** head, int year, int month, int day, int hour, int minute) {
    TimeTravelRecord* newRecord = createTimeTravelRecord(year, month, day, hour, minute);

    if (*head == NULL) {
        *head = newRecord;
    } else {
        (*head)->next = newRecord;
    }
}

void printTimeTravelRecord(TimeTravelRecord* head) {
    while (head) {
        printf("%d-%d-%d %d:%d: ", head->year, head->month, head->day, head->hour, head->minute);
        head = head->next;
    }
}

int main() {
    TimeTravelRecord* head = NULL;

    // Simulate time travel by adding records
    addTimeTravelRecord(&head, 2023, 10, 26, 12, 0);
    addTimeTravelRecord(&head, 2023, 10, 26, 13, 0);
    addTimeTravelRecord(&head, 2023, 10, 26, 14, 0);

    // Print time travel records
    printTimeTravelRecord(head);

    return 0;
}