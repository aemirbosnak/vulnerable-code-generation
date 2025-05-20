//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define ROOMS 10

//Struct to store room information
typedef struct Room {
    char* description;
    bool visited;
    bool containGhost;
} Room;

//Function to generate random room descriptions
char* generateDescription() {
    char* descriptions[5] = {"A dusty old library.", "A creepy basement.", "A dining room with an empty table.", "A bedroom with a creaky bed.", "A dark, mysterious hallway."};
    int index = rand() % 5;
    char* desc = malloc(sizeof(char) * 100);
    strcpy(desc, descriptions[index]);
    return desc;
}

int main() {
    //Initialize game variables
    Room* rooms[ROOMS];
    bool gameRunning = true;
    int currentRoom = 0;
    srand(time(NULL));

    //Generate rooms
    for (int i = 0; i < ROOMS; i++) {
        rooms[i] = malloc(sizeof(Room));
        rooms[i]->description = generateDescription();
        rooms[i]->visited = false;
        rooms[i]->containGhost = false;
        //Randomly assign a room to contain a ghost
        if (rand() % 3 == 0) {
            rooms[i]->containGhost = true;
        }
    }

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself in a dimly lit foyer. The front door is locked behind you.\n");
    printf("Your objective is to find the key to the front door and escape the house.\n");
    printf("Good luck...\n");

    //Game loop
    while (gameRunning) {
        printf("\nCurrent room: %s\n", rooms[currentRoom]->description);
        rooms[currentRoom]->visited = true;
        //Check if room contains a ghost
        if (rooms[currentRoom]->containGhost) {
            printf("You feel a cold presence...a ghost is in this room!\n");
        }

        //Check if player has found the key
        if (currentRoom == 9 && !rooms[9]->containGhost) {
            printf("You found the key to the front door!\n");
            printf("You unlock the door and escape the haunted house! Congratulations!\n");
            gameRunning = false;
            break;
        }

        //Prompt user for action
        printf("What would you like to do?\n");
        printf("1. Move to a different room.\n");
        printf("2. Quit game.\n");

        int action;
        scanf("%d", &action);
        if (action == 1) {
            printf("Choose a room to move to (1-10):\n");
            int destination;
            scanf("%d", &destination);
            //Check if room is valid
            if (destination < 1 || destination > 10) {
                printf("Invalid room. Please choose a room between 1 and 10.\n");
            }
            else {
                //Check if room has already been visited
                if (rooms[destination-1]->visited) {
                    printf("You have already been to that room.\n");
                }
                else {
                    currentRoom = destination-1;
                }
            }
        }
        else if (action == 2) {
            printf("Thanks for playing!\n");
            gameRunning = false;
            break;
        }
        else {
            printf("Invalid action. Please choose 1 or 2.\n");
        }
    }

    //Free dynamically allocated memory
    for (int i = 0; i < ROOMS; i++) {
        free(rooms[i]->description);
        free(rooms[i]);
    }

    return 0;
}