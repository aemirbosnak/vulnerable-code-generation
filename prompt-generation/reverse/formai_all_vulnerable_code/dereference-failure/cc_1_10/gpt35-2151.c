//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define struct for resume */
typedef struct {
    char name[50];
    char address[100];
    char email[50];
    char phone[20];
    char education[100];
    char experience[200];
} Resume;

/* Define function to parse resume */
void parseResume(Resume *resume, char *input) {
    char *token;

    /* Get name */
    token = strtok(input, "\n");
    strcpy(resume->name, token);

    /* Get address */
    token = strtok(NULL, "\n");
    strcpy(resume->address, token);

    /* Get email */
    token = strtok(NULL, "\n");
    strcpy(resume->email, token);

    /* Get phone */
    token = strtok(NULL, "\n");
    strcpy(resume->phone, token);

    /* Get education */
    token = strtok(NULL, "\n");
    strcpy(resume->education, token);

    /* Get experience */
    token = strtok(NULL, "\n");
    strcpy(resume->experience, token);
}

int main() {
    /* Define input and resume */
    char input[500];
    Resume resume;

    /* Get input from user */
    printf("Enter your resume:\n");
    fgets(input, 500, stdin);

    /* Parse resume */
    parseResume(&resume, input);

    /* Print resume */
    printf("Name: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    return 0;
}