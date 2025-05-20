//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define room structure
typedef struct Room {
    int ghosts;
    int bats;
    int treasure;
    int trap;
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
} Room;

// Function declarations
void printRoomInfo(Room* currentRoom);
char getInput();
Room* move(Room* currentRoom, char direction);
void generateRooms(Room* currentRoom, int* numRooms);

int main()
{
    // Seed random number generator
    srand(time(NULL));
    
    // Create starting room
    Room* currentRoom = (Room*)malloc(sizeof(Room));
    currentRoom->ghosts = rand() % 3;
    currentRoom->bats = rand() % 3;
    currentRoom->treasure = rand() % 3;
    currentRoom->trap = rand() % 3;
    currentRoom->north = NULL;
    currentRoom->south = NULL;
    currentRoom->east = NULL;
    currentRoom->west = NULL;
    
    // Generate random rooms
    int numRooms = 0;
    generateRooms(currentRoom, &numRooms);
    
    // Print welcome message
    printf("Welcome to the haunted house!\n");
    printRoomInfo(currentRoom);
    
    // Main game loop
    char input;
    while (input != 'q') {
        input = getInput();
        if (input == 'n') {
            currentRoom = move(currentRoom, 'n');
        } else if (input == 's') {
            currentRoom = move(currentRoom, 's');
        } else if (input == 'e') {
            currentRoom = move(currentRoom, 'e');
        } else if (input == 'w') {
            currentRoom = move(currentRoom, 'w');
        } else if (input == 'i') {
            printRoomInfo(currentRoom);
        } else if (input == 'q') {
            printf("Goodbye!\n");
        } else {
            printf("Invalid input. Enter 'n', 's', 'e', 'w', 'i', or 'q'.\n");
        }
    }
    
    // Free memory
    free(currentRoom);
    
    return 0;
}

void printRoomInfo(Room* currentRoom)
{
    printf("You are in a room with:\n");
    printf("%d ghosts\n", currentRoom->ghosts);
    printf("%d bats\n", currentRoom->bats);
    printf("%d treasure\n", currentRoom->treasure);
    printf("%d trap\n", currentRoom->trap);
    printf("Enter 'n', 's', 'e', 'w', 'i', or 'q'.\n");
}

char getInput()
{
    char input;
    scanf(" %c", &input);
    return input;
}

Room* move(Room* currentRoom, char direction)
{
    Room* nextRoom;
    switch (direction) {
        case 'n':
            nextRoom = currentRoom->north;
            break;
        case 's':
            nextRoom = currentRoom->south;
            break;
        case 'e':
            nextRoom = currentRoom->east;
            break;
        case 'w':
            nextRoom = currentRoom->west;
            break;
        default:
            return currentRoom;
    }
    if (nextRoom == NULL) {
        printf("You cannot go that way.\n");
        return currentRoom;
    } else {
        printf("You move to a new room.\n");
        printRoomInfo(nextRoom);
        return nextRoom;
    }
}

void generateRooms(Room* currentRoom, int* numRooms)
{
    // 75% chance of adding new room
    if (rand() % 4 != 0) {
        return;
    }
    
    // Choose random direction
    int direction = rand() % 4;
    Room* nextRoom;
    switch (direction) {
        case 0:
            if (currentRoom->north == NULL) {
                nextRoom = (Room*)malloc(sizeof(Room));
                nextRoom->ghosts = rand() % 3;
                nextRoom->bats = rand() % 3;
                nextRoom->treasure = rand() % 3;
                nextRoom->trap = rand() % 3;
                nextRoom->north = NULL;
                nextRoom->south = currentRoom;
                nextRoom->east = NULL;
                nextRoom->west = NULL;
                currentRoom->north = nextRoom;
                (*numRooms)++;
            }
            break;
        case 1:
            if (currentRoom->south == NULL) {
                nextRoom = (Room*)malloc(sizeof(Room));
                nextRoom->ghosts = rand() % 3;
                nextRoom->bats = rand() % 3;
                nextRoom->treasure = rand() % 3;
                nextRoom->trap = rand() % 3;
                nextRoom->north = currentRoom;
                nextRoom->south = NULL;
                nextRoom->east = NULL;
                nextRoom->west = NULL;
                currentRoom->south = nextRoom;
                (*numRooms)++;
            }
            break;
        case 2:
            if (currentRoom->east == NULL) {
                nextRoom = (Room*)malloc(sizeof(Room));
                nextRoom->ghosts = rand() % 3;
                nextRoom->bats = rand() % 3;
                nextRoom->treasure = rand() % 3;
                nextRoom->trap = rand() % 3;
                nextRoom->north = NULL;
                nextRoom->south = NULL;
                nextRoom->east = NULL;
                nextRoom->west = currentRoom;
                currentRoom->east = nextRoom;
                (*numRooms)++;
            }
            break;
        case 3:
            if (currentRoom->west == NULL) {
                nextRoom = (Room*)malloc(sizeof(Room));
                nextRoom->ghosts = rand() % 3;
                nextRoom->bats = rand() % 3;
                nextRoom->treasure = rand() % 3;
                nextRoom->trap = rand() % 3;
                nextRoom->north = NULL;
                nextRoom->south = NULL;
                nextRoom->east = currentRoom;
                nextRoom->west = NULL;
                currentRoom->west = nextRoom;
                (*numRooms)++;
            }
            break;
        default:
            break;
    }
    
    // Generate more rooms recursively
    if (*numRooms < 5) {
        generateRooms(currentRoom, numRooms);
        if (currentRoom->north != NULL && rand() % 2 == 0) {
            generateRooms(currentRoom->north, numRooms);
        }
        if (currentRoom->south != NULL && rand() % 2 == 0) {
            generateRooms(currentRoom->south, numRooms);
        }
        if (currentRoom->east != NULL && rand() % 2 == 0) {
            generateRooms(currentRoom->east, numRooms);
        }
        if (currentRoom->west != NULL && rand() % 2 == 0) {
            generateRooms(currentRoom->west, numRooms);
        }
    }
}