//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct word_node* next;
};

struct word_node* create_word_node(char* word, int count) {
    struct word_node* node = (struct word_node*) malloc(sizeof(struct word_node));
    strcpy(node->word, word);
    node->count = count;
    node->next = NULL;
    return node;
}

void add_word(struct word_node** head, char* word, int count) {
    struct word_node* new_node = create_word_node(word, count);
    struct word_node* curr_node = *head;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (curr_node->next!= NULL) {
        curr_node = curr_node->next;
    }

    curr_node->next = new_node;
}

void print_word_counts(struct word_node* head) {
    struct word_node* curr_node = head;

    while (curr_node!= NULL) {
        printf("%s: %d\n", curr_node->word, curr_node->count);
        curr_node = curr_node->next;
    }
}

int compare_words(char* word1, char* word2) {
    return strcmp(word1, word2);
}

void sort_words(struct word_node* head) {
    qsort(head, MAX_WORDS, sizeof(struct word_node*), compare_words);
}

int main() {
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    char* token;
    FILE* file;
    struct word_node* head = NULL;

    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        token = strtok(line, " ");

        while (token!= NULL) {
            strcpy(word, token);
            add_word(&head, word, 1);
            token = strtok(NULL, " ");
        }
    }

    sort_words(head);
    print_word_counts(head);

    return 0;
}