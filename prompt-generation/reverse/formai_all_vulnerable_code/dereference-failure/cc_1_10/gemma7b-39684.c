//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct resume_node {
    char *name;
    struct resume_node *next;
} resume_node;

void parse_resume(char *resume_text) {
    resume_node *head = NULL;
    char *name = NULL;

    // Allocate memory for the resume node
    resume_node *new_node = malloc(sizeof(resume_node));

    // Extract the name from the resume text
    name = strstr(resume_text, "Name:");
    if (name) {
        name += 5; // Skip "Name:"
        new_node->name = malloc(MAX_NAME_LENGTH);
        strncpy(new_node->name, name, MAX_NAME_LENGTH - 1);
    } else {
        new_node->name = NULL;
    }

    // Insert the new node into the linked list
    if (head) {
        new_node->next = head;
    } else {
        head = new_node;
    }

    // Repeat for the remaining nodes
    // (in a real-world scenario, you would iterate over the entire resume text and extract information about other sections, such as skills, experience, etc.)

    // Print the extracted name
    if (new_node->name) {
        printf("Name: %s\n", new_node->name);
    } else {
        printf("No name found.\n");
    }

    // Free the allocated memory
    free(new_node);
}

int main() {
    char resume_text[] = "Name: John Doe\nSkills: Java, Python, C\nExperience: Software Engineer at Google";

    parse_resume(resume_text);

    return 0;
}