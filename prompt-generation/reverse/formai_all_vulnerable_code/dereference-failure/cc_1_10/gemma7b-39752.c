//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

typedef struct resume_node {
    char *name;
    struct resume_node *next;
} resume_node;

resume_node *parse_resume(char *resume_text) {
    resume_node *head = NULL;
    char *name = NULL;

    // Allocate memory for the resume node
    resume_node *new_node = malloc(sizeof(resume_node));

    // Extract the name from the resume text
    name = strstr(resume_text, "Name:");
    if (name) {
        name += 5; // Skip "Name:" and whitespace
        new_node->name = strdup(name);
    } else {
        new_node->name = NULL;
    }

    // Link the new node to the head of the list
    if (head) {
        new_node->next = head;
    } else {
        head = new_node;
    }

    return head;
}

int main() {
    char *resume_text = "John Doe\n"
                           "123 Main St.\n"
                           "New York, NY 10001\n"
                           "Phone: (123) 456-7890\n"
                           "Email: john.doe@example.com\n";

    resume_node *head = parse_resume(resume_text);

    // Print the name of the person
    if (head->name) {
        printf("Name: %s\n", head->name);
    } else {
        printf("Error parsing resume.\n");
    }

    return 0;
}