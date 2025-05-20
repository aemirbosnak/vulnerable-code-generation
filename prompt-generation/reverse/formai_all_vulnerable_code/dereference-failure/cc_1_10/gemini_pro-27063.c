//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the resume data structure
typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} Resume;

// Declare the function to parse a resume file
Resume *parse_resume(char *filename) {
    // Open the resume file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening resume file\n");
        return NULL;
    }

    // Allocate memory for the resume data structure
    Resume *resume = malloc(sizeof(Resume));

    // Read the resume file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Store the parsed data in the resume data structure
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

    // Close the resume file
    fclose(file);

    // Return the resume data structure
    return resume;
}

// Declare the function to print a resume
void print_resume(Resume *resume) {
    // Print the resume data
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

// Declare the main function
int main() {
    // Parse the resume file
    Resume *resume = parse_resume("resume.txt");

    // Print the resume
    print_resume(resume);

    // Free the memory allocated for the resume data structure
    free(resume);

    return 0;
}