//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NAME_LEN 100
#define MAX_COMPANY_LEN 100
#define MAX_POSITION_LEN 100
#define MAX_EDUCATION_LEN 100
#define MAX_SKILL_LEN 100
#define MAX_EXPERIENCE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char company[MAX_COMPANY_LEN];
    char position[MAX_POSITION_LEN];
    char education[MAX_EDUCATION_LEN];
    char skill[MAX_SKILL_LEN];
    char experience[MAX_EXPERIENCE_LEN];
} Resume;

Resume parseResume(char* resumeText) {
    Resume result = {0};
    char* line = strtok(resumeText, "\n");
    while (line!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            strcpy(result.name, line + 6);
        } else if (strncmp(line, "Company:", 8) == 0) {
            strcpy(result.company, line + 9);
        } else if (strncmp(line, "Position:", 9) == 0) {
            strcpy(result.position, line + 10);
        } else if (strncmp(line, "Education:", 9) == 0) {
            strcpy(result.education, line + 10);
        } else if (strncmp(line, "Skill:", 5) == 0) {
            strcpy(result.skill, line + 6);
        } else if (strncmp(line, "Experience:", 9) == 0) {
            strcpy(result.experience, line + 10);
        }
        line = strtok(NULL, "\n");
    }
    return result;
}

int main() {
    char* resumeText = "Name: John Doe\n"
                        "Company: Google\n"
                        "Position: Software Engineer\n"
                        "Education: Computer Science Degree\n"
                        "Skill: C++ Programming\n"
                        "Experience: 5 years of experience in software development.\n";
    Resume resume = parseResume(resumeText);
    printf("Name: %s\n", resume.name);
    printf("Company: %s\n", resume.company);
    printf("Position: %s\n", resume.position);
    printf("Education: %s\n", resume.education);
    printf("Skill: %s\n", resume.skill);
    printf("Experience: %s\n", resume.experience);
    return 0;
}