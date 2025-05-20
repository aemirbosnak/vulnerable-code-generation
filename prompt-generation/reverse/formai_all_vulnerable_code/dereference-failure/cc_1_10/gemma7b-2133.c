//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUM 5

typedef struct Room
{
    int room_num;
    char name[20];
    struct Room* next_room;
} Room;

Room* create_room(int room_num, char* name)
{
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_num = room_num;
    strcpy(new_room->name, name);
    new_room->next_room = NULL;
    return new_room;
}

void play_game(Room* current_room)
{
    printf("You are in the %s.\n", current_room->name);
    printf("What do you want to do? (go, fight, search, quit): ");
    char input[20];
    scanf("%s", input);

    switch (input[0])
    {
        case 'g':
            // Go to the next room
            if (current_room->next_room)
            {
                current_room = current_room->next_room;
                play_game(current_room);
            }
            else
            {
                printf("There is no next room.\n");
            }
            break;
        case 'f':
            // Fight the monster
            printf("You fought the monster and won!\n");
            break;
        case 's':
            // Search for items
            printf("You searched the room and found a treasure!\n");
            break;
        case 'q':
            // Quit the game
            printf("Thank you for playing!\n");
            break;
        default:
            printf("Invalid input.\n");
    }
}

int main()
{
    // Create the rooms
    Room* room_1 = create_room(1, "The Hall");
    Room* room_2 = create_room(2, "The Kitchen");
    Room* room_3 = create_room(3, "The Bedroom");
    Room* room_4 = create_room(4, "The Library");
    Room* room_5 = create_room(5, "The Treasure Room");

    // Connect the rooms
    room_1->next_room = room_2;
    room_2->next_room = room_3;
    room_3->next_room = room_4;
    room_4->next_room = room_5;

    // Start the game
    play_game(room_1);

    return 0;
}