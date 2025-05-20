//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
} Resume;

// Function prototypes
Resume* createResume(char *name, char *email, char *phone, char *skills, char *experience);
void printResume(Resume *resume);
void freeResume(Resume *resume);

int main() {
    // Create a resume
    Resume *resume = createResume("John Doe", "johndoe@example.com", "123-456-7890", "C, Java, Python", "10 years of experience in software development");

    // Print the resume
    printResume(resume);

    // Free the resume
    freeResume(resume);

    return 0;
}

Resume* createResume(char *name, char *email, char *phone, char *skills, char *experience) {
    // Allocate memory for the resume
    Resume *resume = malloc(sizeof(Resume));

    // Copy the data into the resume
    resume->name = strdup(name);
    resume->email = strdup(email);
    resume->phone = strdup(phone);
    resume->skills = strdup(skills);
    resume->experience = strdup(experience);

    // Return the resume
    return resume;
}

void printResume(Resume *resume) {
    // Print the resume data
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
}

void freeResume(Resume *resume) {
    // Free the memory allocated for the resume
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->skills);
    free(resume->experience);
    free(resume);
}