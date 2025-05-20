//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resume
{
    char *name;
    char *address;
    char *phone;
    char *email;
    struct Resume *next;
} Resume;

Resume *parse_resume(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return NULL;
    }

    char line[1024];
    Resume *head = NULL;
    Resume *tail = NULL;

    while (fgets(line, 1024, fp) != NULL)
    {
        char *name = strtok(line, ":");
        char *value = strtok(NULL, ":") + 1;

        if (name == NULL)
        {
            continue;
        }

        switch (name[0])
        {
            case 'N':
                tail->name = strdup(value);
                break;
            case 'A':
                tail->address = strdup(value);
                break;
            case 'P':
                tail->phone = strdup(value);
                break;
            case 'E':
                tail->email = strdup(value);
                break;
            default:
                break;
        }

        if (tail == NULL)
        {
            head = tail = malloc(sizeof(Resume));
        }
        else
        {
            tail = tail->next = malloc(sizeof(Resume));
            tail = tail->next;
        }
    }

    fclose(fp);
    return head;
}

int main()
{
    char *filename = "resume.txt";
    Resume *head = parse_resume(filename);

    if (head != NULL)
    {
        printf("Name: %s\n", head->name);
        printf("Address: %s\n", head->address);
        printf("Phone: %s\n", head->phone);
        printf("Email: %s\n", head->email);
    }

    return 0;
}