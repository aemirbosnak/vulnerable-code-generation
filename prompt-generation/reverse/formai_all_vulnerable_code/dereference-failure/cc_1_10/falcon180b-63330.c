//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_KEYWORDS 20
#define MAX_KEYWORD_LENGTH 50

typedef struct {
    char *name;
    int experience;
    char *skills[MAX_NUM_KEYWORDS];
    int num_skills;
} Resume;

Resume parse_resume(char *filename) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    int i = 0;
    Resume resume;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, ",");
        if (i == 0) {
            resume.name = strdup(token);
        } else if (i == 1) {
            resume.experience = atoi(token);
        } else {
            strcpy(resume.skills[i-2], token);
            i++;
        }
    }

    fclose(fp);
    resume.num_skills = i - 2;

    return resume;
}

void print_resume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Experience: %d years\n", resume.experience);
    printf("Skills:\n");
    for (int i = 0; i < resume.num_skills; i++) {
        printf("%s\n", resume.skills[i]);
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the resume file: ");
    scanf("%s", filename);

    Resume resume = parse_resume(filename);
    print_resume(resume);

    return 0;
}