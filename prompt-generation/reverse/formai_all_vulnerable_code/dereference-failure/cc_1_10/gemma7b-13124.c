//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    int age;
    char occupation[MAX_NAME_LENGTH];
    struct Resume* next;
} Resume;

void parse_resume(Resume* resume, char* resume_text)
{
    char* name_start = strstr(resume_text, "Name:");
    char* name_end = strstr(name_start, ",");
    strcpy(resume->name, name_start + 5);

    char* age_start = strstr(resume_text, "Age:");
    char* age_end = strstr(age_start, ":");
    resume->age = atoi(age_start + 5);

    char* occupation_start = strstr(resume_text, "Occupation:");
    char* occupation_end = strstr(occupation_start, "}");
    strcpy(resume->occupation, occupation_start + 10);

    resume->next = NULL;
}

int main()
{
    Resume* head = NULL;

    char* resume_text = "Name: Romeo Montague\n"
                           "Age: 24\n"
                           "Occupation: Mercutio\n"

                           "Name: Juliet Capulet\n"
                           "Age: 16\n"
                           "Occupation: Tybalt\n";

    parse_resume(head, resume_text);

    Resume* current = head;
    while (current)
    {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Occupation: %s\n", current->occupation);
        printf("\n");
        current = current->next;
    }

    return 0;
}