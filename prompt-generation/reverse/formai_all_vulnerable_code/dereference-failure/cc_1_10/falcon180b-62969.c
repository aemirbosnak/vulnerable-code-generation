//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_COMPANY_LEN 100
#define MAX_EDUCATION_LEN 100
#define MAX_SKILLS_LEN 100
#define MAX_WORK_EXPERIENCE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char company[MAX_COMPANY_LEN];
    char education[MAX_EDUCATION_LEN];
    char skills[MAX_SKILLS_LEN];
    char work_experience[MAX_WORK_EXPERIENCE_LEN];
} Resume;

Resume parse_resume(char *input) {
    Resume resume;
    char *token;
    int work_experience_index = 0;

    // Parse name
    token = strtok(input, ",");
    strcpy(resume.name, token);

    // Parse company
    token = strtok(NULL, ",");
    strcpy(resume.company, token);

    // Parse education
    token = strtok(NULL, ",");
    strcpy(resume.education, token);

    // Parse skills
    token = strtok(NULL, ",");
    strcpy(resume.skills, token);

    // Parse work experience
    while ((token = strtok(NULL, ","))!= NULL) {
        if (work_experience_index >= MAX_WORK_EXPERIENCE_LEN) {
            printf("Error: Work experience exceeds maximum length.\n");
            exit(1);
        }
        strcat(resume.work_experience, token);
        strcat(resume.work_experience, " ");
        work_experience_index += strlen(token) + 1;
    }

    return resume;
}

void print_resume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Company: %s\n", resume.company);
    printf("Education: %s\n", resume.education);
    printf("Skills: %s\n", resume.skills);
    printf("Work Experience: %s\n", resume.work_experience);
}

int main() {
    char input[1000];
    Resume resume;

    printf("Enter resume in format: Name,Company,Education,Skills,Work Experience\n");
    fgets(input, sizeof(input), stdin);

    resume = parse_resume(input);
    print_resume(resume);

    return 0;
}