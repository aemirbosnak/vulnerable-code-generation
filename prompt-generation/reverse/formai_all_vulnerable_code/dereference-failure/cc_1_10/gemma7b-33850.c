//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_GHOSTS 10

typedef struct Ghost {
    char name[20];
    int room_num;
    int is_active;
    struct Ghost* next;
} Ghost;

Ghost* create_ghost(char* name, int room_num) {
    Ghost* ghost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(ghost->name, name);
    ghost->room_num = room_num;
    ghost->is_active = 1;
    ghost->next = NULL;
    return ghost;
}

void add_ghost(Ghost* head, char* name, int room_num) {
    Ghost* new_ghost = create_ghost(name, room_num);
    if (head == NULL) {
        head = new_ghost;
    } else {
        head->next = new_ghost;
        head = new_ghost;
    }
}

int main() {
    Ghost* head = NULL;
    add_ghost(head, "Mr. Bartholomew", 1);
    add_ghost(head, "Miss Amelia", 2);
    add_ghost(head, "The Disembodied", 3);

    printf("Welcome to the Haunted House Simulator!\n");

    // Ghostly activities begin...
    head->is_active = 0;
    printf("Mr. Bartholomew has moved to the attic.\n");

    if (head->next->is_active) {
        printf("Miss Amelia is restless, and she's going to roam the halls.\n");
    }

    if (head->next->next->is_active) {
        printf("The Disembodied is playing hide-and-seek. Can you find him?\n");
    }

    return 0;
}