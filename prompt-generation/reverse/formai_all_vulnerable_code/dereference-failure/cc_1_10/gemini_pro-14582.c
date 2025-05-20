//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the resume struct
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} resume_t;

// Define the parser function
void parse_resume(char *filename, resume_t *resume) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Store the value in the resume struct
        if (strcmp(key, "name") == 0) {
            resume->name = strdup(value);
        } else if (strcmp(key, "email") == 0) {
            resume->email = strdup(value);
        } else if (strcmp(key, "phone") == 0) {
            resume->phone = strdup(value);
        } else if (strcmp(key, "address") == 0) {
            resume->address = strdup(value);
        } else if (strcmp(key, "skills") == 0) {
            resume->skills = strdup(value);
        } else if (strcmp(key, "experience") == 0) {
            resume->experience = strdup(value);
        } else if (strcmp(key, "education") == 0) {
            resume->education = strdup(value);
        }
    }

    // Close the file
    fclose(file);
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check if the user provided a filename
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Parse the resume
    resume_t resume;
    parse_resume(argv[1], &resume);

    // Print the resume
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Skills: %s\n", resume.skills);
    printf("Experience: %s\n", resume.experience);
    printf("Education: %s\n", resume.education);

    // Free the memory allocated for the resume
    free(resume.name);
    free(resume.email);
    free(resume.phone);
    free(resume.address);
    free(resume.skills);
    free(resume.experience);
    free(resume.education);

    return 0;
}