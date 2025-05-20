//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a struct for each individual room
typedef struct Room {
    char name[20];
    char description[100];
    struct Room* north;
    struct Room* east;
    struct Room* south;
    struct Room* west;
} Room;

// Define a struct to hold our player's data
typedef struct Player {
    Room* currentRoom;
    int health;
    int score;
} Player;

// Function prototypes
void initRooms(Room** rooms);
void initPlayer(Player* player, Room** rooms);
void printInstructions();
void printRoom(Player* player);
void movePlayer(Player* player, Room** rooms, char* direction);
bool gameIsOver(Player* player);

int main() {
    // Initialize our rooms and player
    Room* rooms[3];
    initRooms(rooms);
    Player player;
    initPlayer(&player, rooms);
    
    // Start the game
    printf("Welcome to the Adventure Game!\n\n");
    printInstructions();
    
    while (!gameIsOver(&player)) {
        printRoom(&player);
        char input[10];
        printf("Enter a direction (n, e, s, w) or q to quit: ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) {
            break;
        }
        movePlayer(&player, rooms, input);
    }
    
    // End the game
    printf("\nGame over!\nFinal Score: %d\n", player.score);
    return 0;
}

void initRooms(Room** rooms) {
    // Room 0
    Room* room = malloc(sizeof(Room));
    strcpy(room->name, "Starting Room");
    strcpy(room->description, "This is where you begin your adventure.");
    room->north = NULL;
    room->east = rooms[1];
    room->south = NULL;
    room->west = NULL;
    rooms[0] = room;
    
    // Room 1
    room = malloc(sizeof(Room));
    strcpy(room->name, "Middle Room");
    strcpy(room->description, "You are in the middle of your adventure.");
    room->north = rooms[2];
    room->east = NULL;
    room->south = NULL;
    room->west = rooms[0];
    rooms[1] = room;
    
    // Room 2
    room = malloc(sizeof(Room));
    strcpy(room->name, "Final Room");
    strcpy(room->description, "This is the end of your adventure.");
    room->north = NULL;
    room->east = NULL;
    room->south = rooms[1];
    room->west = NULL;
    rooms[2] = room;
}

void initPlayer(Player* player, Room** rooms) {
    player->currentRoom = rooms[0];
    player->health = 100;
    player->score = 0;
}

void printInstructions() {
    printf("Instructions:\n");
    printf("Enter 'n' to move north, 'e' to move east, 's' to move south, 'w' to move west.\n");
    printf("Collect items to gain points, but be careful - some items can hurt you!\n");
    printf("Your health must be above 0 to continue playing.\n\n");
}

void printRoom(Player* player) {
    printf("\n%s\n%s\n", player->currentRoom->name, player->currentRoom->description);
}

void movePlayer(Player* player, Room** rooms, char* direction) {
    Room* nextRoom;
    if (strcmp(direction, "n") == 0) {
        nextRoom = player->currentRoom->north;
    } else if (strcmp(direction, "e") == 0) {
        nextRoom = player->currentRoom->east;
    } else if (strcmp(direction, "s") == 0) {
        nextRoom = player->currentRoom->south;
    } else if (strcmp(direction, "w") == 0) {
        nextRoom = player->currentRoom->west;
    } else {
        printf("Invalid direction.\n");
        return;
    }
    
    // Update the current room if the player can move in that direction
    if (nextRoom == NULL) {
        printf("There's no way to go in that direction.\n");
    } else {
        player->currentRoom = nextRoom;
        printf("Moved to %s.\n", player->currentRoom->name);
        
        // Calculate any points or damage based on items in the room
        if (strcmp(player->currentRoom->name, "Starting Room") == 0) {
            printf("You found a key and gained 10 points!\n");
            player->score += 10;
        } else if (strcmp(player->currentRoom->name, "Middle Room") == 0) {
            printf("You found a trap and lost 10 points and 20 health!\n");
            player->score -= 10;
            player->health -= 20;
        } else if (strcmp(player->currentRoom->name, "Final Room") == 0) {
            printf("You found a treasure and gained 50 points!\n");
            player->score += 50;
        }
    }
}

bool gameIsOver(Player* player) {
    if (player->health <= 0) {
        printf("\nYou've run out of health! Game over.\n");
        return true;
    } else if (strcmp(player->currentRoom->name, "Final Room") == 0) {
        printf("\nCongratulations! You completed the adventure with %d points left and %d health remaining.\n", player->score, player->health);
        return true;
    } else {
        return false;
    }
}