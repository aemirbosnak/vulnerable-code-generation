//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* word;
    struct node* next;
} node;

node* createNode(char* word) {
    node* newNode = malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Error: Could not allocate memory for new node.\n");
        exit(1);
    }
    newNode->word = strdup(word);
    newNode->next = NULL;
    return newNode;
}

void printNode(node* node) {
    if (node == NULL) {
        printf("(nil)\n");
        return;
    }
    printf("%s\n", node->word);
    printNode(node->next);
}

int main() {
    node* root = createNode("apple");
    node* current = root;

    do {
        printf("Choose a word to match from the following: ");
        printNode(root);
        int choice;
        scanf("%d", &choice);
        if (choice < 1 || choice > 4) {
            printf("Invalid choice. Please choose a number between 1 and 4.\n");
            continue;
        }
        current = root;
        for (int i = 1; i <= choice; i++) {
            current = current->next;
        }
        printf("You chose %s.\n", current->word);
        printf("Is this correct? (y/n): ");
        char answer;
        scanf(" %c", &answer);
        if (answer!= 'y') {
            printf("Please choose another word.\n");
        } else {
            printf("Correct!\n");
            break;
        }
    } while (1);

    return 0;
}