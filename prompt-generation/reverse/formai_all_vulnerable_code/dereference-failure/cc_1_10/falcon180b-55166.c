//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Linked list node structure
typedef struct node {
    char text[MAX_LINE_LENGTH];
    struct node* next;
} Node;

// Ebook structure
typedef struct ebook {
    char title[MAX_LINE_LENGTH];
    Node* content;
} Ebook;

// Function to create a new ebook
Ebook* create_ebook(char* title) {
    Ebook* ebook = malloc(sizeof(Ebook));
    strcpy(ebook->title, title);
    ebook->content = NULL;
    return ebook;
}

// Function to add a line of text to the ebook
void add_line(Ebook* ebook, char* line) {
    Node* new_node = malloc(sizeof(Node));
    strcpy(new_node->text, line);
    new_node->next = ebook->content;
    ebook->content = new_node;
}

// Function to print the ebook
void print_ebook(Ebook* ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Content:\n");
    Node* current_node = ebook->content;
    while (current_node!= NULL) {
        printf("%s\n", current_node->text);
        current_node = current_node->next;
    }
}

// Main function
int main() {
    Ebook* ebook = create_ebook("My Ebook");
    add_line(ebook, "Chapter 1");
    add_line(ebook, "This is the first chapter of my ebook.");
    add_line(ebook, "Chapter 2");
    add_line(ebook, "This is the second chapter of my ebook.");
    print_ebook(ebook);
    free(ebook->title);
    free(ebook);
    return 0;
}