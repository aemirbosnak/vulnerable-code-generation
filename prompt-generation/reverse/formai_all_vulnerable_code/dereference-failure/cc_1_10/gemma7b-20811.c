//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: complex
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_TIME_TRAVEL 10

typedef struct TimeTravelRecord {
    int year, month, day, hour, minute, second;
    struct TimeTravelRecord* next;
} TimeTravelRecord;

TimeTravelRecord* insertTimeTravelRecord(TimeTravelRecord* head, int year, int month, int day, int hour, int minute, int second) {
    TimeTravelRecord* newRecord = malloc(sizeof(TimeTravelRecord));
    newRecord->year = year;
    newRecord->month = month;
    newRecord->day = day;
    newRecord->hour = hour;
    newRecord->minute = minute;
    newRecord->second = second;
    newRecord->next = NULL;

    if (head == NULL) {
        head = newRecord;
    } else {
        TimeTravelRecord* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newRecord;
    }

    return head;
}

void displayTimeTravelRecord(TimeTravelRecord* head) {
    TimeTravelRecord* currentRecord = head;
    while (currentRecord) {
        printf("Year: %d, Month: %d, Day: %d, Hour: %d, Minute: %d, Second: %d\n",
            currentRecord->year, currentRecord->month, currentRecord->day, currentRecord->hour,
            currentRecord->minute, currentRecord->second);
        currentRecord = currentRecord->next;
    }
}

int main() {
    TimeTravelRecord* head = NULL;

    // Insert some time travel records
    insertTimeTravelRecord(head, 2023, 10, 20, 12, 0, 0);
    insertTimeTravelRecord(head, 2022, 12, 25, 18, 0, 0);
    insertTimeTravelRecord(head, 2021, 8, 10, 10, 0, 0);

    // Display the time travel records
    displayTimeTravelRecord(head);

    return 0;
}