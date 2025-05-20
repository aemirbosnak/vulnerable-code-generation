//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100];
    char* currentRoom;
    char* roomDesc;
    char* verb;
    char* noun;

    printf("Welcome to the Adventure Game!\n");
    printf("You are in a dark room. There is a door to your right and a door to your left.\n");

    currentRoom = "dark room";
    roomDesc = "There is a door to your right and a door to your left.";

    printf("%s\n", roomDesc);

    printf("What would you like to do? (look, go, take, exit)\n");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s %s %s", verb, noun, currentRoom);

    if (strcmp(verb, "look") == 0) {
        printf("%s\n", roomDesc);
    } else if (strcmp(verb, "go") == 0) {
        if (strcmp(noun, "right") == 0) {
            printf("You go through the right door and enter a new room.\n");
            currentRoom = "new room";
            roomDesc = "There is a treasure chest in the center of the room.";
            printf("%s\n", roomDesc);
        } else if (strcmp(noun, "left") == 0) {
            printf("You go through the left door and enter a new room.\n");
            currentRoom = "new room";
            roomDesc = "There is a trapdoor in the center of the room.";
            printf("%s\n", roomDesc);
        } else {
            printf("You cannot go %s.\n", noun);
        }
    } else if (strcmp(verb, "take") == 0) {
        if (strcmp(noun, "treasure") == 0) {
            printf("You take the treasure chest.\n");
            roomDesc = "There is no treasure chest in the room.\n";
            printf("%s\n", roomDesc);
        } else if (strcmp(noun, "trapdoor") == 0) {
            printf("You take the trapdoor.\n");
            roomDesc = "There is no trapdoor in the room.\n";
            printf("%s\n", roomDesc);
        } else {
            printf("You cannot take %s.\n", noun);
        }
    } else if (strcmp(verb, "exit") == 0) {
        printf("Goodbye!\n");
        exit(0);
    } else {
        printf("I don't understand that command.\n");
    }

    return 0;
}