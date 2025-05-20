//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NAME_LENGTH 64
#define MAX_COMPANY_LENGTH 128
#define MAX_POSITION_LENGTH 64
#define MAX_EDUCATION_LENGTH 128
#define MAX_SKILLS_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    char company[MAX_COMPANY_LENGTH];
    char position[MAX_POSITION_LENGTH];
    char education[MAX_EDUCATION_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
} Resume;

Resume *parseResume(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    Resume *resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        printf("Error allocating memory for resume\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (line[0] == '#') {
            char *p = strchr(line, ':');
            if (p == NULL) {
                printf("Invalid line format: %s\n", line);
                exit(1);
            }
            *p = '\0';
            p += 1;
            if (strcmp(line, "# Name") == 0) {
                strncpy(resume->name, p, MAX_NAME_LENGTH);
            } else if (strcmp(line, "# Company") == 0) {
                strncpy(resume->company, p, MAX_COMPANY_LENGTH);
            } else if (strcmp(line, "# Position") == 0) {
                strncpy(resume->position, p, MAX_POSITION_LENGTH);
            } else if (strcmp(line, "# Education") == 0) {
                strncpy(resume->education, p, MAX_EDUCATION_LENGTH);
            } else if (strcmp(line, "# Skills") == 0) {
                strncpy(resume->skills, p, MAX_SKILLS_LENGTH);
            }
        }
    }

    fclose(file);
    return resume;
}

void printResume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Company: %s\n", resume->company);
    printf("Position: %s\n", resume->position);
    printf("Education: %s\n", resume->education);
    printf("Skills: %s\n", resume->skills);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        exit(1);
    }

    Resume *resume = parseResume(argv[1]);
    if (resume == NULL) {
        return 1;
    }

    printResume(resume);
    free(resume);
    return 0;
}