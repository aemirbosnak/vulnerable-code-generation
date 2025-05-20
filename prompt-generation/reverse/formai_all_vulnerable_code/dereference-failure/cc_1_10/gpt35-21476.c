//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 50
#define MAX_DESC 100

struct room{
    char name[MAX_INPUT];
    char desc[MAX_DESC];
    struct room* north;
    struct room* east;
    struct room* south;
    struct room* west;
};

struct room* createRoom(char name[], char desc[]);
void connectRooms(struct room* room1, struct room* room2, char direction[]);
void printDescription(struct room* currentRoom);
void move(struct room* currentRoom, char direction[]);
void gameLoop();

int main(){
    gameLoop();
    return 0;
}

struct room* createRoom(char name[], char desc[]){
    struct room* newRoom = (struct room*)malloc(sizeof(struct room));
    strcpy(newRoom->name, name);
    strcpy(newRoom->desc, desc);
    newRoom->north = NULL;
    newRoom->east = NULL;
    newRoom->south = NULL;
    newRoom->west = NULL;
    return newRoom;
}

void connectRooms(struct room* room1, struct room* room2, char direction[]){
    if(strcmp(direction, "north") == 0){
        room1->north = room2;
        room2->south = room1;
    }
    else if(strcmp(direction, "east") == 0){
        room1->east = room2;
        room2->west = room1;
    }
    else if(strcmp(direction, "south") == 0){
        room1->south = room2;
        room2->north = room1;
    }
    else if(strcmp(direction, "west") == 0){
        room1->west = room2;
        room2->east = room1;
    }
    else{
        printf("Invalid direction. Please choose north, east, south, or west.\n");
    }
}

void printDescription(struct room* currentRoom){
    printf("You are in %s.\n", currentRoom->name);
    printf("%s\n", currentRoom->desc);
}

void move(struct room* currentRoom, char direction[]){
    if(strcmp(direction, "north") == 0){
        if(currentRoom->north){
            printf("You move north.\n");
            printDescription(currentRoom->north);
        }
        else{
            printf("There is no room to the north.\n");
        }
    }
    else if(strcmp(direction, "east") == 0){
        if(currentRoom->east){
            printf("You move east.\n");
            printDescription(currentRoom->east);
        }
        else{
            printf("There is no room to the east.\n");
        }
    }
    else if(strcmp(direction, "south") == 0){
        if(currentRoom->south){
            printf("You move south.\n");
            printDescription(currentRoom->south);
        }
        else{
            printf("There is no room to the south.\n");
        }
    }
    else if(strcmp(direction, "west") == 0){
        if(currentRoom->west){
            printf("You move west.\n");
            printDescription(currentRoom->west);
        }
        else{
            printf("There is no room to the west.\n");
        }
    }
    else{
        printf("Invalid direction. Please choose north, east, south, or west.\n");
    }
}

void gameLoop(){
    struct room* room1 = createRoom("Room 1", "You are in a dimly lit room. There is a door to the north.");
    struct room* room2 = createRoom("Room 2", "You are in a small room. There is a door to the south and a door to the east.");
    struct room* room3 = createRoom("Room 3", "You are in a large room. There is a door to the west.");
    
    connectRooms(room1, room2, "north");
    connectRooms(room2, room1, "south");
    connectRooms(room2, room3, "east");
    connectRooms(room3, room2, "west");
    
    struct room* currentRoom = room1;
    printDescription(currentRoom);
    
    while(1){
        char input[MAX_INPUT];
        printf("> ");
        fgets(input, MAX_INPUT, stdin);
        
        if(strcmp(input, "north\n") == 0){
            move(currentRoom, "north");
            currentRoom = currentRoom->north;
        }
        else if(strcmp(input, "east\n") == 0){
            move(currentRoom, "east");
            currentRoom = currentRoom->east;
        }
        else if(strcmp(input, "south\n") == 0){
            move(currentRoom, "south");
            currentRoom = currentRoom->south;
        }
        else if(strcmp(input, "west\n") == 0){
            move(currentRoom, "west");
            currentRoom = currentRoom->west;
        }
        else{
            printf("Invalid input. Please enter north, east, south, or west.\n");
        }
    }
}