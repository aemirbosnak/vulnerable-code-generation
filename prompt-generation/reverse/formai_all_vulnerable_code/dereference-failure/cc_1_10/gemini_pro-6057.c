//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Structure to store resume data
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *objective;
    char *education;
    char *experience;
    char *skills;
    char *awards;
    char *references;
} resume;

// Function to parse a resume file and populate the resume structure
resume *parse_resume(char *filename) {
    // Initialize the resume structure
    resume *resume = malloc(sizeof(resume));
    memset(resume, 0, sizeof(resume));

    // Open the resume file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening resume file");
        return NULL;
    }

    // Read the resume file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Trim the line
        strtok(line, "\n");

        // Parse the line
        if (strncmp(line, "Name:", 5) == 0) {
            resume->name = strdup(line + 5);
        } else if (strncmp(line, "Email:", 6) == 0) {
            resume->email = strdup(line + 6);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            resume->phone = strdup(line + 6);
        } else if (strncmp(line, "Address:", 8) == 0) {
            resume->address = strdup(line + 8);
        } else if (strncmp(line, "Objective:", 10) == 0) {
            resume->objective = strdup(line + 10);
        } else if (strncmp(line, "Education:", 10) == 0) {
            resume->education = strdup(line + 10);
        } else if (strncmp(line, "Experience:", 11) == 0) {
            resume->experience = strdup(line + 11);
        } else if (strncmp(line, "Skills:", 7) == 0) {
            resume->skills = strdup(line + 7);
        } else if (strncmp(line, "Awards:", 7) == 0) {
            resume->awards = strdup(line + 7);
        } else if (strncmp(line, "References:", 11) == 0) {
            resume->references = strdup(line + 11);
        }
    }

    // Close the resume file
    fclose(file);

    // Return the resume
    return resume;
}

// Function to print the resume
void print_resume(resume *resume) {
    // Print the resume data
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Objective: %s\n", resume->objective);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    printf("Skills: %s\n", resume->skills);
    printf("Awards: %s\n", resume->awards);
    printf("References: %s\n", resume->references);
}

// Main function
int main() {
    // Parse the resume file
    resume *resume = parse_resume("resume.txt");

    // Print the resume
    print_resume(resume);

    // Free the resume structure
    free(resume);

    return 0;
}