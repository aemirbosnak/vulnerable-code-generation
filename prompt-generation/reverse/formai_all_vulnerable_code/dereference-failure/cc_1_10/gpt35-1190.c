//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* email;
    char* education;
    char* work_experience;
} Resume;

void parse_resume(char* filename) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    Resume resume;
    while ((read = getline(&line, &len, fp)) != -1) {
        char* key = strtok(line, ":");
        char* value = strtok(NULL, "\n");

        if (strcmp(key, "name") == 0) {
            resume.name = value;
        } else if (strcmp(key, "email") == 0) {
            resume.email = value;
        } else if (strcmp(key, "education") == 0) {
            resume.education = value;
        } else if (strcmp(key, "work_experience") == 0) {
            resume.work_experience = value;
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }

    printf("Resume parsed successfully:\n");
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Education: %s\n", resume.education);
    printf("Work Experience: %s\n", resume.work_experience);
}

int main(void) {
    char filename[] = "resume.txt";
    parse_resume(filename);

    return 0;
}