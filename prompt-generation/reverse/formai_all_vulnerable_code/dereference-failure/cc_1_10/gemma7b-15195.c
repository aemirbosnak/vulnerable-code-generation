//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume_node {
    char name[256];
    char email[256];
    char phone[256];
    struct resume_node* next;
} resume_node;

void parse_resume(char* resume_text) {
    resume_node* head = NULL;
    resume_node* current = NULL;

    // Tokenize the resume text
    char* token = strtok(resume_text, " ");

    // Iterate over the tokens
    while (token) {
        // Create a new resume node
        resume_node* new_node = malloc(sizeof(resume_node));

        // Set the node's name, email, and phone
        strcpy(new_node->name, token);
        token = strtok(NULL, " ");
        strcpy(new_node->email, token);
        token = strtok(NULL, " ");
        strcpy(new_node->phone, token);

        // Add the node to the list
        if (head == NULL) {
            head = new_node;
        } else {
            current->next = new_node;
        }

        current = new_node;
    }

    // Print the resume nodes
    resume_node* tmp = head;
    while (tmp) {
        printf("%s, %s, %s\n", tmp->name, tmp->email, tmp->phone);
        tmp = tmp->next;
    }
}

int main() {
    char* resume_text = "John Doe, john.doe@example.com, 123-456-7890\nJane Doe, jane.doe@example.com, 456-789-0123";

    parse_resume(resume_text);

    return 0;
}