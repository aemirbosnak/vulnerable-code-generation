//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A resume is a structured document, so we can represent it as a struct
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} resume;

// Parse a resume from a file
resume *parse_resume(FILE *file) {
    // Allocate memory for the resume
    resume *r = malloc(sizeof(resume));

    // Read the name
    char buffer[256];
    fgets(buffer, 256, file);
    r->name = strdup(buffer);

    // Read the email
    fgets(buffer, 256, file);
    r->email = strdup(buffer);

    // Read the phone
    fgets(buffer, 256, file);
    r->phone = strdup(buffer);

    // Read the address
    fgets(buffer, 256, file);
    r->address = strdup(buffer);

    // Read the skills
    fgets(buffer, 256, file);
    r->skills = strdup(buffer);

    // Read the experience
    fgets(buffer, 256, file);
    r->experience = strdup(buffer);

    // Read the education
    fgets(buffer, 256, file);
    r->education = strdup(buffer);

    // Return the resume
    return r;
}

// Print a resume
void print_resume(resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Address: %s\n", r->address);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);
    printf("Education: %s\n", r->education);
}

// Free the memory allocated for a resume
void free_resume(resume *r) {
    free(r->name);
    free(r->email);
    free(r->phone);
    free(r->address);
    free(r->skills);
    free(r->experience);
    free(r->education);
    free(r);
}

// Main function
int main() {
    // Open the resume file
    FILE *file = fopen("resume.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Parse the resume
    resume *r = parse_resume(file);

    // Print the resume
    print_resume(r);

    // Free the memory allocated for the resume
    free_resume(r);

    // Close the file
    fclose(file);

    return EXIT_SUCCESS;
}