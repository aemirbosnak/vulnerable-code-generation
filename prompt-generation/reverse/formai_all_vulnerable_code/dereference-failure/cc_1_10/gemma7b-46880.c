//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct ResumeEntry
{
    char name[MAX_NAME_LENGTH];
    int age;
    char occupation[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
    struct ResumeEntry* next;
} ResumeEntry;

void parseResume(char* resumeText)
{
    ResumeEntry* head = NULL;
    char* line = strtok(resumeText, "\n");

    // Loop over each line in the resume text
    while (line)
    {
        // Extract the name, age, occupation, and address
        char* name = strstr(line, "Name:");
        char* ageStr = strstr(line, "Age:");
        char* occupation = strstr(line, "Occupation:");
        char* address = strstr(line, "Address:");

        // If the line contains the necessary information, create a new resume entry
        if (name && ageStr && occupation && address)
        {
            ResumeEntry* newEntry = malloc(sizeof(ResumeEntry));
            strcpy(newEntry->name, name);
            newEntry->age = atoi(ageStr);
            strcpy(newEntry->occupation, occupation);
            strcpy(newEntry->address, address);
            newEntry->next = head;
            head = newEntry;
        }

        line = strtok(NULL, "\n");
    }

    // Print the resume entries
    ResumeEntry* current = head;
    while (current)
    {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Occupation: %s\n", current->occupation);
        printf("Address: %s\n", current->address);
        printf("\n");
        current = current->next;
    }
}

int main()
{
    char* resumeText = "Name: John Doe\nAge: 25\nOccupation: Software Engineer\nAddress: 123 Main St.\n\nName: Jane Doe\nAge: 30\nOccupation: Nurse\nAddress: 456 Oak Ave.\n";

    parseResume(resumeText);

    return 0;
}