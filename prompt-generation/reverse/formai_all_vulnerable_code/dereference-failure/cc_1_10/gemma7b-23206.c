//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: detailed
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

void parse_resume(char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        return;
    }

    Resume* head = NULL;
    Resume* current = NULL;

    char line[MAX_NAME_LENGTH];
    while (fgets(line, MAX_NAME_LENGTH, file) != NULL)
    {
        // Extract name, email, phone, and address
        char* name = strchr(line, "Name:");
        char* email = strchr(line, "Email:");
        char* phone = strchr(line, "Phone:");
        char* address = strchr(line, "Address:");

        // Create a new resume node
        Resume* new_resume = malloc(sizeof(Resume));
        new_resume->next = NULL;

        // Populate the node with data
        if (name)
        {
            strcpy(new_resume->name, name + 5);
        }
        if (email)
        {
            strcpy(new_resume->email, email + 6);
        }
        if (phone)
        {
            strcpy(new_resume->phone, phone + 7);
        }
        if (address)
        {
            strcpy(new_resume->address, address + 8);
        }

        // If there is no head node, make it the first node
        if (head == NULL)
        {
            head = new_resume;
        }
        // Otherwise, add it to the end of the linked list
        else
        {
            current->next = new_resume;
            current = new_resume;
        }
    }

    fclose(file);
    return;
}

int main()
{
    parse_resume("resume.txt");

    return 0;
}