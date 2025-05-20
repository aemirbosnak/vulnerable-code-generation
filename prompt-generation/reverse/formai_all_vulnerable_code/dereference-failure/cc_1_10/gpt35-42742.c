//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Room struct to hold room details
struct Room {
    char name[20];
    char description[50];
    int visited;
    struct Room* north;
    struct Room* east;
    struct Room* south;
    struct Room* west;
};

// Function declaration
void printRoom(struct Room*);
void move(struct Room**, char*);
void takeItem(struct Room**, char*);
void useItem(struct Room**, char*);

int main() {
    // Initialize rooms
    struct Room* start = malloc(sizeof(struct Room));
    struct Room* city = malloc(sizeof(struct Room));
    struct Room* lab = malloc(sizeof(struct Room));
    struct Room* ocean = malloc(sizeof(struct Room));

    // Set room details
    strcpy(start->name, "Abandoned House");
    strcpy(start->description, "You find yourself in an abandoned house, surrounded by rubble and debris. It appears to be an aftermath of an apocalypse.");
    start->visited = 0;
    start->north = NULL;
    start->east = city;
    start->south = NULL;
    start->west = NULL;

    strcpy(city->name, "Destroyed City");
    strcpy(city->description, "You see a huge destroyed city with broken buildings and vehicles. It's a sign that the world has ended.");
    city->visited = 0;
    city->north = start;
    city->east = ocean;
    city->south = NULL;
    city->west = lab;

    strcpy(lab->name, "Scientific Lab");
    strcpy(lab->description, "You enter an old scientific lab, and notice that it's been abandoned for years...maybe even decades.");
    lab->visited = 0;
    lab->north = NULL;
    lab->east = city;
    lab->south = NULL;
    lab->west = NULL;

    strcpy(ocean->name, "Radioactive Ocean");
    strcpy(ocean->description, "You see the endless radioactive ocean with no chance of survival without a proper gear.");
    ocean->visited = 0;
    ocean->north = NULL;
    ocean->east = NULL;
    ocean->south = NULL;
    ocean->west = city;

    // Current room pointer
    struct Room* current = start;

    // Game loop
    char input[20];
    int playing = 1;
    while (playing) {
        printRoom(current);
        printf("What would you like to do? (move/take/use/quit) ");
        scanf("%s", input);

        if (strcmp(input, "move") == 0) {
            printf("Which direction? (north/east/south/west) ");
            scanf("%s", input);
            move(&current, input);
        }
        else if (strcmp(input, "take") == 0) {
            printf("Which item would you like to take? ");
            scanf("%s", input);
            takeItem(&current, input);
        }
        else if (strcmp(input, "use") == 0) {
            printf("Which item would you like to use? ");
            scanf("%s", input);
            useItem(&current, input);
        }
        else if (strcmp(input, "quit") == 0) {
            playing = 0;
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }

    // Game over
    printf("Thanks for playing!\n");
    return 0;
}

// Print room details
void printRoom(struct Room* room) {
    printf("\n%s\n%s\n\n", room->name, room->description);
    room->visited = 1;
}

// Move to another room
void move(struct Room** current, char* direction) {
    if (strcmp(direction, "north") == 0 && (*current)->north != NULL) {
        (*current) = (*current)->north;
    }
    else if (strcmp(direction, "east") == 0 && (*current)->east != NULL) {
        (*current) = (*current)->east;
    }
    else if (strcmp(direction, "south") == 0 && (*current)->south != NULL) {
        (*current) = (*current)->south;
    }
    else if (strcmp(direction, "west") == 0 && (*current)->west != NULL) {
        (*current) = (*current)->west;
    }
    else {
        printf("You cannot go that way!\n");
    }
}

// Take an item from the room
void takeItem(struct Room** current, char* item) {
    if (strcmp((*current)->name, "Scientific Lab") == 0 && strcmp(item, "antidote") == 0) {
        printf("You take the antidote.\n");
    }
    else {
        printf("There is no such item here.\n");
    }
}

// Use an item from the inventory
void useItem(struct Room** current, char* item) {
    if (strcmp((*current)->name, "Radioactive Ocean") == 0 && strcmp(item, "antidote") == 0) {
        printf("You use the antidote and escape the radioactive ocean.\n");
        (*current) = (*current)->north; // Moves to start room
    }
    else {
        printf("You cannot use that item here.\n");
    }
}