//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_COMPANY_LEN 100
#define MAX_POSITION_LEN 30
#define MAX_SKILL_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char company[MAX_COMPANY_LEN];
    char position[MAX_POSITION_LEN];
    char *skills;
    int len_skills;
} resume_t;

void extract_skills(char *line, resume_t *resume) {
    int i = 0, j = 0;
    char skill[MAX_SKILL_LEN];

    resume->skills = malloc(MAX_SKILL_LEN * 10);

    while (sscanf(line + i, "%s%n", skill, &j) > 0) {
        resume->skills[resume->len_skills++] = strdup(skill);
        i += j + strlen(skill) + 1;

        if (resume->len_skills >= 10) {
            resume->skills = realloc(resume->skills, (resume->len_skills + 1) * sizeof(char *));
            resume->skills[resume->len_skills - 1] = NULL;
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    resume_t resume;
    char line[1024];

    if (argc != 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Name:") || strstr(line, "name:")) {
            sscanf(line, "Name: %s%n", resume.name, line);
            continue;
        }

        if (strstr(line, "Company:") || strstr(line, "company:")) {
            sscanf(line, "Company: %s%n", resume.company, line);
            continue;
        }

        if (strstr(line, "Position:") || strstr(line, "position:")) {
            sscanf(line, "Position: %s%n", resume.position, line);
            continue;
        }

        extract_skills(line, &resume);
    }

    fclose(file);

    printf("Name: %s\n", resume.name);
    printf("Company: %s\n", resume.company);
    printf("Position: %s\n", resume.position);
    printf("Skills:\n");

    for (int i = 0; resume.skills[i] != NULL; i++) {
        printf("- %s\n", resume.skills[i]);
    }

    free(resume.skills);

    return 0;
}