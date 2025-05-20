//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Candidate {
    char name[MAX_NAME_LENGTH];
    int age;
    double salary;
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

    // Extract candidate name
    name_start = strstr(resume_text, "Name:");
    if (name_start) {
        name_end = strstr(name_start, ":");
        if (name_end) {
            *name_end = '\0';
            head = malloc(sizeof(Candidate));
            strcpy(head->name, name_start + 1);
            head->next = NULL;
        }
    }

    // Extract candidate age
    age_start = strstr(resume_text, "Age:");
    if (age_start) {
        age_end = strstr(age_start, ",");
        if (age_end) {
            *age_end = '\0';
            head->age = atoi(age_start + 1);
        }
    }

    // Extract candidate salary
    salary_start = strstr(resume_text, "Salary:");
    if (salary_start) {
        salary_end = strstr(salary_start, "$");
        if (salary_end) {
            *salary_end = '\0';
            head->salary = atof(salary_start + 1);
        }
    }

    return head;
}

int main() {
    char resume_text[] = "Name: John Doe\nAge: 25, Salary: $50,000";

    Candidate* head = parse_resume(resume_text);

    printf("Name: %s\n", head->name);
    printf("Age: %d\n", head->age);
    printf("Salary: $%f\n", head->salary);

    return 0;
}