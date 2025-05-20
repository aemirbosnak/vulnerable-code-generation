//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10

typedef struct {
    char *name;
    char *description;
    int num_exits;
    int *exits;
} Room;

Room rooms[MAX_ROOMS];
int current_room = 0;

void print_room() {
    printf("%s\n%s\n", rooms[current_room].name, rooms[current_room].description);
    for (int i = 0; i < rooms[current_room].num_exits; i++) {
        printf("%d. %s\n", i + 1, rooms[rooms[current_room].exits[i]].name);
    }
}

void move_room(int choice) {
    if (choice < 1 || choice > rooms[current_room].num_exits) {
        printf("Invalid choice.\n");
        return;
    }
    current_room = rooms[current_room].exits[choice - 1];
}

int main() {
    // Initialize rooms
    rooms[0].name = "The Hallucinatory Hallway";
    rooms[0].description = "You find yourself in a long, winding hallway. The walls are covered in strange, psychedelic paintings. The air is thick with the smell of incense.";
    rooms[0].num_exits = 3;
    rooms[0].exits = malloc(sizeof(int) * 3);
    rooms[0].exits[0] = 1;
    rooms[0].exits[1] = 2;
    rooms[0].exits[2] = 3;

    rooms[1].name = "The Room of Metamorphoses";
    rooms[1].description = "You enter a room that is constantly changing. The walls, the floor, and the ceiling are all shifting and swirling. You can see your own reflection in the walls, but it is constantly changing, too.";
    rooms[1].num_exits = 2;
    rooms[1].exits = malloc(sizeof(int) * 2);
    rooms[1].exits[0] = 0;
    rooms[1].exits[1] = 4;

    rooms[2].name = "The Room of Echoes";
    rooms[2].description = "You enter a room that is filled with echoes. Every sound you make, no matter how small, is repeated over and over again. It is impossible to have a conversation in this room.";
    rooms[2].num_exits = 2;
    rooms[2].exits = malloc(sizeof(int) * 2);
    rooms[2].exits[0] = 0;
    rooms[2].exits[1] = 5;

    rooms[3].name = "The Room of Illusions";
    rooms[3].description = "You enter a room that is filled with illusions. Everything you see is constantly changing and shifting. You can never be sure what is real and what is not.";
    rooms[3].num_exits = 1;
    rooms[3].exits = malloc(sizeof(int) * 1);
    rooms[3].exits[0] = 0;

    rooms[4].name = "The Room of Dreams";
    rooms[4].description = "You enter a room that is filled with dreams. The air is thick with the smell of jasmine and lavender. You can see images of your own dreams floating in the air.";
    rooms[4].num_exits = 1;
    rooms[4].exits = malloc(sizeof(int) * 1);
    rooms[4].exits[0] = 1;

    rooms[5].name = "The Room of Nightmares";
    rooms[5].description = "You enter a room that is filled with nightmares. The air is thick with the smell of fear and decay. You can see images of your own nightmares floating in the air.";
    rooms[5].num_exits = 1;
    rooms[5].exits = malloc(sizeof(int) * 1);
    rooms[5].exits[0] = 2;

    // Game loop
    while (1) {
        print_room();
        printf("Which room do you want to go to? ");
        int choice;
        scanf("%d", &choice);
        move_room(choice);
    }

    return 0;
}