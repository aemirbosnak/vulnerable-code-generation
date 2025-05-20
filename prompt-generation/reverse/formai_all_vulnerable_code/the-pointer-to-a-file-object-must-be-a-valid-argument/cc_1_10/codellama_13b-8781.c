//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
// A unique C Resume Parsing System example program in a Dennis Ritchie style

#include <stdio.h>
#include <string.h>

// Define a structure to represent a resume
struct Resume {
    char name[50];
    char email[50];
    char phone[50];
    char education[50];
    char skills[50];
    char experience[50];
};

// Define a function to parse a resume from a file
void parseResume(struct Resume *resume, FILE *file) {
    // Read the resume file line by line
    while (fgets(resume->name, 50, file)) {
        // Skip the first line, which is the name
        if (strcmp(resume->name, "Name:") == 0) {
            continue;
        }

        // Read the rest of the resume fields
        fgets(resume->email, 50, file);
        fgets(resume->phone, 50, file);
        fgets(resume->education, 50, file);
        fgets(resume->skills, 50, file);
        fgets(resume->experience, 50, file);

        // Break out of the loop when the end of the file is reached
        if (feof(file)) {
            break;
        }
    }
}

// Define a function to print the parsed resume
void printResume(struct Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Education: %s\n", resume->education);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
}

int main() {
    // Create a new resume structure
    struct Resume resume;

    // Open the resume file
    FILE *file = fopen("resume.txt", "r");

    // Parse the resume file
    parseResume(&resume, file);

    // Print the parsed resume
    printResume(&resume);

    // Close the resume file
    fclose(file);

    return 0;
}