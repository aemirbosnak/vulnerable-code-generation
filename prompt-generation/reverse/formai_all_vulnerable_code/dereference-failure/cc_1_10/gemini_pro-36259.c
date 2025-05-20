//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store resume data
typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *education;
    char *experience;
} Resume;

// Function to parse a resume from a file
Resume *parse_resume(char *filename) {
    // Allocate memory for the resume
    Resume *resume = malloc(sizeof(Resume));

    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Store the data in the resume
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
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

// Main function
int main(int argc, char **argv) {
    // Check if a filename was provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Parse the resume
    Resume *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        return 1;
    }

    // Print the resume
    print_resume(resume);

    // Free the memory allocated for the resume
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->skills);
    free(resume->education);
    free(resume->experience);
    free(resume);

    return 0;
}