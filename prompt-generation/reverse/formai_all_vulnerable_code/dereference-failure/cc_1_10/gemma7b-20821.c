//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room;
    int is_active;
    struct Ghost* next;
} Ghost;

Ghost* create_ghost(char* name, int room, int is_active) {
    Ghost* new_ghost = malloc(sizeof(Ghost));
    strcpy(new_ghost->name, name);
    new_ghost->room = room;
    new_ghost->is_active = is_active;
    new_ghost->next = NULL;
    return new_ghost;
}

void add_ghost(Ghost* head, char* name, int room, int is_active) {
    Ghost* new_ghost = create_ghost(name, room, is_active);
    if (head == NULL) {
        head = new_ghost;
    } else {
        head->next = new_ghost;
    }
}

void haunt_house(Ghost* head) {
    srand(time(NULL));
    while (head) {
        int room = rand() % MAX_GHOSTS;
        printf("The ghostly figure of %s has appeared in room %d!\n", head->name, room);
        head->is_active = 0;
        sleep(rand() % 5);
        head->is_active = 1;
    }
}

int main() {
    Ghost* head = NULL;
    add_ghost(head, "Mr. Jones", 1, 1);
    add_ghost(head, "Miss Emily", 2, 1);
    add_ghost(head, "The Disembodied", 3, 1);
    haunt_house(head);
    return 0;
}