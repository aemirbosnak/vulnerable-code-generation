//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10

typedef struct Ghost {
    char name[20];
    int room_num;
    int is_active;
    int movement_pattern;
    struct Ghost* next;
} Ghost;

void create_ghost(Ghost** head) {
    *head = malloc(sizeof(Ghost));
    (*head)->name[0] = '\0';
    (*head)->room_num = 0;
    (*head)->is_active = 0;
    (*head)->movement_pattern = 0;
    (*head)->next = NULL;
}

void add_ghost(Ghost** head, char* name, int room_num, int is_active, int movement_pattern) {
    Ghost* new_ghost = malloc(sizeof(Ghost));
    new_ghost->name[0] = '\0';
    strcpy(new_ghost->name, name);
    new_ghost->room_num = room_num;
    new_ghost->is_active = is_active;
    new_ghost->movement_pattern = movement_pattern;
    new_ghost->next = NULL;

    if (*head == NULL) {
        *head = new_ghost;
    } else {
        (*head)->next = new_ghost;
    }
}

void simulate_haunted_house(Ghost* head) {
    srand(time(NULL));

    while (head) {
        if (head->is_active && rand() % 100 < head->movement_pattern) {
            switch (head->movement_pattern) {
                case 1:
                    printf("Ghost %s is moving towards room %d.\n", head->name, head->room_num);
                    break;
                case 2:
                    printf("Ghost %s is wandering around room %d.\n", head->name, head->room_num);
                    break;
                case 3:
                    printf("Ghost %s is teleporting to room %d.\n", head->name, head->room_num);
                    break;
            }
        }
        head = head->next;
    }
}

int main() {
    Ghost* head = NULL;

    create_ghost(&head);
    add_ghost(&head, "John Doe", 1, 1, 2);
    add_ghost(&head, "Mary Smith", 3, 1, 1);
    add_ghost(&head, "Peter Jones", 2, 0, 3);

    simulate_haunted_house(head);

    return 0;
}