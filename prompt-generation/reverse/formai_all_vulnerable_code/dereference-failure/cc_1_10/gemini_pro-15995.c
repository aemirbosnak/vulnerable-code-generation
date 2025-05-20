//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the resume structure
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} resume;

// Load the resume from a file
resume *load_resume(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Allocate memory for the resume
    resume *r = malloc(sizeof(resume));

    // Read the resume data from the file
    fscanf(file, "%s", r->name);
    fscanf(file, "%s", r->email);
    fscanf(file, "%s", r->phone);
    fscanf(file, "%s", r->address);
    fscanf(file, "%s", r->skills);
    fscanf(file, "%s", r->experience);
    fscanf(file, "%s", r->education);

    // Close the file
    fclose(file);

    // Return the resume
    return r;
}

// Free the memory allocated for the resume
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

// Print the resume
void print_resume(resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Address: %s\n", r->address);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);
    printf("Education: %s\n", r->education);
}

// Main function
int main() {
    // Load the resume from a file
    resume *r = load_resume("resume.txt");

    // Print the resume
    print_resume(r);

    // Free the memory allocated for the resume
    free_resume(r);

    return 0;
}