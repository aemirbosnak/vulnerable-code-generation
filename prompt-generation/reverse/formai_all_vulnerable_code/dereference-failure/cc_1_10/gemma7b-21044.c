//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *address;
} Resume;

void parse_resume(char *resume_data) {
    char *name = NULL;
    char *email = NULL;
    char *phone = NULL;
    char *address = NULL;

    // Allocate memory for the resume structure
    Resume *resume = (Resume *)malloc(sizeof(Resume));
    resume->name = (char *)malloc(MAX_BUFFER_SIZE);
    resume->email = (char *)malloc(MAX_BUFFER_SIZE);
    resume->phone = (char *)malloc(MAX_BUFFER_SIZE);
    resume->address = (char *)malloc(MAX_BUFFER_SIZE);

    // Extract the name, email, phone, and address from the resume data
    name = strstr(resume_data, "Name:");
    email = strstr(name, "Email:");
    phone = strstr(email, "Phone:");
    address = strstr(phone, "Address:");

    // Fill the resume structure with the extracted data
    strcpy(resume->name, name + 5);
    strcpy(resume->email, email + 6);
    strcpy(resume->phone, phone + 7);
    strcpy(resume->address, address + 8);

    // Print the resume data
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);

    // Free the allocated memory
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume);
}

int main() {
    // Get the resume data from the user
    char *resume_data = NULL;
    printf("Enter the resume data: ");
    getline(&resume_data, MAX_BUFFER_SIZE, stdin);

    // Parse the resume data
    parse_resume(resume_data);

    return 0;
}