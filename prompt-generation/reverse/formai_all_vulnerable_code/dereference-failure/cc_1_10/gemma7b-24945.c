//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Candidate
{
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
    struct Candidate* next;
} Candidate;

Candidate* parse_resume(char* resume_text)
{
    Candidate* head = NULL;
    char* name_start = NULL;
    char* name_end = NULL;
    char* age_start = NULL;
    char* age_end = NULL;
    char* salary_start = NULL;
    char* salary_end = NULL;

    // Allocate memory for the candidate list
    head = malloc(sizeof(Candidate));

    // Parse the resume text
    name_start = strstr(resume_text, "Name:");
    name_end = strstr(name_start, "\n");

    age_start = strstr(name_end, "Age:");
    age_end = strstr(age_start, "\n");

    salary_start = strstr(age_end, "Salary:");
    salary_end = strstr(salary_start, "\n");

    // Fill in the candidate information
    strcpy(head->name, name_start + 5);
    head->age = atoi(age_start + 5);
    head->salary = atof(salary_start + 8);

    // Link the candidate to the head of the list
    head->next = NULL;

    return head;
}

int main()
{
    char* resume_text = "Name: John Doe\nAge: 25\nSalary: $50,000\n";

    Candidate* head = parse_resume(resume_text);

    // Print the candidate information
    printf("Name: %s\n", head->name);
    printf("Age: %d\n", head->age);
    printf("Salary: $%f\n", head->salary);

    return 0;
}