//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing resume information
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char skills[500];
    char education[100];
} Resume;

// Function for parsing a resume
Resume parseResume(char* filename) {
    Resume r;

    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // Read the file line by line
    char buffer[1000];
    while (fgets(buffer, 1000, file)) {
        // Strip newline character
        buffer[strcspn(buffer, "\n")] = 0;

        // Split the line into key/value pairs
        char* key = strtok(buffer, ":");
        char* value = strtok(NULL, "");

        // Store the key/value pairs
        if (strcmp(key, "Name") == 0) {
            strcpy(r.name, value);
        } else if (strcmp(key, "Email") == 0) {
            strcpy(r.email, value);
        } else if (strcmp(key, "Phone") == 0) {
            strcpy(r.phone, value);
        } else if (strcmp(key, "Skills") == 0) {
            strcpy(r.skills, value);
        } else if (strcmp(key, "Education") == 0) {
            strcpy(r.education, value);
        }
    }

    // Close the file
    fclose(file);

    return r;
}

int main() {
    // Parse a resume file
    Resume r = parseResume("resume.txt");

    // Print out the resume information
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Skills: %s\n", r.skills);
    printf("Education: %s\n", r.education);

    return 0;
}