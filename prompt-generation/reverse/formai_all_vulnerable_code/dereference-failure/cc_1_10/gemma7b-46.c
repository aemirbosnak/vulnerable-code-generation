//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Cv
{
    char name[MAX_NAME_LENGTH];
    int age;
    struct Cv* next;
} Cv;

Cv* parse_resume(char* resume_text)
{
    Cv* head = NULL;
    char* name = NULL;
    int age = 0;

    // Allocate memory for the first CV node
    Cv* new_cv = malloc(sizeof(Cv));

    // Parse the resume text for the name and age
    name = strstr(resume_text, "Name:");
    age = atoi(strstr(name, "Age:"));

    // Copy the name and age into the CV node
    strcpy(new_cv->name, name + 5);
    new_cv->age = age;

    // Set the new CV node as the head of the list
    head = new_cv;

    // Allocate memory for the remaining CV nodes
    new_cv = malloc(sizeof(Cv));

    // Parse the remaining resume text for the name and age
    name = strstr(resume_text, "Name:");
    age = atoi(strstr(name, "Age:"));

    // Copy the name and age into the CV node
    strcpy(new_cv->name, name + 5);
    new_cv->age = age;

    // Insert the new CV node into the list
    new_cv->next = head;
    head = new_cv;

    // Return the head of the CV list
    return head;
}

int main()
{
    char* resume_text = "Name: John Doe\nAge: 30\n\nName: Jane Doe\nAge: 25";

    Cv* head = parse_resume(resume_text);

    // Print the CV list
    for (Cv* current = head; current; current = current->next)
    {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("\n");
    }

    return 0;
}