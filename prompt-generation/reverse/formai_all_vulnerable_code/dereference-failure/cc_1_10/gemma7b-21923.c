//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to store resume data
typedef struct Resume {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    char summary[200];
} Resume;

// Function to parse a resume and store data in the structure
void parseResume(Resume *resume, char *resumeText) {
    // Extract the name, address, phone number, and email address
    char *nameStart = strstr(resumeText, "Name:");
    char *nameEnd = strstr(nameStart, "\n");
    strcpy(resume->name, nameStart + 5);

    char *addressStart = strstr(nameEnd, "Address:");
    char *addressEnd = strstr(addressStart, "\n");
    strcpy(resume->address, addressStart + 8);

    char *phoneStart = strstr(addressEnd, "Phone:");
    char *phoneEnd = strstr(phoneStart, "\n");
    strcpy(resume->phone, phoneStart + 6);

    char *emailStart = strstr(phoneEnd, "Email:");
    char *emailEnd = strstr(emailStart, "\n");
    strcpy(resume->email, emailStart + 6);

    // Extract the summary
    char *summaryStart = strstr(emailEnd, "Summary:");
    char *summaryEnd = strstr(summaryStart, "\n");
    strcpy(resume->summary, summaryStart + 8);
}

int main() {
    // Create a resume structure
    Resume resume;

    // Get the resume text from the user
    char resumeText[1000];
    printf("Enter the resume text:");
    scanf("%s", resumeText);

    // Parse the resume and store data in the structure
    parseResume(&resume, resumeText);

    // Print the resume data
    printf("Name: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Phone: %s\n", resume.phone);
    printf("Email: %s\n", resume.email);
    printf("Summary: %s\n", resume.summary);

    return 0;
}