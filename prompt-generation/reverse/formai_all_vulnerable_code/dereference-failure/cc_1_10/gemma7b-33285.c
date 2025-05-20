//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10

typedef struct Ghost {
    char name[20];
    int room_num;
    int haunt_type;
    struct Ghost *next;
} Ghost;

Ghost *create_ghost(char *name, int room_num, int haunt_type) {
    Ghost *ghost = (Ghost *)malloc(sizeof(Ghost));
    strcpy(ghost->name, name);
    ghost->room_num = room_num;
    ghost->haunt_type = haunt_type;
    ghost->next = NULL;
    return ghost;
}

void add_ghost(Ghost *ghost_head, char *name, int room_num, int haunt_type) {
    Ghost *new_ghost = create_ghost(name, room_num, haunt_type);
    if (ghost_head == NULL) {
        ghost_head = new_ghost;
    } else {
        ghost_head->next = new_ghost;
        ghost_head = new_ghost;
    }
}

void haunt_house(Ghost *ghost_head) {
    srand(time(NULL));
    int room_num = rand() % MAX_GHOSTS;
    Ghost *current_ghost = ghost_head;
    while (current_ghost) {
        if (current_ghost->room_num == room_num) {
            printf("%s haunts the room %d!\n", current_ghost->name, room_num);
            switch (current_ghost->haunt_type) {
                case 1:
                    printf("They whisper secrets...\n");
                    break;
                case 2:
                    printf("They move furniture...\n");
                    break;
                case 3:
                    printf("They appear in the mirror...\n");
                    break;
                case 4:
                    printf("They scream...\n");
                    break;
            }
        }
        current_ghost = current_ghost->next;
    }
}

int main() {
    Ghost *ghost_head = NULL;
    add_ghost(ghost_head, "John", 3, 1);
    add_ghost(ghost_head, "Mary", 5, 2);
    add_ghost(ghost_head, "Bob", 7, 3);
    add_ghost(ghost_head, "Alice", 9, 4);

    haunt_house(ghost_head);

    return 0;
}