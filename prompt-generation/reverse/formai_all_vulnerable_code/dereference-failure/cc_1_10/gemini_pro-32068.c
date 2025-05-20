//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a structure to represent a resume
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} resume;

// Create a function to parse a resume from a file
resume *parse_resume(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Create a new resume struct
    resume *r = malloc(sizeof(resume));

    // Read the name from the file
    char *line = malloc(1024);
    fgets(line, 1024, file);
    r->name = strdup(line);

    // Read the email from the file
    fgets(line, 1024, file);
    r->email = strdup(line);

    // Read the phone number from the file
    fgets(line, 1024, file);
    r->phone = strdup(line);

    // Read the address from the file
    fgets(line, 1024, file);
    r->address = strdup(line);

    // Read the skills from the file
    fgets(line, 1024, file);
    r->skills = strdup(line);

    // Read the experience from the file
    fgets(line, 1024, file);
    r->experience = strdup(line);

    // Read the education from the file
    fgets(line, 1024, file);
    r->education = strdup(line);

    // Close the file
    fclose(file);

    // Return the resume struct
    return r;
}

// Create a function to print a resume
void print_resume(resume *r) {
    // Print the name
    printf("Name: %s\n", r->name);

    // Print the email
    printf("Email: %s\n", r->email);

    // Print the phone number
    printf("Phone: %s\n", r->phone);

    // Print the address
    printf("Address: %s\n", r->address);

    // Print the skills
    printf("Skills: %s\n", r->skills);

    // Print the experience
    printf("Experience: %s\n", r->experience);

    // Print the education
    printf("Education: %s\n", r->education);
}

// Create a function to free the memory allocated for a resume
void free_resume(resume *r) {
    // Free the name
    free(r->name);

    // Free the email
    free(r->email);

    // Free the phone number
    free(r->phone);

    // Free the address
    free(r->address);

    // Free the skills
    free(r->skills);

    // Free the experience
    free(r->experience);

    // Free the education
    free(r->education);

    // Free the resume struct
    free(r);
}

// Create a function to test the resume parsing system
int main() {
    // Parse a resume from a file
    resume *r = parse_resume("resume.txt");

    // Print the resume
    print_resume(r);

    // Free the memory allocated for the resume
    free_resume(r);

    return 0;
}