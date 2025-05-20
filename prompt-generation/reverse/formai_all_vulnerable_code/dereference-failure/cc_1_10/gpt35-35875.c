//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char skills[200];
    char experience[200];
    char education[200];
} Resume;

void parseResume(char *filename) {
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t len = 0;

    Resume resume;

    while (getline(&line, &len, file) != -1) {
        char *token = strtok(line, ":");
        if (strcmp(token, "Name") == 0) {
            token = strtok(NULL, ":");
            strcpy(resume.name, token);
        } else if (strcmp(token, "Email") == 0) {
            token = strtok(NULL, ":");
            strcpy(resume.email, token);
        } else if (strcmp(token, "Phone") == 0) {
            token = strtok(NULL, ":");
            strcpy(resume.phone, token);
        } else if (strcmp(token, "Address") == 0) {
            token = strtok(NULL, ":");
            strcpy(resume.address, token);
        } else if (strcmp(token, "Skills") == 0) {
            token = strtok(NULL, ":");
            strcpy(resume.skills, token);
        } else if (strcmp(token, "Experience") == 0) {
            token = strtok(NULL, ":");
            strcpy(resume.experience, token);
        } else if (strcmp(token, "Education") == 0) {
            token = strtok(NULL, ":");
            strcpy(resume.education, token);
        }
    }

    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Skills: %s\n", resume.skills);
    printf("Experience: %s\n", resume.experience);
    printf("Education: %s\n", resume.education);

    fclose(file);
    if (line) {
        free(line);
    }
}

int main() {
    parseResume("resume.txt");
    return 0;
}