//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
    char name[50];
    char email[50];
    char phone[15];
    char address[100];
    char skills[50][10];
    char education[10][50];
    char work_experience[10][50];
} Resume;

Resume parse_resume(char* resume_text) {
    Resume resume;
    char* token = strtok(resume_text, " ");

    strcpy(resume.name, token);
    token = strtok(NULL, " ");
    strcpy(resume.email, token);
    token = strtok(NULL, " ");
    strcpy(resume.phone, token);
    token = strtok(NULL, " ");
    strcpy(resume.address, token);
    token = strtok(NULL, " ");
    strcpy(resume.skills[0], token);
    token = strtok(NULL, " ");
    while (token!= NULL) {
        strcpy(resume.skills[strlen(resume.skills)], token);
        token = strtok(NULL, " ");
    }
    token = strtok(NULL, " ");
    strcpy(resume.education[0], token);
    token = strtok(NULL, " ");
    while (token!= NULL) {
        strcpy(resume.education[strlen(resume.education)], token);
        token = strtok(NULL, " ");
    }
    token = strtok(NULL, " ");
    strcpy(resume.work_experience[0], token);
    token = strtok(NULL, " ");
    while (token!= NULL) {
        strcpy(resume.work_experience[strlen(resume.work_experience)], token);
        token = strtok(NULL, " ");
    }

    return resume;
}

int main() {
    char* resume_text = "John Doe\njdoe@example.com\n(123) 456-7890\n123 Main St, Anytown USA 12345\nPython, Java, C++, HTML, CSS, JavaScript\nBachelor's Degree in Computer Science from XYZ University\n3 years of experience as a software developer at ABC Corp";
    Resume resume = parse_resume(resume_text);

    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Skills:\n");
    for (int i = 0; i < strlen(resume.skills); i++) {
        printf("- %s\n", resume.skills[i]);
    }
    printf("Education:\n");
    for (int i = 0; i < strlen(resume.education); i++) {
        printf("- %s\n", resume.education[i]);
    }
    printf("Work Experience:\n");
    for (int i = 0; i < strlen(resume.work_experience); i++) {
        printf("- %s\n", resume.work_experience[i]);
    }

    return 0;
}