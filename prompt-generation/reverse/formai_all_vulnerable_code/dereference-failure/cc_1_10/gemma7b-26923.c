//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SUSPECTS 10

typedef struct Suspect {
  char name[50];
  int id;
  struct Suspect* next;
} Suspect;

Suspect* suspect_list = NULL;

void add_suspect(char* name, int id) {
  Suspect* new_suspect = malloc(sizeof(Suspect));
  strcpy(new_suspect->name, name);
  new_suspect->id = id;
  new_suspect->next = NULL;

  if (suspect_list == NULL) {
    suspect_list = new_suspect;
  } else {
    suspect_list->next = new_suspect;
    suspect_list = new_suspect;
  }
}

void check_intrusion(char* suspect_name) {
  Suspect* current_suspect = suspect_list;

  while (current_suspect) {
    if (strcmp(current_suspect->name, suspect_name) == 0) {
      printf("Suspect %s has been detected!\n", suspect_name);
      break;
    }
    current_suspect = current_suspect->next;
  }

  if (current_suspect == NULL) {
    printf("Suspect %s not found.\n", suspect_name);
  }
}

int main() {
  add_suspect("John Doe", 1);
  add_suspect("Jane Doe", 2);
  add_suspect("Bob Smith", 3);

  check_intrusion("John Doe");
  check_intrusion("Jane Doe");
  check_intrusion("Bob Smith");
  check_intrusion("Alice White");

  return 0;
}