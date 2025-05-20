//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct Resume {
    char name[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
} Resume;

int main() {
    char input[MAX_NAME_LENGTH];
    char *pInput = NULL;
    Resume resume;

    printf("Enter your name: ");
    fgets(input, MAX_NAME_LENGTH, stdin);

    pInput = strdup(input);
    strcpy(resume.name, pInput);

    printf("Enter your address: ");
    fgets(input, MAX_NAME_LENGTH, stdin);

    pInput = strdup(input);
    strcpy(resume.address, pInput);

    printf("Enter your phone number: ");
    fgets(input, MAX_NAME_LENGTH, stdin);

    pInput = strdup(input);
    strcpy(resume.phone, pInput);

    printf("Enter your email address: ");
    fgets(input, MAX_NAME_LENGTH, stdin);

    pInput = strdup(input);
    strcpy(resume.email, pInput);

    printf("Enter your experience: ");
    fgets(input, MAX_EXPERIENCE_LENGTH, stdin);

    pInput = strdup(input);
    strcpy(resume.experience, pInput);

    printf("Here is your resume:\n");
    printf("Name: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Phone number: %s\n", resume.phone);
    printf("Email address: %s\n", resume.email);
    printf("Experience: %s\n", resume.experience);

    return 0;
}