//FormAI DATASET v1.0 Category: Text processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of the Node structure for the linked list
struct Node {
    char *text;
    struct Node *next;
};

struct Node *head = NULL;  // Head of the linked list

/*
This function creates a new Node with the given text and appends it to the linked list
*/
void append(char *text) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->text = (char*) malloc(strlen(text) + 1);  // Allocate memory for text
    strcpy(new_node->text, text);
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        return;
    }
    struct Node *current_node = head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

/*
This function prints the entire linked list
*/
void print() {
    struct Node *current_node = head;
    while (current_node != NULL) {
        printf("%s", current_node->text);
        current_node = current_node->next;
    }
}

int main() {
    // Read text from a file
    FILE *file_pointer = fopen("example.txt", "r");
    char line[100];
    if (file_pointer == NULL) {
        fprintf(stderr, "Error: Unable to open file\n");
        exit(1);
    }
    while (fgets(line, 100, file_pointer) != NULL) {
        append(line);
    }
    fclose(file_pointer);
    // Print the contents of the file on the console
    print();
    // Free allocated memory
    struct Node *current_node = head;
    while (current_node != NULL) {
        struct Node *temp_node = current_node->next;
        free(current_node->text);
        free(current_node);
        current_node = temp_node;
    }
    return 0;
}