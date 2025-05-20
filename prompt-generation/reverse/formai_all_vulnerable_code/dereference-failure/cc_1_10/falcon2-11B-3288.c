//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

// Define a struct to hold parsed resume data
typedef struct resume_info {
    char name[100];
    char phone[20];
    char email[100];
    char address[100];
    char education[100];
    char experience[100];
    char skills[100];
} ResumeInfo;

// Function to read and parse a resume file
ResumeInfo* read_resume(const char* filename) {
    // Open the file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the resume info struct
    ResumeInfo* info = malloc(sizeof(ResumeInfo));

    // Read the name
    fscanf(fp, "%s", info->name);

    // Read the phone number
    fscanf(fp, "%s", info->phone);

    // Read the email address
    fscanf(fp, "%s", info->email);

    // Read the address
    fscanf(fp, "%s", info->address);

    // Read the education section
    fscanf(fp, "%s", info->education);

    // Read the experience section
    fscanf(fp, "%s", info->experience);

    // Read the skills section
    fscanf(fp, "%s", info->skills);

    return info;
}

// Main function
int main(int argc, char* argv[]) {
    ResumeInfo* info = read_resume("resume.txt");

    if (info!= NULL) {
        printf("Name: %s\n", info->name);
        printf("Phone: %s\n", info->phone);
        printf("Email: %s\n", info->email);
        printf("Address: %s\n", info->address);
        printf("Education: %s\n", info->education);
        printf("Experience: %s\n", info->experience);
        printf("Skills: %s\n", info->skills);

        free(info);
    }

    return 0;
}