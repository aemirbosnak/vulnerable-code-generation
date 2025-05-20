//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: protected
#include <stdio.h>
#include <time.h>

#define MAX_PAST 3
#define MAX_FUTURE 5

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

void addTimeTravelRecord(TimeTravelRecord* head, int year, int month, int day, int hour, int minute) {
    TimeTravelRecord* newRecord = createTimeTravelRecord(year, month, day, hour, minute);
    if (head == NULL) {
        head = newRecord;
    } else {
        TimeTravelRecord* currentRecord = head;
        while (currentRecord->next) {
            currentRecord = currentRecord->next;
        }
        currentRecord->next = newRecord;
    }
}

void printTimeTravelRecords(TimeTravelRecord* head) {
    TimeTravelRecord* currentRecord = head;
    while (currentRecord) {
        printf("Year: %d, Month: %d, Day: %d, Hour: %d, Minute: %d\n", currentRecord->year, currentRecord->month, currentRecord->day, currentRecord->hour, currentRecord->minute);
        currentRecord = currentRecord->next;
    }
}

int main() {
    TimeTravelRecord* head = NULL;
    addTimeTravelRecord(head, 2023, 4, 1, 10, 0);
    addTimeTravelRecord(head, 2023, 4, 2, 12, 0);
    addTimeTravelRecord(head, 2023, 4, 3, 14, 0);
    printTimeTravelRecords(head);

    return 0;
}