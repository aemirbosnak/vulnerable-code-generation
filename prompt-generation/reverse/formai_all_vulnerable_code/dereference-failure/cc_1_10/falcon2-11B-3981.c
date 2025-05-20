//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the parsed resume data
typedef struct {
    char name[100];
    int age;
    char job[100];
    char company[100];
    char address[100];
    char phone[20];
    char email[100];
} Resume;

// Function to parse the resume file and extract the data
Resume* parseResume(FILE* file) {
    Resume* resume = malloc(sizeof(Resume));
    
    // Read the name
    fscanf(file, "%s", resume->name);
    
    // Read the age
    fscanf(file, "%d", &resume->age);
    
    // Read the job
    fscanf(file, "%s", resume->job);
    
    // Read the company
    fscanf(file, "%s", resume->company);
    
    // Read the address
    fscanf(file, "%s", resume->address);
    
    // Read the phone number
    fscanf(file, "%s", resume->phone);
    
    // Read the email address
    fscanf(file, "%s", resume->email);
    
    return resume;
}

// Function to print the parsed resume data
void printResume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Age: %d\n", resume->age);
    printf("Job: %s\n", resume->job);
    printf("Company: %s\n", resume->company);
    printf("Address: %s\n", resume->address);
    printf("Phone: %s\n", resume->phone);
    printf("Email: %s\n", resume->email);
}

int main() {
    // Open the resume file
    FILE* file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    // Parse the resume file
    Resume* resume = parseResume(file);
    
    // Print the parsed resume data
    printResume(resume);
    
    // Clean up the memory
    free(resume);
    
    // Close the file
    fclose(file);
    
    return 0;
}