//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold information about a character in Romeo and Juliet
typedef struct {
    char* name;
    int age;
    char* occupation;
} Character;

// Function to create a new character
Character* createCharacter(char* name, int age, char* occupation) {
    Character* newChar = (Character*)malloc(sizeof(Character));
    if (newChar == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }
    newChar->name = strdup(name);
    newChar->age = age;
    newChar->occupation = strdup(occupation);
    return newChar;
}

// Function to print information about a character
void printCharacter(Character* charPtr) {
    printf("Name: %s\n", charPtr->name);
    printf("Age: %d\n", charPtr->age);
    printf("Occupation: %s\n", charPtr->occupation);
}

// Function to delete a character and free memory
void deleteCharacter(Character* charPtr) {
    free(charPtr->name);
    free(charPtr->occupation);
    free(charPtr);
}

int main() {
    // Create Romeo and Juliet
    Character* romeo = createCharacter("Romeo", 18, "Nobleman");
    Character* juliet = createCharacter("Juliet", 16, "Noblewoman");

    // Print information about Romeo and Juliet
    printf("Romeo:\n");
    printCharacter(romeo);
    printf("\nJuliet:\n");
    printCharacter(juliet);

    // Delete Romeo and Juliet
    deleteCharacter(romeo);
    deleteCharacter(juliet);

    return 0;
}