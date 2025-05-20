//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int is_active;
    struct Ghost* next;
} Ghost;

Ghost* create_ghost(char* name, int room_num, int is_active) {
    Ghost* new_ghost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(new_ghost->name, name);
    new_ghost->room_num = room_num;
    new_ghost->is_active = is_active;
    new_ghost->next = NULL;
    return new_ghost;
}

void add_ghost(Ghost* head, char* name, int room_num, int is_active) {
    Ghost* new_ghost = create_ghost(name, room_num, is_active);
    if (head == NULL) {
        head = new_ghost;
    } else {
        head->next = new_ghost;
    }
}

void haunt_house(Ghost* head) {
    while (head) {
        if (head->is_active) {
            printf("The ghostly figure of %s has been spotted in room %d!\n", head->name, head->room_num);
        }
        head = head->next;
    }
}

int main() {
    Ghost* head = NULL;
    add_ghost(head, "Mr. Jones", 1, 1);
    add_ghost(head, "Mrs. Smith", 3, 1);
    add_ghost(head, "Mr. Brown", 5, 0);

    haunt_house(head);

    return 0;
}