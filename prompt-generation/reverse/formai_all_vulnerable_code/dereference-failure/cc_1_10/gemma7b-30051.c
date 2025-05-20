//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct Item {
    char name[MAX_NAME_LENGTH];
    int quantity;
    struct Item* next;
} Item;

typedef struct Character {
    char name[MAX_NAME_LENGTH];
    Item* inventory;
    struct Character* next;
} Character;

Character* headCharacter = NULL;

void insertCharacter(char* name) {
    Character* newNode = malloc(sizeof(Character));
    strcpy(newNode->name, name);
    newNode->inventory = NULL;
    newNode->next = NULL;

    if (headCharacter == NULL) {
        headCharacter = newNode;
    } else {
        Character* temp = headCharacter;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertItem(Character* character, char* itemName, int quantity) {
    Item* newItem = malloc(sizeof(Item));
    strcpy(newItem->name, itemName);
    newItem->quantity = quantity;
    newItem->next = NULL;

    if (character->inventory == NULL) {
        character->inventory = newItem;
    } else {
        Item* temp = character->inventory;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newItem;
    }
}

int main() {
    insertCharacter("Bob");
    insertCharacter("Alice");
    insertCharacter("Tom");

    insertItem(headCharacter, "Sword", 10);
    insertItem(headCharacter, "Shield", 5);
    insertItem(headCharacter->next, "Bow", 20);
    insertItem(headCharacter->next->next, "Arrow", 100);

    Character* currentCharacter = headCharacter;
    while (currentCharacter) {
        printf("%s has %d items:\n", currentCharacter->name);
        Item* item = currentCharacter->inventory;
        while (item) {
            printf("  %s (%d)\n", item->name, item->quantity);
            item = item->next;
        }
        currentCharacter = currentCharacter->next;
    }

    return 0;
}