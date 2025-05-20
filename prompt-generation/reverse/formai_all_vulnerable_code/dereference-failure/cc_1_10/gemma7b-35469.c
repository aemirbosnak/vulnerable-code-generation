//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Candidate {
    char name[MAX_NAME_LENGTH];
    int age;
    char occupation[MAX_NAME_LENGTH];
    struct Candidate* next;
} Candidate;

Candidate* parseResume(char* resumeText) {
    Candidate* head = NULL;
    char* name = NULL;
    int age = 0;
    char* occupation = NULL;

    // Allocate memory for the candidate list
    head = malloc(sizeof(Candidate));

    // Extract the candidate's name, age, and occupation from the resume text
    name = strstr(resumeText, "Name:");
    if (name) {
        name += 5;
        strcpy(head->name, name);
    }

    age = atoi(strstr(resumeText, "Age:"));
    if (age) {
        head->age = age;
    }

    occupation = strstr(resumeText, "Occupation:");
    if (occupation) {
        occupation += 9;
        strcpy(head->occupation, occupation);
    }

    head->next = NULL;

    return head;
}

int main() {
    char* resumeText = "Name: John Doe\nAge: 25\nOccupation: Software Engineer";

    Candidate* head = parseResume(resumeText);

    printf("Name: %s\n", head->name);
    printf("Age: %d\n", head->age);
    printf("Occupation: %s\n", head->occupation);

    return 0;
}