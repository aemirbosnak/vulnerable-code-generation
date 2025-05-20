//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} Resume;

Resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    Resume *resume = malloc(sizeof(Resume));
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->skills = NULL;
    resume->experience = NULL;
    resume->education = NULL;

    int line_number = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        line_number++;

        if (line[0] == '\n') {
            continue;
        }

        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        if (strcmp(key, "name") == 0) {
            resume->name = malloc(strlen(value) + 1);
            strcpy(resume->name, value);
        } else if (strcmp(key, "email") == 0) {
            resume->email = malloc(strlen(value) + 1);
            strcpy(resume->email, value);
        } else if (strcmp(key, "phone") == 0) {
            resume->phone = malloc(strlen(value) + 1);
            strcpy(resume->phone, value);
        } else if (strcmp(key, "skills") == 0) {
            resume->skills = malloc(strlen(value) + 1);
            strcpy(resume->skills, value);
        } else if (strcmp(key, "experience") == 0) {
            resume->experience = malloc(strlen(value) + 1);
            strcpy(resume->experience, value);
        } else if (strcmp(key, "education") == 0) {
            resume->education = malloc(strlen(value) + 1);
            strcpy(resume->education, value);
        }
    }

    fclose(fp);

    return resume;
}

void print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    Resume *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        printf("Error: could not parse resume file\n");
        return 1;
    }

    print_resume(resume);

    return 0;
}