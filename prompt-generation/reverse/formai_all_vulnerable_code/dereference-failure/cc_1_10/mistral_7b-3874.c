//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 256
#define MAX_NAME 50
#define MAX_SKILL 100

typedef struct {
    char name[MAX_NAME];
    char skill[MAX_SKILL][MAX_NAME];
} Resume;

void parse_line(char *line, Resume *resume) {
    char *name_start, *name_end, *skill_start, *skill_end;

    name_start = strchr(line, ':');
    name_start += 1;
    name_end = strchr(name_start, ',');

    strncpy(resume->name, name_start, name_end - name_start);

    if (name_end) {
        *name_end = '\0';
        name_end++;
    }

    skill_start = line;
    skill_end = strchr(skill_start, ',');

    if (skill_start < name_start) {
        strncpy(resume->skill[0], skill_start, skill_end - skill_start);
        memset(resume->skill[1], '\0', MAX_SKILL * MAX_NAME);
    } else {
        int i = 0;
        strtok(skill_start, ",");

        while (resume->skill[i++][0] != '\0') {
            strcpy(resume->skill[i], strtok(NULL, ","));
        }
    }
}

int main() {
    FILE *fp;
    Resume resume;
    char line[MAX_LINE];

    fp = fopen("resumes.txt", "r");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, MAX_LINE, fp) != NULL) {
        parse_line(line, &resume);
        printf("%s\n", resume.name);
        int i = 0;

        if (strlen(resume.skill[0]) > 0) {
            printf("%s: ", resume.name);

            for (; i < 10 && resume.skill[i][0] != '\0'; i++) {
                printf("%s ", resume.skill[i]);
            }

            printf("\n");
        }
    }

    fclose(fp);
    return 0;
}