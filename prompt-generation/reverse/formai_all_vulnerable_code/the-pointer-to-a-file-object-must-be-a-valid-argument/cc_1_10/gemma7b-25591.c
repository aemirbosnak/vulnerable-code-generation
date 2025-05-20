//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Resume* parseResume(FILE* file)
{
    Resume* head = NULL;
    Resume* current = NULL;

    char line[MAX_NAME_LENGTH];

    // Read the file line by line
    while (fgets(line, MAX_NAME_LENGTH, file) != NULL)
    {
        // Extract the name, email, and phone number
        char* name = strstr(line, "Name:");
        char* email = strstr(line, "Email:");
        char* phone = strstr(line, "Phone:");

        // If there is no name, email, or phone number, continue to the next line
        if (name == NULL || email == NULL || phone == NULL)
        {
            continue;
        }

        // Create a new resume node
        current = malloc(sizeof(Resume));
        current->next = NULL;

        // Copy the name, email, and phone number into the node
        strcpy(current->name, name + 5);
        strcpy(current->email, email + 6);
        strcpy(current->phone, phone + 8);

        // If the head of the list is NULL, make it the head
        if (head == NULL)
        {
            head = current;
        }
        // Otherwise, add the node to the end of the list
        else
        {
            current->next = head;
            head = current;
        }
    }

    return head;
}

int main()
{
    FILE* file = fopen("resume.txt", "r");
    Resume* head = parseResume(file);
    fclose(file);

    // Print the name, email, and phone number of each resume
    for (Resume* current = head; current; current = current->next)
    {
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        printf("Phone: %s\n", current->phone);
        printf("\n");
    }

    return 0;
}