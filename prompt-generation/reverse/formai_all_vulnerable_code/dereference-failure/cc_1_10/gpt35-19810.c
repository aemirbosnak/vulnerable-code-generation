//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define a struct to hold resume data */
struct resume_data {
    char *name;
    int age;
    char *email;
    char *education;
    char *skills;
};

/* function to parse resume input and return a resume_data struct */
struct resume_data parse_resume(char *input) {
    struct resume_data resume;
    char *token;

    /* parse name */
    token = strtok(input, "|");
    resume.name = malloc(strlen(token) + 1);
    strcpy(resume.name, token);

    /* parse age */
    token = strtok(NULL, "|");
    resume.age = atoi(token);

    /* parse email */
    token = strtok(NULL, "|");
    resume.email = malloc(strlen(token) + 1);
    strcpy(resume.email, token);

    /* parse education */
    token = strtok(NULL, "|");
    resume.education = malloc(strlen(token) + 1);
    strcpy(resume.education, token);

    /* parse skills */
    token = strtok(NULL, "|");
    resume.skills = malloc(strlen(token) + 1);
    strcpy(resume.skills, token);

    return resume;
}

int main() {
    /* sample resume string input */
    char *resume_input =
        "Ada Lovelace|29|ada.lovelace@abc.com|University of London|Programming";

    /* call parse_resume function to parse the input */
    struct resume_data resume = parse_resume(resume_input);

    /* print parsed data to console */
    printf("Name: %s\n", resume.name);
    printf("Age: %d\n", resume.age);
    printf("Email: %s\n", resume.email);
    printf("Education: %s\n", resume.education);
    printf("Skills: %s\n", resume.skills);

    /* free allocated memory */
    free(resume.name);
    free(resume.email);
    free(resume.education);
    free(resume.skills);

    return 0;
}