//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char skills[100];
    char education[100];
    char experience[500];
    char project[500];
};

void printResume(struct Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    printf("Project: %s\n", resume->project);
}

void parseResume(char *filename, struct Resume *resume) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
  
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        if (strcmp(key, "Name") == 0) {
            strcpy(resume->name, value);
        } else if (strcmp(key, "Email") == 0) {
            strcpy(resume->email, value);
        } else if (strcmp(key, "Phone") == 0) {
            strcpy(resume->phone, value);
        } else if (strcmp(key, "Skills") == 0) {
            strcpy(resume->skills, value);
        } else if (strcmp(key, "Education") == 0) {
            strcpy(resume->education, value);
        } else if (strcmp(key, "Experience") == 0) {
            strcpy(resume->experience, value);
        } else if (strcmp(key, "Project") == 0) {
            strcpy(resume->project, value);
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }
}

int main() {
    struct Resume resume;

    parseResume("resume.txt", &resume);
    printResume(&resume);

    return 0;
}