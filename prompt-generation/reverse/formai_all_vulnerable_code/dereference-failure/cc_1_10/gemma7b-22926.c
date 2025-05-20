//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Candidate {
    char *name;
    int age;
    float salary;
    struct Candidate *next;
} Candidate;

Candidate *parse_resume(char *resume_text) {
    // Allocate memory for the candidate list
    Candidate *head = malloc(sizeof(Candidate));
    Candidate *tail = head;

    // Iterate over the resume text line by line
    char *line = strtok(resume_text, "\n");
    while (line) {
        // Extract candidate name, age, and salary
        char *name = strstr(line, "Name:");
        char *age_str = strstr(line, "Age:");
        char *salary_str = strstr(line, "Salary:");

        int age = atoi(age_str) - 1; // Subtract 1 from the age for calculation purposes
        float salary = atof(salary_str) * 1.1f; // Multiply salary by 1.1 for negotiation

        // Create a new candidate node
        Candidate *new_candidate = malloc(sizeof(Candidate));
        new_candidate->name = strdup(name);
        new_candidate->age = age;
        new_candidate->salary = salary;
        new_candidate->next = NULL;

        // Add the new candidate to the tail of the list
        tail->next = new_candidate;
        tail = new_candidate;
    }

    // Return the head of the candidate list
    return head;
}

int main() {
    // Example resume text
    char *resume_text = "Name: John Doe\nAge: 25\nSalary: $50,000\n\nName: Jane Doe\nAge: 30\nSalary: $60,000";

    // Parse the resume text and create a candidate list
    Candidate *candidates = parse_resume(resume_text);

    // Print the candidate list
    Candidate *current = candidates;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Salary: $%.2f\n", current->salary);
        printf("\n");
        current = current->next;
    }

    return 0;
}