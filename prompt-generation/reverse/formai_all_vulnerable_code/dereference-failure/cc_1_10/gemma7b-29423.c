//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store resume data
typedef struct Resume
{
    char *name;
    char *email;
    char *phone;
    char *address;
    char *summary;
    struct Resume *next;
} Resume;

// Function to insert a resume into the linked list
void insertResume(Resume **head, char *name, char *email, char *phone, char *address, char *summary)
{
    Resume *newResume = (Resume *)malloc(sizeof(Resume));
    newResume->name = strdup(name);
    newResume->email = strdup(email);
    newResume->phone = strdup(phone);
    newResume->address = strdup(address);
    newResume->summary = strdup(summary);
    newResume->next = NULL;

    if (*head == NULL)
    {
        *head = newResume;
    }
    else
    {
        (*head)->next = newResume;
    }
}

// Function to print resumes
void printResumes(Resume *head)
{
    while (head)
    {
        printf("Name: %s\n", head->name);
        printf("Email: %s\n", head->email);
        printf("Phone: %s\n", head->phone);
        printf("Address: %s\n", head->address);
        printf("Summary: %s\n", head->summary);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    Resume *head = NULL;

    // Insert resumes
    insertResume(&head, "John Doe", "john.doe@gmail.com", "123-456-7890", "123 Main St.", "I am a highly motivated and experienced professional with a strong background in software engineering.");
    insertResume(&head, "Jane Doe", "jane.doe@gmail.com", "456-789-0123", "456 Oak Ave.", "I am a highly skilled software engineer with a proven track record of success in delivering complex software systems.");

    // Print resumes
    printResumes(head);

    return 0;
}