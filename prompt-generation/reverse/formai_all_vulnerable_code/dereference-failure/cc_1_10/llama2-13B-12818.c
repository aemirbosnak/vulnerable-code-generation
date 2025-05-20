//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a knight
struct Knight {
    int id;
    char name[20];
    int armor;
    int weapon;
    struct Knight *next;
};

// Function to create a new knight
struct Knight *createKnight(int id, char name[20], int armor, int weapon) {
    struct Knight *knight = (struct Knight *)malloc(sizeof(struct Knight));
    knight->id = id;
    strcpy(knight->name, name);
    knight->armor = armor;
    knight->weapon = weapon;
    knight->next = NULL;
    return knight;
}

// Function to print a list of knights
void printKnights(struct Knight *head) {
    while (head != NULL) {
        printf("Id: %d, Name: %s, Armor: %d, Weapon: %d\n", head->id, head->name, head->armor, head->weapon);
        head = head->next;
    }
}

// Function to add a knight to the end of a list
struct Knight *addKnight(struct Knight **head_ref, int id, char name[20], int armor, int weapon) {
    struct Knight *new_knight = createKnight(id, name, armor, weapon);
    new_knight->next = *head_ref;
    *head_ref = new_knight;
    return new_knight;
}

// Function to remove the first knight from a list
struct Knight *removeKnight(struct Knight **head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }
    struct Knight *temp = *head_ref;
    *head_ref = temp->next;
    free(temp);
    return temp;
}

int main() {
    struct Knight *head = NULL;

    // Add some knights to the list
    head = addKnight(&head, 1, "Sir Reginald", 5, 10);
    head = addKnight(&head, 2, "Sir Edward", 3, 6);
    head = addKnight(&head, 3, "Sir William", 2, 8);

    // Print the list
    printKnights(head);

    // Remove the first knight
    head = removeKnight(&head);

    // Print the updated list
    printKnights(head);

    return 0;
}