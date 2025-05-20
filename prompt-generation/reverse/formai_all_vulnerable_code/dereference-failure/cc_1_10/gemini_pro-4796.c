//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
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
    char *education;
    char *experience;
} resume;

// Parse a resume from a file
resume *parse_resume(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Allocate memory for the resume
    resume *r = malloc(sizeof(resume));
    if (r == NULL) {
        fclose(fp);
        return NULL;
    }

    // Read the resume from the file
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Parse the line
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Set the corresponding field in the resume
        if (strcmp(key, "Name") == 0) {
            r->name = strdup(value);
        } else if (strcmp(key, "Email") == 0) {
            r->email = strdup(value);
        } else if (strcmp(key, "Phone") == 0) {
            r->phone = strdup(value);
        } else if (strcmp(key, "Address") == 0) {
            r->address = strdup(value);
        } else if (strcmp(key, "Skills") == 0) {
            r->skills = strdup(value);
        } else if (strcmp(key, "Education") == 0) {
            r->education = strdup(value);
        } else if (strcmp(key, "Experience") == 0) {
            r->experience = strdup(value);
        }
    }

    // Close the file
    fclose(fp);

    // Return the resume
    return r;
}

// Print the resume
void print_resume(resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Address: %s\n", r->address);
    printf("Skills: %s\n", r->skills);
    printf("Education: %s\n", r->education);
    printf("Experience: %s\n", r->experience);
}

// Free the memory allocated for the resume
void free_resume(resume *r) {
    free(r->name);
    free(r->email);
    free(r->phone);
    free(r->address);
    free(r->skills);
    free(r->education);
    free(r->experience);
    free(r);
}

// Main function
int main(int argc, char **argv) {
    // Check if a filename was provided
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Parse the resume
    resume *r = parse_resume(argv[1]);
    if (r == NULL) {
        printf("Error: could not parse resume\n");
        return 2;
    }

    // Print the resume
    print_resume(r);

    // Free the memory allocated for the resume
    free_resume(r);

    return 0;
}