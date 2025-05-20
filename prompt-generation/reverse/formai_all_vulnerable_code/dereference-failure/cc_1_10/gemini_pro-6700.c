//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a struct to represent a resume
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *education;
    char *experience;
} resume;

// Create a new resume
resume *create_resume() {
    resume *new_resume = (resume *)malloc(sizeof(resume));
    new_resume->name = NULL;
    new_resume->email = NULL;
    new_resume->phone = NULL;
    new_resume->skills = NULL;
    new_resume->education = NULL;
    new_resume->experience = NULL;
    return new_resume;
}

// Parse a resume from a file
resume *parse_resume(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Create a new resume
    resume *new_resume = create_resume();

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Set the appropriate field in the resume
        if (strcmp(key, "name") == 0) {
            new_resume->name = strdup(value);
        } else if (strcmp(key, "email") == 0) {
            new_resume->email = strdup(value);
        } else if (strcmp(key, "phone") == 0) {
            new_resume->phone = strdup(value);
        } else if (strcmp(key, "skills") == 0) {
            new_resume->skills = strdup(value);
        } else if (strcmp(key, "education") == 0) {
            new_resume->education = strdup(value);
        } else if (strcmp(key, "experience") == 0) {
            new_resume->experience = strdup(value);
        }
    }

    // Close the file
    fclose(file);

    // Return the resume
    return new_resume;
}

// Print a resume
void print_resume(resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

// Free the memory allocated for a resume
void free_resume(resume *resume) {
    if (resume->name != NULL) {
        free(resume->name);
    }
    if (resume->email != NULL) {
        free(resume->email);
    }
    if (resume->phone != NULL) {
        free(resume->phone);
    }
    if (resume->skills != NULL) {
        free(resume->skills);
    }
    if (resume->education != NULL) {
        free(resume->education);
    }
    if (resume->experience != NULL) {
        free(resume->experience);
    }
    free(resume);
}

int main() {
    // Parse a resume from a file
    resume *resume = parse_resume("resume.txt");

    // Print the resume
    print_resume(resume);

    // Free the memory allocated for the resume
    free_resume(resume);

    return 0;
}