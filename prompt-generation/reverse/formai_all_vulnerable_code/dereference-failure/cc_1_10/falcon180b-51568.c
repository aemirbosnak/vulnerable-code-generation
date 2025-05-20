//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

typedef struct {
    char name[MAX_STRING_LENGTH];
    char address[MAX_STRING_LENGTH];
    char phone[MAX_STRING_LENGTH];
    char email[MAX_STRING_LENGTH];
} contact;

typedef struct {
    char first_name[MAX_STRING_LENGTH];
    char last_name[MAX_STRING_LENGTH];
    contact contact_info;
} resume;

void print_contact_info(contact c) {
    printf("Name: %s\n", c.name);
    printf("Address: %s\n", c.address);
    printf("Phone: %s\n", c.phone);
    printf("Email: %s\n", c.email);
}

void print_resume_info(resume r) {
    printf("First Name: %s\n", r.first_name);
    printf("Last Name: %s\n", r.last_name);
    print_contact_info(r.contact_info);
}

int main() {
    resume r;
    char line[MAX_STRING_LENGTH];
    char *token;

    // Read in the first line of the resume
    printf("Enter the first line of the resume (in format \"First Name Last Name\")\n");
    fgets(line, MAX_STRING_LENGTH, stdin);
    token = strtok(line, " ");
    strcpy(r.first_name, token);
    token = strtok(NULL, " ");
    strcpy(r.last_name, token);

    // Read in the rest of the resume
    printf("Enter the rest of the resume:\n");
    fgets(line, MAX_STRING_LENGTH, stdin);
    token = strtok(line, "\n");
    while (token!= NULL) {
        if (strstr(token, "Name:")!= NULL) {
            strcpy(r.contact_info.name, strtok(token, ":"));
        } else if (strstr(token, "Address:")!= NULL) {
            strcpy(r.contact_info.address, strtok(token, ":"));
        } else if (strstr(token, "Phone:")!= NULL) {
            strcpy(r.contact_info.phone, strtok(token, ":"));
        } else if (strstr(token, "Email:")!= NULL) {
            strcpy(r.contact_info.email, strtok(token, ":"));
        }
        token = strtok(NULL, "\n");
    }

    // Print out the parsed resume
    print_resume_info(r);

    return 0;
}