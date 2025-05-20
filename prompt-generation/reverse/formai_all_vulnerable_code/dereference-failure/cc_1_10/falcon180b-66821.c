//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_SIZE 100
#define MAX_EDUCATION_SIZE 100
#define MAX_WORK_EXPERIENCE_SIZE 100

typedef struct {
    char name[MAX_NAME_SIZE];
    int age;
    char education[MAX_EDUCATION_SIZE];
    char work_experience[MAX_WORK_EXPERIENCE_SIZE];
} Resume;

Resume parse_resume(char* input) {
    Resume resume;
    char* token = strtok(input, ",");
    strcpy(resume.name, token);

    token = strtok(NULL, ",");
    resume.age = atoi(token);

    token = strtok(NULL, ",");
    strcpy(resume.education, token);

    token = strtok(NULL, ",");
    strcpy(resume.work_experience, token);

    return resume;
}

void print_resume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Age: %d\n", resume.age);
    printf("Education: %s\n", resume.education);
    printf("Work Experience: %s\n", resume.work_experience);
}

int main() {
    char input[1000];
    Resume resume;

    printf("Enter resume in format Name,Age,Education,Work Experience:\n");
    scanf("%s", input);

    resume = parse_resume(input);
    print_resume(resume);

    return 0;
}