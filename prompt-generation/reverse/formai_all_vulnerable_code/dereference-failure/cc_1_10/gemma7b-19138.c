//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: post-apocalyptic
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

int main() {
    srand(time(NULL));
    Ghost* head = NULL;

    // Create a few ghosts
    Ghost* ghost1 = create_ghost("John", 1, 1);
    Ghost* ghost2 = create_ghost("Mary", 2, 0);
    Ghost* ghost3 = create_ghost("Bob", 3, 1);
    Ghost* ghost4 = create_ghost("Alice", 4, 0);
    Ghost* ghost5 = create_ghost("Tom", 5, 1);

    // Add the ghosts to the head
    add_ghost(head, ghost1);
    add_ghost(head, ghost2);
    add_ghost(head, ghost3);
    add_ghost(head, ghost4);
    add_ghost(head, ghost5);

    // Simulate a haunted house
    printf("You are in a dilapidated apartment building in a post-apocalyptic world.\n");
    printf("The only sound is the wind howling and the occasional groan of the dead.\n");

    // Have the ghosts move around
    for (int i = 0; i < MAX_GHOULS; i++) {
        Ghost* current_ghost = head;
        while (current_ghost) {
            if (current_ghost->is_active) {
                int destination_room = rand() % 5 + 1;
                if (destination_room != current_ghost->room_num) {
                    current_ghost->room_num = destination_room;
                    printf("%s has moved to room %d.\n", current_ghost->name, current_ghost->room_num);
                }
            }
            current_ghost = current_ghost->next;
        }
    }

    // See if the player can survive
    printf("Do you want to continue? (Y/N): ");
    char answer;
    scanf("%c", &answer);

    if (answer == 'Y') {
        printf("You have survived the night. Congratulations!\n");
    } else {
        printf("You have perished. Sorry.\n");
    }

    return 0;
}