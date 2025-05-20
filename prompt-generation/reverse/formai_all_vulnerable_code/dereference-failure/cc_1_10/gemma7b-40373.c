//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20
#define MAX_EXPERIENCE_LENGTH 50

typedef struct resume_t {
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    struct resume_t* next;
} resume_t;

resume_t* parse_resume(char* resume_text) {
    resume_t* head = NULL;
    resume_t* current = NULL;

    // Extract the name from the resume text
    char* name = strstr(resume_text, "Name:");
    if (name) {
        name += 5;
        current = malloc(sizeof(resume_t));
        strcpy(current->name, name);
        current->next = NULL;

        if (head) {
            head->next = current;
        } else {
            head = current;
        }
    }

    // Extract the experience from the resume text
    char* experience = strstr(resume_text, "Experience:");
    if (experience) {
        experience += 9;
        current = malloc(sizeof(resume_t));
        strcpy(current->experience, experience);
        current->next = NULL;

        if (head) {
            head->next = current;
        } else {
            head = current;
        }
    }

    return head;
}

int main() {
    char* resume_text = "Name: Romeo Montague\n"
                           "Experience: Software Engineer at Capulet Corporation\n"
                           "Name: Mercutio Capulet\n"
                           "Experience: Sales Manager at Montague Enterprises\n";

    resume_t* head = parse_resume(resume_text);

    // Print the name and experience of each person
    for (resume_t* current = head; current; current = current->next) {
        printf("Name: %s\n", current->name);
        printf("Experience: %s\n", current->experience);
        printf("\n");
    }

    return 0;
}