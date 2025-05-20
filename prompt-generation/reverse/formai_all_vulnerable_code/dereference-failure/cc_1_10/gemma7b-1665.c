//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Candidate
{
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
    struct Candidate* next;
} Candidate;

int main()
{
    Candidate* head = NULL;
    char resume[1024];
    FILE* resumeFile = fopen("resume.txt", "r");
    if (resumeFile == NULL)
    {
        return 1;
    }

    // Read the resume file
    fread(resume, 1024, 1, resumeFile);

    // Parse the resume
    Candidate* current = NULL;
    char* line = strtok(resume, "\n");
    while (line)
    {
        // Extract the candidate's name, age, and salary
        char* name = strtok(line, ":");
        int age = atoi(strtok(name, " "));
        float salary = atof(strtok(strtok(line, ":"), " "));

        // Create a new candidate
        Candidate* newCandidate = malloc(sizeof(Candidate));
        strcpy(newCandidate->name, name);
        newCandidate->age = age;
        newCandidate->salary = salary;
        newCandidate->next = NULL;

        // Add the new candidate to the linked list
        if (current)
        {
            current->next = newCandidate;
        }
        else
        {
            head = newCandidate;
        }

        // Get the next line of the resume
        line = strtok(NULL, "\n");
    }

    // Print the candidates
    Candidate* walker = head;
    while (walker)
    {
        printf("%s, %d, %f\n", walker->name, walker->age, walker->salary);
        walker = walker->next;
    }

    // Close the resume file
    fclose(resumeFile);

    return 0;
}