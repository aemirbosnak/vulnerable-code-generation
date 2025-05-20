//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store resume information
typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} Resume;

// Function to parse a resume file
Resume *parse_resume(char *filename) {
    // Open the resume file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }

    // Allocate memory for the resume
    Resume *resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        printf("Error allocating memory for resume\n");
        return NULL;
    }

    // Initialize the resume fields
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->skills = NULL;
    resume->experience = NULL;
    resume->education = NULL;

    // Parse the resume file
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the name
        if (strstr(line, "Name: ")) {
            resume->name = strdup(line + 6);
        }

        // Parse the email
        else if (strstr(line, "Email: ")) {
            resume->email = strdup(line + 7);
        }

        // Parse the phone
        else if (strstr(line, "Phone: ")) {
            resume->phone = strdup(line + 7);
        }

        // Parse the skills
        else if (strstr(line, "Skills: ")) {
            resume->skills = strdup(line + 8);
        }

        // Parse the experience
        else if (strstr(line, "Experience: ")) {
            resume->experience = strdup(line + 12);
        }

        // Parse the education
        else if (strstr(line, "Education: ")) {
            resume->education = strdup(line + 11);
        }
    }

    // Close the resume file
    fclose(file);

    // Return the resume
    return resume;
}

// Function to print a resume
void print_resume(Resume *resume) {
    // Print the name
    printf("Name: %s\n", resume->name);

    // Print the email
    printf("Email: %s\n", resume->email);

    // Print the phone
    printf("Phone: %s\n", resume->phone);

    // Print the skills
    printf("Skills: %s\n", resume->skills);

    // Print the experience
    printf("Experience: %s\n", resume->experience);

    // Print the education
    printf("Education: %s\n", resume->education);
}

// Main function
int main() {
    // Parse a resume file
    Resume *resume = parse_resume("resume.txt");
    if (resume == NULL) {
        return 1;
    }

    // Print the resume
    print_resume(resume);

    // Free the memory allocated for the resume
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);
    free(resume);

    return 0;
}