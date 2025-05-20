//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a resume
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} resume_t;

// Create a new resume
resume_t *create_resume() {
    resume_t *resume = malloc(sizeof(resume_t));
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->skills = NULL;
    resume->experience = NULL;
    resume->education = NULL;
    return resume;
}

// Free the memory allocated for a resume
void free_resume(resume_t *resume) {
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);
    free(resume);
}

// Parse a resume from a file
resume_t *parse_resume(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Create a new resume
    resume_t *resume = create_resume();

    // Read the resume data
    char line[1024];
    while (fgets(line, 1024, file)) {
        // Parse the line
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Set the corresponding field in the resume
        if (strcmp(key, "Name") == 0) {
            resume->name = strdup(value);
        } else if (strcmp(key, "Email") == 0) {
            resume->email = strdup(value);
        } else if (strcmp(key, "Phone") == 0) {
            resume->phone = strdup(value);
        } else if (strcmp(key, "Skills") == 0) {
            resume->skills = strdup(value);
        } else if (strcmp(key, "Experience") == 0) {
            resume->experience = strdup(value);
        } else if (strcmp(key, "Education") == 0) {
            resume->education = strdup(value);
        }
    }

    // Close the file
    fclose(file);

    // Return the resume
    return resume;
}

// Print a resume
void print_resume(resume_t *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

// Main function
int main() {
    // Parse a resume from a file
    resume_t *resume = parse_resume("resume.txt");

    // Print the resume
    print_resume(resume);

    // Free the memory allocated for the resume
    free_resume(resume);

    return 0;
}