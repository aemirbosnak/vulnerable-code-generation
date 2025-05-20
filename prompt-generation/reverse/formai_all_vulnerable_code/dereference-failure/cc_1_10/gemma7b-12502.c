//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Candidate {
    char name[20];
    int experience;
    float salary;
    struct Candidate* next;
} Candidate;

Candidate* parse_resume(char* resume_text) {
    Candidate* head = NULL;
    Candidate* tail = NULL;
    char* name_start = NULL;
    char* name_end = NULL;
    char* experience_start = NULL;
    char* experience_end = NULL;
    char* salary_start = NULL;
    char* salary_end = NULL;

    // Allocate memory for the first candidate
    head = (Candidate*)malloc(sizeof(Candidate));
    tail = head;

    // Search for the candidate's name, experience, and salary
    name_start = strstr(resume_text, "Name:");
    name_end = strstr(name_start, "\n");
    experience_start = strstr(resume_text, "Experience:");
    experience_end = strstr(experience_start, "\n");
    salary_start = strstr(resume_text, "Salary:");
    salary_end = strstr(salary_start, "\n");

    // Fill in the candidate's information
    strcpy(head->name, name_start + 5);
    head->experience = atoi(experience_start + 9);
    head->salary = atof(salary_start + 7);

    // Link the first candidate to the tail
    tail->next = NULL;

    // Return the head of the candidate list
    return head;
}

int main() {
    char* resume_text = "Name: John Doe\n"
                           "Experience: 5 years\n"
                           "Salary: $50,000\n";

    Candidate* head = parse_resume(resume_text);

    // Print the candidate's information
    printf("Name: %s\n", head->name);
    printf("Experience: %d years\n", head->experience);
    printf("Salary: $%f\n", head->salary);

    return 0;
}