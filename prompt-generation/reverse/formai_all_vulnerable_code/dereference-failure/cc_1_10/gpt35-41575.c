//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Room {
    char* name;
    char* description;
    struct Room** neighbors;
    int numNeighbors;
} Room;

void printIntroduction() {
    printf("\nWelcome to the Adventure Game, designed by Donald Knuth himself!\n");
    printf("You find yourself in a strange land filled with dangerous creatures and mysterious treasures.\n");
    printf("Your goal is to find the legendary Golden Apple, which can only be found by traversing through the treacherous mountains and deep valleys.\n");
    printf("Legend has it that the Golden Apple has the power to grant you any wish you desire.\n");
    printf("Are you brave enough to embark on this perilous journey?\n");
}

Room* createRoom(char* name, char* description, int numNeighbors) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    newRoom->name = name;
    newRoom->description = description;
    newRoom->numNeighbors = numNeighbors;
    newRoom->neighbors = (Room**)malloc(numNeighbors * sizeof(Room*));
    return newRoom;
}

void connectRooms(Room* room1, Room* room2) {
    int index1 = room1->numNeighbors;
    int index2 = room2->numNeighbors;
    room1->neighbors[index1] = room2;
    room2->neighbors[index2] = room1;
    room1->numNeighbors++;
    room2->numNeighbors++;
}

void printRoom(Room* room) {
    printf("You are in %s\n", room->name);
    printf("%s\n", room->description);
    printf("You can go to the following locations:\n");
    for (int i = 0; i < room->numNeighbors; i++) {
        printf("%d. %s\n", i+1, room->neighbors[i]->name);
    }
}

void playGame() {
    // Create rooms
    Room* room1 = createRoom("Valley of Shadows", "You are standing in a dark valley with no sight of the sky. The air is cold and damp.", 2);
    Room* room2 = createRoom("Mountain Pass", "You are walking on a narrow path between two tall mountains. The wind is howling and there is a risk of avalanche.", 3);
    Room* room3 = createRoom("Cave of Whispers", "You have entered a deep cave filled with eerie whispers. It is hard to see in the darkness.", 2);
    Room* room4 = createRoom("Golden Apple Orchard", "You have finally reached the Golden Apple Orchard! The air is filled with the sweet aroma of apples. You can almost taste the treasure.", 0);

    // Connect rooms
    connectRooms(room1, room2);
    connectRooms(room1, room3);
    connectRooms(room2, room3);
    connectRooms(room2, room4);
    connectRooms(room3, room4);

    // Set starting room
    Room* currentRoom = room1;

    // Play game
    while (currentRoom != room4) {
        printRoom(currentRoom);
        printf("Which room do you want to go to? Choose a number between 1-%d\n", currentRoom->numNeighbors);
        int choice;
        scanf("%d", &choice);
        if (choice >= 1 && choice <= currentRoom->numNeighbors) {
            currentRoom = currentRoom->neighbors[choice-1];
        } else {
            printf("Invalid choice. Please choose a number between 1-%d\n", currentRoom->numNeighbors);
        }
    }

    printf("Congratulations! You have found the Golden Apple! What is your wish?\n");
    char wish[100];
    scanf("%s", wish);
    printf("Your wish is granted! %s", wish);
}

int main() {
    srand(time(NULL)); // Seed random number generator
    printIntroduction();
    playGame();
    return 0;
}