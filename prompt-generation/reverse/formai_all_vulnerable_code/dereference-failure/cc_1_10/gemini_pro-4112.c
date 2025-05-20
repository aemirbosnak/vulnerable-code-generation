//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store resume data
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *education;
    char *experience;
} resume;

// Function to parse a resume from a file
resume *parse_resume(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Allocate memory for the resume
    resume *resume = malloc(sizeof(resume));
    if (resume == NULL) {
        perror("Error allocating memory");
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
        char *field = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Set the appropriate field in the resume
        if (strcmp(field, "Name") == 0) {
            resume->name = malloc(strlen(value) + 1);
            strcpy(resume->name, value);
        } else if (strcmp(field, "Email") == 0) {
            resume->email = malloc(strlen(value) + 1);
            strcpy(resume->email, value);
        } else if (strcmp(field, "Phone") == 0) {
            resume->phone = malloc(strlen(value) + 1);
            strcpy(resume->phone, value);
        } else if (strcmp(field, "Skills") == 0) {
            resume->skills = malloc(strlen(value) + 1);
            strcpy(resume->skills, value);
        } else if (strcmp(field, "Education") == 0) {
            resume->education = malloc(strlen(value) + 1);
            strcpy(resume->education, value);
        } else if (strcmp(field, "Experience") == 0) {
            resume->experience = malloc(strlen(value) + 1);
            strcpy(resume->experience, value);
        }
    }

    // Close the file
    fclose(file);

    // Return the resume
    return resume;
}

// Function to print a resume
void print_resume(resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

// Main function
int main() {
    // Parse the resume from a file
    resume *resume = parse_resume("resume.txt");
    if (resume == NULL) {
        return EXIT_FAILURE;
    }

    // Print the resume
    print_resume(resume);

    // Free the memory allocated for the resume
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->skills);
    free(resume->education);
    free(resume->experience);
    free(resume);

    return EXIT_SUCCESS;
}