//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our lollipop-themed nodes
typedef struct {
    int tickleMeNumber;
    char *laughableName;
    struct lollipopNode *next;
} lollipopNode;

// Create a new lollipop node
lollipopNode *createLollipopNode(int number, char *name) {
    lollipopNode *newNode = (lollipopNode *) malloc(sizeof(lollipopNode));
    newNode->tickleMeNumber = number;
    newNode->laughableName = strdup(name);
    newNode->next = NULL;
    return newNode;
}

// Insert a new node at the beginning of the list
void addNewTicklerAtBeginning(lollipopNode **head, int number, char *name) {
    lollipopNode *newNode = createLollipopNode(number, name);
    newNode->next = *head;
    *head = newNode;
}

// Insert a new node at the end of the list
void addNewTicklerAtEnd(lollipopNode **head, int number, char *name) {
    lollipopNode *newNode = createLollipopNode(number, name);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    lollipopNode *currentNode = *head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

// Display the list of ticklers, with some humor
void displayTicklers(lollipopNode *head) {
    printf("Welcome, dear friend, to our whimsical tickler list!\n");
    printf("Let's see who's ticklish today:\n");
    while (head != NULL) {
        printf("Tickle me number: %d\n", head->tickleMeNumber);
        printf("Laughable name: %s\n", head->laughableName);
        printf("Tickle tickle, heehee! \n");
        head = head->next;
    }
}

int main() {
    lollipopNode *ticklerList = NULL;

    addNewTicklerAtBeginning(&ticklerList, 1, "Bozo the Clown");
    addNewTicklerAtEnd(&ticklerList, 2, "Tickle-Me-Elmo");
    addNewTicklerAtEnd(&ticklerList, 3, "Barney the Dinosaur");

    displayTicklers(ticklerList);

    free(ticklerList);

    printf("Tickles and giggles for all! Goodbye!\n");

    return 0;
}