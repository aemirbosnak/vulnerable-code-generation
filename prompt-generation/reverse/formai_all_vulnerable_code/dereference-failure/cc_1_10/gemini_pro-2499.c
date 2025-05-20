//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum length of a resume
#define MAX_RESUME_LENGTH 10000

// Define the data structure to store a resume
typedef struct {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
    char *awards;
} resume;

// Function to parse a resume from a string
resume *parse_resume(char *resume_text) {
    // Allocate memory for the resume
    resume *r = malloc(sizeof(resume));

    // Parse the name
    char *name = strtok(resume_text, "\n");
    r->name = malloc(strlen(name) + 1);
    strcpy(r->name, name);

    // Parse the email
    char *email = strtok(NULL, "\n");
    r->email = malloc(strlen(email) + 1);
    strcpy(r->email, email);

    // Parse the phone
    char *phone = strtok(NULL, "\n");
    r->phone = malloc(strlen(phone) + 1);
    strcpy(r->phone, phone);

    // Parse the address
    char *address = strtok(NULL, "\n");
    r->address = malloc(strlen(address) + 1);
    strcpy(r->address, address);

    // Parse the skills
    char *skills = strtok(NULL, "\n");
    r->skills = malloc(strlen(skills) + 1);
    strcpy(r->skills, skills);

    // Parse the experience
    char *experience = strtok(NULL, "\n");
    r->experience = malloc(strlen(experience) + 1);
    strcpy(r->experience, experience);

    // Parse the education
    char *education = strtok(NULL, "\n");
    r->education = malloc(strlen(education) + 1);
    strcpy(r->education, education);

    // Parse the awards
    char *awards = strtok(NULL, "\n");
    r->awards = malloc(strlen(awards) + 1);
    strcpy(r->awards, awards);

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
    printf("Experience: %s\n", r->experience);
    printf("Education: %s\n", r->education);
    printf("Awards: %s\n", r->awards);
}

// Main function
int main() {
    // Get the resume text from the user
    char resume_text[MAX_RESUME_LENGTH];
    printf("Enter the resume text:\n");
    fgets(resume_text, MAX_RESUME_LENGTH, stdin);

    // Parse the resume
    resume *r = parse_resume(resume_text);

    // Print the resume
    print_resume(r);

    // Free the memory allocated for the resume
    free(r->name);
    free(r->email);
    free(r->phone);
    free(r->address);
    free(r->skills);
    free(r->experience);
    free(r->education);
    free(r->awards);
    free(r);

    return 0;
}