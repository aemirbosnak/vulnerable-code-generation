//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_SKILLS_LENGTH 250
#define MAX_EXPERIENCE_LENGTH 500
#define MAX_EDUCATION_LENGTH 500

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    char education[MAX_EDUCATION_LENGTH];
} Resume;

void parse_line(char *line, Resume *resume) {
    char *key = strtok(line, ":");
    char *value = strtok(NULL, "");

    if (strcmp(key, "Name") == 0) {
        strcpy(resume->name, value);
    } else if (strcmp(key, "Address") == 0) {
        strcpy(resume->address, value);
    } else if (strcmp(key, "Phone") == 0) {
        strcpy(resume->phone, value);
    } else if (strcmp(key, "Email") == 0) {
        strcpy(resume->email, value);
    } else if (strcmp(key, "Skills") == 0) {
        strcpy(resume->skills, value);
    } else if (strcmp(key, "Experience") == 0) {
        strcpy(resume->experience, value);
    } else if (strcmp(key, "Education") == 0) {
        strcpy(resume->education, value);
    }
}

void print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Address: %s\n", resume->address);
    printf("Phone: %s\n", resume->phone);
    printf("Email: %s\n", resume->email);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening resume file");
        return 1;
    }

    char line[1024];
    Resume resume;
    memset(&resume, 0, sizeof(Resume));

    while (fgets(line, sizeof(line), fp)) {
        parse_line(line, &resume);
    }

    fclose(fp);

    print_resume(&resume);

    return 0;
}