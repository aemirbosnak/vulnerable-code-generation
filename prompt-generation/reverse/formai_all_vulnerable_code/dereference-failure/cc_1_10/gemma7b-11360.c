//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct Candidate
{
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    struct Candidate* next;
} Candidate;

Candidate* parse_resume(char* resume_text)
{
    Candidate* head = NULL;
    Candidate* tail = NULL;

    // Extract candidate's name and experience from resume text
    char* name = strstr(resume_text, "Name:");
    char* experience = strstr(resume_text, "Experience:");

    // Create a new candidate
    Candidate* new_candidate = malloc(sizeof(Candidate));
    new_candidate->next = NULL;

    // Set candidate's name and experience
    strncpy(new_candidate->name, name, MAX_NAME_LENGTH - 1);
    strncpy(new_candidate->experience, experience, MAX_EXPERIENCE_LENGTH - 1);

    // If head is NULL, make new candidate the head
    if (head == NULL)
    {
        head = new_candidate;
        tail = new_candidate;
    }
    // Otherwise, add new candidate to the tail
    else
    {
        tail->next = new_candidate;
        tail = new_candidate;
    }

    return head;
}

int main()
{
    char resume_text[] = "Name: John Doe\nExperience: Software Engineer at Google\n\nName: Jane Doe\nExperience: Marketing Manager at Apple";

    Candidate* head = parse_resume(resume_text);

    // Print candidate information
    for (Candidate* current = head; current; current = current->next)
    {
        printf("Name: %s\n", current->name);
        printf("Experience: %s\n", current->experience);
        printf("\n");
    }

    return 0;
}