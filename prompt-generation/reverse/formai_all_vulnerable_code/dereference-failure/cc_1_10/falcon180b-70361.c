//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

struct node {
    char *word;
    int count;
    struct node *next;
};

struct node *hash_table[MAX_SIZE];

int hash(char *word) {
    int sum = 0;
    int i;
    for (i = 0; i < strlen(word); i++) {
        sum += tolower(word[i]);
    }
    return sum % MAX_SIZE;
}

void insert(char *word) {
    int index = hash(word);
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;
    if (hash_table[index] == NULL) {
        hash_table[index] = new_node;
    } else {
        struct node *temp = hash_table[index];
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void search(char *word) {
    int index = hash(word);
    struct node *temp = hash_table[index];
    while (temp!= NULL) {
        if (strcmp(temp->word, word) == 0) {
            printf("%s: %d\n", temp->word, temp->count);
        }
        temp = temp->next;
    }
}

int main() {
    char input[100];
    while (1) {
        printf("Enter a word to search for or type 'exit' to quit: ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        insert(input);
    }

    printf("\nEnter a word to search for: ");
    scanf("%s", input);
    search(input);

    return 0;
}