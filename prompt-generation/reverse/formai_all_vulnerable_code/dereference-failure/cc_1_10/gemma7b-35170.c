//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
    char summary[MAX_NAME_LENGTH];
    struct Resume* next;
} Resume;

int main()
{
    Resume* head = NULL;
    Resume* current = NULL;

    // Allocate memory for the first resume
    head = malloc(sizeof(Resume));
    current = head;

    // Get the resume data from the user
    printf("Enter your name: ");
    scanf("%s", current->name);

    printf("Enter your email address: ");
    scanf("%s", current->email);

    printf("Enter your phone number: ");
    scanf("%s", current->phone);

    printf("Enter your address: ");
    scanf("%s", current->address);

    printf("Enter your summary: ");
    scanf("%s", current->summary);

    // Link the first resume to the head of the list
    head->next = NULL;

    // Traverse the list to the end
    current = head;
    while (current->next)
    {
        current = current->next;
    }

    // Print the resume data
    printf("Name: %s\n", current->name);
    printf("Email: %s\n", current->email);
    printf("Phone: %s\n", current->phone);
    printf("Address: %s\n", current->address);
    printf("Summary: %s\n", current->summary);

    return 0;
}