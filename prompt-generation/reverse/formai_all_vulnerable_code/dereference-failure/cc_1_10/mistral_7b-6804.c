//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    char name[100];
    int age;
    char position[50];
    char company[100];
    char email[50];
} Resume;

bool parse_line(char *line, Resume *resume) {
    char *token;

    // Reset resume data
    memset(resume, 0, sizeof(Resume));

    // Parse name
    token = strtok(line, "|");
    strncpy(resume->name, token, sizeof(resume->name) - 1);
    resume->name[sizeof(resume->name) - 1] = '\0';

    // Parse age
    token = strtok(NULL, "|");
    resume->age = atoi(token);

    // Parse position
    token = strtok(NULL, "|");
    strncpy(resume->position, token, sizeof(resume->position) - 1);
    resume->position[sizeof(resume->position) - 1] = '\0';

    // Parse company
    token = strtok(NULL, "|");
    strncpy(resume->company, token, sizeof(resume->company) - 1);
    resume->company[sizeof(resume->company) - 1] = '\0';

    // Parse email
    token = strtok(NULL, "|");
    strncpy(resume->email, token, sizeof(resume->email) - 1);
    resume->email[sizeof(resume->email) - 1] = '\0';

    // Check for errors
    if (token != NULL) {
        printf("Error: Invalid resume format\n");
        return false;
    }

    return true;
}

int main() {
    FILE *fp;
    char line[200];
    Resume resume;

    fp = fopen("future_resumes.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (parse_line(line, &resume)) {
            printf("Name: %s\n", resume.name);
            printf("Age: %d\n", resume.age);
            printf("Position: %s\n", resume.position);
            printf("Company: %s\n", resume.company);
            printf("Email: %s\n\n", resume.email);
        }
    }

    fclose(fp);

    return 0;
}