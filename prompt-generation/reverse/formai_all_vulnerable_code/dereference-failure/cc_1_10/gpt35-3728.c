//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct node {
    char word[50];
    int count;
    struct node *next;
} Node;

int main(void) {
    char text[MAX_SIZE];
    Node *head = NULL;

    printf("Enter text: ");
    fgets(text, MAX_SIZE, stdin);

    char *word = strtok(text, " \n");
    while (word != NULL) {
        // Convert word to lowercase
        for (int i = 0; word[i]; i++)
            word[i] = tolower(word[i]);

        // Check if word already exists in list
        Node *curr = head;
        while (curr != NULL) {
            if (strcmp(curr->word, word) == 0) {
                curr->count++;
                break;
            }
            curr = curr->next;
        }

        // If word does not exist, add a new node
        if (curr == NULL) {
            Node *new_node = malloc(sizeof(Node));
            strcpy(new_node->word, word);
            new_node->count = 1;
            new_node->next = head;
            head = new_node;
        }

        word = strtok(NULL, " \n");
    }

    // Print counts for each word
    Node *curr = head;
    while (curr != NULL) {
        printf("%s: %d\n", curr->word, curr->count);
        curr = curr->next;
    }

    // Free memory
    curr = head;
    while (curr != NULL) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}