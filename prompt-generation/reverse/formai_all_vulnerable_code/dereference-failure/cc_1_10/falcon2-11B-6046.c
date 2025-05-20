//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    int age;
    char gender[10];
    char phone[20];
    char email[50];
    char address[100];
    char education[100];
    char work_experience[100];
    char skills[100];
} Resume;

int main() {
    Resume resume;
    char line[100];
    FILE *fp;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token;
        token = strtok(line, ",");
        while (token!= NULL) {
            strcpy(resume.name, token);
            token = strtok(NULL, ",");
            resume.age = atoi(token);
            token = strtok(NULL, ",");
            strcpy(resume.gender, token);
            token = strtok(NULL, ",");
            strcpy(resume.phone, token);
            token = strtok(NULL, ",");
            strcpy(resume.email, token);
            token = strtok(NULL, ",");
            strcpy(resume.address, token);
            token = strtok(NULL, ",");
            strcpy(resume.education, token);
            token = strtok(NULL, ",");
            strcpy(resume.work_experience, token);
            token = strtok(NULL, ",");
            strcpy(resume.skills, token);
            token = strtok(NULL, "\n");
        }
    }

    fclose(fp);
    printf("Name: %s\n", resume.name);
    printf("Age: %d\n", resume.age);
    printf("Gender: %s\n", resume.gender);
    printf("Phone: %s\n", resume.phone);
    printf("Email: %s\n", resume.email);
    printf("Address: %s\n", resume.address);
    printf("Education: %s\n", resume.education);
    printf("Work Experience: %s\n", resume.work_experience);
    printf("Skills: %s\n", resume.skills);

    return 0;
}