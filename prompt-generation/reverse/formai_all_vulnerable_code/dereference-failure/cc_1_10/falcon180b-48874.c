//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for resume data
typedef struct {
    char name[50];
    char address[100];
    char phone[15];
    char email[50];
    char education[100];
    char experience[200];
} Resume;

// Function to parse resume data
Resume parseResume(char* data) {
    Resume resume;
    char* token = strtok(data, "\n");
    int i = 0;

    while (token!= NULL) {
        if (i == 0) {
            strcpy(resume.name, token);
        } else if (i == 1) {
            strcpy(resume.address, token);
        } else if (i == 2) {
            strcpy(resume.phone, token);
        } else if (i == 3) {
            strcpy(resume.email, token);
        } else if (i == 4) {
            strcpy(resume.education, token);
        } else if (i == 5) {
            strcpy(resume.experience, token);
        }

        token = strtok(NULL, "\n");
        i++;
    }

    return resume;
}

// Function to print resume data
void printResume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Phone: %s\n", resume.phone);
    printf("Email: %s\n", resume.email);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
}

// Main function
int main() {
    char* data = "John Doe\n"
                 "123 Main St.\n"
                 "555-1234\n"
                 "johndoe@email.com\n"
                 "BS Computer Science\n"
                 "5 years experience in programming\n";

    Resume resume = parseResume(data);
    printResume(resume);

    return 0;
}