//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_COMPANY_LEN 100
#define MAX_POSITION_LEN 100
#define MAX_EDUCATION_LEN 100
#define MAX_SKILLS_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char company[MAX_COMPANY_LEN];
    char position[MAX_POSITION_LEN];
    char education[MAX_EDUCATION_LEN];
    char skills[MAX_SKILLS_LEN];
} Resume;

Resume parseResume(char* input) {
    Resume r;
    char* token;
    int i = 0;

    r.name[0] = '\0';
    r.company[0] = '\0';
    r.position[0] = '\0';
    r.education[0] = '\0';
    r.skills[0] = '\0';

    token = strtok(input, ",");
    while (token!= NULL) {
        if (i == 0) {
            strcpy(r.name, token);
        } else if (i == 1) {
            strcpy(r.company, token);
        } else if (i == 2) {
            strcpy(r.position, token);
        } else if (i == 3) {
            strcpy(r.education, token);
        } else if (i == 4) {
            strcpy(r.skills, token);
        }
        i++;
        token = strtok(NULL, ",");
    }

    return r;
}

void printResume(Resume r) {
    printf("Name: %s\n", r.name);
    printf("Company: %s\n", r.company);
    printf("Position: %s\n", r.position);
    printf("Education: %s\n", r.education);
    printf("Skills: %s\n", r.skills);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <resume>\n", argv[0]);
        return 1;
    }

    char* input = argv[1];
    Resume r = parseResume(input);
    printResume(r);

    return 0;
}