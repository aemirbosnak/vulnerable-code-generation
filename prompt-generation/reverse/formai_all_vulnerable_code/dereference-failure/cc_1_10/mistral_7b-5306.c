//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CANDIDATES 10
#define HASH_SIZE 101

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct HashNode {
    Candidate data;
    struct HashNode *next;
} HashNode;

unsigned int hash(const char *str) {
    unsigned int hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % HASH_SIZE;
}

HashNode *create_node(const Candidate candidate) {
    HashNode *new_node = (HashNode *) malloc(sizeof(HashNode));

    new_node->data = candidate;
    new_node->next = NULL;

    return new_node;
}

void insert_candidate(HashNode **hash_table, const Candidate candidate) {
    unsigned int index = hash(candidate.name);

    if (*hash_table == NULL) {
        *hash_table = create_node(candidate);
    } else {
        HashNode *current = *hash_table;

        while (current != NULL) {
            if (strcmp(current->data.name, candidate.name) == 0) {
                current->data.votes += candidate.votes;
                free(candidate.name);
                free(candidate.name + sizeof(candidate.name) - 1);
                free(&candidate);
                return;
            }
            current = current->next;
        }

        HashNode *new_node = create_node(candidate);
        new_node->next = *hash_table;
        *hash_table = new_node;
    }
}

void print_results(HashNode *hash_table) {
    printf("\n--- ELECTRONIC VOTING SYSTEM RESULTS ---\n");

    for (HashNode *current = hash_table; current != NULL; current = current->next) {
        printf("%s: %d votes\n", current->data.name, current->data.votes);
    }
}

int main() {
    HashNode *hash_table[HASH_SIZE] = {0};

    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; ++i) {
        Candidate candidate;
        printf("\nEnter candidate %d details:\n", i + 1);
        printf("Name: ");
        scanf("%s", candidate.name);
        printf("Votes: ");
        scanf("%d", &candidate.votes);

        insert_candidate(hash_table, candidate);
    }

    print_results(hash_table);

    return 0;
}