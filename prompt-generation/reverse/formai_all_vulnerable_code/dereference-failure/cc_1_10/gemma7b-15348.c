//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 10

typedef struct Ghost {
  char name[20];
  int room_num;
  int haunt_freq;
  struct Ghost* next;
} Ghost;

Ghost* create_ghost(char* name, int room_num, int haunt_freq) {
  Ghost* new_ghost = malloc(sizeof(Ghost));
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
    head->next = new_ghost;
  }
}

void haunt_house(Ghost* head) {
  time_t now = time(NULL);
  srand(now);
  while (head) {
    int haunt_chance = rand() % head->haunt_freq;
    if (haunt_chance == 0) {
      printf("Suddenly, a cold wind blows through the halls... \n");
      printf("A ghostly figure appears, its eyes glowing... \n");
      printf("The figure whispers your name... \n");
      printf("Fear not, it is only a friendly ghost. \n");
    }
    head = head->next;
  }
}

int main() {
  Ghost* head = NULL;
  add_ghost(head, "Mr. Bartholomew", 1, 3);
  add_ghost(head, "Ms. Sophia", 3, 5);
  add_ghost(head, "The Bloody Bride", 5, 2);

  haunt_house(head);

  return 0;
}