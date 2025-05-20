//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char education[100];
    char experience[200];
} Resume;

int main() {
    const char* FILENAME = "resume.txt";
    const char* DELIMITER = "/";

    FILE* file = fopen(FILENAME, "r");
    if (!file) {
        printf("Could not open file %s\n", FILENAME);
        return 1;
    }

    // Parse resume data from file
    Resume resume;
    char* line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    while ((linelen = getline(&line, &linecap, file)) > 0) {
        char* key = strtok(line, DELIMITER);
        char* value = strtok(NULL, DELIMITER);
        if (strcmp(key, "Name") == 0) {
            strcpy(resume.name, value);
        } else if (strcmp(key, "Email") == 0) {
            strcpy(resume.email, value);
        } else if (strcmp(key, "Phone") == 0) {
            strcpy(resume.phone, value);
        } else if (strcmp(key, "Address") == 0) {
            strcpy(resume.address, value);
        } else if (strcmp(key, "Education") == 0) {
            strcpy(resume.education, value);
        } else if (strcmp(key, "Experience") == 0) {
            strcpy(resume.experience, value);
        } else {
            printf("Invalid key in file: %s\n", key);
        }
    }

    // Print parsed resume data
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    // Clean up
    free(line);
    fclose(file);
    return 0;
}