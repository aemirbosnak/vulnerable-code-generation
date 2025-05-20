//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[50];
    char phone[15];
    char skills[100];
    char education[100];
    char experience[100];
} applicant;

void parseResume(applicant *app, char *filename);
void printApplicantInfo(applicant app);

int main() {
    char filename[50];
    printf("Enter the filename of the resume to parse: ");
    scanf("%s", filename);
    
    applicant app;
    memset(&app, 0, sizeof(applicant));
    parseResume(&app, filename);
    printApplicantInfo(app);

    return 0;
}

void parseResume(applicant *app, char *filename) {
    FILE *fp;
    char buff[255], *token;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fgets(buff, 255, fp)) {
        token = strtok(buff, ":\n");
        if (strcmp(token, "Name") == 0) {
            token = strtok(NULL, ":\n");
            strcpy(app->name, token);
        } else if (strcmp(token, "Email") == 0) {
            token = strtok(NULL, ":\n");
            strcpy(app->email, token);
        } else if (strcmp(token, "Phone") == 0) {
            token = strtok(NULL, ":\n");
            strcpy(app->phone, token);
        } else if (strcmp(token, "Skills") == 0) {
            token = strtok(NULL, ":\n");
            strcpy(app->skills, token);
        } else if (strcmp(token, "Education") == 0) {
            token = strtok(NULL, ":\n");
            strcpy(app->education, token);
        } else if (strcmp(token, "Experience") == 0) {
            token = strtok(NULL, ":\n");
            strcpy(app->experience, token);
        }
    }

    fclose(fp);
}

void printApplicantInfo(applicant app) {
    printf("\n========== Applicant Information ==========\n");
    printf("Name:\t\t%s\n", app.name);
    printf("Email:\t\t%s\n", app.email);
    printf("Phone:\t\t%s\n", app.phone);
    printf("Skills:\t\t%s\n", app.skills);
    printf("Education:\t%s\n", app.education);
    printf("Experience:\t%s\n", app.experience);
}