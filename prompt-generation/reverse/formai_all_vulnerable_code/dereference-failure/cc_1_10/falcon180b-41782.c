//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_ADDRESS_LENGTH 200
#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_EMAIL_LENGTH 100
#define MAX_SKILLS_LENGTH 500

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
} Resume;

Resume parse_resume(char *input) {
    Resume resume;
    char *token;
    int i = 0;

    // Extract name
    token = strtok(input, ",");
    strcpy(resume.name, token);
    i++;

    // Extract address
    token = strtok(NULL, ",");
    strcpy(resume.address, token);
    i++;

    // Extract phone number
    token = strtok(NULL, ",");
    strcpy(resume.phone_number, token);
    i++;

    // Extract email
    token = strtok(NULL, ",");
    strcpy(resume.email, token);
    i++;

    // Extract skills
    token = strtok(NULL, ",");
    while (token!= NULL && i < MAX_SKILLS_LENGTH) {
        strcat(resume.skills, token);
        strcat(resume.skills, " ");
        token = strtok(NULL, ",");
        i++;
    }

    return resume;
}

void print_resume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Phone Number: %s\n", resume.phone_number);
    printf("Email: %s\n", resume.email);
    printf("Skills: %s\n", resume.skills);
}

int main() {
    char input[1000];
    Resume resume;

    printf("Enter resume in format: Name,Address,Phone Number,Email,Skill1,Skill2,...\n");
    scanf("%[^\n]", input);

    resume = parse_resume(input);
    print_resume(resume);

    return 0;
}