//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct resume_entry {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    struct resume_entry* next;
} resume_entry;

resume_entry* parse_resume(char* resume_text) {
    resume_entry* head = NULL;
    char* name_start = NULL;
    char* email_start = NULL;
    char* phone_start = NULL;

    // Allocate memory for the first resume entry
    head = malloc(sizeof(resume_entry));

    // Extract the name, email, and phone number from the resume text
    name_start = strstr(resume_text, "Name:");
    email_start = strstr(resume_text, "Email:");
    phone_start = strstr(resume_text, "Phone:");

    // If the resume text contains the necessary information, fill the resume entry
    if (name_start && email_start && phone_start) {
        strcpy(head->name, name_start + 5);
        strcpy(head->email, email_start + 6);
        strcpy(head->phone, phone_start + 7);
    }

    // Link the first resume entry to the head of the linked list
    head->next = NULL;

    // Return the head of the linked list
    return head;
}

int main() {
    char* resume_text = "Name: John Doe\nEmail: john.doe@example.com\nPhone: (123) 456-7890";

    resume_entry* head = parse_resume(resume_text);

    // Print the name, email, and phone number of the first resume entry
    printf("Name: %s\n", head->name);
    printf("Email: %s\n", head->email);
    printf("Phone: %s\n", head->phone);

    return 0;
}