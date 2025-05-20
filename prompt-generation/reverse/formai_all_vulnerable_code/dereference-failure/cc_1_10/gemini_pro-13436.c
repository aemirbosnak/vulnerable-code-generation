//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
} resume_t;

// Create a new resume
resume_t *new_resume(char *name, char *email, char *phone, char *skills, char *experience) {
    resume_t *r = malloc(sizeof(resume_t));
    r->name = strdup(name);
    r->email = strdup(email);
    r->phone = strdup(phone);
    r->skills = strdup(skills);
    r->experience = strdup(experience);
    return r;
}

// Free a resume
void free_resume(resume_t *r) {
    free(r->name);
    free(r->email);
    free(r->phone);
    free(r->skills);
    free(r->experience);
    free(r);
}

// Print a resume
void print_resume(resume_t *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);
}

// Parse a resume from a string
resume_t *parse_resume(char *str) {
    char *name = NULL;
    char *email = NULL;
    char *phone = NULL;
    char *skills = NULL;
    char *experience = NULL;

    char *start = str;
    char *end = NULL;

    // Parse the name
    end = strstr(start, "\n");
    if (end != NULL) {
        name = strndup(start, end - start);
        start = end + 1;
    }

    // Parse the email
    end = strstr(start, "\n");
    if (end != NULL) {
        email = strndup(start, end - start);
        start = end + 1;
    }

    // Parse the phone
    end = strstr(start, "\n");
    if (end != NULL) {
        phone = strndup(start, end - start);
        start = end + 1;
    }

    // Parse the skills
    end = strstr(start, "\n");
    if (end != NULL) {
        skills = strndup(start, end - start);
        start = end + 1;
    }

    // Parse the experience
    experience = strdup(start);

    // Create the resume
    return new_resume(name, email, phone, skills, experience);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <resume.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the resume from a file
    char *str = NULL;
    size_t len = 0;
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    if (getline(&str, &len, f) == -1) {
        perror("Error reading file");
        return EXIT_FAILURE;
    }
    fclose(f);

    // Parse the resume
    resume_t *r = parse_resume(str);

    // Print the resume
    print_resume(r);

    // Free the resume
    free_resume(r);

    return EXIT_SUCCESS;
}