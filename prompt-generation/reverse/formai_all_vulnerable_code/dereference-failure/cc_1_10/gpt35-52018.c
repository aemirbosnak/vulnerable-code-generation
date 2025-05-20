//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a resume
typedef struct {
    char* name;
    char* email;
    char* phone;
    char* experience;
    char* education;
} Resume;

// Define a function to parse a resume and return a Resume struct
Resume parseResume(char* resumeText) {
    Resume resume;

    // Use string manipulation to extract information from the resume
    char* nameToken = strtok(resumeText, "\n"); // First line is name
    char* emailToken = strtok(NULL, "\n"); // Second line is email
    char* phoneToken = strtok(NULL, "\n"); // Third line is phone number
    char* experienceToken = strtok(NULL, "\n"); // Fourth line is experience
    char* educationToken = strtok(NULL, "\n"); // Fifth line is education

    // Allocate memory for each field and copy the corresponding information
    resume.name = malloc(strlen(nameToken) + 1);
    strcpy(resume.name, nameToken);
    resume.email = malloc(strlen(emailToken) + 1);
    strcpy(resume.email, emailToken);
    resume.phone = malloc(strlen(phoneToken) + 1);
    strcpy(resume.phone, phoneToken);
    resume.experience = malloc(strlen(experienceToken) + 1);
    strcpy(resume.experience, experienceToken);
    resume.education = malloc(strlen(educationToken) + 1);
    strcpy(resume.education, educationToken);

    return resume;
}

int main() {
    // Define a sample resume text
    char* resumeText = "John Doe\njohndoe@email.com\n555-555-5555\nSoftware Developer\nBachelor's Degree";

    // Parse the resume text
    Resume resume = parseResume(resumeText);

    // Print the parsed information
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Experience: %s\n", resume.experience);
    printf("Education: %s\n", resume.education);

    // Free memory allocated for each field
    free(resume.name);
    free(resume.email);
    free(resume.phone);
    free(resume.experience);
    free(resume.education);

    return 0;
}