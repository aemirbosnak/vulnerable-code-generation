//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_SIZE 10000 // Maximum size of a resume in bytes

typedef struct {
    char name[50];
    char email[50];
    char phone[15];
    char address[100];
    char education[100];
    char experience[200];
} Resume;

Resume* parseResume(char* buffer) {
    Resume* resume = (Resume*)malloc(sizeof(Resume));
    char* token;

    // Extract name
    token = strtok(buffer, ",");
    strcpy(resume->name, token);

    // Extract email
    token = strtok(NULL, ",");
    strcpy(resume->email, token);

    // Extract phone number
    token = strtok(NULL, ",");
    strcpy(resume->phone, token);

    // Extract address
    token = strtok(NULL, ",");
    strcpy(resume->address, token);

    // Extract education
    token = strtok(NULL, ",");
    strcpy(resume->education, token);

    // Extract experience
    token = strtok(NULL, ",");
    strcpy(resume->experience, token);

    return resume;
}

void printResume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

int main() {
    FILE* file;
    char buffer[MAX_RESUME_SIZE];
    Resume* resume;

    file = fopen("resume.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fgets(buffer, MAX_RESUME_SIZE, file);

    resume = parseResume(buffer);

    printResume(resume);

    free(resume);
    fclose(file);

    return 0;
}