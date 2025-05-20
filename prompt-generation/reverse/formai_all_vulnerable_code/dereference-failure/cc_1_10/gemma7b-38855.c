//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct ResumeEntry {
    char name[MAX_NAME_LENGTH];
    int experienceYears;
    double salary;
    struct ResumeEntry* next;
} ResumeEntry;

void parseResume(char* resumeText) {
    ResumeEntry* head = NULL;
    char* name = NULL;
    int experienceYears = 0;
    double salary = 0.0;

    // Analyze the resume text line by line
    char* line = strtok(resumeText, "\n");
    while (line) {
        // Extract the candidate's name
        if (strstr(line, "Name:") != NULL) {
            name = strtok(line, ":") + 1;
            strcpy(head->name, name);
        }

        // Extract the number of experience years
        if (strstr(line, "Experience Years:") != NULL) {
            experienceYears = atoi(strtok(line, ":") + 1);
            head->experienceYears = experienceYears;
        }

        // Extract the salary
        if (strstr(line, "Salary:") != NULL) {
            salary = atof(strtok(line, ":") + 1);
            head->salary = salary;
        }

        // Create a new resume entry
        head = malloc(sizeof(ResumeEntry));
        head->next = NULL;

        // Add the new entry to the list
        if (head) {
            if (head->next) {
                head->next->next = head;
            } else {
                head->next = head;
            }
        }

        line = strtok(NULL, "\n");
    }

    // Print the resume entries
    ResumeEntry* current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Experience Years: %d\n", current->experienceYears);
        printf("Salary: %.2lf\n", current->salary);
        printf("\n");
        current = current->next;
    }
}

int main() {
    char* resumeText = "Name: John Doe\nExperience Years: 5\nSalary: 50000\n\nName: Jane Doe\nExperience Years: 3\nSalary: 40000";

    parseResume(resumeText);

    return 0;
}