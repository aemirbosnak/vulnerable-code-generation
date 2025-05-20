//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: random
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

// Create a new resume
resume *new_resume() {
    resume *r = malloc(sizeof(resume));
    r->name = NULL;
    r->email = NULL;
    r->phone = NULL;
    r->address = NULL;
    r->skills = NULL;
    r->education = NULL;
    r->experience = NULL;
    return r;
}

// Parse a resume from a file
resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    resume *r = new_resume();

    char line[1024];
    while (fgets(line, 1024, fp) != NULL) {
        // Parse the line
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        // Store the data in the resume struct
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

    fclose(fp);

    return r;
}

// Print a resume
void print_resume(resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Address: %s\n", r->address);
    printf("Skills: %s\n", r->skills);
    printf("Education: %s\n", r->education);
    printf("Experience: %s\n", r->experience);
}

// Free the memory allocated for a resume
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

int main() {
    // Parse the resume
    resume *r = parse_resume("resume.txt");

    // Print the resume
    print_resume(r);

    // Free the memory allocated for the resume
    free_resume(r);

    return 0;
}