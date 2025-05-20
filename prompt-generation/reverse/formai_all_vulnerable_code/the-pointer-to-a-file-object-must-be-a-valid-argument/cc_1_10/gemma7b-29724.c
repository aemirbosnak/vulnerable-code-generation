//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct resume_node {
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    struct resume_node* next;
} resume_node;

resume_node* parse_resume(FILE* file) {
    resume_node* head = NULL;
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];

    // Read the file line by line
    char line[MAX_NAME_LENGTH];
    while (fgets(line, MAX_NAME_LENGTH, file) != NULL) {
        // Extract the name and experience from the line
        char* name_start = strstr(line, "Name:");
        char* experience_start = strstr(line, "Experience:");

        // If the name and experience have been extracted, create a new node
        if (name_start && experience_start) {
            resume_node* new_node = malloc(sizeof(resume_node));
            new_node->next = head;
            head = new_node;

            // Copy the name and experience into the node
            strcpy(new_node->name, name_start + 5);
            strcpy(new_node->experience, experience_start + 9);
        }
    }

    return head;
}

int main() {
    FILE* file = fopen("resume.txt", "r");
    resume_node* head = parse_resume(file);

    // Print the name and experience of each node
    for (resume_node* node = head; node; node = node->next) {
        printf("Name: %s\n", node->name);
        printf("Experience: %s\n", node->experience);
        printf("\n");
    }

    fclose(file);

    return 0;
}