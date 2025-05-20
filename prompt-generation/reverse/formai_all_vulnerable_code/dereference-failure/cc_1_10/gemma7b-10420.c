//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Cv
{
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
} Cv;

void parse_resume(char *resume_text)
{
    Cv *cv = malloc(sizeof(Cv));

    // Extract name
    char *name_start = strstr(resume_text, "Name:");
    if (name_start)
    {
        name_start += 5; // Skip "Name:" and spaces
        strncpy(cv->name, name_start, MAX_NAME_LENGTH - 1);
    }

    // Extract age
    char *age_start = strstr(resume_text, "Age:");
    if (age_start)
    {
        age_start += 5; // Skip "Age:" and spaces
        cv->age = atoi(age_start);
    }

    // Extract salary
    char *salary_start = strstr(resume_text, "Salary:");
    if (salary_start)
    {
        salary_start += 8; // Skip "Salary:" and spaces
        cv->salary = atof(salary_start);
    }

    // Print parsed data
    printf("Name: %s\n", cv->name);
    printf("Age: %d\n", cv->age);
    printf("Salary: %.2f\n", cv->salary);

    free(cv);
}

int main()
{
    char resume_text[] = "Name: John Doe\nAge: 25\nSalary: 50000.00";

    parse_resume(resume_text);

    return 0;
}