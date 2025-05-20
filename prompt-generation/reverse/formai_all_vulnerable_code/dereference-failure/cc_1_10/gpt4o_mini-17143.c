//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the node structure, where imagination meets reality
typedef struct Node {
    char data[256];
    struct Node* next;
} Node;

// Functions to birth, append, and traverse the dreamlike list
Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node** head, const char* data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void traverseList(Node* head) {
    Node* temp = head;
    printf("In the surreal garden of dreams, we wander...\n");
    while (temp != NULL) {
        printf("Node: %s\n", temp->data);
        temp = temp->next;
    }
    printf("...and emerge transformed.\n");
}

// A function to darkly whisper a tale of deletion
void deleteNode(Node** head, const char* data) {
    if (*head == NULL) {
        printf("No nodes to delete, only shadows remain.\n");
        return;
    }
    
    Node* temp = *head;
    Node* prev = NULL;
    
    while (temp != NULL && strcmp(temp->data, data) != 0) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("The specter of '%s' was never here to be found.\n", data);
        return;
    }
    
    if (prev == NULL) {
        *head = temp->next; // Detaching the head, as if a dream forgotten
    } else {
        prev->next = temp->next;
    }
    free(temp); // Set free the spectral node
    printf("The node '%s' has been released back into the ether.\n", data);
}

// Recursively whisper sweet nothings
void clearList(Node* head) {
    if (head == NULL) return;
    clearList(head->next);
    free(head);
}

// A mosaic of function declarations
void surrealListOperation() {
    Node* surrealList = NULL;

    // The journey begins, append more dreams to the list
    appendNode(&surrealList, "A silver bird in a cerulean sky");
    appendNode(&surrealList, "The echoing laughter of forgotten children");
    appendNode(&surrealList, "Whispers of timeless shadows");
    
    // Traverse the list of dreams
    traverseList(surrealList);
    
    // Attempt to delete a dream
    deleteNode(&surrealList, "The echoing laughter of forgotten children");
    traverseList(surrealList);
    
    // Seeking another deletion
    deleteNode(&surrealList, "A phoenix rising from the ashes");
    
    // Clear all remaining dreams from the surreal list
    clearList(surrealList);
    printf("All dreams have evaporated into the abyss.\n");
}

// The canvas of existence
int main() {
    printf("Welcome to the realm of Surreal Linked Lists...\n");
    surrealListOperation();
    return 0;
}