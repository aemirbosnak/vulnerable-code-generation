//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

// Linked List Node for Words
struct node {
    char word[MAX_WORD_LEN];
    int count;
    struct node *next;
};

// Function to Add Word to Linked List
void add_word(struct node **head, char *word) {
    // Check if Word Already Exists
    struct node *tmp = *head;
    while (tmp != NULL) {
        if (strcmp(tmp->word, word) == 0) {
            tmp->count++;
            return;
        }
        tmp = tmp->next;
    }

    // Add New Word to Linked List
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = *head;
    *head = new_node;
}

// Function to Print Linked List
void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

int main() {
    // Open Input File for Reading
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Create Linked List to Store Words
    struct node *word_list = NULL;

    // Parse Text from Input File
    char word[MAX_WORD_LEN];
    int c;
    memset(word, 0, MAX_WORD_LEN);
    while ((c = fgetc(input_file)) != EOF) {
        if (isalpha(c)) {
            strncat(word, &c, 1);
        } else {
            if (strlen(word) > 0) {
                add_word(&word_list, word);
                memset(word, 0, MAX_WORD_LEN);
            }
        }
    }

    // Print Word Counts
    print_list(word_list);

    // Close Input File
    fclose(input_file);

    return 0;
}