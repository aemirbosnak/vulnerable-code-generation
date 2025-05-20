//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: detailed
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
    char* current_position = NULL;
    char* current_company = NULL;

    // Allocate memory for the first entry
    head = malloc(sizeof(resume_entry));
    head->next = NULL;

    // Extract the name and experience sections
    name_start = strstr(resume_text, "Name:");
    experience_start = strstr(name_start, "Experience:");

    // Parse the name and experience sections
    while (name_start && experience_start) {
        // Extract the name and experience
        strncpy(head->name, name_start + 5, MAX_NAME_LENGTH - 1);
        strncpy(head->experience, experience_start + 9, MAX_EXPERIENCE_LENGTH - 1);

        // Allocate memory for the next entry
        resume_entry* new_entry = malloc(sizeof(resume_entry));
        new_entry->next = NULL;

        // Link the new entry to the head
        head->next = new_entry;
        head = new_entry;

        // Find the next name and experience sections
        name_start = strstr(experience_start, "Name:");
        experience_start = strstr(name_start, "Experience:");
    }

    return head;
}

int main() {
    char* resume_text = "Name: John Doe\nExperience:\n"
                              "Current Position: Software Engineer\n"
                              "Current Company: ACME Inc.\n"
                              "Previous Position: Junior Engineer\n"
                              "Previous Company: XYZ Corp.\n";

    resume_entry* head = parse_resume(resume_text);

    // Print the resume entries
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Experience:\n");
        printf("  Current Position: %s\n", head->experience);
        printf("  Current Company: %s\n", head->experience);
        printf("\n");
        head = head->next;
    }

    return 0;
}