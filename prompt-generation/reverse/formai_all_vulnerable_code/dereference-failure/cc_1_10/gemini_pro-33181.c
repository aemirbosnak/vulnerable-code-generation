//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a resume
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *education;
    char *experience;
} resume;

// Function to parse a resume from a file
resume *parse_resume(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    // Create a new resume
    resume *r = malloc(sizeof(resume));

    // Read the name
    char buffer[1024];
    fgets(buffer, sizeof(buffer), file);
    r->name = strdup(buffer);

    // Read the email
    fgets(buffer, sizeof(buffer), file);
    r->email = strdup(buffer);

    // Read the phone
    fgets(buffer, sizeof(buffer), file);
    r->phone = strdup(buffer);

    // Read the address
    fgets(buffer, sizeof(buffer), file);
    r->address = strdup(buffer);

    // Read the skills
    fgets(buffer, sizeof(buffer), file);
    r->skills = strdup(buffer);

    // Read the education
    fgets(buffer, sizeof(buffer), file);
    r->education = strdup(buffer);

    // Read the experience
    fgets(buffer, sizeof(buffer), file);
    r->experience = strdup(buffer);

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
    printf("Address: %s\n", r->address);
    printf("Skills: %s\n", r->skills);
    printf("Education: %s\n", r->education);
    printf("Experience: %s\n", r->experience);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Parse the resume
    resume *r = parse_resume(argv[1]);

    // Print the resume
    print_resume(r);

    // Free the resume
    free(r->name);
    free(r->email);
    free(r->phone);
    free(r->address);
    free(r->skills);
    free(r->education);
    free(r->experience);
    free(r);

    return 0;
}