//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256

typedef struct Resume {
    char name[MAX_NAME_LENGTH];
    int age;
    char occupation[MAX_NAME_LENGTH];
    struct Resume* next;
} Resume;

void parse_resume(char* resume_text) {
    Resume* head = NULL;
    Resume* tail = NULL;

    // Extract name, age, and occupation from the resume text
    char* name = strstr(resume_text, "Name:");
    char* age_str = strstr(resume_text, "Age:");
    char* occupation = strstr(resume_text, "Occupation:");

    // Allocate memory for the resume node
    Resume* new_resume = malloc(sizeof(Resume));

    // Set the name, age, and occupation
    strncpy(new_resume->name, name + 5, MAX_NAME_LENGTH - 1);
    new_resume->age = atoi(age_str + 5);
    strncpy(new_resume->occupation, occupation + 9, MAX_NAME_LENGTH - 1);

    // Link the new resume node to the head of the list
    if (head == NULL) {
        head = new_resume;
        tail = new_resume;
    } else {
        tail->next = new_resume;
        tail = new_resume;
    }

    // Print the name, age, and occupation of the resume
    printf("Name: %s\n", new_resume->name);
    printf("Age: %d\n", new_resume->age);
    printf("Occupation: %s\n", new_resume->occupation);
}

int main() {
    char* resume_text = "Name: John Doe\nAge: 25\nOccupation: Software Engineer";

    parse_resume(resume_text);

    return 0;
}