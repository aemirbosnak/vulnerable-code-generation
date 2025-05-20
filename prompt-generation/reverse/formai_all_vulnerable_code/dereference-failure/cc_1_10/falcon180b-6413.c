//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the resume data
typedef struct {
    char name[50];
    char email[50];
    char phone[15];
    char address[100];
    char education[100];
    char experience[200];
} Resume;

// Function to parse the resume data
Resume parseResume(char* data) {
    Resume resume;
    char* token = strtok(data, ",");

    // Parse the name
    strcpy(resume.name, token);
    token = strtok(NULL, ",");

    // Parse the email
    strcpy(resume.email, token);
    token = strtok(NULL, ",");

    // Parse the phone number
    strcpy(resume.phone, token);
    token = strtok(NULL, ",");

    // Parse the address
    strcpy(resume.address, token);
    token = strtok(NULL, ",");

    // Parse the education
    strcpy(resume.education, token);
    token = strtok(NULL, ",");

    // Parse the experience
    strcpy(resume.experience, token);

    return resume;
}

// Function to print the resume data
void printResume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
}

// Main function
int main() {
    char resumeData[500];

    // Prompt the user to enter the resume data
    printf("Enter the resume data: ");
    fgets(resumeData, sizeof(resumeData), stdin);

    // Parse the resume data
    Resume resume = parseResume(resumeData);

    // Print the resume data
    printResume(resume);

    return 0;
}