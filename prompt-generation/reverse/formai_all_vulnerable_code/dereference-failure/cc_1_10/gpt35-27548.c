//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char* word;
    int frequency;
    struct node* next;
} Node;

char* sanitize(char* word) {
    char* sanitized = (char*)malloc(sizeof(char) * (strlen(word) + 1));
    int j = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (isalpha(word[i])) {
            sanitized[j] = tolower(word[i]);
            j++;
        }
    }
    sanitized[j] = '\0';
    return sanitized;
}

void insert(Node** head, char* word) {
    char* sanitized = sanitize(word);
    Node* current = *head;
    Node* prev = NULL;
    while (current != NULL && strcmp(current->word, sanitized) < 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL || strcmp(current->word, sanitized) != 0) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->word = sanitized;
        new_node->frequency = 1;
        new_node->next = current;
        if (prev == NULL) {
            *head = new_node;
        } else {
            prev->next = new_node;
        }
    } else {
        current->frequency++;
        free(sanitized);
    }
}

void print_list(Node* head) {
    while (head != NULL) {
        printf("%s: %d\n", head->word, head->frequency);
        head = head->next;
    }
}

int main() {
    char* input = (char*)malloc(sizeof(char) * 100);
    Node* head = NULL;
    while (fgets(input, 100, stdin) != NULL && input[0] != '\n') {
        char* word = strtok(input, " \t\r\n");
        while (word != NULL) {
            insert(&head, word);
            word = strtok(NULL, " \t\r\n");
        }
    }
    print_list(head);
    return 0;
}