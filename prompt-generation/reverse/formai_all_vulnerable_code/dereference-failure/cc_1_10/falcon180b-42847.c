//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    char email[100];
    char phone[20];
    int experience;
} Resume;

Resume parseResume(char *resumeText) {
    Resume result;
    char *token;
    int i = 0;

    // Extract name
    token = strtok(resumeText, "\n");
    strcpy(result.name, token);

    // Extract email
    token = strtok(NULL, "\n");
    strcpy(result.email, token);

    // Extract phone number
    token = strtok(NULL, "\n");
    strcpy(result.phone, token);

    // Extract experience
    result.experience = atoi(strtok(NULL, "\n"));

    return result;
}

void printResume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Experience: %d years\n", resume.experience);
}

int main() {
    char resumeText[1000];
    Resume resume;

    // Read resume from standard input
    printf("Enter your resume:\n");
    fgets(resumeText, sizeof(resumeText), stdin);

    // Parse resume
    resume = parseResume(resumeText);

    // Print resume
    printResume(resume);

    return 0;
}