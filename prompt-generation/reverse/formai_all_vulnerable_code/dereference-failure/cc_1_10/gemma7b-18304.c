//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct resume_node {
    char name[MAX_NAME_LENGTH];
    struct resume_node* next;
} resume_node;

resume_node* parse_resume(char* resume_text) {
    resume_node* head = NULL;
    char* name = NULL;
    char* text = strtok(resume_text, "\n");

    while (text) {
        name = strstr(text, "Name:");
        if (name) {
            name = name + 5;
            text = strtok(NULL, "\n");
            if (head == NULL) {
                head = malloc(sizeof(resume_node));
                head->next = NULL;
                strcpy(head->name, name);
            } else {
                resume_node* new_node = malloc(sizeof(resume_node));
                new_node->next = NULL;
                strcpy(new_node->name, name);
                head->next = new_node;
                head = new_node;
            }
        }
        text = strtok(NULL, "\n");
    }

    return head;
}

int main() {
    char* resume_text = "Name: John Doe\n"
                           "Address: 123 Main St.\n"
                           "Phone: (555) 123-4567\n"
                           "Email: john.doe@example.com\n";

    resume_node* head = parse_resume(resume_text);

    while (head) {
        printf("Name: %s\n", head->name);
        head = head->next;
    }

    return 0;
}