//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64
#define MAX_RESUME_SIZE 1000

typedef struct {
    char name[MAX_WORD_SIZE];
    char value[MAX_LINE_SIZE];
} KeyValue;

typedef struct {
    int numSections;
    char sections[MAX_RESUME_SIZE];
} Resume;

Resume parseResume(FILE *fp) {
    Resume resume = {0};
    char line[MAX_LINE_SIZE];
    char section[MAX_WORD_SIZE];
    int sectionCount = 0;

    while(fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if(strncmp(line, "Name: ", 6) == 0) {
            strcpy(resume.sections[sectionCount], "Name");
            strcpy(resume.sections[++sectionCount], &line[6]);
        } else if(strncmp(line, "Education: ", 10) == 0) {
            strcpy(resume.sections[sectionCount], "Education");
            strcpy(resume.sections[++sectionCount], &line[10]);
        } else if(strncmp(line, "Experience: ", 10) == 0) {
            strcpy(resume.sections[sectionCount], "Experience");
            strcpy(resume.sections[++sectionCount], &line[10]);
        } else if(strncmp(line, "Skills: ", 7) == 0) {
            strcpy(resume.sections[sectionCount], "Skills");
            strcpy(resume.sections[++sectionCount], &line[7]);
        }
    }

    resume.numSections = sectionCount;

    return resume;
}

void printResume(Resume resume) {
    int i;

    for(i = 0; i < resume.numSections; i++) {
        printf("%s:\n", resume.sections[i]);
    }
}

int main() {
    FILE *fp;
    Resume resume;

    fp = fopen("resume.txt", "r");

    if(fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    resume = parseResume(fp);

    printResume(resume);

    fclose(fp);

    return 0;
}