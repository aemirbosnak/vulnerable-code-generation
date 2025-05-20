//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to represent a resume
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
    char *awards;
} resume;

// Function to parse a resume from a file
resume *parse_resume(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the resume
    resume *r = malloc(sizeof(resume));
    if (r == NULL) {
        fprintf(stderr, "Error allocating memory for resume\n");
        return NULL;
    }

    // Read the resume from the file
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line
        if (strstr(line, "Name:")) {
            r->name = strdup(line + 6);
        } else if (strstr(line, "Email:")) {
            r->email = strdup(line + 7);
        } else if (strstr(line, "Phone:")) {
            r->phone = strdup(line + 7);
        } else if (strstr(line, "Skills:")) {
            r->skills = strdup(line + 8);
        } else if (strstr(line, "Experience:")) {
            r->experience = strdup(line + 11);
        } else if (strstr(line, "Education:")) {
            r->education = strdup(line + 10);
        } else if (strstr(line, "Awards:")) {
            r->awards = strdup(line + 7);
        }
    }

    // Close the file
    fclose(file);

    // Return the resume
    return r;
}

// Function to print a resume
void print_resume(resume *r) {
    // Print the resume
    printf("Name: %s", r->name);
    printf("Email: %s", r->email);
    printf("Phone: %s", r->phone);
    printf("Skills: %s", r->skills);
    printf("Experience: %s", r->experience);
    printf("Education: %s", r->education);
    printf("Awards: %s", r->awards);
}

// Main function
int main(int argc, char *argv[]) {
    // Check the command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the resume
    resume *r = parse_resume(argv[1]);
    if (r == NULL) {
        fprintf(stderr, "Error parsing resume\n");
        return EXIT_FAILURE;
    }

    // Print the resume
    print_resume(r);

    // Free the memory allocated for the resume
    free(r->name);
    free(r->email);
    free(r->phone);
    free(r->skills);
    free(r->experience);
    free(r->education);
    free(r->awards);
    free(r);

    return EXIT_SUCCESS;
}