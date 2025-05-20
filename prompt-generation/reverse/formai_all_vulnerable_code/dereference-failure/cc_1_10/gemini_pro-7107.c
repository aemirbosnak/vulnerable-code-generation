//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store resume data
typedef struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char skills[100];
    char experience[100];
    char education[100];
} Resume;

// Function to parse a resume file
Resume *parseResume(char *filename) {
    // Open the resume file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening resume file");
        return NULL;
    }

    // Allocate memory for the resume struct
    Resume *resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        perror("Error allocating memory for resume");
        fclose(fp);
        return NULL;
    }

    // Read the resume file line by line
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse the resume line
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Store the resume data in the struct
        if (strcmp(key, "Name") == 0) {
            strcpy(resume->name, value);
        } else if (strcmp(key, "Email") == 0) {
            strcpy(resume->email, value);
        } else if (strcmp(key, "Phone") == 0) {
            strcpy(resume->phone, value);
        } else if (strcmp(key, "Skills") == 0) {
            strcpy(resume->skills, value);
        } else if (strcmp(key, "Experience") == 0) {
            strcpy(resume->experience, value);
        } else if (strcmp(key, "Education") == 0) {
            strcpy(resume->education, value);
        }
    }

    // Close the resume file
    fclose(fp);

    // Return the resume struct
    return resume;
}

// Function to print a resume
void printResume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

// Main function
int main() {
    // Parse the resume file
    Resume *resume = parseResume("resume.txt");
    if (resume == NULL) {
        return 1;
    }

    // Print the resume
    printResume(resume);

    // Free the resume struct
    free(resume);

    return 0;
}