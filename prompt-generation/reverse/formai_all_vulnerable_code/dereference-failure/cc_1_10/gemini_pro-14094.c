//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold resume data
typedef struct resume {
    char name[100];
    char email[100];
    char phone[100];
    char skills[1000];
    char education[1000];
    char experience[1000];
} resume;

// Function to parse a resume from a file
resume parse_resume(char *filename) {
    // Open the resume file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Read the resume data into a string
    char *data = NULL;
    size_t len = 0;
    getline(&data, &len, fp);

    // Close the resume file
    fclose(fp);

    // Parse the resume data
    resume r;
    memset(&r, 0, sizeof(resume));

    // Get the name
    char *name = strtok(data, ",");
    strcpy(r.name, name);

    // Get the email
    char *email = strtok(NULL, ",");
    strcpy(r.email, email);

    // Get the phone
    char *phone = strtok(NULL, ",");
    strcpy(r.phone, phone);

    // Get the skills
    char *skills = strtok(NULL, ",");
    strcpy(r.skills, skills);

    // Get the education
    char *education = strtok(NULL, ",");
    strcpy(r.education, education);

    // Get the experience
    char *experience = strtok(NULL, ",");
    strcpy(r.experience, experience);

    // Return the resume
    return r;
}

// Function to print a resume
void print_resume(resume r) {
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Skills: %s\n", r.skills);
    printf("Education: %s\n", r.education);
    printf("Experience: %s\n", r.experience);
}

// Main function
int main() {
    // Parse the resume
    resume r = parse_resume("resume.txt");

    // Print the resume
    print_resume(r);

    return 0;
}