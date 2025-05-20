//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a resume struct
typedef struct resume {
    char* name;
    char* email;
    char* phone;
    char* linkedin;
    char* skills;
    char* experience;
    char* education;
} resume_t;

// Define a resume parser function
resume_t* parse_resume(char* filename) {
    // Open the resume file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening resume file");
        return NULL;
    }

    // Read the resume file into a buffer
    char* buffer = NULL;
    size_t size = 0;
    size_t nread = getline(&buffer, &size, file);
    if (nread == -1) {
        perror("Error reading resume file");
        fclose(file);
        return NULL;
    }

    // Close the resume file
    fclose(file);

    // Allocate memory for the resume struct
    resume_t* resume = malloc(sizeof(resume_t));
    if (resume == NULL) {
        perror("Error allocating memory for resume struct");
        free(buffer);
        return NULL;
    }

    // Parse the resume file
    char* line = strtok(buffer, "\n");
    while (line != NULL) {
        // Parse the line
        char* key = strtok(line, ": ");
        char* value = strtok(NULL, "\n");

        // Set the corresponding field in the resume struct
        if (strcmp(key, "Name") == 0) {
            resume->name = strdup(value);
        } else if (strcmp(key, "Email") == 0) {
            resume->email = strdup(value);
        } else if (strcmp(key, "Phone") == 0) {
            resume->phone = strdup(value);
        } else if (strcmp(key, "LinkedIn") == 0) {
            resume->linkedin = strdup(value);
        } else if (strcmp(key, "Skills") == 0) {
            resume->skills = strdup(value);
        } else if (strcmp(key, "Experience") == 0) {
            resume->experience = strdup(value);
        } else if (strcmp(key, "Education") == 0) {
            resume->education = strdup(value);
        }

        // Get the next line
        line = strtok(NULL, "\n");
    }

    // Free the buffer
    free(buffer);

    // Return the resume struct
    return resume;
}

// Define a function to print the resume
void print_resume(resume_t* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("LinkedIn: %s\n", resume->linkedin);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

// Main function
int main() {
    // Parse the resume file
    resume_t* resume = parse_resume("resume.txt");
    if (resume == NULL) {
        return EXIT_FAILURE;
    }

    // Print the resume
    print_resume(resume);

    // Free the resume struct
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->linkedin);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);
    free(resume);

    return EXIT_SUCCESS;
}