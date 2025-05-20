//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining the structure of the Resume
struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char skills[200];
    char education[100];
    char experience[200];
} ;

// Function to display the Resume
void displayResume(struct Resume r) {
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Address: %s\n", r.address);
    printf("Skills: %s\n", r.skills);
    printf("Education: %s\n", r.education);
    printf("Experience: %s\n", r.experience);
}

// Function to parse the Resume using a string
void parseResume(char *resumeStr, struct Resume *r) {
    char *token;

    // Parsing the name
    token = strtok(resumeStr, "\n");
    strcpy(r->name, token);

    // Parsing the email
    token = strtok(NULL, "\n");
    strcpy(r->email, token);

    // Parsing the phone number
    token = strtok(NULL, "\n");
    strcpy(r->phone, token);

    // Parsing the address
    token = strtok(NULL, "\n");
    strcpy(r->address, token);

    // Parsing the skills
    token = strtok(NULL, "\n");
    strcpy(r->skills, token);

    // Parsing the education
    token = strtok(NULL, "\n");
    strcpy(r->education, token);

    // Parsing the experience
    token = strtok(NULL, "\n");
    strcpy(r->experience, token);
}

// Main function 
int main() {
    char resumeString[1000]; 
    printf("Enter the Resume:\n");
    fgets(resumeString, sizeof(resumeString), stdin);

    struct Resume r;
    parseResume(resumeString, &r);
    printf("\nParsed Resume:\n");
    displayResume(r);

    return 0; 
}