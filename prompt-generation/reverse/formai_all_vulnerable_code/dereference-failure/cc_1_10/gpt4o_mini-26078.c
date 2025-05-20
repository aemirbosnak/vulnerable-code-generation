//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Character {
    char name[50];
    char description[200];
    struct Character *next;
} Character;

typedef struct {
    Character *head;
} Index;

Index *createIndex() {
    Index *index = (Index *)malloc(sizeof(Index));
    index->head = NULL;
    return index;
}

void addCharacter(Index *index, const char *name, const char *description) {
    Character *newCharacter = (Character *)malloc(sizeof(Character));
    strcpy(newCharacter->name, name);
    strcpy(newCharacter->description, description);
    newCharacter->next = index->head;
    index->head = newCharacter;
}

void searchCharacter(Index *index, const char *name) {
    Character *current = index->head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Character: %s\nDescription: %s\n", current->name, current->description);
            return;
        }
        current = current->next;
    }
    printf("Alas! The character \"%s\" is not found in our tale.\n", name);
}

void displayCharacters(Index *index) {
    Character *current = index->head;
    printf("In fair Verona, where we lay our scene:\n");
    while (current != NULL) {
        printf("- %s\n", current->name);
        current = current->next;
    }
}

void freeIndex(Index *index) {
    Character *current = index->head;
    while (current != NULL) {
        Character *temp = current;
        current = current->next;
        free(temp);
    }
    free(index);
}

int main() {
    Index *verona = createIndex();

    addCharacter(verona, "Romeo Montague", "A young man from the Montague family, hopelessly in love with Juliet.");
    addCharacter(verona, "Juliet Capulet", "A young woman from the Capulet family, who falls for Romeo.");
    addCharacter(verona, "Mercutio", "A close friend of Romeo, known for his quick wit and lively imagination.");
    addCharacter(verona, "Tybalt Capulet", "Juliet’s fiery cousin, who despises the Montagues.");
    addCharacter(verona, "Friar Laurence", "A kind priest who aids Romeo and Juliet in secrecy.");

    int choice;
    char inputName[50];
    do {
        printf("\n1. Search for a Character\n");
        printf("2. Display All Characters\n");
        printf("3. Exit\n");
        printf("Choose thy destiny (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the character: ");
                scanf("%s", inputName);
                searchCharacter(verona, inputName);
                break;
            case 2:
                displayCharacters(verona);
                break;
            case 3:
                printf("Parting is such sweet sorrow, we shall meet again.\n");
                break;
            default:
                printf("A rose by any other name would smell as sweet, but this choice is void!\n");
                break;
        }
    } while (choice != 3);

    freeIndex(verona);
    return 0;
}