//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to store resume data
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} resume;

// Function to parse a resume file
resume *parse_resume(char *filename) {
    // Open the resume file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening resume file\n");
        return NULL;
    }

    // Allocate memory for the resume struct
    resume *r = malloc(sizeof(resume));

    // Parse the resume file
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Parse the name
        if (strstr(line, "Name:")) {
            r->name = strdup(line + 6);
        }

        // Parse the email
        if (strstr(line, "Email:")) {
            r->email = strdup(line + 7);
        }

        // Parse the phone number
        if (strstr(line, "Phone:")) {
            r->phone = strdup(line + 7);
        }

        // Parse the skills
        if (strstr(line, "Skills:")) {
            r->skills = strdup(line + 8);
        }

        // Parse the experience
        if (strstr(line, "Experience:")) {
            r->experience = strdup(line + 12);
        }

        // Parse the education
        if (strstr(line, "Education:")) {
            r->education = strdup(line + 11);
        }
    }

    // Close the resume file
    fclose(fp);

    // Return the resume struct
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

// Main function
int main() {
    // Parse the resume file
    resume *r = parse_resume("resume.txt");

    // Print the resume
    print_resume(r);

    // Free the memory allocated for the resume struct
    free(r);

    return 0;
}