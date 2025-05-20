//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Resume
{
    char name[MAX];
    char email[MAX];
    char phone[MAX];
    char address[MAX];
    char summary[MAX];
    struct Resume* next;
} Resume;

void parseResume(Resume* resume)
{
    char* line;
    FILE* file = fopen("resume.txt", "r");

    // Read each line of the resume file
    while ((line = fgets(resume->summary, MAX, file)) != NULL)
    {
        // Remove newline character from the line
        line[strcspn(line, "\n")] = '\0';

        // Store the line in the resume summary
        strcat(resume->summary, line);
    }

    fclose(file);
}

int main()
{
    Resume* resume = NULL;
    resume = malloc(sizeof(Resume));

    parseResume(resume);

    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Summary: %s\n", resume->summary);

    free(resume);

    return 0;
}