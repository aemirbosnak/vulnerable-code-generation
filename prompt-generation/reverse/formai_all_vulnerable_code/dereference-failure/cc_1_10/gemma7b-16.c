//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resume
{
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char summary[200];
    struct Resume* next;
} Resume;

void parseResume(char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        return;
    }

    Resume* head = NULL;
    Resume* current = NULL;

    char line[100];
    while (fgets(line, 100, file) != NULL)
    {
        // Extract name, email, phone, address, and summary
        char* name = strstr(line, "Name:");
        char* email = strstr(line, "Email:");
        char* phone = strstr(line, "Phone:");
        char* address = strstr(line, "Address:");
        char* summary = strstr(line, "Summary:");

        // Create a new resume node
        Resume* newResume = malloc(sizeof(Resume));
        newResume->next = NULL;

        // Fill in the node's data
        strcpy(newResume->name, name);
        strcpy(newResume->email, email);
        strcpy(newResume->phone, phone);
        strcpy(newResume->address, address);
        strcpy(newResume->summary, summary);

        // If the head is NULL, make it the head of the list
        if (head == NULL)
        {
            head = newResume;
        }

        // Otherwise, add the node to the end of the list
        if (current)
        {
            current->next = newResume;
        }

        current = newResume;
    }

    fclose(file);
}

int main()
{
    parseResume("resume.txt");

    return 0;
}