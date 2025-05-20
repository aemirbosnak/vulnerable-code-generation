//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 255

typedef struct Candidate {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
    struct Candidate* next;
} Candidate;

Candidate* parse_resume(char* resume_text) {
    Candidate* head = NULL;
    char* name_start = NULL;
    char* name_end = NULL;
    char* age_start = NULL;
    char* age_end = NULL;
    char* salary_start = NULL;
    char* salary_end = NULL;

    // Parse the resume text to find the candidate's name, age, and salary.
    name_start = strstr(resume_text, "Name:");
    if (name_start) {
        name_end = strstr(name_start, ",");
        if (name_end) {
            strncpy(head->name, name_start + 5, name_end - name_start - 5);
        }
    }

    age_start = strstr(resume_text, "Age:");
    if (age_start) {
        age_end = strstr(age_start, ":");
        if (age_end) {
            head->age = atoi(age_start + 5);
        }
    }

    salary_start = strstr(resume_text, "Salary:");
    if (salary_start) {
        salary_end = strstr(salary_start, "$");
        if (salary_end) {
            head->salary = atof(salary_start + 8);
        }
    }

    return head;
}

int main() {
    char* resume_text = "Name: John Doe, Age: 25, Salary: $50,000";

    Candidate* head = parse_resume(resume_text);

    printf("Name: %s\n", head->name);
    printf("Age: %d\n", head->age);
    printf("Salary: %f\n", head->salary);

    return 0;
}