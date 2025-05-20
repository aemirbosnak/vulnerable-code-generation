//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: modular
#include <stdio.h>
#include <string.h>

// Define a structure to store resume data
typedef struct resume_data {
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char summary[200];
} resume_data;

// Function to parse a resume
void parse_resume(char *resume_text) {
    // Create a pointer to a resume data structure
    resume_data *resume = (resume_data *)malloc(sizeof(resume_data));

    // Extract the name, email, phone number, and address from the resume text
    char *name_start = strstr(resume_text, "Name:");
    char *name_end = strstr(name_start, "\n");
    strcpy(resume->name, name_start + 5);

    char *email_start = strstr(resume_text, "Email:");
    char *email_end = strstr(email_start, "\n");
    strcpy(resume->email, email_start + 5);

    char *phone_start = strstr(resume_text, "Phone:");
    char *phone_end = strstr(phone_start, "\n");
    strcpy(resume->phone, phone_start + 5);

    char *address_start = strstr(resume_text, "Address:");
    char *address_end = strstr(address_start, "\n");
    strcpy(resume->address, address_start + 5);

    // Extract the summary from the resume text
    char *summary_start = strstr(resume_text, "Summary:");
    char *summary_end = strstr(summary_start, "\n\n");
    strcpy(resume->summary, summary_start + 5);

    // Print the resume data
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Summary: %s\n", resume->summary);

    // Free the memory allocated for the resume data structure
    free(resume);
}

int main() {
    // Parse a resume
    parse_resume("resume.txt");

    return 0;
}