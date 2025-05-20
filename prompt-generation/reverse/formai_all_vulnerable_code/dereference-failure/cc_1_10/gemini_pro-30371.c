//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a resume
typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *education;
    char *experience;
} Resume;

// Function to parse a resume from a file
Resume *parse_resume(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the resume
    Resume *resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        printf("Error allocating memory for resume\n");
        fclose(file);
        return NULL;
    }

    // Initialize the resume fields
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->skills = NULL;
    resume->education = NULL;
    resume->experience = NULL;

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Set the appropriate resume field
        if (strcmp(key, "Name") == 0) {
            resume->name = strdup(value);
        } else if (strcmp(key, "Email") == 0) {
            resume->email = strdup(value);
        } else if (strcmp(key, "Phone") == 0) {
            resume->phone = strdup(value);
        } else if (strcmp(key, "Skills") == 0) {
            resume->skills = strdup(value);
        } else if (strcmp(key, "Education") == 0) {
            resume->education = strdup(value);
        } else if (strcmp(key, "Experience") == 0) {
            resume->experience = strdup(value);
        }
    }

    // Close the file
    fclose(file);

    // Return the resume
    return resume;
}

// Function to print a resume
void print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

// Function to free the memory allocated for a resume
void free_resume(Resume *resume) {
    if (resume != NULL) {
        free(resume->name);
        free(resume->email);
        free(resume->phone);
        free(resume->skills);
        free(resume->education);
        free(resume->experience);
        free(resume);
    }
}

// Main function
int main() {
    // Parse the resume from a file
    Resume *resume = parse_resume("resume.txt");

    // Print the resume
    if (resume != NULL) {
        print_resume(resume);
    } else {
        printf("Error parsing resume\n");
    }

    // Free the memory allocated for the resume
    free_resume(resume);

    return 0;
}