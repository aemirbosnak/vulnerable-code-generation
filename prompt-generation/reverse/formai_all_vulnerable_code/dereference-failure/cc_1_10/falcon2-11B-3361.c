//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a resume
typedef struct resume {
    char name[100];
    char email[100];
    char phone[20];
    char address[100];
    char skills[1000];
    char experience[1000];
    char education[1000];
} Resume;

// Function to parse a resume
Resume* parse_resume(char* resume_str) {
    Resume* resume = (Resume*)malloc(sizeof(Resume));

    resume->name[0] = '\0';
    resume->email[0] = '\0';
    resume->phone[0] = '\0';
    resume->address[0] = '\0';
    resume->skills[0] = '\0';
    resume->experience[0] = '\0';
    resume->education[0] = '\0';

    // Parse the resume string
    char* token = strtok(resume_str, "\n");
    while (token!= NULL) {
        if (strncmp(token, "Name: ", 6) == 0) {
            strcpy(resume->name, token + 6);
        } else if (strncmp(token, "Email: ", 7) == 0) {
            strcpy(resume->email, token + 7);
        } else if (strncmp(token, "Phone: ", 6) == 0) {
            strcpy(resume->phone, token + 6);
        } else if (strncmp(token, "Address: ", 8) == 0) {
            strcpy(resume->address, token + 8);
        } else if (strncmp(token, "Skills: ", 6) == 0) {
            strcpy(resume->skills, token + 6);
        } else if (strncmp(token, "Experience: ", 9) == 0) {
            strcpy(resume->experience, token + 9);
        } else if (strncmp(token, "Education: ", 9) == 0) {
            strcpy(resume->education, token + 9);
        }

        token = strtok(NULL, "\n");
    }

    return resume;
}

int main() {
    char resume_str[] = "Name: John Doe\nEmail: johndoe@example.com\nPhone: (123) 456-7890\nAddress: 123 Main St, Anytown, USA\nSkills: C, Python, Java\nExperience: Software Engineer, Company X (2015-2020)\nEducation: Bachelor of Science in Computer Science, University of XYZ (2011-2015)\n";

    Resume* resume = parse_resume(resume_str);
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);

    free(resume);
    return 0;
}