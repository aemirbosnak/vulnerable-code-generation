//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *family;
    char *fate;
} Character;

void allocateCharacter(Character *c, const char *name, const char *family, const char *fate) {
    c->name = (char *)malloc(strlen(name) + 1);
    if (c->name == NULL) {
        fprintf(stderr, "Memory allocation failed for name.\n");
        exit(1);
    }
    strcpy(c->name, name);

    c->family = (char *)malloc(strlen(family) + 1);
    if (c->family == NULL) {
        fprintf(stderr, "Memory allocation failed for family.\n");
        exit(1);
    }
    strcpy(c->family, family);

    c->fate = (char *)malloc(strlen(fate) + 1);
    if (c->fate == NULL) {
        fprintf(stderr, "Memory allocation failed for fate.\n");
        exit(1);
    }
    strcpy(c->fate, fate);
}

void freeCharacter(Character *c) {
    free(c->name);
    free(c->family);
    free(c->fate);
}

void printCharacter(Character *c) {
    printf("Character: %s\n", c->name);
    printf("Family: %s\n", c->family);
    printf("Fate: %s\n", c->fate);
    printf("\n");
}

void loveStory(Character *romeo, Character *juliet) {
    printf("Once upon a time in fair Verona,\n");
    
    printf("We meet our brave lover, %s,\n", romeo->name);
    printf("A Montague, with a heart full of yearning,\n");
    printf("For his sweet love, the fair maiden, %s,\n", juliet->name);
    printf("From the rival house of Capulet, oh! What a fate!\n");

    printf("Together they crafted a plan to be united,\n");
    printf("But fate, it seemed, had other plans ignited.\n");
    printf("With love as their shield, they dared the conflict,\n");
    printf("Yet destiny’s hand crafted a tragic conflict.\n");

    printf("As they swore their love in the darkness of night,\n");
    printf("The world around them fell into a dismal plight.\n");
}

int main() {
    Character romeo;
    Character juliet;

    // Allocate memory for characters
    allocateCharacter(&romeo, "Romeo Montague", "Montague", "Doomed by fate");
    allocateCharacter(&juliet, "Juliet Capulet", "Capulet", "Tragic demise");

    // Print the love story
    printCharacter(&romeo);
    printCharacter(&juliet);
    
    loveStory(&romeo, &juliet);

    // Free the allocated memory
    freeCharacter(&romeo);
    freeCharacter(&juliet);

    printf("And thus, their love intertwined,\n");
    printf("In the end, the bonds they formed were forever enshrined.\n");
    return 0;
}