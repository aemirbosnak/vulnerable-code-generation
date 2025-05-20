//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 1000

typedef struct CvEntry {
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    struct CvEntry* next;
} CvEntry;

CvEntry* parse_resume(char* resume_text) {
    // Allocate memory for the first CvEntry
    CvEntry* head = malloc(sizeof(CvEntry));
    head->next = NULL;

    // Parse the resume text line by line
    char* line = strtok(resume_text, "\n");
    while (line) {
        // Extract the candidate's name and experience
        char* name = strstr(line, "Name:");
        char* experience = strstr(line, "Experience:");

        // If the candidate's name and experience are found, create a new CvEntry
        if (name && experience) {
            CvEntry* new_entry = malloc(sizeof(CvEntry));
            strcpy(new_entry->name, name + 5);
            strcpy(new_entry->experience, experience + 9);
            new_entry->next = head;
            head = new_entry;
        }

        // Get the next line of the resume text
        line = strtok(NULL, "\n");
    }

    // Return the head of the linked list of CvEntries
    return head;
}

int main() {
    // Example use:
    char* resume_text = "Name: John Doe\nExperience: Software Engineer at Google\n\nName: Jane Doe\nExperience: Marketing Manager at Apple";

    CvEntry* head = parse_resume(resume_text);

    // Print the list of CvEntries
    CvEntry* current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Experience: %s\n", current->experience);
        printf("\n");
        current = current->next;
    }

    return 0;
}