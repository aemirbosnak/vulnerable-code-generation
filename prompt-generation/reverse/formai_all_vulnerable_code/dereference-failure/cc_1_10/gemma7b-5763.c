//Gemma-7B DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_STORAGE 1024

typedef struct Knight {
    char name[50];
    int strength;
    int agility;
    FILE *file;
} Knight;

Knight knights[MAX_STORAGE];

void saveKnight(Knight *knight) {
    FILE *file = knight->file;
    fprintf(file, "%s, %d, %d\n", knight->name, knight->strength, knight->agility);
}

Knight *loadKnight(char *name) {
    for (int i = 0; i < MAX_STORAGE; i++) {
        if (knights[i].name[0] == name[0]) {
            return &knights[i];
        }
    }

    return NULL;
}

int main() {
    // Create a new knight
    Knight *knight = malloc(sizeof(Knight));
    knight->name[0] = 'A';
    knight->strength = 10;
    knight->agility = 8;
    knight->file = fopen("knight.txt", "w");

    // Save the knight
    saveKnight(knight);

    // Load the knight
    Knight *loadedKnight = loadKnight("A");

    // Check if the knight was loaded
    if (loadedKnight) {
        printf("Name: %s\nStrength: %d\nAgility: %d\n", loadedKnight->name, loadedKnight->strength, loadedKnight->agility);
    } else {
        printf("Knight not found.\n");
    }

    return 0;
}