//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: realistic
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
    Candidate* tail = NULL;

    // Extract candidate name, age, and salary from the resume text
    char* name = strstr(resume_text, "Name:");
    char* age_str = strstr(resume_text, "Age:");
    char* salary_str = strstr(resume_text, "Salary:");

    // Validate the extracted data
    if (name == NULL || age_str == NULL || salary_str == NULL)
    {
        return NULL;
    }

    // Create a new candidate
    Candidate* new_candidate = (Candidate*)malloc(sizeof(Candidate));
    new_candidate->next = NULL;

    // Populate the candidate's data
    strcpy(new_candidate->name, name);
    new_candidate->age = atoi(age_str);
    new_candidate->salary = atof(salary_str);

    // If the head of the list is NULL, make it the head
    if (head == NULL)
    {
        head = new_candidate;
        tail = new_candidate;
    }
    // Otherwise, add the candidate to the tail
    else
    {
        tail->next = new_candidate;
        tail = new_candidate;
    }

    return head;
}

int main()
{
    char* resume_text = "Name: John Doe\nAge: 25\nSalary: 50000";

    Candidate* head = parse_resume(resume_text);

    // Print the candidate's data
    printf("Name: %s\n", head->name);
    printf("Age: %d\n", head->age);
    printf("Salary: %f\n", head->salary);

    return 0;
}