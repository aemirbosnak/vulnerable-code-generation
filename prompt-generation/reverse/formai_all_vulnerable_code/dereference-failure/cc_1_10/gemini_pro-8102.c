//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a node for the linked list
typedef struct node {
    char *word;
    int count;
    struct node *next;
} node;

// Create a new node
node *create_node(char *word) {
    node *new_node = malloc(sizeof(node));
    new_node->word = malloc(strlen(word) + 1);
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

// Insert a node into the linked list
void insert_node(node **head, node *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Find a node in the linked list
node *find_node(node *head, char *word) {
    node *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Print the linked list
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

// Free the linked list
void free_list(node *head) {
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

// Count the words in a string
int count_words(char *string) {
    int count = 0;
    char *word = strtok(string, " ");
    while (word != NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Read a file into a string
char *read_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    char *string = malloc(size + 1);
    fread(string, 1, size, fp);
    string[size] = '\0';
    fclose(fp);
    return string;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char *string = read_file(argv[1]);
    if (string == NULL) {
        printf("Error reading file\n");
        return 1;
    }
    node *head = NULL;
    int word_count = count_words(string);
    char *word = strtok(string, " ");
    while (word != NULL) {
        node *node = find_node(head, word);
        if (node == NULL) {
            node = create_node(word);
            insert_node(&head, node);
        } else {
            node->count++;
        }
        word = strtok(NULL, " ");
    }
    printf("Word count: %d\n", word_count);
    print_list(head);
    free_list(head);
    free(string);
    return 0;
}