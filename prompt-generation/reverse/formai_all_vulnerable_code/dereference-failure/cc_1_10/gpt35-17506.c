//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
    char name[50];
    char email[50];
    char phone[15];
    char education[100];
    char skills[200];
} Resume;

void parseResume(char *filename) {

    FILE *fp;
    char line[200];
    Resume res;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Failed to open file!\n");
        return;
    }

    while(fgets(line, sizeof(line), fp)) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, ":");

        if (strcmp(key, "Name") == 0) {
            strcpy(res.name, value);
        } else if (strcmp(key, "Email") == 0) {
            strcpy(res.email, value);
        } else if (strcmp(key, "Phone") == 0) {
            strcpy(res.phone, value);
        } else if (strcmp(key, "Education") == 0) {
            strcpy(res.education, value);
        } else if (strcmp(key, "Skills") == 0) {
            strcpy(res.skills, value);
        } else {
            printf("Error: Invalid key found in resume file!\n");
            return;
        }
    }

    fclose(fp);

    printf("Resume Parsing Complete!\n");
    printf("Name: %s\n", res.name);
    printf("Email: %s\n", res.email);
    printf("Phone: %s\n", res.phone);
    printf("Education: %s\n", res.education);
    printf("Skills: %s\n", res.skills);
}

int main() {
    parseResume("resume.txt");
    return 0;
}