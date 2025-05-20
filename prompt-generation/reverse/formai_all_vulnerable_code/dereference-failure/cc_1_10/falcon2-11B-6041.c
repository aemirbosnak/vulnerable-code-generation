//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure to hold the parsed resume information
struct Resume {
    char name[100];
    char job[100];
    char company[100];
    char address[100];
    char phone[20];
    char email[100];
};

// Function to parse the resume file and extract the relevant information
struct Resume parseResume(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return (struct Resume){ "", "", "", "", "", "" };
    }

    char line[200];
    char temp[200];
    char* endptr;

    struct Resume resume;

    while (fgets(line, sizeof(line), file)!= NULL) {
        strtok(line, " ");  // Split the line by spaces
        strcpy(temp, strtok(NULL, "\n"));  // Remove the trailing newline character

        if (strcmp(temp, "Name:") == 0) {
            strcpy(resume.name, strtok(NULL, "\n"));
        } else if (strcmp(temp, "Job:") == 0) {
            strcpy(resume.job, strtok(NULL, "\n"));
        } else if (strcmp(temp, "Company:") == 0) {
            strcpy(resume.company, strtok(NULL, "\n"));
        } else if (strcmp(temp, "Address:") == 0) {
            strcpy(resume.address, strtok(NULL, "\n"));
        } else if (strcmp(temp, "Phone:") == 0) {
            strcpy(resume.phone, strtok(NULL, "\n"));
        } else if (strcmp(temp, "Email:") == 0) {
            strcpy(resume.email, strtok(NULL, "\n"));
        }
    }

    fclose(file);
    return resume;
}

int main() {
    struct Resume resume = parseResume("resume.txt");
    printf("Name: %s\n", resume.name);
    printf("Job: %s\n", resume.job);
    printf("Company: %s\n", resume.company);
    printf("Address: %s\n", resume.address);
    printf("Phone: %s\n", resume.phone);
    printf("Email: %s\n", resume.email);

    return 0;
}