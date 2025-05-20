//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Resume {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
    char* occupation;
} Resume;

void parse_resume(char* resume_text) {
    Resume resume;

    // Extract name
    char* name_start = strstr(resume_text, "Name:");
    if (name_start) {
        name_start += 5;
        strcpy(resume.name, name_start);
    }

    // Extract age
    char* age_start = strstr(resume_text, "Age:");
    if (age_start) {
        age_start += 5;
        resume.age = atoi(age_start);
    }

    // Extract salary
    char* salary_start = strstr(resume_text, "Salary:");
    if (salary_start) {
        salary_start += 8;
        resume.salary = atof(salary_start);
    }

    // Extract occupation
    char* occupation_start = strstr(resume_text, "Occupation:");
    if (occupation_start) {
        occupation_start += 10;
        resume.occupation = strdup(occupation_start);
    }

    // Print resume information
    printf("Name: %s\n", resume.name);
    printf("Age: %d\n", resume.age);
    printf("Salary: %.2f\n", resume.salary);
    printf("Occupation: %s\n", resume.occupation);
}

int main() {
    char* resume_text = "Name: John Doe\nAge: 30\nSalary: 50000.00\nOccupation: Software Engineer";

    parse_resume(resume_text);

    return 0;
}