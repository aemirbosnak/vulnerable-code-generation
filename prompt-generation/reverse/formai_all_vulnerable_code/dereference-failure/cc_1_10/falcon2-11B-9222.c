//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to initialize the Haunted House
void initializeHouse(char** house, int size) {
    for (int i = 0; i < size; i++) {
        strcpy(house[i], "room ");
        house[i][strlen(house[i])-1] = '\0';
    }
}

// Function to enter the Haunted House
void enterHouse(char** house, int size) {
    printf("You enter the haunted house...\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", house[i]);
    }
}

// Function to exit the Haunted House
void exitHouse(char** house, int size) {
    printf("You exit the haunted house...\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", house[i]);
    }
}

// Function to check if there is a ghost in the room
int isGhost(char* room) {
    if (strcmp(room, "ghost room") == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int size = 10;
    char** house = malloc(size * sizeof(char*));
    if (house == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    initializeHouse(house, size);
    house[0] = "entrance";
    house[1] = "living room";
    house[2] = "kitchen";
    house[3] = "dining room";
    house[4] = "bedroom";
    house[5] = "bathroom";
    house[6] = "study";
    house[7] = "library";
    house[8] = "basement";
    house[9] = "ghost room";
    enterHouse(house, size);
    printf("You find a key in the study!\n");
    printf("You can unlock the basement with the key.\n");
    exitHouse(house, size);
    if (isGhost(house[9])) {
        printf("You encounter the ghost!\n");
        exitHouse(house, size);
    }
    return 0;
}