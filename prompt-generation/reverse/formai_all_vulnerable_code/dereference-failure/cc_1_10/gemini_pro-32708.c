//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct {
  char *name;
  int steps;
  int distance;
  int calories;
  time_t timestamp;
} entry_t;

typedef struct {
  entry_t *entries;
  int num_entries;
  int capacity;
} tracker_t;

tracker_t *tracker_create(int capacity) {
  tracker_t *tracker = malloc(sizeof(tracker_t));
  tracker->entries = malloc(capacity * sizeof(entry_t));
  tracker->num_entries = 0;
  tracker->capacity = capacity;
  return tracker;
}

void tracker_destroy(tracker_t *tracker) {
  for (int i = 0; i < tracker->num_entries; i++) {
    free(tracker->entries[i].name);
  }
  free(tracker->entries);
  free(tracker);
}

void tracker_add_entry(tracker_t *tracker, char *name, int steps, int distance, int calories) {
  if (tracker->num_entries == tracker->capacity) {
    tracker->entries = realloc(tracker->entries, tracker->capacity * 2 * sizeof(entry_t));
    tracker->capacity *= 2;
  }
  entry_t *entry = &tracker->entries[tracker->num_entries++];
  entry->name = strdup(name);
  entry->steps = steps;
  entry->distance = distance;
  entry->calories = calories;
  entry->timestamp = time(NULL);
}

void tracker_print_entries(tracker_t *tracker) {
  for (int i = 0; i < tracker->num_entries; i++) {
    entry_t *entry = &tracker->entries[i];
    printf("%s: %d steps, %d distance, %d calories, %s\n", entry->name, entry->steps, entry->distance, entry->calories, ctime(&entry->timestamp));
  }
}

int main() {
  tracker_t *tracker = tracker_create(10);
  tracker_add_entry(tracker, "Running", 1000, 1000, 100);
  tracker_add_entry(tracker, "Cycling", 500, 500, 50);
  tracker_add_entry(tracker, "Swimming", 250, 250, 25);
  tracker_print_entries(tracker);
  tracker_destroy(tracker);
  return 0;
}