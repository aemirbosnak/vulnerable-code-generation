//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo and Juliet-inspired C program to parse a resume

// Define the names of the two lovers
#define ROMEO "Romeo"
#define JULIET "Juliet"

// Define the structure of a resume
struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
};

// Function to parse a resume from a file
struct resume *parse_resume(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Create a new resume struct
    struct resume *resume = malloc(sizeof(struct resume));
    if (resume == NULL) {
        perror("Error allocating memory for resume");
        fclose(file);
        return NULL;
    }

    // Read the lines of the file
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Parse the line
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Store the key-value pair in the resume struct
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
    fclose(file);

    // Return the resume struct
    return resume;
}

// Function to print a resume
void print_resume(const struct resume *resume) {
    // Print the resume details
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the resume
    struct resume *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        return EXIT_FAILURE;
    }

    // Print the resume
    print_resume(resume);

    // Free the resume struct
    free(resume);

    return EXIT_SUCCESS;
}