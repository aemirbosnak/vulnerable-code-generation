//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resume
{
    char *name;
    char *address;
    char *phone;
    char *email;
    char *summary;
    struct Resume *next;
} Resume;

Resume *parse_resume(char *file_path)
{
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL)
    {
        return NULL;
    }

    char line[256];
    Resume *head = NULL;
    Resume *curr = NULL;

    while (fgets(line, 256, fp) != NULL)
    {
        // Extract resume information
        char *name = strchr(line, "Name:") + 5;
        char *address = strchr(line, "Address:") + 8;
        char *phone = strchr(line, "Phone:") + 6;
        char *email = strchr(line, "Email:") + 6;
        char *summary = strchr(line, "Summary:") + 8;

        // Allocate memory for the resume
        curr = malloc(sizeof(Resume));
        if (curr == NULL)
        {
            fclose(fp);
            return NULL;
        }

        // Initialize the resume data
        curr->name = strdup(name);
        curr->address = strdup(address);
        curr->phone = strdup(phone);
        curr->email = strdup(email);
        curr->summary = strdup(summary);

        // Add the resume to the list
        if (head == NULL)
        {
            head = curr;
        }
        else
        {
            curr->next = head;
            head = curr;
        }
    }

    fclose(fp);
    return head;
}

int main()
{
    char *file_path = "resume.txt";
    Resume *head = parse_resume(file_path);

    if (head != NULL)
    {
        printf("Name: %s\n", head->name);
        printf("Address: %s\n", head->address);
        printf("Phone: %s\n", head->phone);
        printf("Email: %s\n", head->email);
        printf("Summary: %s\n", head->summary);
    }

    return 0;
}