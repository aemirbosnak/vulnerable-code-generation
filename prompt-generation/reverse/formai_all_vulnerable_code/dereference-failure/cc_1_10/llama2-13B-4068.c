//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a knight
struct Knight {
    int gold;    // Gold coins carried by the knight
    struct Knight *next;  // Pointer to the next knight in the list
};

// Function to create a new knight
struct Knight *createKnight(int gold) {
    struct Knight *newKnight = (struct Knight *) malloc(sizeof(struct Knight));
    newKnight->gold = gold;
    newKnight->next = NULL;
    return newKnight;
}

// Function to add a knight to the beginning of a list
struct Knight *addKnightToBeginning(struct Knight *list, int gold) {
    struct Knight *newKnight = createKnight(gold);
    newKnight->next = list;
    list = newKnight;
    return list;
}

// Function to add a knight to the end of a list
struct Knight *addKnightToEnd(struct Knight *list, int gold) {
    struct Knight *newKnight = createKnight(gold);
    struct Knight *current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newKnight;
    newKnight->next = NULL;
    return list;
}

// Function to remove the first knight from a list
struct Knight *removeFirstKnight(struct Knight *list) {
    struct Knight *result = list->next;
    list->next = list->next->next;
    return result;
}

// Function to remove the last knight from a list
struct Knight *removeLastKnight(struct Knight *list) {
    struct Knight *current = list;
    struct Knight *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    return current;
}

// Function to traverse the list of knights
void traverseKnights(struct Knight *list) {
    struct Knight *current = list;
    while (current != NULL) {
        printf("Knight %d has %d gold coins\n", current->gold, current->next == NULL ? 0 : current->next->gold);
        current = current->next;
    }
}

int main() {
    struct Knight *list = NULL;
    list = addKnightToBeginning(list, 50);
    list = addKnightToBeginning(list, 30);
    list = addKnightToEnd(list, 20);
    list = removeFirstKnight(list);
    list = removeLastKnight(list);
    traverseKnights(list);
    return 0;
}