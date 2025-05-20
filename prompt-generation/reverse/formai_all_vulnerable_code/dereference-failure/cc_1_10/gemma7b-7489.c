//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int type;
    struct Ghost* next;
} Ghost;

Ghost* create_ghost(char* name, int room_num, int type) {
    Ghost* new_ghost = (Ghost*)malloc(sizeof(Ghost));
    strcpy(new_ghost->name, name);
    new_ghost->room_num = room_num;
    new_ghost->type = type;
    new_ghost->next = NULL;
    return new_ghost;
}

void add_ghost(Ghost* head, char* name, int room_num, int type) {
    Ghost* new_ghost = create_ghost(name, room_num, type);
    if (head == NULL) {
        head = new_ghost;
    } else {
        head->next = new_ghost;
    }
}

void haunt_house(Ghost* head) {
    time_t t = time(NULL);
    srand(t);
    while (head) {
        int room_num = rand() % MAX_GHOSTS + 1;
        switch (head->type) {
            case 1:
                printf("%s has moved to room %d!\n", head->name, room_num);
                break;
            case 2:
                printf("%s has opened a door to room %d.\n", head->name, room_num);
                break;
            case 3:
                printf("%s has whispered secrets in room %d.\n", head->name, room_num);
                break;
        }
        head = head->next;
    }
}

int main() {
    Ghost* head = NULL;
    add_ghost(head, "Jack", 1, 1);
    add_ghost(head, "Mary", 2, 2);
    add_ghost(head, "Bob", 3, 3);

    haunt_house(head);

    return 0;
}