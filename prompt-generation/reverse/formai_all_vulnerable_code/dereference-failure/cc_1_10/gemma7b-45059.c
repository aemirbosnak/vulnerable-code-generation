//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Candidate {
    char name[256];
    int age;
    float salary;
    struct Candidate* next;
} Candidate;

Candidate* parse_resume(char* resume_text) {
    Candidate* candidates = NULL;
    char* name_start = NULL;
    char* name_end = NULL;
    char* age_start = NULL;
    char* age_end = NULL;
    char* salary_start = NULL;
    char* salary_end = NULL;

    // Find the candidate's name, age, and salary
    name_start = strstr(resume_text, "Name:");
    name_end = strstr(name_start, "\n");
    age_start = strstr(resume_text, "Age:");
    age_end = strstr(age_start, "\n");
    salary_start = strstr(resume_text, "Salary:");
    salary_end = strstr(salary_start, "\n");

    // Create a new candidate
    Candidate* new_candidate = malloc(sizeof(Candidate));
    new_candidate->next = NULL;

    // Fill in the candidate's information
    strcpy(new_candidate->name, name_start + 5);
    new_candidate->age = atoi(age_start + 5);
    new_candidate->salary = atof(salary_start + 8);

    // Add the candidate to the list
    if (candidates == NULL) {
        candidates = new_candidate;
    } else {
        candidates->next = new_candidate;
        candidates = candidates->next;
    }

    return candidates;
}

int main() {
    char* resume_text = "Name: John Doe\nAge: 25\nSalary: $50,000\n\nName: Jane Doe\nAge: 30\nSalary: $60,000\n";

    Candidate* candidates = parse_resume(resume_text);

    // Print the candidates
    for (Candidate* candidate = candidates; candidate; candidate = candidate->next) {
        printf("Name: %s\n", candidate->name);
        printf("Age: %d\n", candidate->age);
        printf("Salary: $%f\n", candidate->salary);
        printf("\n");
    }

    return 0;
}