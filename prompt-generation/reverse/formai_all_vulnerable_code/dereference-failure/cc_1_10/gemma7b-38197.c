//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Cv
{
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
    struct Cv* next;
} Cv;

void parse_resume(char* resume_text)
{
    Cv* head = NULL;
    Cv* tail = NULL;

    // Extract name, age, and salary from the resume text
    char* name = strstr(resume_text, "Name:");
    char* age_str = strstr(resume_text, "Age:");
    char* salary_str = strstr(resume_text, "Salary:");

    // If name, age, or salary is not found, return
    if (name == NULL || age_str == NULL || salary_str == NULL)
    {
        return;
    }

    // Allocate memory for the Cv structure
    Cv* new_cv = malloc(sizeof(Cv));

    // Copy the name, age, and salary from the resume text
    strcpy(new_cv->name, name + 5);
    new_cv->age = atoi(age_str + 5);
    new_cv->salary = atof(salary_str + 8);

    // If the head of the linked list is NULL, make it the head
    if (head == NULL)
    {
        head = new_cv;
        tail = new_cv;
    }
    // Otherwise, add the new Cv to the tail of the linked list
    else
    {
        tail->next = new_cv;
        tail = new_cv;
    }

    // Print the name, age, and salary of the Cv
    printf("Name: %s\n", new_cv->name);
    printf("Age: %d\n", new_cv->age);
    printf("Salary: %.2f\n", new_cv->salary);
}

int main()
{
    char resume_text[] = "Name: John Doe\nAge: 25\nSalary: $50,000";

    parse_resume(resume_text);

    return 0;
}