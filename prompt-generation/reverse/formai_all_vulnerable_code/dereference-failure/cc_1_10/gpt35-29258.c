//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LENGTH 1000

// A struct to store the relevant information extracted from the resume
typedef struct {
    char name[50];
    char email[50];
    char phone_number[20];
    char skills[100];
    char experience[200];
    char education[200];
} Resume;

// Function to extract the name from the resume
char* extract_name(char* resume) {
    char* name = (char*)malloc(sizeof(char)*50);
    int i = 0, j = 0;
    while(resume[i]) {
        if((resume[i] >= 'a' && resume[i] <= 'z') || (resume[i] >= 'A' && resume[i] <= 'Z') || resume[i] == ' ')
            name[j++] = resume[i];
        i++;
    }
    name[j] = '\0';
    return name;
}

int main() {
    char resume[MAX_RESUME_LENGTH];
    printf("Enter the resume:\n");
    fgets(resume, MAX_RESUME_LENGTH, stdin);

    Resume parsed_resume;

    // Extract the name from the resume
    char* name = extract_name(resume);
    strcpy(parsed_resume.name, name);
    free(name);

    // Extract the email from the resume
    // ...

    printf("Name: %s\n", parsed_resume.name);
    printf("Email: %s\n", parsed_resume.email);
    printf("Phone Number: %s\n", parsed_resume.phone_number);
    printf("Skills: %s\n", parsed_resume.skills);
    printf("Experience: %s\n", parsed_resume.experience);
    printf("Education: %s\n", parsed_resume.education);

    return 0;
}