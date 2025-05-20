//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int votes;
    struct node *next;
} candidate;

typedef struct node {
    candidate data;
    struct node *next;
} node;

node *head = NULL;

void add_candidate(char *name) {
    node *new_node = (node *)malloc(sizeof(node));
    candidate *new_candidate = &new_node->data;
    strcpy(new_candidate->name, name);
    new_candidate->votes = 0;
    new_node->next = head;
    head = new_node;
}

void cast_vote(char *name) {
    node *current = head;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            current->data.votes++;
            printf("Thank you for casting your vote for %s.\n", name);
            return;
        }
        current = current->next;
    }
    printf("Sorry, that candidate is not on the ballot.\n");
}

void display_results() {
    node *current = head;
    while (current != NULL) {
        printf("%s: %d votes\n", current->data.name, current->data.votes);
        current = current->next;
    }
}

int main() {
    add_candidate("Alice");
    add_candidate("Bob");
    add_candidate("Charlie");

    while (1) {
        char name[50];
        printf("Please enter the name of the candidate you wish to vote for: ");
        scanf("%s", name);
        cast_vote(name);
    }

    display_results();

    return 0;
}