//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 1024

typedef struct {
  int id;
  time_t timestamp;
  char *text;
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int num_entries = 0;
pthread_mutex_t lock;

void *write_entry(void *arg) {
  pthread_mutex_lock(&lock);
  int id = num_entries++;
  time_t timestamp = time(NULL);
  char *text = (char *)arg;

  entries[id].id = id;
  entries[id].timestamp = timestamp;
  entries[id].text = strdup(text);

  pthread_mutex_unlock(&lock);

  return NULL;
}

void *read_entries(void *arg) {
  pthread_mutex_lock(&lock);
  for (int i = 0; i < num_entries; i++) {
    printf("Entry %d:\n", entries[i].id);
    printf("Timestamp: %ld\n", entries[i].timestamp);
    printf("Text: %s\n\n", entries[i].text);
  }
  pthread_mutex_unlock(&lock);

  return NULL;
}

int main() {
  pthread_t write_thread, read_thread;

  pthread_mutex_init(&lock, NULL);

  char *text1 = "This is the first entry.";
  char *text2 = "This is the second entry.";

  pthread_create(&write_thread, NULL, write_entry, text1);
  pthread_create(&read_thread, NULL, read_entries, NULL);

  pthread_join(write_thread, NULL);
  pthread_join(read_thread, NULL);

  pthread_mutex_destroy(&lock);

  return 0;
}