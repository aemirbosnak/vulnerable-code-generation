//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a struct to store the resume data
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} resume;

// Function to parse the resume from a file
resume *parse_resume(char *filename) {
    // Opening the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return NULL;
    }

    // Allocating memory for the resume struct
    resume *r = malloc(sizeof(resume));

    // Reading the resume data from the file
    char line[1024];

    // Reading the name
    fgets(line, 1024, file);
    r->name = strdup(line);

    // Reading the email
    fgets(line, 1024, file);
    r->email = strdup(line);

    // Reading the phone
    fgets(line, 1024, file);
    r->phone = strdup(line);

    // Reading the skills
    fgets(line, 1024, file);
    r->skills = strdup(line);

    // Reading the experience
    fgets(line, 1024, file);
    r->experience = strdup(line);

    // Reading the education
    fgets(line, 1024, file);
    r->education = strdup(line);

    // Closing the file
    fclose(file);

    // Returning the resume struct
    return r;
}

// Function to print the resume data
void print_resume(resume *r) {
    // Printing the name
    printf("Name: %s\n", r->name);

    // Printing the email
    printf("Email: %s\n", r->email);

    // Printing the phone
    printf("Phone: %s\n", r->phone);

    // Printing the skills
    printf("Skills: %s\n", r->skills);

    // Printing the experience
    printf("Experience: %s\n", r->experience);

    // Printing the education
    printf("Education: %s\n", r->education);
}

// Main function
int main() {
    // Parsing the resume from a file
    resume *r = parse_resume("resume.txt");

    // Printing the resume data
    print_resume(r);

    // Freeing the memory allocated for the resume struct
    free(r);

    return 0;
}