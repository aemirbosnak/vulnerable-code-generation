//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Structure to hold the information for each resume
typedef struct {
    char name[MAX_STRING_LENGTH];
    char skills[MAX_STRING_LENGTH];
    char experience[MAX_STRING_LENGTH];
    char education[MAX_STRING_LENGTH];
} Resume;

// Function to parse a single resume from a file
Resume parseResume(FILE* file) {
    Resume resume;
    char line[MAX_STRING_LENGTH];

    // Read in each line of the resume
    fgets(line, MAX_STRING_LENGTH, file);
    strcpy(resume.name, line);

    fgets(line, MAX_STRING_LENGTH, file);
    strcpy(resume.skills, line);

    fgets(line, MAX_STRING_LENGTH, file);
    strcpy(resume.experience, line);

    fgets(line, MAX_STRING_LENGTH, file);
    strcpy(resume.education, line);

    return resume;
}

// Function to print out the information for a single resume
void printResume(Resume resume) {
    printf("Name: %s", resume.name);
    printf("Skills: %s", resume.skills);
    printf("Experience: %s", resume.experience);
    printf("Education: %s", resume.education);
}

int main() {
    FILE* file;
    Resume resume;

    // Open the file containing the resumes
    file = fopen("resumes.txt", "r");

    // Parse each resume from the file and print out its information
    while (!feof(file)) {
        resume = parseResume(file);
        printResume(resume);
        printf("\n");
    }

    // Close the file
    fclose(file);

    return 0;
}