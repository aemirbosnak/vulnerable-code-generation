//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_NAME 50
#define MAX_SKILL 100

typedef struct {
    char name[MAX_NAME];
    char skill[MAX_SKILL][50];
    int num_skill;
} Resume;

void parse_line(char *line, Resume *resume) {
    char *token;
    char name[MAX_NAME];
    int i = 0;

    token = strtok(line, ": ");
    strcpy(name, token);

    if (strcmp(name, "Skills:") == 0) {
        resume->num_skill = 0;
        return;
    }

    if (resume->num_skill < MAX_SKILL) {
        strcpy(resume->skill[resume->num_skill], token);
        resume->num_skill++;
    }
}

int main(int argc, char **argv) {
    Resume resume;
    char line[MAX_LINE];
    int i;

    if (argc != 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE, fp)) {
        parse_line(line, &resume);
    }

    printf("\nName: %s\n", resume.name);
    printf("Skills:\n");
    for (i = 0; i < resume.num_skill; i++) {
        printf("- %s\n", resume.skill[i]);
    }

    fclose(fp);
    return 0;
}