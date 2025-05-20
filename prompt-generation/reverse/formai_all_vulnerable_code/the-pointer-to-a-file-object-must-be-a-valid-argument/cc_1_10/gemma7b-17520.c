//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct ResumeEntry
{
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    struct ResumeEntry* next;
} ResumeEntry;

ResumeEntry* parseResume(FILE* file)
{
    ResumeEntry* head = NULL;
    char line[MAX_NAME_LENGTH];

    // Read the file line by line
    while (fgets(line, MAX_NAME_LENGTH, file) != NULL)
    {
        // Extract the name and experience from the line
        char* name = strstr(line, "Name:");
        char* experience = strstr(line, "Experience:");

        // If the name and experience are not empty, create a new resume entry
        if (name && experience)
        {
            ResumeEntry* newEntry = malloc(sizeof(ResumeEntry));
            strcpy(newEntry->name, name);
            strcpy(newEntry->experience, experience);
            newEntry->next = head;
            head = newEntry;
        }
    }

    return head;
}

int main()
{
    FILE* file = fopen("resume.txt", "r");
    ResumeEntry* head = parseResume(file);

    // Print the resume entries
    for (ResumeEntry* entry = head; entry; entry = entry->next)
    {
        printf("Name: %s\n", entry->name);
        printf("Experience: %s\n", entry->experience);
        printf("\n");
    }

    fclose(file);
    return 0;
}