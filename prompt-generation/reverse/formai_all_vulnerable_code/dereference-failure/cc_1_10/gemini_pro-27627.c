//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the resume structure
typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} Resume;

// Create a new resume
Resume *createResume(char *name, char *email, char *phone, char *address, char *skills, char *experience, char *education) {
    Resume *resume = malloc(sizeof(Resume));
    resume->name = name;
    resume->email = email;
    resume->phone = phone;
    resume->address = address;
    resume->skills = skills;
    resume->experience = experience;
    resume->education = education;
    return resume;
}

// Free the memory allocated for a resume
void freeResume(Resume *resume) {
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);
    free(resume);
}

// Parse a resume from a file
Resume *parseResume(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    char *name = NULL;
    char *email = NULL;
    char *phone = NULL;
    char *address = NULL;
    char *skills = NULL;
    char *experience = NULL;
    char *education = NULL;

    while ((read = getline(&line, &len, file)) != -1) {
        if (strncmp(line, "Name:", 5) == 0) {
            name = strdup(line + 5);
        } else if (strncmp(line, "Email:", 6) == 0) {
            email = strdup(line + 6);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            phone = strdup(line + 6);
        } else if (strncmp(line, "Address:", 8) == 0) {
            address = strdup(line + 8);
        } else if (strncmp(line, "Skills:", 7) == 0) {
            skills = strdup(line + 7);
        } else if (strncmp(line, "Experience:", 11) == 0) {
            experience = strdup(line + 11);
        } else if (strncmp(line, "Education:", 10) == 0) {
            education = strdup(line + 10);
        }
    }

    fclose(file);
    free(line);

    return createResume(name, email, phone, address, skills, experience, education);
}

// Print a resume to the console
void printResume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

// Main function
int main() {
    // Create a new resume
    Resume *resume = createResume("John Doe", "johndoe@example.com", "555-555-5555", "123 Main Street", "C++, Java, Python", "Software Engineer at Google", "BS in Computer Science from Stanford University");

    // Print the resume to the console
    printResume(resume);

    // Free the memory allocated for the resume
    freeResume(resume);

    return 0;
}