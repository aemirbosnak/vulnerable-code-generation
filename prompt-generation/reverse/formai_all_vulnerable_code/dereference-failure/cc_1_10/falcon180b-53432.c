//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct node {
    char *data;
    int count;
    struct node *next;
};

int main() {
    char str[MAX_SIZE];
    char *token;
    struct node *head = NULL;

    // Prompt user to enter a string
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    // Remove newline character from string
    str[strcspn(str, "\n")] = '\0';

    // Count number of words in string
    token = strtok(str, " ");
    while (token!= NULL) {
        struct node *temp = head;

        // Check if word already exists in hash table
        while (temp!= NULL && strcmp(temp->data, token)!= 0) {
            temp = temp->next;
        }

        // If word exists, increment count
        if (temp!= NULL) {
            temp->count++;
        } else {
            // Otherwise, add new word to hash table
            struct node *new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = strdup(token);
            new_node->count = 1;
            new_node->next = head;
            head = new_node;
        }

        token = strtok(NULL, " ");
    }

    // Print hash table
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%s: %d\n", temp->data, temp->count);
        temp = temp->next;
    }

    return 0;
}