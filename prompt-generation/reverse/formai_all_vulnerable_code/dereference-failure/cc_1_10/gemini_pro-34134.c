//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the linked list
struct node {
    char *word;
    int count;
    struct node *next;
};

// Create a new node
struct node *create_node(char *word) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

// Insert a word into the linked list
void insert_word(struct node **head, char *word) {
    struct node *new_node = create_node(word);

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Otherwise, insert the new node at the end of the list
    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Count the number of occurrences of a word in a string
int count_occurrences(char *str, char *word) {
    int count = 0;
    char *ptr = str;

    while ((ptr = strstr(ptr, word)) != NULL) {
        count++;
        ptr += strlen(word);
    }

    return count;
}

// Print the linked list
void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

// Free the linked list
void free_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

int main() {
    // Get the input string from the user
    char *str = (char *)malloc(1000);
    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);

    // Create a linked list to store the word counts
    struct node *head = NULL;

    // Tokenize the string and count the occurrences of each word
    char *token = strtok(str, " ,.-!");
    while (token != NULL) {
        int count = count_occurrences(str, token);
        insert_word(&head, token);
        token = strtok(NULL, " ,.-!");
    }

    // Print the word counts
    print_list(head);

    // Free the linked list
    free_list(head);

    return 0;
}