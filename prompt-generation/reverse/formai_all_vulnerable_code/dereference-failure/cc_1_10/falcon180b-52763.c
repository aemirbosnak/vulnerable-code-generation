//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_RESUME_SIZE 1000000 // maximum size of a resume in bytes
#define MAX_NAME_LENGTH 50 // maximum length of a name

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char address[MAX_RESUME_SIZE];
    char email[MAX_RESUME_SIZE];
    char phone[MAX_RESUME_SIZE];
} Resume;

Resume parseResume(FILE *fp) {
    Resume resume;
    char line[MAX_RESUME_SIZE];
    char *token;
    int i = 0;
    while (fgets(line, MAX_RESUME_SIZE, fp)) {
        if (i == 0) {
            token = strtok(line, " ");
            strcpy(resume.name, token);
        } else if (i == 1) {
            token = strtok(NULL, " ");
            resume.age = atoi(token);
        } else if (i == 2) {
            token = strtok(NULL, " ");
            strcpy(resume.address, token);
        } else if (i == 3) {
            token = strtok(NULL, " ");
            strcpy(resume.email, token);
        } else if (i == 4) {
            token = strtok(NULL, " ");
            strcpy(resume.phone, token);
        }
        i++;
    }
    return resume;
}

void printResume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Age: %d\n", resume.age);
    printf("Address: %s\n", resume.address);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
}

int main() {
    FILE *fp;
    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }
    Resume resume = parseResume(fp);
    printResume(resume);
    fclose(fp);
    return 0;
}