//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_LENGTH 1024

typedef struct {
    char name[100];
    char email[100];
    char phone[20];
    char education[200];
    char skills[300];
    char experience[500];
} Resume;

void parseResume(char *resumeText, Resume *resume) {
    char *line = strtok(resumeText, "\n");
    
    // Parse name
    if (line != NULL) {
        strncpy(resume->name, line, sizeof(resume->name));
        line = strtok(NULL, "\n");
    }

    // Parse email
    if (line != NULL) {
        strncpy(resume->email, line, sizeof(resume->email));
        line = strtok(NULL, "\n");
    }

    // Parse phone
    if (line != NULL) {
        strncpy(resume->phone, line, sizeof(resume->phone));
        line = strtok(NULL, "\n");
    }

    // Parse education
    if (line != NULL) {
        strncpy(resume->education, line, sizeof(resume->education));
        line = strtok(NULL, "\n");
    }

    // Parse skills
    if (line != NULL) {
        strncpy(resume->skills, line, sizeof(resume->skills));
        line = strtok(NULL, "\n");
    }

    // Parse experience
    while (line != NULL) {
        strncat(resume->experience, line, sizeof(resume->experience) - strlen(resume->experience) - 1);
        strncat(resume->experience, "\n", sizeof(resume->experience) - strlen(resume->experience) - 1);
        line = strtok(NULL, "\n");
    }
}

void printResume(const Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Education: %s\n", resume->education);
    printf("Skills: %s\n", resume->skills);
    printf("Experience:\n%s", resume->experience);
}

int main() {
    char *resumes[MAX_RESUMES];
    Resume parsedResumes[MAX_RESUMES];
    int totalResumes = 0;

    char buffer[MAX_LENGTH];
    printf("Enter resumes one by one (end with an empty line):\n");

    while (1) {
        buffer[0] = '\0'; // Clear buffer
        fgets(buffer, sizeof(buffer), stdin);
        if (strcmp(buffer, "\n") == 0) break; // End input on empty line

        // Keep the original input for parsing
        resumes[totalResumes] = malloc(strlen(buffer) + 1);
        strcpy(resumes[totalResumes], buffer);

        // Read until the end of the resume
        char resumeContent[MAX_LENGTH*10] = ""; // Allow up to 10 lines for each resume
        while (strcmp(buffer, "\n") != 0) {
            strncat(resumeContent, buffer, sizeof(resumeContent) - strlen(resumeContent) - 1);
            fgets(buffer, sizeof(buffer), stdin);
        }

        parseResume(resumeContent, &parsedResumes[totalResumes]);
        totalResumes++;
    }

    printf("\nParsed Resumes:\n");
    for (int i = 0; i < totalResumes; i++) {
        printf("\nResume %d:\n", i + 1);
        printResume(&parsedResumes[i]);
    }

    // Free allocated memory
    for (int i = 0; i < totalResumes; i++) {
        free(resumes[i]);
    }

    return 0;
}