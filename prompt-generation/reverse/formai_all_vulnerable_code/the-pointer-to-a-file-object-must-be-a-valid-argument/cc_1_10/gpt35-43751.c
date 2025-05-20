//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's define a structure to hold resume information
typedef struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[50];
    char experience[100];
} Resume;

// Function to parse a resume from a file
Resume parseResume(char* filename) {
    // Open the file for reading
    FILE* resumeFile = fopen(filename, "r");

    // Allocate memory for the resume
    Resume r;
    memset(&r, 0, sizeof(Resume));

    // Read each line of the file and extract information
    char line[256];
    while (fgets(line, sizeof(line), resumeFile)) {
        if (strstr(line, "Name:")) {
            // Extract the name from the line and copy it to the resume
            strncpy(r.name, line + 6, 50);
        } else if (strstr(line, "Email:")) {
            // Extract the email from the line and copy it to the resume
            strncpy(r.email, line + 7, 50);
        } else if (strstr(line, "Phone:")) {
            // Extract the phone number from the line and copy it to the resume
            strncpy(r.phone, line + 7, 20);
        } else if (strstr(line, "Education:")) {
            // Extract the education information from the line and copy it to the resume
            strncpy(r.education, line + 11, 50);
        } else if (strstr(line, "Experience:")) {
            // Extract the experience information from the line and copy it to the resume
            strncpy(r.experience, line + 12, 100);
        }
    }

    // Close the file
    fclose(resumeFile);

    // Return the parsed resume
    return r;
}

// Main function
int main() {
    Resume r = parseResume("resume.txt");

    // Print out the information in the resume
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Education: %s\n", r.education);
    printf("Experience: %s\n", r.experience);

    return 0;
}