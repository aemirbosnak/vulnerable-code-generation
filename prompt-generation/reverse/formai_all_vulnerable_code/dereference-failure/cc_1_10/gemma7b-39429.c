//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_GHOSTS 3

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

void add_ghost(Ghost* head, char* name, int room_num, int is_active) {
    Ghost* ghost = create_ghost(name, room_num, is_active);
    if (head == NULL) {
        head = ghost;
    } else {
        head->next = ghost;
        head = ghost;
    }
}

void haunt_house(Ghost* head) {
    time_t t = time(NULL);
    srand(t);

    while (head) {
        int rand_room = rand() % NUM_GHOSTS + 1;
        if (head->is_active && head->room_num == rand_room) {
            printf("%s has appeared in room %d!\n", head->name, head->room_num);
        }
    }
}

int main() {
    Ghost* head = NULL;

    add_ghost(head, "John Doe", 1, 1);
    add_ghost(head, "Jane Doe", 2, 1);
    add_ghost(head, "Billy Smith", 3, 0);

    haunt_house(head);

    return 0;
}