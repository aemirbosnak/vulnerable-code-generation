//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int is_active;
    struct Ghost* next;
} Ghost;

Ghost* create_ghost(char* name, int room_num, int is_active) {
    Ghost* ghost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(ghost->name, name);
    ghost->room_num = room_num;
    ghost->is_active = is_active;
    ghost->next = NULL;
    return ghost;
}

void add_ghost(Ghost* head, Ghost* new_ghost) {
    if (head == NULL) {
        head = new_ghost;
    } else {
        head->next = new_ghost;
        head = new_ghost;
    }
}

void haunt_house(Ghost* head) {
    while (head) {
        printf("%s has entered the %d room...\n", head->name, head->room_num);
        printf("The air is thick with the scent of %s's presence...\n", head->name);
        head = head->next;
    }
}

int main() {
    Ghost* head = NULL;
    Ghost* new_ghost;

    new_ghost = create_ghost("Anya", 1, 1);
    add_ghost(head, new_ghost);

    new_ghost = create_ghost("Boris", 3, 1);
    add_ghost(head, new_ghost);

    new_ghost = create_ghost("Christina", 2, 0);
    add_ghost(head, new_ghost);

    haunt_house(head);

    return 0;
}