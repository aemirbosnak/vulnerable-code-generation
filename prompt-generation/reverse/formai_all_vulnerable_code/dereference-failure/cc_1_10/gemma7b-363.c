//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HISTORY 10

typedef struct Memory {
  char name[50];
  int year;
  struct Memory *next;
} Memory;

Memory *head = NULL;

void add_memory(char *name, int year) {
  Memory *new_mem = malloc(sizeof(Memory));
  strcpy(new_mem->name, name);
  new_mem->year = year;
  new_mem->next = NULL;

  if (head == NULL) {
    head = new_mem;
  } else {
    head->next = new_mem;
  }
}

void time_travel(int year) {
  Memory *current = head;
  while (current) {
    if (current->year == year) {
      printf("Greetings, %s! You are in the year %d.\n", current->name, year);
      printf("Here is a list of your memories from that year:");
      for (Memory *mem = current; mem; mem = mem->next) {
        printf(" - %s in %d\n", mem->name, mem->year);
      }
      break;
    } else if (current->year < year) {
      printf("You have not yet created any memories in the year %d.\n", year);
      break;
    }
    current = current->next;
  }

  if (current == NULL) {
    printf("No memories found for the year %d.\n", year);
  }
}

int main() {
  add_memory("Sir William", 1001);
  add_memory("Lady Alice", 1002);
  add_memory("Young John", 1003);

  time_travel(1002);

  return 0;
}