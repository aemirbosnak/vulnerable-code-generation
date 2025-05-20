//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Romeo and Juliet-style C Resume Parsing System

// Define the structure of a resume
typedef struct {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *education;
    char *experience;
} Resume;

// Function to parse a resume file
Resume *parse_resume(char *filename) {
    // Allocate memory for the resume struct
    Resume *resume = malloc(sizeof(Resume));

    // Read the resume file into a buffer
    FILE *file = fopen(filename, "r");
    char *buffer = NULL;
    size_t bufsize = 0;
    getline(&buffer, &bufsize, file);

    // Parse the resume file line by line
    while (getline(&buffer, &bufsize, file) != -1) {
        // Check if the line starts with a specific keyword
        if (strstr(buffer, "Name:") != NULL) {
            // Parse the name
            resume->name = malloc(strlen(buffer) - 5);
            strncpy(resume->name, buffer + 5, strlen(buffer) - 6);
        } else if (strstr(buffer, "Email:") != NULL) {
            // Parse the email
            resume->email = malloc(strlen(buffer) - 6);
            strncpy(resume->email, buffer + 6, strlen(buffer) - 7);
        } else if (strstr(buffer, "Phone:") != NULL) {
            // Parse the phone number
            resume->phone = malloc(strlen(buffer) - 6);
            strncpy(resume->phone, buffer + 6, strlen(buffer) - 7);
        } else if (strstr(buffer, "Address:") != NULL) {
            // Parse the address
            resume->address = malloc(strlen(buffer) - 8);
            strncpy(resume->address, buffer + 8, strlen(buffer) - 9);
        } else if (strstr(buffer, "Skills:") != NULL) {
            // Parse the skills
            resume->skills = malloc(strlen(buffer) - 7);
            strncpy(resume->skills, buffer + 7, strlen(buffer) - 8);
        } else if (strstr(buffer, "Education:") != NULL) {
            // Parse the education
            resume->education = malloc(strlen(buffer) - 10);
            strncpy(resume->education, buffer + 10, strlen(buffer) - 11);
        } else if (strstr(buffer, "Experience:") != NULL) {
            // Parse the experience
            resume->experience = malloc(strlen(buffer) - 11);
            strncpy(resume->experience, buffer + 11, strlen(buffer) - 12);
        }
    }

    // Close the resume file
    fclose(file);

    // Return the resume struct
    return resume;
}

// Function to print a resume
void print_resume(Resume *resume) {
    // Print the resume information
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

// Main function
int main() {
    // Parse the resume file
    Resume *resume = parse_resume("resume.txt");

    // Print the resume
    print_resume(resume);

    // Free the memory allocated for the resume struct
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->skills);
    free(resume->education);
    free(resume->experience);
    free(resume);

    return 0;
}