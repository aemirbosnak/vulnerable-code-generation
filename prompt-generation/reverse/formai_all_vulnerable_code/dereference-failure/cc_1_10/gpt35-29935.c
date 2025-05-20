//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char word[50];
    int count;
    struct node* next;
} node_t;

node_t* head = NULL;

void add_word(char* word) {
    if (head == NULL) {
        node_t* new_node = malloc(sizeof(node_t));
        strcpy(new_node->word, word);
        new_node->count = 1;
        new_node->next = NULL;
        head = new_node;
    } else {
        node_t* current = head;
        while (current != NULL) {
            if (strcmp(current->word, word) == 0) {
                current->count++;
                return;
            }
            current = current->next;
        }
        
        node_t* new_node = malloc(sizeof(node_t));
        strcpy(new_node->word, word);
        new_node->count = 1;
        new_node->next = head;
        head = new_node;
    }
}

void print_list() {
    node_t* current = head;
    while (current != NULL) {
        printf("%s : %d\n", current->word, current->count);
        current = current->next;
    }
}

int main() {
    char input[10000];
    printf("Enter some text: ");
    fgets(input, 10000, stdin);
    
    char* token = strtok(input, " ");
    while (token != NULL) {
        char* word = malloc(strlen(token) + 1);
        strcpy(word, token);
        
        // remove newline character from end of input
        if (word[strlen(word) - 1] == '\n') {
            word[strlen(word) - 1] = '\0';
        }
        
        add_word(word);
        
        token = strtok(NULL, " ");
        free(word);
    }
    
    printf("\nWord Frequencies:\n");
    print_list();
    
    return 0;
}