//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[100];
    char phone[20];
    char email[100];
    char address[100];
    char work_experience[100];
} Resume;

void parse_resume(const char* filename, Resume* resume) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        return;
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        char* field = strtok(line, ":");
        if (field!= NULL) {
            field = strtok(NULL, ":");
            strcpy(resume->name, field);
        }
        else {
            fprintf(stderr, "Invalid resume format\n");
            return;
        }

        field = strtok(NULL, ":");
        if (field!= NULL) {
            field = strtok(NULL, ":");
            strcpy(resume->phone, field);
        }
        else {
            fprintf(stderr, "Invalid resume format\n");
            return;
        }

        field = strtok(NULL, ":");
        if (field!= NULL) {
            field = strtok(NULL, ":");
            strcpy(resume->email, field);
        }
        else {
            fprintf(stderr, "Invalid resume format\n");
            return;
        }

        field = strtok(NULL, ":");
        if (field!= NULL) {
            field = strtok(NULL, ":");
            strcpy(resume->address, field);
        }
        else {
            fprintf(stderr, "Invalid resume format\n");
            return;
        }

        field = strtok(NULL, ":");
        if (field!= NULL) {
            field = strtok(NULL, ":");
            strcpy(resume->work_experience, field);
        }
        else {
            fprintf(stderr, "Invalid resume format\n");
            return;
        }
    }

    fclose(file);
}

int main() {
    Resume resume;
    parse_resume("resume.txt", &resume);

    printf("Name: %s\n", resume.name);
    printf("Phone: %s\n", resume.phone);
    printf("Email: %s\n", resume.email);
    printf("Address: %s\n", resume.address);
    printf("Work Experience:\n");
    printf("%s\n", resume.work_experience);

    return 0;
}