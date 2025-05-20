//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: careful
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
        perror("Error opening file");
        return NULL;
    }

    // Allocate memory for the resume
    resume *r = malloc(sizeof(resume));
    if (r == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    // Read the name
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, file);
    r->name = strdup(line);

    // Read the email
    getline(&line, &len, file);
    r->email = strdup(line);

    // Read the phone
    getline(&line, &len, file);
    r->phone = strdup(line);

    // Read the skills
    getline(&line, &len, file);
    r->skills = strdup(line);

    // Read the experience
    getline(&line, &len, file);
    r->experience = strdup(line);

    // Read the education
    getline(&line, &len, file);
    r->education = strdup(line);

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

// Function to free the memory allocated for a resume
void free_resume(resume *r) {
    free(r->name);
    free(r->email);
    free(r->phone);
    free(r->skills);
    free(r->experience);
    free(r->education);
    free(r);
}

// Main function
int main() {
    // Parse the resume
    resume *r = parse_resume("resume.txt");
    if (r == NULL) {
        return EXIT_FAILURE;
    }

    // Print the resume
    print_resume(r);

    // Free the memory allocated for the resume
    free_resume(r);

    return EXIT_SUCCESS;
}