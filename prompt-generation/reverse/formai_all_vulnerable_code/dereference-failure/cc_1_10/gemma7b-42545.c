//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int is_active;
    struct Ghost* next;
} Ghost;

Ghost* create_ghost(char* name, int room_num, int is_active) {
    Ghost* new_ghost = malloc(sizeof(Ghost));
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

int main() {
    srand(time(NULL));

    Ghost* head = NULL;
    add_ghost(head, "Mr. Jones", 1, 1);
    add_ghost(head, "Ms. Smith", 2, 0);
    add_ghost(head, "Mr. Brown", 3, 1);

    int room_num = rand() % MAX_GHOSTS + 1;

    printf("You are in room %d.\n", room_num);

    Ghost* current_ghost = head;
    while (current_ghost) {
        if (current_ghost->room_num == room_num && current_ghost->is_active) {
            printf("Suddenly, you hear a noise... %s is lurking in the halls.\n", current_ghost->name);
            break;
        }
        current_ghost = current_ghost->next;
    }

    if (current_ghost == NULL) {
        printf("No ghosts were found.\n");
    }

    return 0;
}