//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for storing resume data
typedef struct {
    char name[50];
    char email[50];
    char phone[15];
    char education[100];
    char skills[200];
} Resume;

// Define a function for parsing resumes
Resume parseResume(char* resumeText) {
    Resume resume;
    // Extract name from resume
    char* namePtr = strtok(resumeText, "\n");
    strcpy(resume.name, namePtr);
    // Extract email from resume
    char* emailPtr = strstr(resumeText, "Email: ") + strlen("Email: ");
    sscanf(emailPtr, "%s", resume.email);
    // Extract phone number from resume
    char* phonePtr = strstr(resumeText, "Phone: ") + strlen("Phone: ");
    sscanf(phonePtr, "%s", resume.phone);
    // Extract education from resume
    char* educationPtr = strstr(resumeText, "Education: ") + strlen("Education: ");
    strcpy(resume.education, educationPtr);
    // Extract skills from resume
    char* skillsPtr = strstr(resumeText, "Skills: ") + strlen("Skills: ");
    strcpy(resume.skills, skillsPtr);
    return resume;
}

int main() {
    char resumeText[500];
    printf("Welcome to the Resume Parsing System!\n");
    printf("Enter the text of the resume to be parsed:\n");
    fgets(resumeText, 500, stdin);
    // Replace newlines with spaces for easier parsing
    for (int i = 0; i < strlen(resumeText); i++) {
        if (resumeText[i] == '\n')
            resumeText[i] = ' ';
    }
    Resume resume = parseResume(resumeText);
    printf("\nResume successfully parsed:\n");
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Skills: %s\n", resume.skills);
    return 0;
}