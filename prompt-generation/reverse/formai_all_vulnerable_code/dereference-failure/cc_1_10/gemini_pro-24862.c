//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a resume
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *education;
    char *skills;
    char *experience;
} resume;

// Define the function to parse a resume
resume *parse_resume(char *file_name) {
    // Open the file
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        return NULL;
    }

    // Allocate memory for the resume
    resume *resume = malloc(sizeof(resume));
    if (resume == NULL) {
        fclose(file);
        return NULL;
    }

    // Initialize the resume
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->address = NULL;
    resume->education = NULL;
    resume->skills = NULL;
    resume->experience = NULL;

    // Read the resume file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line
        if (strncmp(line, "Name:", 5) == 0) {
            // Parse the name
            resume->name = strdup(line + 5);
        } else if (strncmp(line, "Email:", 6) == 0) {
            // Parse the email
            resume->email = strdup(line + 6);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            // Parse the phone number
            resume->phone = strdup(line + 6);
        } else if (strncmp(line, "Address:", 8) == 0) {
            // Parse the address
            resume->address = strdup(line + 8);
        } else if (strncmp(line, "Education:", 10) == 0) {
            // Parse the education
            resume->education = strdup(line + 10);
        } else if (strncmp(line, "Skills:", 7) == 0) {
            // Parse the skills
            resume->skills = strdup(line + 7);
        } else if (strncmp(line, "Experience:", 11) == 0) {
            // Parse the experience
            resume->experience = strdup(line + 11);
        }
    }

    // Close the file
    fclose(file);

    // Return the resume
    return resume;
}

// Define the function to print a resume
void print_resume(resume *resume) {
    // Print the resume
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Education: %s\n", resume->education);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check if the user has provided a file name
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    // Parse the resume
    resume *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        printf("Error: Could not parse resume\n");
        return 1;
    }

    // Print the resume
    print_resume(resume);

    // Free the resume
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->education);
    free(resume->skills);
    free(resume->experience);
    free(resume);

    return 0;
}