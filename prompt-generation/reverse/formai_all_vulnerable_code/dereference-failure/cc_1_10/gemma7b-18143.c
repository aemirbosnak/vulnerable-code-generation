//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: real-life
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

    // Find the candidate's name, age, and salary
    name_start = strstr(resume_text, "Name:");
    if (name_start) {
        name_end = strstr(name_start, ",");
        strcpy(head->name, name_start + 5);
    }

    age_start = strstr(resume_text, "Age:");
    if (age_start) {
        age_end = strstr(age_start, ":");
        head->age = atoi(age_start + 5);
    }

    salary_start = strstr(resume_text, "Salary:");
    if (salary_start) {
        salary_end = strstr(salary_start, "$");
        head->salary = atof(salary_start + 8);
    }

    // Create a new candidate node and add it to the list
    head = malloc(sizeof(Candidate));
    head->next = NULL;

    return head;
}

int main() {
    char* resume_text = "Name: John Doe, Age: 25, Salary: $50,000";

    Candidate* head = parse_resume(resume_text);

    printf("Name: %s", head->name);
    printf(", Age: %d", head->age);
    printf(", Salary: $%f", head->salary);

    return 0;
}