//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Resume structure
typedef struct {
    char name[50];
    char email[50];
    char phone[15];
    char education[50];
    char experience[50];
} Resume;

// Function to parse and print Resume data
void parseResume(char* data) {
    Resume resume;
    char* token = strtok(data, ",");
    
    // Parse name
    strcpy(resume.name, token);
    token = strtok(NULL, ",");
    
    // Parse email
    strcpy(resume.email, token);
    token = strtok(NULL, ",");
    
    // Parse phone
    strcpy(resume.phone, token);
    token = strtok(NULL, ",");
    
    // Parse education
    strcpy(resume.education, token);
    token = strtok(NULL, ",");
    
    // Parse experience
    strcpy(resume.experience, token);
    
    // Print Resume data
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
}

int main() {
    // Example Resume data
    char* data = "John Doe,johndoe@email.com,555-555-5555,BSc Computer Science,3 years";
    
    // Parse and print Resume data
    parseResume(data);
    
    return 0;
}