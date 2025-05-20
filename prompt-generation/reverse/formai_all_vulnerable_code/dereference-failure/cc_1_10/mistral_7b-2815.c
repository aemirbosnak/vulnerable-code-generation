//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 101
#define HASH_FUNCTION(x) (x % TABLE_SIZE)

typedef struct {
    int id;
    char vote;
    struct node *next;
} node;

node *table[TABLE_SIZE] = {NULL};

void register_voter(int id) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->id = id;
    new_node->vote = '\0';
    new_node->next = table[HASH_FUNCTION(id)] == NULL ? NULL : table[HASH_FUNCTION(id)];
    table[HASH_FUNCTION(id)] = new_node;
}

void vote(int id, char vote) {
    node *current = table[HASH_FUNCTION(id)];

    while (current != NULL && current->id != id) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid voter ID.\n");
        return;
    }

    current->vote = vote;
}

void print_votes() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        node *current = table[i];
        if (current != NULL) {
            printf("Voter ID: %d, Vote: %c\n", current->id, current->vote);
            current = current->next;
        }
    }
}

int main() {
    int num_voters;
    scanf("%d", &num_voters);

    for (int i = 0; i < num_voters; i++) {
        int id;
        scanf("%d", &id);
        register_voter(id);
    }

    char candidate;
    for (int i = 0; i < num_voters; i++) {
        int id;
        scanf("%d", &id);
        scanf(" %c", &candidate);
        vote(id, candidate);
    }

    print_votes();

    return 0;
}