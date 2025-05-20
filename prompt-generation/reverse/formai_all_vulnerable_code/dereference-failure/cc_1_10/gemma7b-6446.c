//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int type;
    struct Ghost* next;
} Ghost;

Ghost* create_ghost(char* name, int room_num, int type) {
    Ghost* ghost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(ghost->name, name);
    ghost->room_num = room_num;
    ghost->type = type;
    ghost->next = NULL;
    return ghost;
}

void add_ghost(Ghost** head, char* name, int room_num, int type) {
    Ghost* ghost = create_ghost(name, room_num, type);
    if (*head == NULL) {
        *head = ghost;
    } else {
        (*head)->next = ghost;
        *head = ghost;
    }
}

int main() {
    srand(time(NULL));
    Ghost** head = NULL;

    // Create a haunted house
    add_ghost(head, "Sally", 1, 1);
    add_ghost(head, "John", 2, 2);
    add_ghost(head, "Mary", 3, 1);
    add_ghost(head, "Bob", 4, 2);

    // Simulate the haunted house
    int room_num = rand() % 5 + 1;
    printf("You are in room %d.\n", room_num);

    Ghost* current_ghost = head;
    while (current_ghost) {
        if (current_ghost->room_num == room_num) {
            printf("The ghostly presence of %s is detected.\n", current_ghost->name);
            switch (current_ghost->type) {
                case 1:
                    printf("They are weeping.\n");
                    break;
                case 2:
                    printf("They are moaning.\n");
                    break;
            }
        }
        current_ghost = current_ghost->next;
    }

    return 0;
}