//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    struct Resume* next;
} Resume;

void parse_resume(char* resume_text)
{
    // Allocate memory for the resume structure
    Resume* resume = (Resume*)malloc(sizeof(Resume));

    // Extract the name, email, and phone number from the text
    char* name_start = strstr(resume_text, "Name:");
    char* name_end = strstr(name_start, "Email:");
    strcpy(resume->name, name_start + 5);

    char* email_start = strstr(name_end, "Email:");
    char* email_end = strstr(email_start, "Phone:");
    strcpy(resume->email, email_start + 6);

    char* phone_start = strstr(email_end, "Phone:");
    char* phone_end = strstr(phone_start, "Experience:");
    strcpy(resume->phone, phone_start + 6);

    // Extract the experience from the text
    char* experience_start = strstr(phone_end, "Experience:");
    char* experience_end = strstr(experience_start, "Skills:");
    strcpy(resume->experience, experience_start + 9);

    // Link the resume to the next resume (or set to NULL if it is the first resume)
    resume->next = NULL;

    // Print the resume information
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Experience: %s\n", resume->experience);
}

int main()
{
    char* resume_text = "Name: John Doe\nEmail: john.doe@example.com\nPhone: (123) 456-7890\nExperience: Software Engineer at ACME Corporation\nSkills: Java, C++, Python";

    parse_resume(resume_text);

    return 0;
}