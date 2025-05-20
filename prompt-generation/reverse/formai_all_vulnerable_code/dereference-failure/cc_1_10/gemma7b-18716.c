//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Resume
{
    char *name;
    char *email;
    char *phone;
    char *address;
    char *summary;
    struct Resume *next;
} Resume;

Resume *parse_resume(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return NULL;
    }

    Resume *head = NULL;
    Resume *tail = NULL;

    char line[1024];
    while (fgets(line, 1024, fp) != NULL)
    {
        // Remove leading and trailing whitespace
        line[strcspn(line, " \t\n")] = '\0';

        // Extract key-value pairs
        char *key = strstr(line, ":");
        char *value = key ? strchr(key, ":") + 1 : "";

        // Create a new resume entry
        Resume *new_resume = malloc(sizeof(Resume));
        new_resume->name = strdup(value);

        // Add the new resume entry to the list
        if (head == NULL)
        {
            head = new_resume;
            tail = new_resume;
        }
        else
        {
            tail->next = new_resume;
            tail = new_resume;
        }
    }

    fclose(fp);
    return head;
}

int main()
{
    char *filename = "resume.txt";
    Resume *head = parse_resume(filename);

    if (head)
    {
        printf("Name: %s\n", head->name);
        printf("Email: %s\n", head->email);
        printf("Phone: %s\n", head->phone);
        printf("Address: %s\n", head->address);
        printf("Summary: %s\n", head->summary);
    }

    return 0;
}