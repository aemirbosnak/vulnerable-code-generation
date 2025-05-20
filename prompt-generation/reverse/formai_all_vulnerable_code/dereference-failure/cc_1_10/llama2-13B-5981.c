//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct knight {
    int gold;
    struct knight *next;
};

// Function to create a new node with a given amount of gold
struct knight *newKnight(int gold) {
    struct knight *newNode = malloc(sizeof(struct knight));
    newNode->gold = gold;
    newNode->next = NULL;
    return newNode;
}

// Function to add a knight to the end of the list
void addKnight(struct knight **head_ref, int gold) {
    struct knight *newNode = newKnight(gold);
    if (*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        struct knight *current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to remove the knight with the highest gold from the list
struct knight *removeHighestKnight(struct knight **head_ref) {
    struct knight *current = *head_ref;
    struct knight *highest = NULL;
    int highestGold = 0;

    while (current != NULL) {
        if (current->gold > highestGold) {
            highest = current;
            highestGold = current->gold;
        }
        current = current->next;
    }

    if (highest != NULL) {
        *head_ref = highest->next;
        free(highest);
        return highest;
    } else {
        return NULL;
    }
}

int main() {
    struct knight *head = NULL;

    // Add some knights to the list
    addKnight(&head, 100);
    addKnight(&head, 50);
    addKnight(&head, 200);

    // Remove the knight with the highest gold
    struct knight *removed = removeHighestKnight(&head);
    if (removed != NULL) {
        printf("Removed knight with gold %d\n", removed->gold);
    } else {
        printf("No knight to remove\n");
    }

    // Print the remaining knights in the list
    struct knight *current = head;
    while (current != NULL) {
        printf("%d ", current->gold);
        current = current->next;
    }
    printf("\n");

    return 0;
}