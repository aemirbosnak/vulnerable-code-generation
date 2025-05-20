//FormAI DATASET v1.0 Category: Spell checking ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

// Node structure for Linked List
typedef struct node {
    char* word;
    struct node *next;
} node;

// Function to create a new node
node* create_node(char* word) {
    node* new_node = malloc(sizeof(node));
    new_node->word = malloc(strlen(word) + 1);
    strcpy(new_node->word, word);
    new_node->next = NULL;
    return new_node;
}

// Function to free memory allocated for linked list
void free_list(node* head) {
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->word);
        free(temp);
    }
}

// Function to add a word to the linked list
void add_word(node** head_ptr, char* word) {
    node* new_node = create_node(word);
    if (*head_ptr == NULL) {
        *head_ptr = new_node;
    } else {
        node* curr = *head_ptr;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = new_node;
    }
}

// Function to check if a word is in the linked list
int is_word_in_list(node* head, char* word) {
    while (head != NULL) {
        if (strcmp(head->word, word) == 0)
            return 1;
        head = head->next;
    }
    return 0;
}

// Function to check if a word is spelled correctly
int spell_check(char* word, node* dictionary) {
    if (is_word_in_list(dictionary, word))
        return 1;
    return 0;
}

int main() {

    char word[MAX_WORD_LENGTH];

    // Initialize the dictionary
    node* dictionary = NULL;
    add_word(&dictionary, "hello");
    add_word(&dictionary, "world");
    add_word(&dictionary, "computer");
    add_word(&dictionary, "science");

    printf("Enter a word: ");
    scanf("%s", word);

    if (spell_check(word, dictionary)) {
        printf("The word is spelled correctly\n");
    } else {
        printf("The word is spelled incorrectly\n");
    }

    // Free memory allocated for dictionary
    free_list(dictionary);

    return 0;
}