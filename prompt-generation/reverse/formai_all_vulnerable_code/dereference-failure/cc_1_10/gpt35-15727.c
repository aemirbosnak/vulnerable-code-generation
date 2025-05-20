//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 250

typedef struct node {
    char word[MAX_WORD_SIZE];
    int count;
    struct node *next;
} word_node;

word_node *create_node(char *word) {
    word_node *node = (word_node *)malloc(sizeof(word_node));
    strncpy(node->word, word, MAX_WORD_SIZE);
    node->count = 1;
    node->next = NULL;
    return node;
}

void insert_word(char *word, word_node **head) {
    if (*head == NULL) {
        *head = create_node(word);
        return;
    }
    word_node *current = *head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }
    current = create_node(word);
    current->next = *head;
    *head = current;
}

void print_word_counts(word_node *head) {
    if (head == NULL) {
        printf("No words to count!\n");
        return;
    }
    printf("Word\t\tCount\n");
    printf("----------------------\n");
    while (head != NULL) {
        printf("%-15s %d\n", head->word, head->count);
        head = head->next;
    }
}

void sanitize_word(char *word) {
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        word[i] = tolower(word[i]);
        if (!isalpha(word[i])) {
            for (int j = i; j < length - 1; j++) {
                word[j] = word[j + 1];
            }
            i--;
            length--;
        }
    }
    word[length] = '\0';
}

int main() {
    char input[10000];
    printf("Enter a sentence to count word frequencies:\n");
    fgets(input, 10000, stdin);

    word_node *head = NULL;
    char *word = strtok(input, " ");
    while (word != NULL) {
        sanitize_word(word);
        insert_word(word, &head);
        word = strtok(NULL, " ");
    }

    print_word_counts(head);
    return 0;
}