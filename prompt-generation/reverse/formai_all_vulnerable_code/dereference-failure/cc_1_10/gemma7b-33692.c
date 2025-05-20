//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: high level of detail
#include <stdio.h>
#include <string.h>

// Define a structure to store resume data
typedef struct resume {
    char name[20];
    char email[20];
    char phone[20];
    char address[100];
    char summary[200];
} resume_t;

// Function to parse a resume
resume_t parse_resume(char *resume_text) {
    // Allocate memory for the resume structure
    resume_t *resume = malloc(sizeof(resume_t));

    // Extract the name, email, phone number, and address from the resume text
    char *name_start = strstr(resume_text, "Name:");
    char *name_end = strstr(name_start, "\n");
    strcpy(resume->name, name_start + 5);

    char *email_start = strstr(name_end, "Email:");
    char *email_end = strstr(email_start, "\n");
    strcpy(resume->email, email_start + 6);

    char *phone_start = strstr(email_end, "Phone:");
    char *phone_end = strstr(phone_start, "\n");
    strcpy(resume->phone, phone_start + 6);

    char *address_start = strstr(phone_end, "Address:");
    char *address_end = strstr(address_start, "\n");
    strcpy(resume->address, address_start + 8);

    // Extract the summary from the resume text
    char *summary_start = strstr(address_end, "Summary:");
    char *summary_end = strstr(summary_start, "\n");
    strcpy(resume->summary, summary_start + 8);

    return *resume;
}

int main() {
    // Example resume text
    char *resume_text = "Name: John Doe\nEmail: john.doe@example.com\nPhone: (123) 456-7890\nAddress: 123 Main St., New York, NY 10001\nSummary: Highly motivated and experienced software engineer with a strong background in Java and C++.";

    // Parse the resume
    resume_t resume = parse_resume(resume_text);

    // Print the resume data
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Summary: %s\n", resume.summary);

    return 0;
}