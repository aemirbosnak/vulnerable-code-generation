//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: random
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_ROOMS 5

typedef struct Room {
    char name[20];
    struct Room* next;
    int has_key;
    int has_monster;
} Room;

void create_room(Room** head, char* name, int has_key, int has_monster) {
    Room* new_room = malloc(sizeof(Room));
    strcpy(new_room->name, name);
    new_room->next = NULL;
    new_room->has_key = has_key;
    new_room->has_monster = has_monster;
    *head = new_room;
}

void play_game() {
    srand(time(NULL));
    Room* head = NULL;
    create_room(&head, "The Hallway", 1, 1);
    create_room(&head, "The Kitchen", 0, 0);
    create_room(&head, "The Bedroom", 1, 0);
    create_room(&head, "The Library", 0, 1);

    int current_room = 0;
    char input[20];

    while (current_room < MAX_ROOMS) {
        printf("%s\n", head->name);

        // Get user input
        scanf("%s", input);

        // Check if the input is valid
        if (strcmp(input, "north") == 0) {
            if (head->next) {
                current_room++;
            } else {
                printf("There is no way to go north.\n");
            }
        } else if (strcmp(input, "south") == 0) {
            if (head->next) {
                current_room--;
            } else {
                printf("There is no way to go south.\n");
            }
        } else if (strcmp(input, "east") == 0) {
            printf("There is no way to go east.\n");
        } else if (strcmp(input, "west") == 0) {
            printf("There is no way to go west.\n");
        } else {
            printf("Invalid input.\n");
        }

        head = head->next;
    }

    printf("You have won the game!\n");
}

int main() {
    play_game();
    return 0;
}