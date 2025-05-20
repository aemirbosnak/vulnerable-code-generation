//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Candidate {
    char name[MAX_NAME_LENGTH];
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

    // Iterate over the resume text line by line
    char* line = strtok(resume_text, "\n");
    while (line) {
        // Find the start and end of the candidate's name
        name_start = strstr(line, "Name:");
        if (name_start) {
            name_end = strchr(name_start, ":");
            name_start += 5; // Skip "Name:" and spaces
            candidates = malloc(sizeof(Candidate));
            strcpy(candidates->name, name_start);
            candidates->next = NULL;
        }

        // Find the start and end of the candidate's age
        age_start = strstr(line, "Age:");
        if (age_start) {
            age_end = strchr(age_start, ":");
            age_start += 5; // Skip "Age:" and spaces
            candidates->age = atoi(age_start);
        }

        // Find the start and end of the candidate's salary
        salary_start = strstr(line, "Salary:");
        if (salary_start) {
            salary_end = strchr(salary_start, "$");
            salary_start += 8; // Skip "Salary:" and dollar sign
            candidates->salary = atof(salary_start);
        }

        line = strtok(NULL, "\n");
    }

    return candidates;
}

int main() {
    char* resume_text = "John Doe\n"
                            "Age: 25\n"
                            "Salary: $50,000\n"
                            "Jane Doe\n"
                            "Age: 30\n"
                            "Salary: $60,000\n";

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