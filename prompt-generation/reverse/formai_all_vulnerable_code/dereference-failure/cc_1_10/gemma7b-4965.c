//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PAST 10
#define MAX_FUTURE 20

typedef struct TimeCapsule {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
  struct TimeCapsule* next;
} TimeCapsule;

TimeCapsule* createTimeCapsule(int year, int month, int day, int hour, int minute, int second) {
  TimeCapsule* capsule = malloc(sizeof(TimeCapsule));
  capsule->year = year;
  capsule->month = month;
  capsule->day = day;
  capsule->hour = hour;
  capsule->minute = minute;
  capsule->second = second;
  capsule->next = NULL;
  return capsule;
}

void addTimeCapsule(TimeCapsule* head, int year, int month, int day, int hour, int minute, int second) {
  TimeCapsule* capsule = createTimeCapsule(year, month, day, hour, minute, second);
  if (head == NULL) {
    head = capsule;
  } else {
     capsule->next = head;
    head = capsule;
  }
}

void printTimeCapsules(TimeCapsule* head) {
  while (head) {
    printf("%d-%d-%d %d:%d:%d\n", head->year, head->month, head->day, head->hour, head->minute, head->second);
    head = head->next;
  }
}

int main() {
  TimeCapsule* head = NULL;
  addTimeCapsule(head, 2023, 6, 1, 12, 0, 0);
  addTimeCapsule(head, 2024, 1, 1, 12, 0, 0);
  addTimeCapsule(head, 2025, 6, 1, 12, 0, 0);
  printTimeCapsules(head);
  return 0;
}