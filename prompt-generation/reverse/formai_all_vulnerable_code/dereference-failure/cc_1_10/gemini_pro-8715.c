//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the resume structure
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} resume_t;

// Function to parse a resume from a file
resume_t *parse_resume(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Create a new resume
    resume_t *resume = malloc(sizeof(resume_t));
    if (resume == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    // Read the resume data
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse the line
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Set the appropriate field in the resume
        if (strcmp(key, "Name") == 0) {
            resume->name = strdup(value);
        } else if (strcmp(key, "Email") == 0) {
            resume->email = strdup(value);
        } else if (strcmp(key, "Phone") == 0) {
            resume->phone = strdup(value);
        } else if (strcmp(key, "Address") == 0) {
            resume->address = strdup(value);
        } else if (strcmp(key, "Skills") == 0) {
            resume->skills = strdup(value);
        } else if (strcmp(key, "Experience") == 0) {
            resume->experience = strdup(value);
        } else if (strcmp(key, "Education") == 0) {
            resume->education = strdup(value);
        }
    }

    // Close the file
    fclose(fp);

    // Return the resume
    return resume;
}

// Function to print a resume
void print_resume(resume_t *resume) {
    // Print the resume data
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

// Main function
int main(int argc, char *argv[]) {
    // Parse the resume
    resume_t *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        return EXIT_FAILURE;
    }

    // Print the resume
    print_resume(resume);

    // Free the resume
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);
    free(resume);

    return EXIT_SUCCESS;
}