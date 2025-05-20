//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold a resume information
struct Resume {
    char* name;
    char* email;
    char* phone;
    char* address;
    char* experience;
    char* education;
    char* skills;
};

// Function to parse a resume from a file
struct Resume* parseResume(char* filename) {
    // Open the file for reading
    FILE* file = fopen(filename, "r");

    // Create a new Resume struct to hold the parsed data
    struct Resume* resume = malloc(sizeof(struct Resume));

    // Read the file line by line
    char line[1024];
    while (fgets(line, 1024, file) != NULL) {
        // Check if the line starts with "Name"
        if (strncmp(line, "Name:", 5) == 0) {
            // Extract the name from the line
            resume->name = strdup(line + 6);
        }
        // Check if the line starts with "Email"
        else if (strncmp(line, "Email:", 6) == 0) {
            // Extract the email from the line
            resume->email = strdup(line + 7);
        }
        // Check if the line starts with "Phone"
        else if (strncmp(line, "Phone:", 6) == 0) {
            // Extract the phone number from the line
            resume->phone = strdup(line + 7);
        }
        // Check if the line starts with "Address"
        else if (strncmp(line, "Address:", 8) == 0) {
            // Extract the address from the line
            resume->address = strdup(line + 9);
        }
        // Check if the line starts with "Experience"
        else if (strncmp(line, "Experience:", 10) == 0) {
            // Extract the experience from the line
            resume->experience = strdup(line + 11);
        }
        // Check if the line starts with "Education"
        else if (strncmp(line, "Education:", 10) == 0) {
            // Extract the education from the line
            resume->education = strdup(line + 11);
        }
        // Check if the line starts with "Skills"
        else if (strncmp(line, "Skills:", 7) == 0) {
            // Extract the skills from the line
            resume->skills = strdup(line + 8);
        }
    }

    // Close the file
    fclose(file);

    // Return the parsed resume
    return resume;
}

// Function to print the resume information
void printResume(struct Resume* resume) {
    // Print the name
    printf("Name: %s\n", resume->name);
    // Print the email
    printf("Email: %s\n", resume->email);
    // Print the phone number
    printf("Phone: %s\n", resume->phone);
    // Print the address
    printf("Address: %s\n", resume->address);
    // Print the experience
    printf("Experience: %s\n", resume->experience);
    // Print the education
    printf("Education: %s\n", resume->education);
    // Print the skills
    printf("Skills: %s\n", resume->skills);
}

int main() {
    // Parse the resume from the file
    struct Resume* resume = parseResume("resume.txt");

    // Print the resume information
    printResume(resume);

    // Free the memory allocated for the resume
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->experience);
    free(resume->education);
    free(resume->skills);
    free(resume);

    return 0;
}