//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char summary[MAX_NAME_LENGTH];
    struct Resume *next;
} Resume;

void parse_resume(char *resume_text)
{
    // Allocate memory for the resume node
    Resume *new_resume = (Resume *)malloc(sizeof(Resume));

    // Extract the name, email, and phone number from the text
    char *name = strstr(resume_text, "Name:");
    char *email = strstr(resume_text, "Email:");
    char *phone = strstr(resume_text, "Phone:");

    // Copy the extracted data into the resume node
    strncpy(new_resume->name, name + 5, MAX_NAME_LENGTH - 1);
    strncpy(new_resume->email, email + 6, MAX_NAME_LENGTH - 1);
    strncpy(new_resume->phone, phone + 7, MAX_NAME_LENGTH - 1);

    // Extract the summary from the text
    char *summary = strstr(resume_text, "Summary:");
    summary = summary + 8; // Skip the "Summary:" part

    // Copy the extracted summary into the resume node
    strncpy(new_resume->summary, summary, MAX_NAME_LENGTH - 1);

    // Link the new resume node to the next node
    new_resume->next = NULL;

    // Add the new resume node to the list
    // (This part is not included in the code snippet)
}

int main()
{
    char resume_text[] = "Name: John Doe\nEmail: john.doe@example.com\nPhone: 123-456-7890\nSummary: Experienced software engineer with a strong background in Java and C++.\n";

    parse_resume(resume_text);

    return 0;
}