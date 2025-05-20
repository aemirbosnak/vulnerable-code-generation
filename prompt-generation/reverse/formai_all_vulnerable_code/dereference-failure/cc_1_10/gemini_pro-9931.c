//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store resume data
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills[10];
    char *education[10];
    char *experience[10];
} resume;

// Function to parse resume from a text file
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
        return NULL;
    }

    // Initialize the resume fields
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->address = NULL;
    for (int i = 0; i < 10; i++) {
        resume->skills[i] = NULL;
        resume->education[i] = NULL;
        resume->experience[i] = NULL;
    }

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line
        char *field = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Set the appropriate field in the resume
        if (strcmp(field, "Name") == 0) {
            resume->name = strdup(value);
        } else if (strcmp(field, "Email") == 0) {
            resume->email = strdup(value);
        } else if (strcmp(field, "Phone") == 0) {
            resume->phone = strdup(value);
        } else if (strcmp(field, "Address") == 0) {
            resume->address = strdup(value);
        } else if (strcmp(field, "Skills") == 0) {
            char *skill = strtok(value, ",");
            int i = 0;
            while (skill != NULL) {
                resume->skills[i] = strdup(skill);
                i++;
                skill = strtok(NULL, ",");
            }
        } else if (strcmp(field, "Education") == 0) {
            char *degree = strtok(value, ",");
            int i = 0;
            while (degree != NULL) {
                resume->education[i] = strdup(degree);
                i++;
                degree = strtok(NULL, ",");
            }
        } else if (strcmp(field, "Experience") == 0) {
            char *job = strtok(value, ",");
            int i = 0;
            while (job != NULL) {
                resume->experience[i] = strdup(job);
                i++;
                job = strtok(NULL, ",");
            }
        }
    }

    // Close the file
    fclose(file);

    // Return the resume
    return resume;
}

// Function to print the resume
void print_resume(resume *resume) {
    // Print the name
    printf("Name: %s\n", resume->name);

    // Print the contact information
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);

    // Print the skills
    printf("Skills:\n");
    for (int i = 0; i < 10; i++) {
        if (resume->skills[i] != NULL) {
            printf("    * %s\n", resume->skills[i]);
        }
    }

    // Print the education
    printf("Education:\n");
    for (int i = 0; i < 10; i++) {
        if (resume->education[i] != NULL) {
            printf("    * %s\n", resume->education[i]);
        }
    }

    // Print the experience
    printf("Experience:\n");
    for (int i = 0; i < 10; i++) {
        if (resume->experience[i] != NULL) {
            printf("    * %s\n", resume->experience[i]);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if a filename was provided
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Parse the resume
    resume *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        return 1;
    }

    // Print the resume
    print_resume(resume);

    // Free the memory allocated for the resume
    free(resume);

    return 0;
}