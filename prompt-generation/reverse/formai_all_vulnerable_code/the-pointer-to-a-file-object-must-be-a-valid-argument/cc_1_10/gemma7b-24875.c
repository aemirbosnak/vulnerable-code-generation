//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct ResumeEntry {
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    struct ResumeEntry* next;
} ResumeEntry;

ResumeEntry* parseResume(FILE* resumeFile) {
    ResumeEntry* head = NULL;
    char line[MAX_NAME_LENGTH];
    char* nameStart;
    char* experienceStart;

    // Read the resume file line by line
    while (fgets(line, MAX_NAME_LENGTH, resumeFile) != NULL) {
        // Find the start of the name and experience sections
        nameStart = strstr(line, "Name:");
        experienceStart = strstr(line, "Experience:");

        // If the name and experience sections are found, create a new resume entry
        if (nameStart && experienceStart) {
            ResumeEntry* newEntry = malloc(sizeof(ResumeEntry));

            // Copy the name and experience sections from the line into the new entry
            strncpy(newEntry->name, nameStart + 5, MAX_NAME_LENGTH - 1);
            strncpy(newEntry->experience, experienceStart + 10, MAX_EXPERIENCE_LENGTH - 1);

            // Add the new entry to the head of the linked list
            if (head == NULL) {
                head = newEntry;
            } else {
                newEntry->next = head;
                head = newEntry;
            }
        }
    }

    return head;
}

int main() {
    FILE* resumeFile = fopen("resume.txt", "r");
    ResumeEntry* head = parseResume(resumeFile);

    // Print the name and experience of each resume entry
    for (ResumeEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
        printf("Name: %s\n", currentEntry->name);
        printf("Experience: %s\n", currentEntry->experience);
        printf("\n");
    }

    fclose(resumeFile);

    return 0;
}