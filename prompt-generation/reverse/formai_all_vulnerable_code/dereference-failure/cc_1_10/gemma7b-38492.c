//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
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
    CvEntry* head = NULL;
    CvEntry* tail = NULL;

    // Extract candidate name and experience
    char* name = strstr(resume_text, "Name:");
    char* experience = strstr(resume_text, "Experience:");

    // Allocate memory for new CvEntry
    CvEntry* new_entry = malloc(sizeof(CvEntry));

    // Fill CvEntry data
    strcpy(new_entry->name, name);
    strcpy(new_entry->experience, experience);

    // Link new CvEntry to head if it is the first entry
    if (head == NULL) {
        head = new_entry;
        tail = new_entry;
    } else {
        tail->next = new_entry;
        tail = new_entry;
    }

    return head;
}

int main() {
    char* resume_text = "Name: John Doe\nExperience: Software Engineer at Google\n\nName: Jane Doe\nExperience: Marketing Manager at Apple";

    CvEntry* head = parse_resume(resume_text);

    // Print candidate name and experience
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Experience: %s\n", head->experience);
        printf("\n");
        head = head->next;
    }

    return 0;
}