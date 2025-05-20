//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 100
#define MAX_NAME_LENGTH 50

typedef struct Character {
    char name[MAX_NAME_LENGTH];
    char role[MAX_NAME_LENGTH];
    char relationship[MAX_NAME_LENGTH];
    int index;

} Character;

typedef struct Index {
    Character *characters[MAX_CHARACTERS];
    int count;
} Index;

void addCharacter(Index *index, const char *name, const char *role, const char *relationship) {
    if (index->count >= MAX_CHARACTERS) {
        printf("Alas! The index is full, cannot add more characters.\n");
        return;
    }
    Character *newChar = (Character *)malloc(sizeof(Character));
    strcpy(newChar->name, name);
    strcpy(newChar->role, role);
    strcpy(newChar->relationship, relationship);
    newChar->index = index->count;
    
    index->characters[index->count++] = newChar;
    printf("Enter the eternal name, %s! In our hearts, you shall remain.\n", name);
}

void displayCharacter(const Character *character) {
    printf("Character: %s\n", character->name);
    printf("Role: %s\n", character->role);
    printf("Relationship: %s\n", character->relationship);
    printf("--------------------------------\n");
}

Character* findCharacter(const Index *index, const char *name) {
    for (int i = 0; i < index->count; i++) {
        if (strcmp(index->characters[i]->name, name) == 0) {
            return index->characters[i];
        }
    }
    printf("Wherefore art thou, dear %s? Not found in our scrolls!\n", name);
    return NULL;
}

void removeCharacter(Index *index, const char *name) {
    for (int i = 0; i < index->count; i++) {
        if (strcmp(index->characters[i]->name, name) == 0) {
            free(index->characters[i]);

            // Shift the remaining characters down
            for (int j = i; j < index->count - 1; j++) {
                index->characters[j] = index->characters[j + 1];
            }
            index->characters[index->count - 1] = NULL;
            index->count--;
            printf("%s the character has departed, their story concluded.\n", name);
            return;
        }
    }
    printf("Would that you could find %s in our realms!\n", name);
}

void displayAllCharacters(const Index *index) {
    printf("Gather 'round, good folk, and behold the roster of our tale:\n");
    for (int i = 0; i < index->count; i++) {
        displayCharacter(index->characters[i]);
    }
}

void freeIndex(Index *index) {
    for (int i = 0; i < index->count; i++) {
        free(index->characters[i]);
    }
    index->count = 0;
}

int main() {
    Index characterIndex = {.count = 0};

    // Adding characters to the index
    addCharacter(&characterIndex, "Romeo", "Lover", "Juliet");
    addCharacter(&characterIndex, "Juliet", "Lover", "Romeo");
    addCharacter(&characterIndex, "Mercutio", "Friend", "Romeo");
    addCharacter(&characterIndex, "Tybalt", "Rival", "Romeo");
    
    // Find a character
    Character *found = findCharacter(&characterIndex, "Juliet");
    if (found) {
        displayCharacter(found);
    }

    // Display all characters
    displayAllCharacters(&characterIndex);

    // Remove a character
    removeCharacter(&characterIndex, "Tybalt");

    // Display remaining characters
    displayAllCharacters(&characterIndex);

    // Clean up
    freeIndex(&characterIndex);
    return 0;
}