//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: careful
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

resume_node* parse_resume(char* resume_text) {
    resume_node* head = NULL;
    char* name_start = NULL;
    char* experience_start = NULL;
    char* current_position = NULL;
    char* current_company = NULL;
    char* current_responsibilities = NULL;

    // Allocate memory for the first node
    head = malloc(sizeof(resume_node));

    // Parse the name section
    name_start = strstr(resume_text, "Name:");
    if (name_start) {
        name_start += 5;
        strcpy(head->name, name_start);
    }

    // Parse the experience section
    experience_start = strstr(resume_text, "Experience:");
    if (experience_start) {
        experience_start += 9;

        // Iterate over the experience sections
        while (current_position = strstr(experience_start, "Position:")) {
            current_position += 8;
            current_company = strstr(current_position, "Company:");
            current_company += 9;
            current_responsibilities = strstr(current_position, "Responsibilities:");
            current_responsibilities += 13;

            // Allocate memory for a new node
            resume_node* new_node = malloc(sizeof(resume_node));

            // Copy data from the current node to the new node
            strcpy(new_node->name, head->name);
            strcpy(new_node->experience, current_position);

            // Add the new node to the end of the list
            new_node->next = NULL;
            if (head->next) {
                head->next->next = new_node;
            } else {
                head->next = new_node;
            }

            experience_start = strstr(current_position, "Experience:");
        }
    }

    return head;
}

int main() {
    char* resume_text = "Name: John Doe\n"
                           "Experience:\n"
                           "Position: Software Engineer\n"
                           "Company: Google\n"
                           "Responsibilities:\n"
                           "Write software\n"
                           "Maintain software\n"
                           "\n"
                           "Position: Junior Engineer\n"
                           "Company: Microsoft\n"
                           "Responsibilities:\n"
                           "Write software\n"
                           "Test software\n";

    resume_node* head = parse_resume(resume_text);

    // Print the name and experience of each node
    for (resume_node* current = head; current; current = current->next) {
        printf("Name: %s\n", current->name);
        printf("Experience:\n");
        printf("%s\n", current->experience);
        printf("\n");
    }

    return 0;
}