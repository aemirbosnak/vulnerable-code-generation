//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing resume data
typedef struct {
    char* name;
    char* email;
    char* phone;
    char* education;
    char* skills;
    char* experience;
} Resume;

// Function to parse resume data from a file
Resume* parseResume(char* fileName) {
    // Allocate memory for the resume struct
    Resume* resume = (Resume*) malloc(sizeof(Resume));
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->education = NULL;
    resume->skills = NULL;
    resume->experience = NULL;

    // Open the file
    FILE* file = fopen(fileName, "r");
    
    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error: unable to open file %s\n", fileName);
        return NULL;
    }
    
    // Parse each line of the file
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character at the end of the line
        line[strcspn(line, "\n")] = 0;

        // Check for name field
        if (strstr(line, "Name:") != NULL) {
            resume->name = strdup(line + 5);
        }
        // Check for email field
        else if (strstr(line, "Email:") != NULL) {
            resume->email = strdup(line + 6);
        }
        // Check for phone field
        else if (strstr(line, "Phone:") != NULL) {
            resume->phone = strdup(line + 6);
        }
        // Check for education field
        else if (strstr(line, "Education:") != NULL) {
            resume->education = strdup(line + 10);
        }
        // Check for skills field
        else if (strstr(line, "Skills:") != NULL) {
            resume->skills = strdup(line + 7);
        }
        // Check for experience field
        else if (strstr(line, "Experience:") != NULL) {
            resume->experience = strdup(line + 11);
        }
    }

    // Close the file
    fclose(file);

    // Return the parsed resume data
    return resume;
}

// Function to print resume data
void printResume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Education: %s\n", resume->education);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
}

int main(int argc, char* argv[]) {
    // Check for correct number of command line arguments
    if (argc != 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    // Parse the resume data
    Resume* resume = parseResume(argv[1]);

    // Print the resume data
    printResume(resume);

    // Free allocated memory
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->education);
    free(resume->skills);
    free(resume->experience);
    free(resume);

    return 0;
}