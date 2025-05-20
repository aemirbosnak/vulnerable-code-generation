//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *clue;
    struct Node *next;
} Node;

Node* createNode(char *clue) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->clue = strdup(clue);
    newNode->next = NULL;
    return newNode;
}

void appendClue(Node **head, char *clue) {
    Node *newNode = createNode(clue);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

void deleteClue(Node **head, char *clue) {
    Node *temp = *head, *prev = NULL;

    if (temp != NULL && strcmp(temp->clue, clue) == 0) {
        *head = temp->next;
        free(temp->clue);
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->clue, clue) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Clue '%s' not found!\n", clue);
        return;
    }

    prev->next = temp->next;
    free(temp->clue);
    free(temp);
}

void printClues(Node *head) {
    Node *current = head;
    if (!current) {
        printf("No clues investigated yet.\n");
        return;
    }
    printf("Clues gathered:\n");
    while (current != NULL) {
        printf("- %s\n", current->clue);
        current = current->next;
    }
}

void freeClues(Node **head) {
    Node *current = *head;
    Node *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current->clue);
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

void searchClue(Node *head, char *clue) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->clue, clue) == 0) {
            printf("Clue '%s' discovered!\n", clue);
            return;
        }
        current = current->next;
    }
    printf("Clue '%s' is absent from the files.\n", clue);
}

int main() {
    Node *clueList = NULL;
    char choice[50];
    char clue[100];

    printf("Sherlock Holmes Investigative System\n");
    printf("=====================================\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Append Clue\n");
        printf("2. Delete Clue\n");
        printf("3. Search Clue\n");
        printf("4. Print Clues\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = 0; // Remove newline character

        switch (atoi(choice)) {
            case 1:
                printf("Enter the clue to append: ");
                fgets(clue, sizeof(clue), stdin);
                clue[strcspn(clue, "\n")] = 0; // Remove newline character
                appendClue(&clueList, clue);
                printf("Clue '%s' appended!\n", clue);
                break;
            case 2:
                printf("Enter the clue to delete: ");
                fgets(clue, sizeof(clue), stdin);
                clue[strcspn(clue, "\n")] = 0; // Remove newline character
                deleteClue(&clueList, clue);
                break;
            case 3:
                printf("Enter the clue to search: ");
                fgets(clue, sizeof(clue), stdin);
                clue[strcspn(clue, "\n")] = 0; // Remove newline character
                searchClue(clueList, clue);
                break;
            case 4:
                printClues(clueList);
                break;
            case 5:
                freeClues(&clueList);
                printf("Exiting Sherlock Holmes Investigative System. Farewell!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }

    return 0;
}