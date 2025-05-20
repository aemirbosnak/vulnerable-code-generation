//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: detailed
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
    char* name_start = NULL;
    char* name_end = NULL;
    char* age_start = NULL;
    char* age_end = NULL;
    char* salary_start = NULL;
    char* salary_end = NULL;

    // Allocate memory for the first candidate
    head = (Candidate*)malloc(sizeof(Candidate));
    tail = head;

    // Search for the candidate's name, age, and salary
    name_start = strstr(resume_text, "Name:");
    name_end = strstr(name_start, "\n");
    age_start = strstr(resume_text, "Age:");
    age_end = strstr(age_start, "\n");
    salary_start = strstr(resume_text, "Salary:");
    salary_end = strstr(salary_start, "\n");

    // Fill in the candidate's information
    strcpy(tail->name, name_start + 5);
    tail->age = atoi(age_start + 5);
    tail->salary = atof(salary_start + 5);

    // Link the first candidate to the list
    if (head == tail)
    {
        head->next = NULL;
    }

    // Search for the remaining candidates
    while ((name_start = strstr(name_end, "Name:")) != NULL)
    {
        // Allocate memory for the next candidate
        tail = (Candidate*)malloc(sizeof(Candidate));
        tail->next = NULL;

        // Fill in the candidate's information
        strcpy(tail->name, name_start + 5);
        tail->age = atoi(age_start + 5);
        tail->salary = atof(salary_start + 5);

        // Link the next candidate to the list
        tail->next = head;
        head = tail;
        name_end = strstr(name_start, "\n");
    }

    return head;
}

int main()
{
    char resume_text[] = "Name: John Doe\nAge: 25\nSalary: 50000\n\nName: Jane Doe\nAge: 30\nSalary: 60000\n";

    Candidate* head = parse_resume(resume_text);

    // Print the candidate's information
    while (head)
    {
        printf("Name: %s\n", head->name);
        printf("Age: %d\n", head->age);
        printf("Salary: %f\n", head->salary);
        printf("\n");
        head = head->next;
    }

    return 0;
}