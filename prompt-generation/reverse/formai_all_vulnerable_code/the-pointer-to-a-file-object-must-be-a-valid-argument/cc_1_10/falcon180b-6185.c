//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LENGTH 1000

typedef struct {
    char name[100];
    char email[100];
    char phone[20];
    char address[200];
    char education[MAX_RESUME_LENGTH];
    char experience[MAX_RESUME_LENGTH];
} Resume;

Resume parseResume(char* resumeText) {
    Resume result;
    char* token;
    char* savePtr;

    // Extract name
    token = strtok_r(resumeText, "\n", &savePtr);
    strcpy(result.name, token);

    // Extract email
    token = strtok_r(NULL, "\n", &savePtr);
    strcpy(result.email, token);

    // Extract phone number
    token = strtok_r(NULL, "\n", &savePtr);
    strcpy(result.phone, token);

    // Extract address
    token = strtok_r(NULL, "\n", &savePtr);
    strcpy(result.address, token);

    // Extract education
    token = strtok_r(NULL, "\n", &savePtr);
    strcpy(result.education, token);

    // Extract experience
    token = strtok_r(NULL, "\n", &savePtr);
    strcpy(result.experience, token);

    return result;
}

void printResume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
}

int main() {
    char resumeText[MAX_RESUME_LENGTH];
    Resume resume;

    // Read resume from file
    FILE* file = fopen("resume.txt", "r");
    fgets(resumeText, MAX_RESUME_LENGTH, file);
    fclose(file);

    // Parse resume
    resume = parseResume(resumeText);

    // Print resume
    printResume(resume);

    return 0;
}