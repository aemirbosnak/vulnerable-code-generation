//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct resume_entry {
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    struct resume_entry* next;
} resume_entry;

resume_entry* parse_resume(char* resume_text) {
    resume_entry* head = NULL;
    char* name_start = NULL;
    char* experience_start = NULL;
    char* current_line = NULL;

    // Allocate memory for the first entry
    head = malloc(sizeof(resume_entry));

    // Parse the resume line by line
    current_line = strtok(resume_text, "\n");
    while (current_line) {
        // Find the name and experience sections
        if (name_start = strstr(current_line, "Name:")) {
            name_start += 6;
            strcpy(head->name, name_start);
        }

        if (experience_start = strstr(current_line, "Experience:")) {
            experience_start += 10;
            strcpy(head->experience, experience_start);
        }

        // Create a new entry if necessary
        if (head->next == NULL) {
            head->next = malloc(sizeof(resume_entry));
            head = head->next;
        }

        // Move to the next line
        current_line = strtok(NULL, "\n");
    }

    return head;
}

int main() {
    char* resume_text = "Name: John Doe\nExperience: Software Engineer at Google\n\nName: Jane Doe\nExperience: Marketing Manager at Facebook";

    resume_entry* head = parse_resume(resume_text);

    // Print the parsed entries
    for (resume_entry* current = head; current; current = current->next) {
        printf("Name: %s\n", current->name);
        printf("Experience: %s\n", current->experience);
        printf("\n");
    }

    return 0;
}