//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 10

typedef struct Ghost {
    char name[20];
    int room_num;
    int type;
    struct Ghost* next;
} Ghost;

void generate_ghosts(Ghost** head) {
    time_t t = time(NULL);
    srand(t);

    for (int i = 0; i < MAX_GHOULS; i++) {
        Ghost* new_ghost = (Ghost*)malloc(sizeof(Ghost));
        strcpy(new_ghost->name, "Ghost ");
        new_ghost->room_num = rand() % 10 + 1;
        new_ghost->type = rand() % 3 + 1;
        new_ghost->next = *head;
        *head = new_ghost;
    }
}

void haunt_house(Ghost* head) {
    while (head) {
        printf("The ghostly figure of %s haunts room %d.\n", head->name, head->room_num);
        switch (head->type) {
            case 1:
                printf("They wander aimlessly, seeking a purpose.\n");
                break;
            case 2:
                printf("They whisper secrets in the ear of unsuspecting victims.\n");
                break;
            case 3:
                printf("They appear in mirrors, taunting the living.\n");
                break;
        }
        head = head->next;
    }
}

int main() {
    Ghost* head = NULL;
    generate_ghosts(&head);
    haunt_house(head);
    return 0;
}