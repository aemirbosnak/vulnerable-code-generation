//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of resumes you can parse
#define MAXIMUM_RESUMES 100

// Define the maximum length for a resume field
#define MAX_FIELD_LENGTH 100

// Define the structure for a resume
typedef struct {
    char name[MAX_FIELD_LENGTH];
    char email[MAX_FIELD_LENGTH];
    char phone[MAX_FIELD_LENGTH];
    char education[MAX_FIELD_LENGTH];
    char experience[MAX_FIELD_LENGTH];
    char skills[MAX_FIELD_LENGTH];
} Resume;

// Define the function to parse a resume
Resume parseResume(char* resumeContent) {
    // Split the resume content by fields
    char* name = strtok(resumeContent, "\n");
    char* email = strtok(NULL, "\n");
    char* phone = strtok(NULL, "\n");
    char* education = strtok(NULL, "\n");
    char* experience = strtok(NULL, "\n");
    char* skills = strtok(NULL, "\n");

    // Create the resume object
    Resume resume;
    strcpy(resume.name, name);
    strcpy(resume.email, email);
    strcpy(resume.phone, phone);
    strcpy(resume.education, education);
    strcpy(resume.experience, experience);
    strcpy(resume.skills, skills);

    // Return the resume object
    return resume;
}

// Define the function to print a resume
void printResume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
    printf("Skills: %s\n", resume.skills);
}

int main() {
    // Define the array of resumes
    Resume resumes[MAXIMUM_RESUMES];
    int numberOfResumes = 0;

    // Open the resumes file
    FILE* resumesFile = fopen("resumes.txt", "r");
    if (resumesFile == NULL) {
        printf("Error: could not open the resumes file.\n");
        return 1;
    }

    // Read all the resumes from the file
    char resumeContent[MAX_FIELD_LENGTH * 6 + 5];
    while (fgets(resumeContent, sizeof(resumeContent), resumesFile) != NULL) {
        Resume resume = parseResume(resumeContent);
        resumes[numberOfResumes++] = resume;
    }

    // Close the resumes file
    fclose(resumesFile);

    // Print all the resumes
    for (int i = 0; i < numberOfResumes; i++) {
        printResume(resumes[i]);
    }

    // Return success
    return 0;
}