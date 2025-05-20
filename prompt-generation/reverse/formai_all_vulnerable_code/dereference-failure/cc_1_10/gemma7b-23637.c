//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct resume_t {
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    struct resume_t* next;
} resume_t;

resume_t* parse_resume(char* resume_text) {
    char* name = NULL;
    char* experience = NULL;
    resume_t* head = NULL;

    // Allocate memory for the first resume entry
    head = malloc(sizeof(resume_t));
    head->next = NULL;

    // Extract the name and experience from the resume text
    name = strstr(resume_text, "Name:");
    experience = strstr(name, "Experience:");

    // Copy the name and experience into the resume entry
    strcpy(head->name, name + 5);
    strcpy(head->experience, experience + 10);

    // Return the head of the resume list
    return head;
}

int main() {
    char* resume_text = "Name: John Doe\nExperience: Software Engineer at Google\n\nName: Jane Doe\nExperience: Marketing Manager at Facebook";

    resume_t* head = parse_resume(resume_text);

    // Print the name and experience of each resume entry
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Experience: %s\n", head->experience);
        printf("\n");

        head = head->next;
    }

    return 0;
}