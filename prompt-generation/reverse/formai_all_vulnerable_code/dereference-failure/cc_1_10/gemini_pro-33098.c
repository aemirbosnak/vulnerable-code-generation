//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the resume struct
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
} resume;

// Create a new resume
resume *new_resume() {
    resume *r = malloc(sizeof(resume));
    r->name = NULL;
    r->email = NULL;
    r->phone = NULL;
    r->skills = NULL;
    r->experience = NULL;
    return r;
}

// Free the memory allocated for a resume
void free_resume(resume *r) {
    free(r->name);
    free(r->email);
    free(r->phone);
    free(r->skills);
    free(r->experience);
    free(r);
}

// Parse a resume from a file
resume *parse_resume(char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        return NULL;
    }

    resume *r = new_resume();

    // Read the name
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, f);
    r->name = strdup(line);

    // Read the email
    getline(&line, &len, f);
    r->email = strdup(line);

    // Read the phone
    getline(&line, &len, f);
    r->phone = strdup(line);

    // Read the skills
    getline(&line, &len, f);
    r->skills = strdup(line);

    // Read the experience
    getline(&line, &len, f);
    r->experience = strdup(line);

    fclose(f);

    return r;
}

// Print a resume
void print_resume(resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);
}

// Main function
int main() {
    // Parse the resume from a file
    resume *r = parse_resume("resume.txt");

    // Print the resume
    print_resume(r);

    // Free the memory allocated for the resume
    free_resume(r);

    return 0;
}