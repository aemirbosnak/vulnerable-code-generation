//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100
#define MAX_FIELDS 10

// Struct to hold resume information
typedef struct {
    char name[MAX_WORD_LENGTH];
    char email[MAX_WORD_LENGTH];
    char phone[MAX_WORD_LENGTH];
    char address[MAX_LINE_LENGTH];
    char education[MAX_LINE_LENGTH];
    char experience[MAX_LINE_LENGTH];
} Resume;

int main() {
    FILE *resumeFile;
    char line[MAX_LINE_LENGTH];
    char *token;
    char *saveptr;
    Resume resume;
    int fieldCount = 0;

    // Open the resume file for reading
    resumeFile = fopen("resume.txt", "r");

    if (resumeFile == NULL) {
        printf("Error: Unable to open resume file.\n");
        return 1;
    }

    // Read the first line of the file to get the name
    fgets(line, MAX_LINE_LENGTH, resumeFile);
    token = strtok_r(line, " ", &saveptr);
    strcpy(resume.name, token);

    // Continue reading lines to get the rest of the information
    while (fgets(line, MAX_LINE_LENGTH, resumeFile)!= NULL) {
        // Check if the line contains a field separator (:)
        if (strchr(line, ':')!= NULL) {
            // Split the line into fields using the field separator
            token = strtok_r(line, ":", &saveptr);
            strcpy(resume.email, token);
            token = strtok_r(NULL, ":", &saveptr);
            strcpy(resume.phone, token);
            token = strtok_r(NULL, ":", &saveptr);
            strcpy(resume.address, token);
            token = strtok_r(NULL, ":", &saveptr);
            strcpy(resume.education, token);
            token = strtok_r(NULL, ":", &saveptr);
            strcpy(resume.experience, token);
            fieldCount++;
        } else {
            // The line is part of the experience field
            strcat(resume.experience, line);
            strcat(resume.experience, "\n");
        }
    }

    // Close the resume file
    fclose(resumeFile);

    // Print the resume information
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Education: %s\n", resume.education);
    printf("Experience:\n%s", resume.experience);

    return 0;
}