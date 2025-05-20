//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store resume data
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} resume;

// Function to parse a resume from a file
resume *parse_resume(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the resume
    resume *r = malloc(sizeof(resume));

    // Read the name
    char line[256];
    fgets(line, 256, file);
    r->name = malloc(strlen(line) + 1);
    strcpy(r->name, line);

    // Read the email
    fgets(line, 256, file);
    r->email = malloc(strlen(line) + 1);
    strcpy(r->email, line);

    // Read the phone number
    fgets(line, 256, file);
    r->phone = malloc(strlen(line) + 1);
    strcpy(r->phone, line);

    // Read the skills
    fgets(line, 256, file);
    r->skills = malloc(strlen(line) + 1);
    strcpy(r->skills, line);

    // Read the experience
    fgets(line, 256, file);
    r->experience = malloc(strlen(line) + 1);
    strcpy(r->experience, line);

    // Read the education
    fgets(line, 256, file);
    r->education = malloc(strlen(line) + 1);
    strcpy(r->education, line);

    // Close the file
    fclose(file);

    // Return the resume
    return r;
}

// Function to print a resume
void print_resume(resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);
    printf("Education: %s\n", r->education);
}

// Main function
int main() {
    // Parse a resume from a file
    resume *r = parse_resume("resume.txt");

    // Print the resume
    print_resume(r);

    // Free the memory allocated for the resume
    free(r->name);
    free(r->email);
    free(r->phone);
    free(r->skills);
    free(r->experience);
    free(r->education);
    free(r);

    return 0;
}