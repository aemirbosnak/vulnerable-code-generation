//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A fair declaration, a Node be named
typedef struct Node {
    char name[50];
    struct Node *next;
} Node;

// A tragedy unfolds as we create our linked list
Node* createNode(char name[]) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// In this masquerade, we insert a Node with grace
void insertNode(Node **head, char name[]) {
    Node *newNode = createNode(name);
    newNode->next = *head;
    *head = newNode;
}

// With love entwined, we display the list
void displayList(Node *node) {
    while (node != NULL) {
        printf("%s -> ", node->name);
        node = node->next;
    }
    printf("NULL\n");
}

// A harsh decree, we must remove a Node
void deleteNode(Node **head, char name[]) {
    Node *temp = *head, *prev = NULL;

    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next; 
        free(temp);         
        return;
    }
    
    // Losing love, we search for the Node
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Alas, %s not found!\n", name);
        return;
    }
    
    // The sorrowful parting
    prev->next = temp->next;
    free(temp);
}

// A fateful night, we count the Nodes
int countNodes(Node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    Node *head = NULL;
    char name[50];
    int choice;

    // A gathering to remember, where choices are made
    do {
        printf("\nA Tale of Nodes, Choose thy action:\n");
        printf("1. Add a character\n");
        printf("2. Remove a character\n");
        printf("3. Show the characters\n");
        printf("4. Count the characters\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("What be the character's name? ");
                scanf("%s", name);
                insertNode(&head, name);
                printf("%s hath entered the tale!\n", name);
                break;
            case 2:
                printf("Which character must depart? ");
                scanf("%s", name);
                deleteNode(&head, name);
                break;
            case 3:
                printf("The characters of our play are:\n");
                displayList(head);
                break;
            case 4:
                printf("Count thou the characters: %d\n", countNodes(head));
                break;
            case 5:
                printf("Farewell, till we meet again.\n");
                break;
            default:
                printf("Invalid choice, perhaps dost thou need more love?\n");
        }
    } while (choice != 5);
    
    // A final curtain, we free the memory
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}