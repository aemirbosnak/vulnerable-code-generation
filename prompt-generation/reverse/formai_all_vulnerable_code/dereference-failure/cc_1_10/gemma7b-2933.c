//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
} Resume;

int main()
{
    Resume resume;
    char resume_text[1024];

    // Get the resume text from the user
    printf("Enter the resume text: ");
    fgets(resume_text, 1024, stdin);

    // Parse the resume text and extract the resume information
    char* name_start = strstr(resume_text, "Name:");
    char* name_end = strstr(name_start, "Email:");

    char* email_start = strstr(name_end, "Email:");
    char* email_end = strstr(email_start, "Phone:");

    char* phone_start = strstr(email_end, "Phone:");
    char* phone_end = strstr(phone_start, "Address:");

    char* address_start = strstr(phone_end, "Address:");
    char* address_end = strstr(address_start, "End:");

    // Fill the resume structure with the extracted information
    strcpy(resume.name, name_start + 5);
    strcpy(resume.email, email_start + 6);
    strcpy(resume.phone, phone_start + 6);
    strcpy(resume.address, address_start + 7);

    // Print the resume information
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);

    return 0;
}