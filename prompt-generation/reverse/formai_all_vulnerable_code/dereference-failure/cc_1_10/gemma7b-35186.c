//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
  char name[20];
  int room_num;
  int haunt_freq;
  struct Ghost* next;
} Ghost;

Ghost* create_ghost(char* name, int room_num, int haunt_freq) {
  Ghost* new_ghost = (Ghost*)malloc(sizeof(Ghost));
  strcpy(new_ghost->name, name);
  new_ghost->room_num = room_num;
  new_ghost->haunt_freq = haunt_freq;
  new_ghost->next = NULL;
  return new_ghost;
}

void add_ghost(Ghost* head, char* name, int room_num, int haunt_freq) {
  Ghost* new_ghost = create_ghost(name, room_num, haunt_freq);
  if (head == NULL) {
    head = new_ghost;
  } else {
    new_ghost->next = head;
    head = new_ghost;
  }
}

void haunt_house(Ghost* head) {
  srand(time(NULL));
  while (1) {
    int rand_num = rand() % MAX_GHOSTS;
    Ghost* current_ghost = head;
    for (int i = 0; i < rand_num; i++) {
      current_ghost = current_ghost->next;
    }
    printf("%s haunts the room number %d!\n", current_ghost->name, current_ghost->room_num);
    sleep(current_ghost->haunt_freq);
  }
}

int main() {
  Ghost* head = NULL;
  add_ghost(head, "Mr. Jones", 1, 3);
  add_ghost(head, "Mrs. Smith", 2, 2);
  add_ghost(head, "The Poltergeist", 3, 4);
  haunt_house(head);
  return 0;
}