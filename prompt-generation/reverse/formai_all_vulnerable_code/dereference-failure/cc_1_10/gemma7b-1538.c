//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
  char name[20];
  int age;
  int room_num;
  struct Ghost* next;
} Ghost;

Ghost* create_ghost(char* name, int age, int room_num) {
  Ghost* ghost = (Ghost*)malloc(sizeof(Ghost));
  strcpy(ghost->name, name);
  ghost->age = age;
  ghost->room_num = room_num;
  ghost->next = NULL;
  return ghost;
}

void add_ghost(Ghost* head, char* name, int age, int room_num) {
  Ghost* new_ghost = create_ghost(name, age, room_num);
  if (head == NULL) {
    head = new_ghost;
  } else {
    new_ghost->next = head;
    head = new_ghost;
  }
}

void haunt_house(Ghost* head) {
  while (head) {
    printf("%s has crept into your room!\n", head->name);
    printf("They are wandering around...\n");
    sleep(1);
    printf("Suddenly, you hear a noise... \n");
    sleep(1);
    printf("You feel a cold hand brush against your skin...\n");
    sleep(1);
    printf("Fear not, it is only %s.\n", head->name);
    sleep(1);
  }
}

int main() {
  Ghost* head = NULL;
  add_ghost(head, "Mr. Jones", 30, 1);
  add_ghost(head, "Mrs. Smith", 25, 2);
  add_ghost(head, "The Phantom", 18, 3);

  haunt_house(head);

  return 0;
}