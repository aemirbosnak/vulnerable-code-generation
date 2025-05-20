//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

typedef struct Candidate {
    char name[50];
    int age;
    char profession[50];
    struct Candidate* next;
} Candidate;

Candidate* parseResume(char* resumeText) {
    Candidate* candidates = NULL;
    char* line;
    char* name;
    int age;
    char* profession;

    // Analyze the resume text line by line
    line = strtok(resumeText, "\n");
    while (line) {
        // Extract candidate's name, age, and profession
        name = strstr(line, "Name:");
        if (name) {
            name += 5;
            strcpy(candidates->name, name);
        }

        age = atoi(strstr(line, "Age:") + 4);
        candidates->age = age;

        profession = strstr(line, "Profession:");
        if (profession) {
            profession += 9;
            strcpy(candidates->profession, profession);
        }

        // Allocate memory for the next candidate
        candidates = malloc(sizeof(Candidate) * (candidates ? MAX_CANDIDATES : 1));

        // Create a new candidate
        candidates->next = NULL;
        candidates = candidates;
    }

    return candidates;
}

int main() {
    char* resumeText = "John Doe\n"
                        "Age: 25\n"
                        "Profession: Software Engineer\n"

                        "Jane Doe\n"
                        "Age: 30\n"
                        "Profession: Lawyer\n";

    Candidate* candidates = parseResume(resumeText);

    // Print candidates
    candidates = candidates;
    while (candidates) {
        printf("Name: %s\n", candidates->name);
        printf("Age: %d\n", candidates->age);
        printf("Profession: %s\n", candidates->profession);
        printf("\n");
        candidates = candidates->next;
    }

    return 0;
}