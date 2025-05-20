//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: visionary
// Ode to the Ivory Tower of Epistles

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A missive, a digital quill's stroke
typedef struct {
  char *to;
  char *from;
  char *subject;
  char *body;
  time_t timestamp;
  int read;
} Epistle;

// A repository of scribes and their exchanges
typedef struct {
  Epistle **epistles;
  int count;
  int capacity;
} Archive;

// The grand master of correspondence
typedef struct {
  Archive inbox;
  Archive outbox;
} MailingList;

// The genesis of a new list, a blank canvas for words
MailingList *new_list() {
  MailingList *list = malloc(sizeof(MailingList));
  list->inbox.epistles = NULL;
  list->inbox.count = 0;
  list->inbox.capacity = 0;
  list->outbox.epistles = NULL;
  list->outbox.count = 0;
  list->outbox.capacity = 0;
  return list;
}

// A new missive, ready to convey thoughts
Epistle *new_epistle(char *to, char *from, char *subject, char *body) {
  Epistle *epistle = malloc(sizeof(Epistle));
  epistle->to = strdup(to);
  epistle->from = strdup(from);
  epistle->subject = strdup(subject);
  epistle->body = strdup(body);
  epistle->timestamp = time(NULL);
  epistle->read = 0;
  return epistle;
}

// Compose a missive and add it to the outbox
void compose_epistle(MailingList *list, char *to, char *from, char *subject, char *body) {
  Epistle *epistle = new_epistle(to, from, subject, body);
  if (list->outbox.count == list->outbox.capacity) {
    list->outbox.epistles = realloc(list->outbox.epistles, 2 * list->outbox.capacity * sizeof(Epistle *));
    list->outbox.capacity *= 2;
  }
  list->outbox.epistles[list->outbox.count++] = epistle;
}

// Retrieve a missive from the inbox by index
Epistle *get_inbox_epistle(MailingList *list, int index) {
  if (index < 0 || index >= list->inbox.count) return NULL;
  return list->inbox.epistles[index];
}

// Mark a missive as read
void mark_epistle_read(MailingList *list, Epistle *epistle) {
  epistle->read = 1;
}

// Print a missive to the screen
void print_epistle(Epistle *epistle) {
  printf("To: %s\n", epistle->to);
  printf("From: %s\n", epistle->from);
  printf("Subject: %s\n", epistle->subject);
  printf("Body: %s\n", epistle->body);
  printf("Timestamp: %s\n", ctime(&epistle->timestamp));
  printf("Read: %s\n", epistle->read ? "Yes" : "No");
}

// The main orchestrator, where epistles take flight
int main() {
  MailingList *list = new_list();

  // Compose and send a few missives
  compose_epistle(list, "friend@example.com", "me@example.com", "Hello from the future", "How are you doing in the year 2023?");
  compose_epistle(list, "colleague@example.com", "me@example.com", "Regarding the project", "I've made some progress on the report, and I'd like to discuss it with you");

  // Fetch and print the inbox missives
  for (int i = 0; i < list->inbox.count; i++) {
    Epistle *epistle = get_inbox_epistle(list, i);
    print_epistle(epistle);
  }

  // Mark the first missive as read
  mark_epistle_read(list, get_inbox_epistle(list, 0));

  return 0;
}