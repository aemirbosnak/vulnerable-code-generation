//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    struct Resume* next;
} Resume;

Resume* parse_resume(FILE* file)
{
    Resume* head = NULL;
    char line[MAX_NAME_LENGTH + MAX_EXPERIENCE_LENGTH];

    FILE* fp = fopen(file, "r");
    if (fp == NULL)
    {
        return NULL;
    }

    while (fgets(line, MAX_NAME_LENGTH + MAX_EXPERIENCE_LENGTH, fp) != NULL)
    {
        char* name = strchr(line, ':');
        char* experience = strstr(line, 'Experience:');

        if (name && experience)
        {
            Resume* new_resume = malloc(sizeof(Resume));
            new_resume->next = head;
            head = new_resume;

            strncpy(new_resume->name, name + 1, MAX_NAME_LENGTH - 1);
            strncpy(new_resume->experience, experience + 10, MAX_EXPERIENCE_LENGTH - 1);
        }
    }

    fclose(fp);
    return head;
}

int main()
{
    FILE* file = fopen("resume.txt", "r");
    Resume* resume_head = parse_resume(file);

    for (Resume* current = resume_head; current; current = current->next)
    {
        printf("Name: %s\n", current->name);
        printf("Experience: %s\n", current->experience);
    }

    fclose(file);
    return 0;
}