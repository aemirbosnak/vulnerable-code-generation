//FormAI DATASET v1.0 Category: System event logger ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000

struct Event {
   int id;
   char *timestamp;
   char *description;
};

void log_event(struct Event **event_list, char *description);

int main() {
   int i;
   struct Event *event_list[MAX_EVENTS] = {NULL};
   
   for (i = 0; i < MAX_EVENTS; i++) {
      log_event(event_list, "System event logged");
   }

   for (i = 0; i < MAX_EVENTS; i++) {
      if (event_list[i] != NULL) {
         printf("Event %d: %s\n", event_list[i]->id, event_list[i]->description);
         free(event_list[i]->timestamp);
         free(event_list[i]->description);
         free(event_list[i]);
      }
   }

   return 0;
}

void log_event(struct Event **event_list, char *description) {
   static int current_id = 0;
   static int event_index = 0;
   time_t current_time = time(NULL);
   struct tm *tm_time = localtime(&current_time);
   char *timestamp = asctime(tm_time);

   if (event_index >= MAX_EVENTS) {
      printf("Error: Maximum number of events exceeded");
      exit(1);
   }

   struct Event *new_event = (struct Event *)malloc(sizeof(struct Event));

   if (new_event == NULL) {
      printf("Error: Unable to allocate memory for new event");
      exit(1);
   }

   new_event->id = current_id++;
   new_event->timestamp = timestamp;
   new_event->description = description;

   event_list[event_index++] = new_event;
}