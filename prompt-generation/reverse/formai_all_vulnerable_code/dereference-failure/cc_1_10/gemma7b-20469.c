//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 512

typedef struct CvEntry {
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    struct CvEntry* next;
} CvEntry;

void parse_cv(char* cv_text) {
    CvEntry* head = NULL;
    CvEntry* current = NULL;
    char* name = NULL;
    char* experience = NULL;

    // Extract name and experience from the CV text
    name = strstr(cv_text, "Name:");
    experience = strstr(cv_text, "Experience:");

    // Allocate memory for the first CvEntry
    head = (CvEntry*)malloc(sizeof(CvEntry));
    head->next = NULL;

    // Set name and experience in the first CvEntry
    strcpy(head->name, name);
    strcpy(head->experience, experience);

    // Link the first CvEntry to the current CvEntry
    current = head;

    // Iterate over the remaining CV text to find additional CvEntries
    while (name = strstr(experience, "Name:")) {
        // Allocate memory for a new CvEntry
        current->next = (CvEntry*)malloc(sizeof(CvEntry));
        current->next->next = NULL;

        // Set name and experience in the new CvEntry
        strcpy(current->next->name, name);
        experience = strstr(experience, "Experience:");
        strcpy(current->next->experience, experience);

        // Link the new CvEntry to the current CvEntry
        current = current->next;
    }

    // Print the Cv entries
    current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Experience: %s\n", current->experience);
        printf("\n");
        current = current->next;
    }
}

int main() {
    char* cv_text = "Name: John Doe\nExperience: Software Engineer at Google\n\nName: Jane Doe\nExperience: Marketing Manager at Microsoft\n";

    parse_cv(cv_text);

    return 0;
}