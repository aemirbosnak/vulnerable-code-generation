//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    struct Resume* next;
} Resume;

void parse_resume(Resume* resume)
{
    char* name = strtok(resume->name, " ");
    char* email = strtok(resume->email, "@");
    char* phone = strtok(resume->phone, "-");
    char* experience = strtok(resume->experience, ",");

    printf("Name: %s\n", name);
    printf("Email: %s@\n", email);
    printf("Phone: %s-\n", phone);
    printf("Experience: %s\n", experience);
}

int main()
{
    Resume* head = NULL;
    Resume* current = NULL;

    // Create a new resume
    current = (Resume*)malloc(sizeof(Resume));
    current->next = NULL;

    // Populate the resume
    strcpy(current->name, "John Doe");
    strcpy(current->email, "john.doe@example.com");
    strcpy(current->phone, "555-123-4567");
    strcpy(current->experience, "Software Engineer, 5+ years");

    // Add the resume to the list
    if (head == NULL)
    {
        head = current;
    }
    else
    {
        current->next = head;
        head = current;
    }

    // Parse the resume
    parse_resume(head);

    return 0;
}