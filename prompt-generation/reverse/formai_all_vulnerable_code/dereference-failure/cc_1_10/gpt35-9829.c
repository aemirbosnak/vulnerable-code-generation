//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for resume data
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char education[50];
    char experience[100];
} Resume;

// Define function to parse resume data from a string
Resume parseResume(char *resumeString) {
    Resume resume;
    char *token;
    
    // Parse name
    token = strtok(resumeString, ",");
    strcpy(resume.name, token);
    
    // Parse email
    token = strtok(NULL, ",");
    strcpy(resume.email, token);
    
    // Parse phone number
    token = strtok(NULL, ",");
    strcpy(resume.phone, token);
    
    // Parse education
    token = strtok(NULL, ",");
    strcpy(resume.education, token);
    
    // Parse experience
    token = strtok(NULL, ",");
    strcpy(resume.experience, token);
    
    return resume;
}

int main() {
    char resumeString[300];
    printf("Enter resume data in the following format:\n");
    printf("Name,Email,Phone,Education,Experience\n");
    fgets(resumeString, 300, stdin);
    Resume resume = parseResume(resumeString);
    
    // Display parsed resume data
    printf("\nResume Parsed Successfully:\n");
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
    
    return 0;
}