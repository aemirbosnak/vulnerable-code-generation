//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
    struct Resume* next;
} Resume;

int main()
{
    Resume* head = NULL;
    Resume* tail = NULL;

    // Parse resume data from file
    FILE* file = fopen("resume.txt", "r");
    if (file)
    {
        char line[MAX_NAME_LENGTH];
        while (fgets(line, MAX_NAME_LENGTH, file) != NULL)
        {
            // Extract name, email, phone, and address
            char* name = strtok(line, ":");
            char* email = strtok(NULL, ":");
            char* phone = strtok(NULL, ":");
            char* address = strtok(NULL, "\n");

            // Create a new resume node
            Resume* new_node = (Resume*)malloc(sizeof(Resume));
            new_node->next = NULL;
            strcpy(new_node->name, name);
            strcpy(new_node->email, email);
            strcpy(new_node->phone, phone);
            strcpy(new_node->address, address);

            // If the head is NULL, make it the head of the list
            if (head == NULL)
            {
                head = new_node;
                tail = new_node;
            }
            // Otherwise, add it to the tail of the list
            else
            {
                tail->next = new_node;
                tail = new_node;
            }
        }
        fclose(file);
    }

    // Print the resumes
    for (Resume* current = head; current; current = current->next)
    {
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        printf("Phone: %s\n", current->phone);
        printf("Address: %s\n", current->address);
        printf("\n");
    }

    return 0;
}